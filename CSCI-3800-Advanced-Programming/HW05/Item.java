/*
    - Patrick Tate
    - CSCI 3800 HW 05
 */

public class Item {

    private String name;
    private long itemID;
    private double price;
    private long departmentID;
    private boolean onSale;

    public Item(){
        this.name = "";
        this.itemID = 0;
        this.price = 0.0;
        this.departmentID = 0;
        this.onSale = false;
    }

    // **********************
    // getters
    public String getName() {
        return name;
    }
    public double getPrice() {
        return price;
    }
    public long getItemID() {
        return itemID;
    }
    public long getDepartmentID() {
        return departmentID;
    }
    public boolean getOnSale(){
        return this.onSale;
    }

    // ***************************
    // setters
    public void setName(String name) {
        this.name = name;
    }
    public void setItemID(long itemID) {
        this.itemID = itemID;
    }
    public void setPrice(double price) {
        if(price < this.price)
            this.setOnSale(true);
        this.price = price;
    }
    public void setDepartmentID(long departmentID) {
        this.departmentID = departmentID;
    }
    public void setOnSale(boolean a ){
        this.onSale = a;
    }
    public boolean itemAdded(){
        return this.onSale;
    }
}

