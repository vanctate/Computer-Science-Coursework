/*
    Patrick Tate
    CSCI 3800 HW6 Problem 2
 */

import java.net.*;
import java.io.*;
import java.util.ArrayList;
import java.util.*;


/*
    Server class loads an array list of Book objects from a ser file. If there ser file does not load for some reason,
    uncomment the writing to ser file section and run.
 */
public class Server {

    private Socket socket = null;
    private ServerSocket server = null;
    private ArrayList<Author> authors = new ArrayList<>();// keep track of authors
    private ArrayList<Book> currentBooks = new ArrayList<>();// holds the serialized list of books


    public Server(int port) throws IOException{

        // list of books to be serialized in ser file
        ArrayList<Book> initialBookList = new ArrayList<>();

        // ser file to hold serialized arraylist of books
        File aFile = new File("books.ser");


        // variables for book1
        Publisher p1 = new Publisher("Wizards of the Coast");
        String title1 = "Dragons of Autumn Twilight";
        Author author1 = new Author("Margaret Weis");
        this.authors.add(author1);
        Author author2 = new Author("Tracy Hickman");
        this.authors.add(author2);
        ArrayList<Author> book1Authorsb = new ArrayList<>();
        book1Authorsb.add(author1);
        book1Authorsb.add(author2);
        // instantiate a PrintedBook object
        PrintedBook book1 = new PrintedBook(title1, "Co", 1987, book1Authorsb,
                p1, 571, "paperback");

        // variables for book2
        Publisher p2 = new Publisher("Bantam");
        String title2 = "Harry Potter";
        Author author3 = new Author("JK Rowling");
        this.authors.add(author3);
        ArrayList<Author> book2Authors = new ArrayList<>();
        book2Authors.add(author3);
        PrintedBook book2 = new PrintedBook(title2, "UK", 2003, book2Authors,
                p2, 314, "paperback");

        // variables for book3
        Publisher p3 = new Publisher("Orbit");
        String title3 = "The Wheel of Time";
        Author author4 = new Author("Robert Jordan");
        this.authors.add(author4);
        Author author5 = new Author("Spike Spiegel");
        this.authors.add(author5);
        ArrayList<Author> book3Authors = new ArrayList<>();
        book3Authors.add(author4);
        book3Authors.add(author5);
        PrintedBook book3 = new PrintedBook(title3, "Ca", 2001, book3Authors,
                p3, 541, "hard cover");


        // add 3 books to book list
        initialBookList.add(book1);
        initialBookList.add(book2);
        initialBookList.add(book3);


        // IF SER FILE DOES NOT LOAD, UNCOMMENT THIS SECTION
        // *******************  WRITING  *************
        //System.out.println("Serializing Book array list:\n"+book1);
        // write ser file
        /*
        ObjectOutputStream oos;
        try {
            //Opening Stream to save objects to file.
            oos = new ObjectOutputStream( new FileOutputStream(aFile) );

            oos.writeObject( initialBookList ); // write the object
            oos.close(); //After writing the object the output stream must be closed.
        }
        catch (NullPointerException e){ e.printStackTrace();}
        System.out.println("Object Saved to File: "+ aFile.getAbsolutePath());
        */

        // read in ser file as an array list of book objects
        try {
            FileInputStream fileIn = new FileInputStream("books.ser");
            ObjectInputStream in = new ObjectInputStream(fileIn);

            this.currentBooks = (ArrayList<Book>) in.readObject();
            System.out.println("Current books read in from file:");
            for(Book b : this.currentBooks){
                System.out.println(b.getTitle());
            }
            System.out.println();
        }
        catch (IOException i){
            i.printStackTrace();
        }
        catch (ClassNotFoundException c){
            System.out.println("Class not found");

        }


        server = new ServerSocket(port);
        System.out.println("Server Started");
        System.out.println("Waiting for client...");

        while(true) {

            try{
                Socket socket = server.accept();
                System.out.println("Client Connected");

                new ServerThread(socket).start();

            }catch(Exception e){
                e.printStackTrace();
                System.out.println("Connection Error");
            }



        }

    }


