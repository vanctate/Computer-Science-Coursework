/*
    - Patrick Tate
    - CSCI 3800 HW03 | Problem 1
 */

// class to represent an Othello gameboard
// the gameboard consists of an 8x8 grid of char valued pieces either O for open, B for black, or W for white
// the gameboard keeps track of how many black/white pieces it contains
// the gameboard also keeps track of valid positions for potential black/white pieces to be placed

public class Grid {

    // Othello gameboard is 8x8
    private int ROWS;
    private int COLUMNS;
    private int totalBlack; // used to calculate black's score
    private int totalWhite; // used to calculate white's score
    private String validBlackPos; // valid positions for black placements
    private String validWhitePos; // valid positions for white placements
    private char gameBoard[][]; // 8x8 Othello gameboard

    public Grid(){
        this.ROWS = 8;
        this.COLUMNS = 8;
        this.totalBlack = 2;
        this.totalWhite = 2;
        // since black places a piece first, availableWhitePos doesn't need to be set until after black places first piece
        this.validBlackPos = "(2,3), (3,2), (5,4), (4,5)";
        this.validWhitePos = "";

        this.gameBoard = new char[this.ROWS][this.COLUMNS]; // Othello is 8x8 grid

        // initialize the Othello gameboard
        for(int row = 0; row < this.ROWS; row++){
            for(int col = 0; col < this.COLUMNS; col++){
                this.gameBoard[row][col] = 'O';
            }// for col
        }// for row

        this.gameBoard[3][3] = 'W';
        this.gameBoard[4][4] = 'W';
        this.gameBoard[3][4] = 'B';
        this.gameBoard[4][3] = 'B';
    }

    // getters
    public int getROWS(){
        return this.ROWS;
    }
    public int getCOLUMNS(){
        return this.COLUMNS;
    }
    public int getTotalBlack(){
        return this.totalBlack;
    }
    public int getTotalWhite(){
        return this.totalWhite;
    }
    public String getValidBlackPos(){
        return this.validBlackPos;
    }
    public String getValidWhitePos(){
        return this.validWhitePos;
    }

    public void findValidBlackPositions(){

        // reset validWhitePositions
        this.validBlackPos = "";

        for (int row = 0; row < this.ROWS; row++){

            for (int col = 0; col < this.COLUMNS; col++){

                if (this.gameBoard[row][col] == 'W') {

                    // check below for B, then check up for open w/ black in between
                    if (((row - 1) >= 0) && (this.gameBoard[row - 1][col] == 'B')){
                        int nextRow = row + 1;
                        if ((nextRow <= 7) && (this.gameBoard[nextRow][col]) == 'O'){
                            String validPos = "(" + nextRow + "," + col + ")";
                            this.validBlackPos = this.validBlackPos + validPos;
                        }
                        else {
                            while ((nextRow < 7) && (this.gameBoard[nextRow][col]) == 'W') {
                                nextRow++;
                                if (this.gameBoard[nextRow][col] == 'O'){
                                    String validPos = "(" + nextRow + "," + col + ")";
                                    this.validBlackPos = this.validBlackPos + validPos;
                                }// if
                            }// while
                        }// else
                    }// if

                    // check above for W, then below for open
                    else if (((row + 1) <= 7) && (this.gameBoard[row + 1][col] == 'B')){
                        int nextRow = row - 1;
                        if ((nextRow >= 0) && (this.gameBoard[nextRow][col] == 'O')){
                            String validPos = "(" + nextRow + "," + col + ")";
                            this.validBlackPos = this.validBlackPos + validPos;
                        }
                        else {
                            while ((nextRow > 0) && (this.gameBoard[nextRow][col] == 'W')){
                                nextRow--;
                                if (this.gameBoard[nextRow][col] == 'O'){
                                    String validPos = "(" + nextRow + "," + col + ")";
                                    this.validBlackPos = this.validBlackPos + validPos;
                                }// if
                            }// while
                        }//else
                    }// else if


                    if (((col - 1) >= 0) && (this.gameBoard[row][col - 1] == 'B')){
                        int nextCol = col + 1;
                        if ((nextCol <= 7) && (this.gameBoard[row][nextCol] == 'O')){
                            String validPos = "(" + row + "," + nextCol + ")";
                            this.validBlackPos = this.validBlackPos + validPos;
                        }// if
                        else{
                            while ((nextCol < 7) && (this.gameBoard[row][nextCol] == 'W')){
                                nextCol++;
                                if (this.gameBoard[row][nextCol] == 'O'){
                                    String validPos = "(" + row + "," + nextCol + ")";
                                    this.validBlackPos = this.validBlackPos + validPos;
                                }// if
                            }// while
                        }// else
                    }// if

                    else if (((col + 1) < 7) && (this.gameBoard[row][col + 1] == 'B')){
                        int nextCol = col - 1;
                        if ((nextCol >= 0) && (this.gameBoard[row][nextCol] == 'O')){
                            String validPos = "(" + row + "," + nextCol + ")";
                            this.validBlackPos = this.validBlackPos + validPos;
                        }// if
                        else{
                            while ((nextCol > 0) && (this.gameBoard[row][nextCol] == 'W')){
                                nextCol--;
                                if (this.gameBoard[row][nextCol] == 'O'){
                                    String validPos = "(" + row + "," + nextCol + ")";
                                    this.validBlackPos = this.validBlackPos + validPos;
                                }// if
                            }// while
                        }// else
                    }// else if

                }// if grid position == 'B'

            }// for columns
        }// for rows
    }

