// Patrick Tate
// CSCI 3761 Lab 2
// simple client program with menu of options


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>

#define MAXBUFFSIZE 1024 // max byte transfer
#define PORT 46000 // port number for client

int main(int argc, char *argv[])
{
    // socket variables
    int sockfd, numbytes;
    char buf[MAXBUFFSIZE]; // to hold send/receive data
    char newFile[MAXBUFFSIZE];
    struct hostent *he;
    struct sockaddr_in their_addr;
    int saved_stdout;

    printf("***********\n");
    printf("Client side\n");
    printf("***********\n");

    if (argc != 2) {
        fprintf(stderr,"usage: client hostname\n");
        exit(1);
    }
    if ((he=gethostbyname(argv[1])) == NULL) {
        herror("gethostbyname");
        exit(1);
    }
    printf("Getting server info... \n");
    if ((sockfd = socket(PF_INET, SOCK_STREAM, 0)) == -1) {   // get the socket file
        perror("socket");
        exit(1);
    }
    printf("Creating socket\n");
    their_addr.sin_family = AF_INET;    // host byte order
    their_addr.sin_port = htons(PORT);  // short, network byte order
    their_addr.sin_addr = *((struct in_addr *)he->h_addr); // store server ip addess (from the
                                                           // gethostbyname function)
    memset(their_addr.sin_zero, '\0', sizeof their_addr.sin_zero);
    if (connect(sockfd, (struct sockaddr *)&their_addr,     // connect to server
                sizeof their_addr) == -1) {
        perror("connect");
        exit(1);
    }
    printf("Connecting to the server\n"); //connected to server

    while(1){
        // initial menu
        printf("\nFor menu options enter: 'help'\n");
        printf("> ");

        // store input in buffer and send to server
        scanf("%s", &buf[0]);
        send(sockfd, buf, MAXBUFFSIZE, 0);

        // compare menu options
        // catalog
        if (strcmp(buf, "catalog") == 0) {
            memset(buf, 0, MAXBUFFSIZE);
            if(recv(sockfd, buf, sizeof(buf), 0) < 0){
                printf("\nError!! Cannot recieve data.\n");
            }else{
                printf("%s", buf);
            }
            continue;
        }
        // ls
        else if (strcmp(buf, "ls") == 0) {
            system("ls");
            continue;
        }
        // pwd
        else if (strcmp(buf, "pwd") == 0) {
            system("pwd");
            continue;
        }
        // spwd server
        else if (strcmp(buf, "spwd") == 0) {
            memset(buf, 0, MAXBUFFSIZE);
            if(recv(sockfd, buf, sizeof(buf), 0) < 0){
                printf("\nError!! Cannot recieve data.\n");
            }else{
                printf("%s", buf);
            }
            continue;
        }
        // download
        else if (strcmp(buf, "download") == 0) {
            memset(buf, 0, MAXBUFFSIZE);
            printf("\nEnter filename you want to download:\n");
            printf("> ");
            scanf("%s", &buf[0]);
            // check for valid filename
            send(sockfd, buf, MAXBUFFSIZE, 0);
            recv(sockfd, buf, MAXBUFFSIZE, 0);

            if (strcmp(buf, "fail") == 0) {
                printf("Filename not found in server directory.\n");
            } else {
                printf("\nEnter filename for the destination file:\n");
                FILE *fp;
                // create the file on client side
                fp = fopen(newFile, "w");
                memset(buf, 0, MAXBUFFSIZE);
                recv(sockfd, buf, MAXBUFFSIZE, 0);
                fprintf(fp, buf);
                fclose(fp);
                printf("File downloaded.\n");
            }
            continue;
        // upload
        } else if (strcmp(buf, "upload") == 0) {
            printf("\nEnter upload filename:\n");
            printf("> ");
            scanf("%s", &buf[0]);
            FILE *f;
            f = fopen(buf, "r");

            // if not found print message
            if (f == NULL) {
                printf("Can't find file in client.\n");
            // else upload file
            } else {
                printf("\nEnter upload destination filename:\n");
                printf("> ");
                scanf("%s", &newFile[0]);
                send(sockfd, newFile, MAXBUFFSIZE, 0);
                fseek(f, 0, SEEK_END);
                rewind(f);
                memset(buf, 0, MAXBUFFSIZE);
                fread(buf, sizeof(char), sizeof(buf), f);
                send(sockfd, buf, MAXBUFFSIZE, 0);
                fclose(f);
                printf("File upload complete.\n");
            }
            continue;
        } else if (strcmp(buf, "help") == 0) { // help
            printf("\nMenu options:\n");
            printf("****************\n");
            printf("catalog - show files in the server’s directory\n");
            printf("ls - show files in the client's directory\n");
            printf("download [source-filename] [dest-filename] - download files\n");
            printf("upload [source-filename] [dest-filename] - upload files\n");
            printf("pwd - display client current directory\n");
            printf("spwd - display server current directory\n");
            printf("bye - disconnect from server\n");
            continue;
        } else if(strcmp(buf, "bye") == 0){ // bye
            printf("\nDisconnected from server.\n");
            close(sockfd);
            exit(1);
        } else { //check for invalid commands
            printf("\nInvalid command\n");
            continue;
        }
        memset(buf, 0, MAXBUFFSIZE); //clear buffer
        printf("\n");
    }
    return 0;
}
