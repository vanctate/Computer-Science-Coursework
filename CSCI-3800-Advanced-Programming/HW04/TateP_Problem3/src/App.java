/*
    - Patrick Tate
    - CSCI 3800 HW 4 Problem 3

 */

import java.io.IOException; // to ensure proper input from the user
import java.util.ArrayList; // App has a list of books
import java.util.HashMap;   // App has a map of authors
import java.util.InputMismatchException; // ensure proper input from the user
import java.util.Scanner;   // obtain input from the user

/*
    App class to model our library on. An App object has a list of books(PrintedBooks and EBoos), and a hashMap of
    authors where the key is the author's name, and the value is the Author object.

    App class has a menu function which implements the requirements for problem 4, as well as the necessary functions
    to work within the menu.

 */

public class App {

    private ArrayList<Book> bookList;
    private HashMap<String, Author> authors;

    public App(){
        this.bookList = new ArrayList<Book>();
        this.authors = new HashMap<String, Author>();
    }

    public App(ArrayList<Book> bookList, HashMap<String, Author> authorList){
        this.bookList = new ArrayList<Book>(bookList);
        this.authors = new HashMap<String, Author>(authorList);

    }

    // getters
    public ArrayList<Book> getBookList() {
        return this.bookList;
    }
    public HashMap<String, Author> getAuthors(){
        return this.authors;
    }

    // setters
    public void setBookList(ArrayList<Book> bookList){
        this.bookList = bookList;
    }
    public void setAuthors(HashMap<String, Author> authorList){
        this.authors = authorList;
    }

    // returns a String of book titles for easy printing
    public String getBooks(){
        String bookList = "";
        for(Book book : this.bookList){
            if (this.bookList.size() == 1){
                bookList = book.getTitle() + ".";
            }
            else if(book == this.bookList.get(this.bookList.size() - 1)){
                bookList = bookList + book.getTitle() + ".";
            }
            else {
                bookList = bookList + book.getTitle() + ", ";
            }
        }
        return bookList;
    }

    public void printBooks(){
        for(Book b : this.bookList){
            System.out.println(b);
            System.out.println();
        }
    }

    public void printAuthors(){
       for(String authorName : this.authors.keySet()){
           System.out.println(authorName);
       }
    }

    // menu for use to add/remove books and authors
    public void menu(){
        int choice = 0;

        while (choice != 9){
            System.out.println("Enter a number corresponding to the action you wish to perform.");
            System.out.println();
            System.out.println("Enter 1 to add a book to the library.");
            System.out.println("Enter 2 to add an author to the library.");
            System.out.println("Enter 3 to remove a book from the library.");
            System.out.println("Enter 4 to remove an author from the library.");
            System.out.println("Enter 5 remove an author from a specific book.");
            System.out.println("Enter 6 to add an author to a specific book.");
            System.out.println("Enter 7 to print the books in the library.");
            System.out.println("Enter 8 to print the authors in the library.");
            System.out.println("Enter 9 quit the program.");

            Scanner input = new Scanner(System.in);
            try {
                choice = input.nextInt();
            }
            catch(InputMismatchException e){
                System.err.println("*** Incorrect type entered, try again ***");

            }

            switch (choice)
            {
                // add a book to the App, PrintedBook or EBook
                case 1:{
                    System.out.println("Enter the name of the type of book you want to add.");
                    System.out.println("Enter 1 for printed book, 2 for e-book");
                    int bookChoice = 0;
                    try {
                        bookChoice = input.nextInt();
                    }
                    catch (InputMismatchException e){
                        System.err.println("*** Incorrect type entered, try again ***");
                    }
                    if(bookChoice == 1){
                        PrintedBook b = this.getPrintedBookInfo();
                        this.addBook(b);
                        // add the authors to the library map of authors
                        for(Author a : b.getAuthors()){
                            this.authors.put(a.getName(), a);
                        }
                    }
                    else if(bookChoice == 2){
                        EBook eB = this.getEBookInfo();
                        this.addBook(eB);
                        // add the authors to the library map of authors
                        for(Author a : eB.getAuthors()){
                            this.authors.put(a.getName(), a);
                        }
                    }
                    break;
                }
                // add an author to the App's map of authors
                case 2:{
                    Author a = this.getAuthorInfo();
                    this.addAuthor(a);
                    break;
                }
                // remove book from App's list of books
                case 3:{
                    System.out.println("Enter the book title you wish to remove.");
                    Scanner inputB = new Scanner(System.in);
                    String title = inputB.nextLine();
                    this.removeBook(title);
                    break;
                }

                // remove author from library map
                case 4:{
                    System.out.println("Enter the author you wish to remove.");
                    Scanner inputA = new Scanner(System.in);
                    String aName = inputA.nextLine();
                    this.removeAuthor(aName);
                    break;
                }

                // remove author from specific book
                case 5:{
                    System.out.println("Enter the book whose author you wish to remove.");
                    Scanner input5 = new Scanner(System.in);
                    String bTitle = input5.nextLine();
                    System.out.println("Enter the author's name you wish to remove.");
                    String name = input5.nextLine();
                    this.removeAuthorFromBook(bTitle, name);

                    break;
                }

                // add author to specific book
                case 6:{
                    System.out.println("Enter the book that you want to add an author to.");
                    Scanner input6 = new Scanner(System.in);
                    String title = input6.nextLine();
                    System.out.println("Enter the author's name you want to add");
                    String name = input6.nextLine();
                    Author ab = new Author(name);
                    this.addAuthorToBook(title, ab);
                    break;
                }

                // print books in the library
                case 7:{
                    System.out.println();
                    System.out.println("Current library books listed below:");
                    this.printBooks();
                    System.out.println();
                    break;
                }

                // print authors in the library
                case 8:{
                    System.out.println();
                    System.out.println("Current library authors listed below:");
                    this.printAuthors();
                    System.out.println();
                    break;
                }

                case 9:{
                    System.exit(0);
                    break;
                }

                default:{
                    System.out.println("*** Invalid entry: Enter an int 1-9 ***");
                }

            }// switch



        }// while user still wants to intereact with menu
    }// menu function