    public void findValidWhitePositions(){
        // reset validWhitePositions
        this.validWhitePos = "";

        for (int row = 0; row < this.ROWS; row++){

            for (int col = 0; col < this.COLUMNS; col++){

                if (this.gameBoard[row][col] == 'B') {

                    // check below for W, then check up for open w/ black in between
                    if (((row - 1) >= 0) && (this.gameBoard[row - 1][col] == 'W')){
                        int nextRow = row + 1;
                        if ((nextRow <= 7) && (this.gameBoard[nextRow][col]) == 'O'){
                            String validPos = "(" + nextRow + "," + col + ")";
                            this.validWhitePos = this.validWhitePos + validPos;
                        }
                        else {
                            while ((nextRow < 7) && (this.gameBoard[nextRow][col]) == 'B') {
                                nextRow++;
                                if (this.gameBoard[nextRow][col] == 'O'){
                                    String validPos = "(" + nextRow + "," + col + ")";
                                    this.validWhitePos = this.validWhitePos + validPos;
                                }// if
                            }// while
                        }// else
                    }// if

                    // check above for W, then below for open
                    else if (((row + 1) <= 7) && (this.gameBoard[row + 1][col] == 'W')){
                        int nextRow = row - 1;
                        if ((nextRow >= 0) && (this.gameBoard[nextRow][col] == 'O')){
                            String validPos = "(" + nextRow + "," + col + ")";
                            this.validWhitePos = this.validWhitePos + validPos;
                        }
                        else {
                            while ((nextRow > 0) && (this.gameBoard[nextRow][col] == 'B')){
                                nextRow--;
                                if (this.gameBoard[nextRow][col] == 'O'){
                                    String validPos = "(" + nextRow + "," + col + ")";
                                    this.validWhitePos = this.validWhitePos + validPos;
                                }// if
                            }// while
                        }//else
                    }// else if


                    if (((col - 1) >= 0) && (this.gameBoard[row][col - 1] == 'W')){
                        int nextCol = col + 1;
                        if ((nextCol <= 7) && (this.gameBoard[row][nextCol] == 'O')){
                            String validPos = "(" + row + "," + nextCol + ")";
                            this.validWhitePos = this.validWhitePos + validPos;
                        }// if
                        else{
                            while ((nextCol < 7) && (this.gameBoard[row][nextCol] == 'B')){
                                nextCol++;
                                if (this.gameBoard[row][nextCol] == 'O'){
                                    String validPos = "(" + row + "," + nextCol + ")";
                                    this.validWhitePos = this.validWhitePos + validPos;
                                }// if
                            }// while
                        }// else
                    }// if

                    else if (((col + 1) < 7) && (this.gameBoard[row][col + 1] == 'W')){
                        int nextCol = col - 1;
                        if ((nextCol >= 0) && (this.gameBoard[row][nextCol] == 'O')){
                            String validPos = "(" + row + "," + nextCol + ")";
                            this.validWhitePos = this.validWhitePos + validPos;
                        }// if
                        else{
                            while ((nextCol > 0) && (this.gameBoard[row][nextCol] == 'B')){
                                nextCol--;
                                if (this.gameBoard[row][nextCol] == 'O'){
                                    String validPos = "(" + row + "," + nextCol + ")";
                                    this.validWhitePos = this.validWhitePos + validPos;
                                }// if
                            }// while
                        }// else
                    }// else if

                }// if grid position == 'B'

            }// for columns
        }// for rows
    }

    public void calcPieceCount(){
        this.totalBlack = 0;
        this.totalWhite = 0;

        for(int i = 0; i < 8; i++){
            for(int j = 0; j < 8; j++){
                if (this.gameBoard[i][j] == 'B'){
                    this.totalBlack++;
                }
                else if (this.gameBoard[i][j] == 'W'){
                    this.totalWhite++;
                }
            }// j
        }// i
    }


