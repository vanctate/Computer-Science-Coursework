// Patrick Tate
// CSCI 3761 Lab 2
// simple server program


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/wait.h>
#include <signal.h>

// port number
#define PORTNUM 46000

// max size transfer
#define MAXBUFFERSIZE 1024

// total connections
#define BACKLOG 10

using namespace std;

void sigchld_handler(int s)
{
    while(waitpid(-1, NULL, WNOHANG) > 0);
}

int main(void)
{

    // socket variables
    int sockfd, new_fd;
    struct sockaddr_in my_addr;
    struct sockaddr_in their_addr;
    char buf[MAXBUFFERSIZE]; // to hold send/receive data
    int saved_stdout;
    int saved_stdout2;

    // message server side
    printf("*******\n");
    printf("Server side\n");
    printf("*******\n");


    socklen_t sin_size;
    struct sigaction sa;
    int yes=1;
    // check for socket error
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket");
        exit(1);
    }

    printf("Socket created.\n");
    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(int)) == -1) {
        perror("setsockopt");
        exit(1);
    }
    my_addr.sin_family = AF_INET;
    my_addr.sin_port = htons(PORTNUM);
    my_addr.sin_addr.s_addr = INADDR_ANY;
    memset(my_addr.sin_zero, '\0', sizeof my_addr.sin_zero);
    // bind socket
    if (bind(sockfd, (struct sockaddr *)&my_addr, sizeof my_addr) == -1) {
        perror("bind");
        exit(1); }
    printf("Binding.\n");
    if (listen(sockfd, BACKLOG) == -1) {
        perror("listen");
        exit(1);
    }
    printf("Listening for connections.\n");
    sa.sa_handler = sigchld_handler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = SA_RESTART;
    // catch errors
    if (sigaction(SIGCHLD, &sa, NULL) == -1) {
        perror("sigaction");
        exit(1); }

    // connection loop
    while(true) {
        sin_size = sizeof their_addr;

        //accept new connections
        if ((new_fd = accept(sockfd, (struct sockaddr *)&their_addr, \
                             &sin_size)) == -1) {
            perror("accept");
            continue;
        }
        printf("Connection from %s\n", \
                    inet_ntoa(their_addr.sin_addr));

        if (new_fd < 0) {
            printf("Cannot connect!\n");
        } else {
            // fork for multiple clients
            int Fork = fork();
            if (Fork < 0) {
                printf("Issue creating fork.\n");
            } else if (Fork == 0) {
                // main menu loop
                while(true) {
                    recv(new_fd, buf, MAXBUFFERSIZE, 0);

                    // catalog
                    if (strcmp(buf, "catalog") == 0) {
                        printf("> Client requested 'catalog'\n");
                        saved_stdout = dup(1);
                        // send ls to client
                        dup2(new_fd, 1);
                        system("ls");
                        dup2(saved_stdout, 1);
                        close(saved_stdout);
                        continue;
                    // spwd
                    } else if (strcmp(buf, "spwd") == 0) {
                        printf("> Client requested 'spwd'\n");
                        saved_stdout2 = dup(1);
                        dup2(new_fd, 1);
                        // send pwd to client
                        system("pwd");
                        dup2(saved_stdout2, 1);
                        close(saved_stdout2);
                        continue;
                    // download
                    } else if (strcmp(buf, "download") == 0) {
                        printf("> Client requested 'download'\n");
                        // clear buffer
                        memset(buf, 0, MAXBUFFERSIZE);
                        // receive file name
                        recv(new_fd, buf, MAXBUFFERSIZE, 0);
                        printf("> Finding filename: %s\n", buf);
                        FILE *f;
                        // open file and check fail or success
                        f = fopen(buf, "r");
                        if (f == NULL) {
                            printf("*** Fail. Can't find file in server ***\n");
                            memset(buf, 0, MAXBUFFERSIZE);
                            send(new_fd, "fail", MAXBUFFERSIZE, 0);
                        } else {
                            send(new_fd, buf, MAXBUFFERSIZE, 0);
                            printf("Success. Downloading file to client side\n");
                            fseek(f, 0, SEEK_END);
                            rewind(f);
                            memset(buf, 0, MAXBUFFERSIZE);
                            fread(buf, sizeof(char), sizeof(buf), f);
                            send(new_fd, buf, MAXBUFFERSIZE, 0);
                            fclose(f);
                        }
                        continue;
                    // upload
                    } else if (strcmp(buf, "upload") == 0) {
                        printf("> Client requested 'upload'\n");
                        recv(new_fd, buf, MAXBUFFERSIZE, 0);
                        printf("> Uploading new filename: %s\n", buf);
                        // open new file
                        FILE *f;
                        f = fopen(buf, "w");
                        memset(buf, 0, MAXBUFFERSIZE);
                        recv(new_fd, buf, MAXBUFFERSIZE, 0);
                        fprintf(f, buf);
                        fclose(f);
                        printf("New file uploaded successfully.\n");
                        continue;
                    // ls
                    } else if (strcmp(buf, "ls") == 0) {
                        printf("> Client requested 'ls'\n");
                        continue;
                    // pwd
                    } else if (strcmp(buf, "pwd") == 0) {
                        printf("> Client requested 'pwd'\n");
                        continue;
                    // help
                    } else if (strcmp(buf, "help") == 0) {
                        printf("> Client requested 'help'\n");
                        continue;
                    // bye
                    } else if (strcmp(buf, "bye") == 0) {
                        printf("Disconnect from: %s\n", \
                            inet_ntoa(their_addr.sin_addr));
                        close(new_fd);
                        break;
                    // invalid entry
                    } else {
                        printf("> ** Invalid entry **\n");
                        continue;
                    }

                    // clear the buffer after each loop
                    memset(buf, 0, MAXBUFFERSIZE);

                } //menu while loop
            } //if fork
        } //if connection
    } //connection while loop

    // close server
    close(new_fd);
    return 0;

}
