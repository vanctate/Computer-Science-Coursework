/*
    - Patrick Tate
    - CSCI 3800 HW 4 Problem 3

 */

import java.util.ArrayList; // because each book has a list of author/s

public class EBook extends Book {

    private double size; // size in MB

    // default constructor
    public EBook(){
        this.size = 0.0;
    }

    public EBook(String title, String location, int yearPub,
                 ArrayList<Author> authorList, Publisher publisher,
                 double size){
        // call base class Book constructor
        super(title, location, yearPub, authorList, publisher);
        this.size = size;
    }

    public double getSize(){
        return this.size;
    }
    public void setSize(double size){
        this.size = size;
    }

    @Override
    public String toString(){

        return "Title: '" + this.getTitle() + ".'" + " Author/s: " + this.getAuthors() + "\n" +
                "Publisher " + this.getPublisher().getName() + ". Publication year: " + this.getYearPub() + "." + "\n" +
                "E-book Size: " + this.size + " MB.";
    }

}
