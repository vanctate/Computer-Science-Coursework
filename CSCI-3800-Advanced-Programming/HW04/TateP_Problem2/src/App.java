/*
    - Patrick Tate
    - CSCI 3800 HW 4 Problem 2

 */


import java.util.*;
import java.util.ArrayList;

public class App {
    public static void main(String[] args){


        // variables for book1
        Publisher p1 = new Publisher("Wizards of the Coast");
        String title = "Dragons of Autumn Twilight";
        Author author1 = new Author("Margaret Weis");
        Author author2 = new Author("Tracy Hickman");
        HashSet<Author> book1Authors = new HashSet<Author>();
        book1Authors.add(author1);
        book1Authors.add(author2);
        Set<Author> asdf = new HashSet<Author>(book1Authors);
        System.out.println(asdf);

        // instantiate a PrintedBook object
        PrintedBook book1 = new PrintedBook(title, "Co", 1987, book1Authors,
                p1, 571, "paperback");

        // print book1
        System.out.println(book1);

        // add author test
        Author author3 = new Author("Larry Elmore");
        book1.addAuthor(author3);
        System.out.println(book1);

        // variables for book 2
        // book2 has same publisher and authors
        String title2 = "Dragons of Summer Flame";
        // book2
        PrintedBook book2 = new PrintedBook(title2, "Co", 1989, book1Authors,
                p1, 638, "paperback");
        System.out.println(book2);

        // check comparable
        // should print a 1 because book 2 has a larger publication year
        int result = book2.compareTo(book1);
        System.out.println(result);

        // test functionality of removeAuthor and findAuthor functions
        Author tester = new Author("asdf");
        book2.removerAuthor(tester);
        book2.findAuthor(author1);
        System.out.println();

    }
}
