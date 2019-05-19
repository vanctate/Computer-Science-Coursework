/*
    Patrick Tate
    CSCI 3800 HW6
 */

import java.io.Serializable;

public class Publisher implements Serializable {
    private String name;

    public Publisher(String name){
        this.name = name;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    /**
     * The toString method converts an object to a string. It is used to display the object in a println call.
     * @return
     */
    public String toString(){
        return name;
    }
}
