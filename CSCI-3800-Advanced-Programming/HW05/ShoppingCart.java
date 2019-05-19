/*
    - Patrick Tate
    - CSCI 3800 HW 05
 */

public class ShoppingCart extends ItemList {

    private String id;

    public ShoppingCart(Item[] items){
        super(items);
        this.id = "SC123";
    }

    public String getID(){return this.id ;}


}