    // multi thread server to handle multiple clients
    class ServerThread extends Thread{
        private Socket socket;
        public ServerThread(Socket socket) throws IOException{
            this.socket = socket;
        }

        public void run(){

            DataInputStream inputFile = null;
            PrintWriter output = null;

            try {
                inputFile = new DataInputStream(new BufferedInputStream(socket.getInputStream()));
                output = new PrintWriter(socket.getOutputStream(), true);
                String prompt = "Enter a command(Add, List, Get)";
                // read input text from client
                output.println(prompt);

                String line = inputFile.readUTF();
                String[] userEntry = line.split(",");

                // check for the correct amount of parameters when adding
                if((userEntry.length != 5) && (userEntry[0].equals("Add"))){
                    output.println("Error: Some data is incorrect");
                    System.out.println("Closing Connection");
                    socket.close();
                    inputFile.close();

                }

                if (!userEntry[0].equals("Disconnect")) {

                    String clientCommand = userEntry[0];
                    clientCommand = clientCommand.toLowerCase();
                    String title;
                    switch (clientCommand) {

                        // parses response from user for the book to add
                        // author must exist in the authors array list for the book to be added to currentBooks array list
                        case "add":

                            // convert string year to int
                            String yr = userEntry[2];
                            int year = Integer.parseInt(yr);

                            // search for if the author exists
                            // if author exists, set boolean to true and add author to new array list
                            boolean authorFound = false;
                            ArrayList<Author> clientAuthors = new ArrayList<>();
                            for(Author a : authors){
                                if(a.getName().equals(userEntry[4])){
                                    authorFound = true;
                                    clientAuthors.add(a);
                                    break;
                                }
                            }

                            // if author is found, add the book with client information
                            if(authorFound){
                                Publisher temp = new Publisher("temp");
                                PrintedBook clientBook = new PrintedBook(userEntry[1], userEntry[3], year,clientAuthors,
                                        temp,399, "hard cover");
                                currentBooks.add(clientBook);
                                output.println("OK: Done.");
                            }
                            else{
                                output.println("ERR: some data is incorrect.");
                            }

                            // display current books and close server
                            System.out.println("Current books on server:");
                            System.out.println(currentBooks);
                            System.out.println("Closing Connection");
                            socket.close();
                            inputFile.close();

                            break;

                        // print the book titles in book list
                        case "list":

                            // loop through current books and add each title to the bookString
                            String bookString = "Current books: ";
                            for(Book b : currentBooks){
                                bookString = bookString + b.getTitle() + ", ";
                            }
                            output.println(bookString);
                            System.out.println("Closing Connection");
                            socket.close();
                            inputFile.close();
                            break;

                        // lists the book's info if found
                        case "get":

                            boolean found = false;
                            for(Book b : currentBooks){
                                if(b.getTitle().equals(userEntry[1])) {
                                    String bookInfo = "OK: The book is called ";
                                    bookInfo = bookInfo + b.getTitle() + ", published in " + b.getYearPub();
                                    bookInfo = bookInfo + ". It is located at " + b.getLocationCode();
                                    bookInfo = bookInfo + ". And the author/s are: " + b.getAuthors();
                                    output.println(bookInfo);
                                    break;
                                }

                            }
                            // if book not found, print message and exit server
                            if(!found){
                                output.println("ERR: No book with that title");
                                System.out.println("Closing Connection");
                                socket.close();
                                inputFile.close();
                            }
                            break;

                        // incorrect data entered from user
                        default:
                            output.println("ERR: Wrong payload");
                            System.out.println("Closing Connection");
                            socket.close();
                            inputFile.close();
                            break;

                    }
                } else {

                    System.out.println("Closing Connection");
                    socket.close();
                    inputFile.close();

                }

                //serialize books
                try {
                    FileOutputStream fileOut = new FileOutputStream("books.ser");
                    ObjectOutputStream out = new ObjectOutputStream(fileOut);
                    out.writeObject(currentBooks);


                } catch (IOException i) {
                    i.printStackTrace();
                }
            }catch(IOException i){
                i.printStackTrace();
            }
        }
    }

    public static void main (String[] args) throws IOException{

        Server server = new Server(5003);

    }


}
