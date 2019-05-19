/*
    - Patrick Tate
    - CSCI 3800 HW 05
 */

public class SoftwareDepartment extends Department {

    private String type;
    private int rating;
    private String brand;
    Item [] software = new Item[100];
    public String getCreator() {
        return brand;
    }

    public void setRating(int rating) {
        this.rating = rating;
    }

    public String getType() {
        return type;
    }

    public void setBrand(String creator) {
        this.brand = brand;
    }

    public int getRating() {
        return rating;
    }

    public void setType(String softType) {
        this.type = softType;
    }


    private static SoftwareDepartment _instance = new SoftwareDepartment();

    public static SoftwareDepartment instance(){
        return _instance;
    }

    protected SoftwareDepartment(){
        try{
            if(_instance != null){
                throw new Exception("Cannot create another object");
            }
        }catch(Exception e){
            e.printStackTrace();
        }
    }
}


