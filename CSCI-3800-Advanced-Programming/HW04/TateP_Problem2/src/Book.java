/*
    - Patrick Tate
    - CSCI 3800 HW 4 Problem 2

 */


import java.util.ArrayList;
import java.util.HashSet;
import java.util.Iterator;
import java.util.Set;

/**
 * Represent books in our library
 */
public abstract class Book implements Comparable<Book> {


    private String title;
    private String locationCode;
    private int yearPub;

    // Part 2: enable a set of Authors so a book can have multiple authors
    private HashSet<Author> authors;
    private Publisher publisher;

    /**
     * Initializes the book
     * @param title book's title
     * @param location book's location in the library. it's usually a code like G70.212.R54
     * @param yearPub year of publication
     * @param author author object.
     * @param publisher publisher object.
     */

    // default constructor
    public Book(){
        this.title = "";
        this.locationCode = "";
        this.yearPub = 0;
        this.authors = new HashSet<Author>();
    }

    public Book ( String title, String location, int yearPub,
                  HashSet<Author> authorList, Publisher publisher){

        this.title =title;
        this.locationCode = location;
        this.yearPub = yearPub;

        this.publisher = publisher;

        // hw 4 enhancement
        this.authors = new HashSet<Author>(authorList);

    }


    // Comparable
    @Override
    public int compareTo(Book o){

        if (this.yearPub == o.getYearPub()){
            return 0;
        }
        else if(this.yearPub > o.getYearPub()){
            return 1;
        }
        else{
            return -1;
        }
    }


    // return author/authors
    public String getAuthors(){
        // cycle through the authro list and print each
        String authorList = "";
        Author lastAuthor = new Author("tempName");
        // find last author in the set
        Iterator<Author> last = this.authors.iterator();
        while(last.hasNext()){
            lastAuthor = last.next();
        }
        for(Author a : this.authors){
            if(a == lastAuthor){
                authorList = authorList + a;
            }
            else{
                authorList = authorList + a + ", ";
            }
        }
        return authorList;
    }

    // remover an author
    // true if author in the list, false and message if not
    public boolean removerAuthor(Author author){
        if (this.authors.contains(author)){
            this.authors.remove(author);
            return true;
        }
        else{
            System.out.println(this.title + " does not have author: " + author.getName());
            return false;
        }
    }

    // search for an author
    public boolean findAuthor(Author author){
        if (this.authors.contains(author)){
            System.out.println(this.title + " has author " + author.getName());
            return true;
        }
        else {
            System.out.println(this.title + " does not have author " + author.getName());
            return false;
        }
    }

    public Publisher getPublisher() {
        return publisher;
    }

    public int getYearPub() {
        return yearPub;
    }

    public void setYearPub(int yearPub) {
        this.yearPub = yearPub;
    }

    public String getLocationCode() {
        return locationCode;
    }

    public void setLocationCode(String locationCode) {
        this.locationCode = locationCode;
    }

    public String getTitle() {
        return title;
    }

    public void setTitle(String title) {
        this.title = title;
    }

    public void addAuthor(Author author){
        this.authors.add(author);
    }

    /**
     * The toString method converts an object to a string. It is used to display the object in a println call.
     * To be overridden by PrintedBook subclass
     */
    public abstract String toString();
}
