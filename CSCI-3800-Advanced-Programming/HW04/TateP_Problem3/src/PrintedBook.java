/*
    - Patrick Tate
    - CSCI 3800 HW 4 Problem 3

 */

import java.util.ArrayList; // because each book has a list of author/s

public class PrintedBook extends Book {

    private int totalPages;
    private String type; // paperback or hardcover

    // default constructor
    public PrintedBook(){
        this.totalPages = 0;
        this.type = "";
    }

    // constructor
    public PrintedBook(String title, String location, int yearPub,
                       ArrayList<Author> authorList, Publisher publisher,
                       int pages, String type){
        super(title, location, yearPub, authorList, publisher);

        this.totalPages = pages;
        this.type = type;

    }

    // getters
    public int getTotalPages(){
        return this.totalPages;
    }
    public String getType(){
        return this.type;
    }

    // setters
    public void setTotalPages(int pages){
        this.totalPages = pages;
    }
    public void setType(String type){
        this.type = type;
    }

    @Override
    public String toString(){

        return "Title: '" + this.getTitle() + ".'" + " Author/s: " + this.getAuthors() + "\n" +
                "Total Pages: " + this.totalPages + "." + " Type: " + this.type + "\n" +
                "Publisher: " + this.getPublisher() + "." + " Publication Year: " + this.getYearPub() + "\n";
    }

}
