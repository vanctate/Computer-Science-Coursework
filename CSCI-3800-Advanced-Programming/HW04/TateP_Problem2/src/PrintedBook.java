/*
    - Patrick Tate
    - CSCI 3800 HW 4 Problem 2

 */

import java.util.ArrayList;
import java.util.HashSet;
import java.util.*;

public class PrintedBook extends Book {

    private int totalPages;
    private String type; // paperback or hardcover

    // default constructor
    public PrintedBook(){
        this.totalPages = 0;
        this.type = "";
    }

    public PrintedBook(String title, String location, int yearPub,
                       HashSet<Author> authorList, Publisher publisher,
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

    // overrides toString from base Book class
    @Override
    public String toString(){

        return "Title: '" + this.getTitle() + ".'" + " Authors: " + this.getAuthors() + "\n" +
                "Total Pages: " + this.totalPages + "." + " Type: " + this.type + "\n" +
                "Publisher: " + this.getPublisher() + "." + " Publication Year: " + this.getYearPub() + "\n";
    }

}
