/*
    - Patrick Tate
    - CSCI 3800 HW 05
 */

public class BookDepartment extends Department {

    ItemList [] books = new ItemList[100];
    private String category;
    private int rating;
    private int totalBooks;

    // singleton
    protected BookDepartment(){
        try{
            if(_instance != null){
                throw new Exception("Cannot create another object");
            }
        }catch(Exception e){
            e.printStackTrace();
        }
    }

    public int getRating() {
        return this.rating;
    }

    public void setRating(int rating) {
        this.rating = rating;
    }

    public int getTotalBooks() {
        return this.totalBooks;
    }

    public void setBooks(ItemList[] books) {

        this.books = books;
    }

    public String getCategory() {

        return this.category;
    }

    public void setTotalBooks(int totalBooks) {

        this.totalBooks = totalBooks;
    }

    private static BookDepartment _instance = new BookDepartment();

    public static BookDepartment instance(){
        return _instance;
    }


}

