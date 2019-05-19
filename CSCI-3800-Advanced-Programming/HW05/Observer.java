/*
    - Patrick Tate
    - CSCI 3800 HW 05
 */

public class Observer extends Customer{

    String message = "wow";
    boolean isNotified = false;

    public void update(Item i){

        System.out.println("New item is on sale: " );
        System.out.println(i);
        setIsNotified(true);
    }
    public boolean getIsNotified(){
        return isNotified;
    }
    public void setIsNotified (boolean a){
        isNotified = a;
    }

    public String toString() {
        return super.toString() + " says 'WOW!!!'";
    }
}
