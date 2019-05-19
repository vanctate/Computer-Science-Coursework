/*
    - Patrick Tate
    - CSCI 3800 HW 4 Problem 3

 */

import java.util.ArrayList; // because each book has a list of author/s

/**
 * Represent books in our library
 */
public abstract class Book implements Comparable<Book> {

    private String title;
    private String locationCode;
    private int yearPub;

    // Part 1: enable an ArrayList of Authors so a book can have multiple authors
    private ArrayList<Author> authors;
    private Publisher publisher;

    // default constructor
    public Book() {
        this.title = "";
        this.locationCode = "";
        this.yearPub = 0;
        this.authors = new ArrayList<Author>();
    }

    public Book(String title, String location, int yearPub,
                ArrayList<Author> authorList, Publisher publisher) {

        this.title = title;
        this.locationCode = location;
        this.yearPub = yearPub;

        this.publisher = publisher;

        // hw 4 enhancement
        this.authors = new ArrayList<Author>(authorList);

    }


    // Comparable
    @Override
    public int compareTo(Book o) {
        //return yearPub.compareTo(o.getYearPub());
        if (this.yearPub == o.getYearPub()) {
            return 0;
        } else if (this.yearPub > o.getYearPub()) {
            return 1;
        } else {
            return -1;
        }
    }

    // add an author the the arrayList
    public void addAuthor(Author author) {
        this.authors.add(author);
    }

    // remover an author
    // true if author in the list, false and message if not
    public boolean removerAuthor(Author author) {
        if (this.authors.contains(author)) {
            this.authors.remove(author);
            return true;
        } else {
            System.out.println("This book does not have author: " + author.getName());
            return false;
        }
    }

    // searches for a matching author string name and delete author if found
    public void deleteAuthor(String name){
        for(int i = 0; i < this.authors.size(); i++){
            if(name.equals(authors.get(i).getName())){
                authors.remove(authors.get(i));
            }
        }
    }


    // search for an author
    public boolean findAuthor(Author author) {
        if (this.authors.contains(author)) {
            System.out.println(this.title + " has author " + author.getName());
            return true;
        } else {
            System.out.println(this.title + " does not have author " + author.getName());
            return false;
        }
    }

    // return author/authors
    public ArrayList<Author> getAuthors() {
        return this.authors;
    }

    public Boolean checkTitle(String title){
        return this.title == title;
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

    public String getTitle(){
        return this.title;
    }

    public void setTitle(String title) {
        this.title = title;
    }


    /**
     * The toString method converts an object to a string. It is used to display the object in a println call.
     * To be overridden in EBook and PrintedBook subclasses
     */
    public abstract String toString();

}