    // obtain variables from user for a PrintedBook and returns a PrintedBook object with those values
    public PrintedBook getPrintedBookInfo(){
        Scanner input = new Scanner(System.in);
        System.out.println("Enter the name of the book");
        String title = input.nextLine();

        System.out.println("Enter the location code.");
        Scanner input2 = new Scanner(System.in);
        String location = input2.next();

        System.out.println("Enter the publication year.");
        Scanner input3 = new Scanner(System.in);
        int yearPub = 0;
        try{
            yearPub = input3.nextInt();
        }
        catch(InputMismatchException e){
            System.err.println("Incorrect value entered, publication year set to 0.");
        }

        System.out.println("Enter an author(you can add more later).");
        Scanner input4 = new Scanner(System.in);
        String author = input4.nextLine();
        Author bookAuthor = new Author(author);
        ArrayList<Author> bAuthors = new ArrayList<>();
        bAuthors.add(bookAuthor);

        System.out.println("Enter the publisher name.");
        Scanner input5 = new Scanner(System.in);
        String pub = input5.next();
        Publisher pub1 = new Publisher(pub);

        System.out.println("Enter how many pages.");
        Scanner input6 = new Scanner(System.in);
        int pages = 0;
        try{
            pages = input6.nextInt();
        }
        catch(InputMismatchException e){
            System.err.println("Incorrect value entered, pages set to 0.");
        }

        System.out.println("Enter the type(hardcover or paperback).");
        Scanner input7 = new Scanner(System.in);
        String type = input7.next();

        PrintedBook addBook = new PrintedBook(title, location, yearPub, bAuthors, pub1, pages, type);
        return addBook;
    }

    // obtain variables from user for an EBook and returns a PrintedBook object with those values
    public EBook getEBookInfo(){
        Scanner input = new Scanner(System.in);
        System.out.println("Enter the name of the book");
        String title = input.nextLine();

        System.out.println("Enter the location code.");
        Scanner input2 = new Scanner(System.in);
        String location = input2.next();

        System.out.println("Enter the publication year.");
        Scanner input3 = new Scanner(System.in);
        int yearPub = 0;
        try{
            yearPub = input3.nextInt();
        }
        catch(InputMismatchException e){
            System.err.println("Incorrect value entered, publication year set to 0.");
        }

        System.out.println("Enter an author(you can add more later).");
        Scanner input4 = new Scanner(System.in);
        String author = input4.nextLine();
        Author bookAuthor = new Author(author);
        ArrayList<Author> bAuthors = new ArrayList<>();
        bAuthors.add(bookAuthor);

        System.out.println("Enter the publisher name.");
        Scanner input5 = new Scanner(System.in);
        String pub = input5.next();
        Publisher pub1 = new Publisher(pub);

        System.out.println("Enter the e-book size in MB.");
        Scanner input6 = new Scanner(System.in);
        double size = 0.0;
        try{
            size = input6.nextDouble();
        }
        catch (InputMismatchException e){
            System.err.println("Incorrect type entered, size set to 0.0");
        }

        EBook addBook = new EBook(title, location, yearPub, bAuthors, pub1, size);
        return addBook;

    }

    // add book method accepts PrintedBook and EBook objects
    public <T extends Book> void addBook(T book){
        this.bookList.add(book);
    }

    // get the author's name from the user a return an Author object with that name
    public Author getAuthorInfo(){
        Scanner input = new Scanner(System.in);
        System.out.println("Enter the author's name.");
        String name = input.nextLine();
        Author a = new Author(name);

        return a;
    }

    // add an author to the hashMap of authors
    public void addAuthor(Author a){
        this.authors.put(a.getName(), a);
    }


    // searches for a matchin book title and if found, removes it from the App's list of books
    public void removeBook(String title){
        // iterate through bookList and compare title, if found remove
        for(int i = 0; i < bookList.size(); i ++){
            if(title.equals(bookList.get(i).getTitle())){
                bookList.remove(bookList.get(i));
                System.out.println(title + " removed from list");
            }
        }
    }

    // removes an author from the hashMap of the App's authors
    public void removeAuthor(String name){
        if(authors.containsKey(name)){
            authors.remove(name);
        }
    }

    // searches for a matching book title and if found, removes the author's name from that book's list of authors
    public void removeAuthorFromBook(String title, String name){
        for(int i = 0; i < bookList.size(); i ++){
            if(title.equals(bookList.get(i).getTitle())){
                bookList.get(i).deleteAuthor(name);
                authors.remove(name);

            }
        }
    }

    // searches for a matching book title and if found, adds an author to that book's list of authors
    public void addAuthorToBook(String title, Author a){
        for(int i = 0; i < bookList.size(); i++){
            if(title.equals(bookList.get(i).getTitle())){
                bookList.get(i).addAuthor(a);
                authors.put(a.getName(), a);
            }
        }
    }

}
