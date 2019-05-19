/*
    - Patrick Tate
    - CSCI 3800 HW03 | Problem 1
 */

import java.util.Scanner;

// class to simulate a player
// a player has a color(B or W), a score, and a string of available positions

public class Player {

    private char color;
    private int score;
    private String availablePositions;

    public Player(char color){
        this.color = color;
        this.score = 0;
        this.availablePositions = "";
    }

    // getters
    public char getColor(){
        return this.color;
    }
    public int getScore(){
        return this.score;
    }
    public String getAvailablePositions(){
        return this.availablePositions;
    }

    // setters
    public void setScore(int score){
        this.score = score;
    }
    public void setAvailablePositions(String availablePositions){
        this.availablePositions = availablePositions;
    }

    public void printAvilablePositions(){
        System.out.println(this.availablePositions);
    }

    public Boolean isLoser(){
        return this.availablePositions.length() == 0;
    }

    public int checkPositionBoundary(int position, Grid othelloBoard, String rowOrColumn){

        while ((position <= 0) || (position > othelloBoard.getCOLUMNS())){
            System.out.println("*** Invalid Entry: enter an int value 1-8 for the " + rowOrColumn);
            System.out.println("Enter a value 1-8 for the " + rowOrColumn);
            Scanner input = new Scanner(System.in);
            int newPosition = input.nextInt();
            position = newPosition;
        }// while

        return position;
    }


}
