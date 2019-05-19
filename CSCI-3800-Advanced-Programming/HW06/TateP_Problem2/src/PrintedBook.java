/*
    Patrick Tate
    CSCI 3800 HW6
 */

import java.util.ArrayList;

public class PrintedBook extends Book {

    private int totalPages;
    private String type; // paperback or hardcover

    // default constructor
    public PrintedBook(){
        this.totalPages = 0;
        this.type = "";
    }

    // custom constructor
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

    // overrides the toString from the base Book class
    @Override
    public String toString(){

        return "The book called '" + this.getTitle() + " published in " + this.getYearPub() + ". It is located at " + this.getLocationCode() + " and the authors are " + this.getAuthors();

    }

}
