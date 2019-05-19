/*
    Patrick Tate
    CSCI 3800 HW6 Problem 1
 */


import java.net.*;
import java.io.*;
import java.util.Scanner;


public class Client {

    private Socket socket = null;
    private BufferedReader serverinput = null;
    private DataOutputStream output = null;
    private String serverPrompt = "";


    public Client(String address, int port) throws IOException, UnknownHostException{

        socket = new Socket(address, port);
        System.out.println("Connected");


        // takes input from terminal
        serverinput  = new BufferedReader(new InputStreamReader(socket.getInputStream()));
        // sends output to the socket
        output = new DataOutputStream(socket.getOutputStream());
        // string to read input from input
        String line = "";


        // obtain input and print prompts for client
        Scanner scan = new Scanner(System.in);
        serverPrompt = serverinput.readLine();
        System.out.println(serverPrompt);
        System.out.println("List: print all book titles; Get: obtain info about book by title; Disconnect: exit connection");
        System.out.println("If adding a book, type Add followed by comma separated values for [title],[year],[location],[Author (FirstName LastName]");
        System.out.println("Example below (note, only include one author):");
        System.out.println("*Add book example: Add,The Witcher,2013,Uk,Andrzej Sapkowski");
        System.out.println("*Get example: Get,Harry Potter");
        System.out.println("*List example: List");

        line = scan.nextLine();

        // sents to client line of commands as string
        output.writeUTF(line);

        // gets client response
        serverPrompt = serverinput.readLine();
        System.out.println(serverPrompt);

        System.out.println("Closing connection");
        serverinput.close();
        output.close();
        socket.close();


    }

    // run client and connect to the server
    public static void main(String args[]) throws IOException, UnknownHostException {
        Client client = new Client("localhost", 5002);

    }

}
