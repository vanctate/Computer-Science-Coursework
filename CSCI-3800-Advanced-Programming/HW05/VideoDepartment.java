/*
    - Patrick Tate
    - CSCI 3800 HW 05
 */

public class VideoDepartment extends Department {
    private Item [] videoGames= new Item[100];
    private String name;
    private int gameID;
    private int videoGamePrice;
    private String videoGName;

    protected VideoDepartment(){
        try{
            if(_instance != null){
                throw new Exception("Cannot create another object");
            }
        }catch(Exception e){
            e.printStackTrace();
        }
    }

    public int getGameID() {
        return gameID;
    }

    public int getVideoGamePrice() {
        return videoGamePrice;
    }
    public String getName(){
        return name;
    }

    public void setVideoGamePrice(int videoGamePrice) {
        this.videoGamePrice = videoGamePrice;
    }

    public void setName(String videoGName) {
        this.name = videoGName;
    }

    public void setGameID(int gameID) {
        this.gameID = gameID;
    }

    private static VideoDepartment _instance = new VideoDepartment();

    public static VideoDepartment instance(){
        return _instance;
    }


}