    public int checkLeft(Piece piece){
        int position = -1;

        if ((piece.getColumn() - 1) < 0){
            return position;
        }
        else{
            if ((this.gameBoard[piece.getRow()][piece.getColumn()] == 'O')){
                if (this.gameBoard[piece.getRow()][piece.getColumn() - 1] == piece.getOppositeColor()){
                    int scanLeft = piece.getColumn() - 2;
                    while(scanLeft >= 0){
                        if (this.gameBoard[piece.getRow()][scanLeft] == piece.getColor()){
                            position = scanLeft;
                            break;
                        }
                        else{
                            scanLeft--;
                        }
                    }
                }
            }
        }
        return position;
    }

    public int checkRight(Piece piece){
        int position = -1;

        if ((piece.getColumn() + 1) > 0){
            return position;
        }
        else{
            if ((this.gameBoard[piece.getRow()][piece.getColumn()] == 'O')){
                if (this.gameBoard[piece.getRow()][piece.getColumn() + 1] == piece.getOppositeColor()){
                    int scanRight = piece.getColumn() + 2;
                    while(scanRight <= 7){
                        if (this.gameBoard[piece.getRow()][scanRight] == piece.getColor()){
                            position = scanRight;
                            break;
                        }
                        else{
                            scanRight--;
                        }
                    }
                }
            }
        }
        return position;

    }

    public int checkUp(Piece piece){
        int position = -1;

        if ((piece.getRow() - 1) < 0){
            return position;
        }
        else{
            if ((this.gameBoard[piece.getRow()][piece.getColumn()] == 'O')){
                if (this.gameBoard[piece.getRow() - 1][piece.getColumn()] == piece.getOppositeColor()){
                    int scanUp = piece.getColumn() - 2;
                    while(scanUp >= 0){
                        if (this.gameBoard[scanUp][piece.getColumn()] == piece.getColor()){
                            position = scanUp;
                            break;
                        }
                        else{
                            scanUp--;
                        }
                    }
                }
            }
        }
        return position;
    }

    public int checkDown(Piece piece){
        int position = -1;

        if ((piece.getRow() + 1) > 7){
            return position;
        }
        else{
            if ((this.gameBoard[piece.getRow()][piece.getColumn()] == 'O')){
                if (this.gameBoard[piece.getRow() + 1][piece.getColumn()] == piece.getOppositeColor()){
                    int scanDown = piece.getColumn() + 2;
                    while(scanDown < 8){
                        if (this.gameBoard[scanDown][piece.getColumn()] == piece.getColor()){
                            position = scanDown;
                            break;
                        }
                        else{
                            scanDown--;
                        }
                    }
                }
            }
        }
        return position;
    }

    public void insertPiece(Piece piece){
        int leftFlag = this.checkLeft(piece);
        int rightFlag = this.checkRight(piece);
        int upFlag = this.checkUp(piece);
        int downFlag = this.checkDown(piece);

        if (leftFlag >= 0){
            this.gameBoard[piece.getRow()][piece.getColumn()] = piece.getColor();
            int flip = piece.getColumn() - 1;
            while(flip > leftFlag){
                this.gameBoard[piece.getRow()][flip] = piece.getColor();
                flip--;
            }
        }

        if (rightFlag >= 0){
            this.gameBoard[piece.getRow()][piece.getColumn()] = piece.getColor();
            int flip = piece.getColumn() + 1;
            while(flip < rightFlag){
                this.gameBoard[piece.getRow()][flip] = piece.getColor();
                flip++;
            }
        }

        if (upFlag >= 0){
            this.gameBoard[piece.getRow()][piece.getColumn()] = piece.getColor();
            int flip = piece.getRow() - 1;
            while(flip > upFlag){
                this.gameBoard[flip][piece.getColumn()] = piece.getColor();
                flip--;
            }
        }

        if (downFlag >= 0){
            this.gameBoard[piece.getRow()][piece.getColumn()] = piece.getColor();
            int flip = piece.getRow() + 1;
            while(flip < downFlag){
                this.gameBoard[flip][piece.getColumn()] = piece.getColor();
                flip++;
            }
        }

        if ((leftFlag < 0) && (rightFlag < 0) && (upFlag < 0) && (downFlag < 0)){
            System.out.println("*** Invalid Position Attempted ***");
        }


    }

    public void printGameBoard(){
        for(int i = 0; i < 8; i++){
            for(int j = 0; j < 8; j++){
                System.out.print(this.gameBoard[i][j]);
            }
            System.out.println();
        }
    }

}
