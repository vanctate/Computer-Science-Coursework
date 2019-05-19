/*
    - Patrick Tate
    - CSCI 3800 HW03 | Problem 1
 */

// class to represent a piece on the Othello board
// a piece has a color, row, and a column

public class Piece {
    private char color; // black 'B' or white 'W'
    private int row;
    private int column;

    public Piece(char color, int row, int column){
        this.color = color;
        this.row = row - 1;
        this.column = column - 1;
    }

    // getters
    public char getColor(){
        return this.color;
    }
    public int getRow(){
        return this.row;
    }
    public int getColumn(){
        return this.column;
    }

    public char getOppositeColor(){
        if (this.color == 'B'){
            return 'W';
        }
        else if (this.color == 'W'){
            return 'B';
        }
        else{
            System.out.println("*** Error: Wrong piece color entered, program exiting ***");
            System.exit(0);
            return 'E';
        }
    }

    public void flipColor(){
        if (this.color == 'B'){
            this.color = 'W';
        }
        else if (this.color == 'W'){
            this.color = 'B';
        }
        else {
            System.out.println("*** Error: Wrong piece color entered, program exiting ***");
            System.exit(0);
        }
    }
}
