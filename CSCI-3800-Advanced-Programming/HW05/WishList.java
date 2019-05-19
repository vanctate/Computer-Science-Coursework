/*
    - Patrick Tate
    - CSCI 3800 HW 05
 */

public class WishList extends ItemList {

    private String id;

    public WishList(Item[] items){
        super(items);
        this.id = "WL123";
    }

    public String getID(){return this.id ;}

}
