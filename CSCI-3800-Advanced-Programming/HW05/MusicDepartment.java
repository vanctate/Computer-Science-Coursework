/*
    - Patrick Tate
    - CSCI 3800 HW 05
 */

public class MusicDepartment extends Department{

    String id = "Music123";



    private static MusicDepartment _instance = new MusicDepartment();

    public static MusicDepartment instance(){
        return _instance;
    }

    protected MusicDepartment(){
        try{
            if(_instance != null){
                throw new Exception("Cannot create another object");
            }
        }catch(Exception e){
            e.printStackTrace();
        }
    }
}
