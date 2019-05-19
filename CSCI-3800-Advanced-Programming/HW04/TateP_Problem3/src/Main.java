/*
    - Patrick Tate
    - CSCI 3800 HW 4 Problem 3

 */

import java.util.ArrayList;
import java.util.HashMap;

/*
    This is the driver to demonstrate the functionality of the App object menu. The App object is instantiated with
    2 PrintedBook objects and 1 EBook object, a hashMap of authors, and an arrayList of books. The user has the option
    in the menu of 1) adding a book to the library, 2) adding an author to the library, 3) remove a book from the library,
    4) remove an author from the library, 5) remove an author from a specific book, 6) add an author to a specific book,
    7) print the books in the library, 8) print the authors in the library, and 9) exit the program.

    When the user removes a book from the library, I did not automatically remove that book's authors from the library
    because those authors might have other books in the library, removing the author of a book the user removed is left
    up to the uesr.

    However, when a user adds a book to the library, that book's author/s are added to the library's hashMap of authors.


 */

public class Main {
    public static void main(String[] args){


        // variables for book1
        Publisher p1 = new Publisher("Wizards of the Coast");
        String title = "Dragons of Autumn Twilight";
        Author author1 = new Author("Margaret Weis");
        Author author2 = new Author("Tracy Hickman");
        ArrayList<Author> book1Authors = new ArrayList<Author>();
        book1Authors.add(author1);
        book1Authors.add(author2);

        // book =1
        PrintedBook book1 = new PrintedBook(title, "Co", 1987, book1Authors,
                p1, 571, "paperback");


        Author author3 = new Author("Larry Elmore");
        book1.addAuthor(author3);
        //System.out.println(book1);

        // variables for book 2
        // book2 has same publisher and authors
        String title2 = "Dragons of Summer Flame";
        // book2
        PrintedBook book2 = new PrintedBook(title2, "Co", 1989, book1Authors,
                p1, 638, "paperback");

        // variables for eBook1
        Author eAuthor1 = new Author("Kensy Carner");
        Author eAuthor2 = new Author("Spike Spiegel");
        ArrayList<Author> eBook1Authors = new ArrayList<>();
        eBook1Authors.add(eAuthor1);
        eBook1Authors.add(eAuthor2);
        Publisher ePub = new Publisher("Funimation");
        String eTitle = "Cowboy Bebop";
        double eSize = 1.89;
        // eBook1
        EBook eBook1 = new EBook(eTitle, "Tokyo", 2003, eBook1Authors, ePub, eSize);
        //System.out.println(eBook1);

        // App object testing
        ArrayList<Book> libraryBooks = new ArrayList<Book>();
        libraryBooks.add(book1);
        libraryBooks.add(book2);
        libraryBooks.add(eBook1);

        // create a hashmap of authors for the App object
        HashMap<String, Author> libAuthors = new HashMap<>();
        libAuthors.put(eAuthor1.getName(), eAuthor1);
        libAuthors.put(eAuthor2.getName(), eAuthor2);
        libAuthors.put(author1.getName(), author1);
        libAuthors.put(author2.getName(), author2);
        libAuthors.put(author3.getName(), author3);

        // instantiate an App object and run the menu
        App library = new App(libraryBooks, libAuthors);
        library.menu();



    }
}
