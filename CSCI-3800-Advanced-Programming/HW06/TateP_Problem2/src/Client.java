/*
    Patrick Tate
    CSCI 3800 HW6 Problem 2
 */


import java.net.*;
import java.io.*;
import java.util.Scanner;


public class Client {

    private Socket socket = null;
    private BufferedReader serverInput = null;
    private DataOutputStream clientOutput = null;
    private String clientResponse = "";


    public Client(String address, int port) throws IOException, UnknownHostException{

        socket = new Socket(address, port);
        System.out.println("Connected");


        // takes input from terminal
        serverInput  = new BufferedReader(new InputStreamReader(socket.getInputStream()));
        // sends output to the socket
        clientOutput = new DataOutputStream(socket.getOutputStream());
        // string to read input from input
        String serverString = "";


        Scanner sc = new Scanner(System.in);

        clientResponse = serverInput.readLine();
        System.out.println(clientResponse);

        System.out.println("List: print all book titles; Get: obtain info about book by title; Disconnect: exit connection");
        System.out.println("If adding a book, type Add followed by comma separated values for [title],[year],[location],[Author (FirstName LastName]");
        System.out.println("Example below (note, only include one author):");
        System.out.println("*Add book example: Add,The Witcher,2013,Uk,Andrzej Sapkowski");
        System.out.println("*Get example: Get,Harry Potter");
        System.out.println("*List example: List");
        serverString = sc.nextLine();

        // sents to client line of commands as string
        clientOutput.writeUTF(serverString);

        // gets client response
        clientResponse = serverInput.readLine();
        System.out.println(clientResponse);
        serverString = sc.nextLine();

        System.out.println("Closing connection");
        serverInput.close();
        clientOutput.close();
        socket.close();


    }


    public static void main(String args[]) throws IOException, UnknownHostException {
        Client client = new Client("localhost", 5003);

    }

}
