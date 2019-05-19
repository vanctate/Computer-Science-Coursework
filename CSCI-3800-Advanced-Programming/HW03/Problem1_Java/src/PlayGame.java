/*
    - Patrick Tate
    - CSCI 3800 HW03 | Problem 1
 */

import java.util.Scanner;

// runs a simple game of Othello
// user plays as both black and white players
// game runs until one player cannot place a valid piece, then the player with the most pieces wins

public class PlayGame {

    public static void main(String[] args){

        Grid othelloBoard = new Grid();
        othelloBoard.findValidBlackPositions();
        othelloBoard.findValidWhitePositions();

        Player player1Black = new Player('B');
        player1Black.setAvailablePositions(othelloBoard.getValidBlackPos());
        player1Black.setScore(othelloBoard.getTotalBlack());

        Player player2White = new Player('W');
        player2White.setAvailablePositions(othelloBoard.getValidWhitePos());
        player2White.setScore(othelloBoard.getTotalWhite());

        System.out.println("*** Welcome To Othello ***");
        System.out.println();
        othelloBoard.printGameBoard();
        System.out.println();
        System.out.println("Black Score: " + player1Black.getScore());
        System.out.println("White Score: " + player2White.getScore());
        System.out.println();
        System.out.println("Black goes first.");
        System.out.println();

        while((!player1Black.isLoser()) && (!player2White.isLoser())){

            System.out.println("Valid positions for black are listed below.");
            System.out.println("Positions are in (row,pair) combos and in array notation, so add 1 to each.");
            player1Black.printAvilablePositions();

            System.out.println("Enter a row 1-8 for your black piece.");
            Scanner input = new Scanner(System.in);
            int blackRow = input.nextInt();
            blackRow = player1Black.checkPositionBoundary(blackRow, othelloBoard, "row");

            System.out.println("Enter a column 1-8 for your black piece.");
            int blackCol = input.nextInt();
            blackCol = player1Black.checkPositionBoundary(blackCol, othelloBoard, "column");

            othelloBoard.findValidBlackPositions();
            player1Black.setAvailablePositions(othelloBoard.getValidBlackPos());
            int blackRowString = blackRow - 1;
            int blackColString = blackCol - 1;

            String blackInsert = "(" + blackRowString + "," + blackColString + ")";
            String validBlack = player1Black.getAvailablePositions();
            while (!validBlack.contains(blackInsert)){

                if(player1Black.isLoser()){
                    if(player1Black.getScore() < player2White.getScore()){
                        System.out.println("Black wins. White loses.");
                    }
                    else{
                        System.out.println("White wins. Black loses.");
                    }
                }
                else if (player2White.isLoser()){
                    if(player1Black.getScore() < player2White.getScore()){
                        System.out.println("Black wins. White loses.");
                    }
                    else{
                        System.out.println("White wins. Black loses.");
                    }
                }
                else {
                    System.out.println("* Invalid Position. Re-enter row and column *");
                    System.out.println("Enter a row 1-8 for your black piece.");
                    input = new Scanner(System.in);
                    blackRow = input.nextInt();
                    blackRow = player1Black.checkPositionBoundary(blackRow, othelloBoard, "row");

                    System.out.println("Enter a column 1-8 for your black piece.");
                    blackCol = input.nextInt();
                    blackCol = player1Black.checkPositionBoundary(blackCol, othelloBoard, "column");

                    blackRowString = blackRow - 1;
                    blackColString = blackCol - 1;

                    blackInsert = "(" + blackRowString + "," + blackColString + ")";
                    //validBlack = player1Black.getAvailablePositions();
                }
            }// while
            Piece blackPiece = new Piece(player1Black.getColor(), ++blackRowString, ++blackColString);
            othelloBoard.insertPiece(blackPiece);

            othelloBoard.calcPieceCount();
            othelloBoard.findValidBlackPositions();
            othelloBoard.findValidWhitePositions();
            player1Black.setAvailablePositions(othelloBoard.getValidBlackPos());
            player2White.setAvailablePositions(othelloBoard.getValidWhitePos());
            player1Black.setScore(othelloBoard.getTotalBlack());
            player2White.setScore(othelloBoard.getTotalWhite());
            System.out.println();
            othelloBoard.printGameBoard();
            System.out.println("Black Score: " + player1Black.getScore());
            System.out.println("White Score: " + player2White.getScore());
            System.out.println();


            // whites turn
            System.out.println("Valid positions for white are listed below.");
            System.out.println("Positions are in (row,pair) combos and in array notation, so add 1 to each.");
            player2White.printAvilablePositions();

            System.out.println("Enter a row 1-8 for your white piece.");
            input = new Scanner(System.in);
            int whiteRow = input.nextInt();
            whiteRow = player2White.checkPositionBoundary(whiteRow, othelloBoard, "row");

            System.out.println("Enter a column 1-8 for your white piece.");
            int whiteCol = input.nextInt();
            whiteCol = player2White.checkPositionBoundary(whiteCol, othelloBoard, "column");

            othelloBoard.findValidWhitePositions();
            player2White.setAvailablePositions(othelloBoard.getValidWhitePos());
            int whiteRowString = whiteRow - 1;
            int whiteColString = whiteCol - 1;

            String whiteInsert = "(" + whiteRowString + "," + whiteColString + ")";
            String validWhite = player2White.getAvailablePositions();
            while (!validWhite.contains(whiteInsert)){

                if(player1Black.isLoser()){
                    if(player1Black.getScore() < player2White.getScore()){
                        System.out.println("Black wins. White loses.");
                    }
                    else{
                        System.out.println("White wins. Black loses.");
                    }
                }
                else if (player2White.isLoser()){
                    if(player1Black.getScore() < player2White.getScore()){
                        System.out.println("Black wins. White loses.");
                    }
                    else{
                        System.out.println("White wins. Black loses.");
                    }
                }
                else {
                    System.out.println("* Invalid Position. Re-enter row and column *");
                    System.out.println("Enter a row 1-8 for your white piece.");
                    input = new Scanner(System.in);
                    input.nextInt();
                    whiteRow = player2White.checkPositionBoundary(whiteRow, othelloBoard, "row");

                    System.out.println("Enter a column 1-8 for your white piece.");
                    whiteCol = input.nextInt();
                    whiteCol = player2White.checkPositionBoundary(whiteCol, othelloBoard, "column");

                    whiteRowString = whiteRow - 1;
                    whiteColString = whiteCol - 1;

                    whiteInsert = "(" + whiteRowString + "," + whiteColString + ")";

                }
            }// while

            Piece whitePiece = new Piece(player2White.getColor(), ++whiteRowString, ++whiteColString);
            othelloBoard.insertPiece(whitePiece);

            othelloBoard.calcPieceCount();
            othelloBoard.findValidBlackPositions();
            othelloBoard.findValidWhitePositions();
            player1Black.setAvailablePositions(othelloBoard.getValidBlackPos());
            player2White.setAvailablePositions(othelloBoard.getValidWhitePos());
            player1Black.setScore(othelloBoard.getTotalBlack());
            player2White.setScore(othelloBoard.getTotalWhite());
            System.out.println();
            othelloBoard.printGameBoard();
            System.out.println("Black Score: " + player1Black.getScore());
            System.out.println("White Score: " + player2White.getScore());
            System.out.println();



        }// while game not over
    }
}
