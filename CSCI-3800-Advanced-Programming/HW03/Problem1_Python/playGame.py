# Patrick Tate
# CSCI 3800 HW03 | Problem 1

# playGame simulates a simple game of Othello
# the game ends when either player has no more valid moves
# the player with the highest score wins

from grid import Grid # to represent the Othello gameboard
from piece import Piece # so pieces can be inserted into the Othello gameboard
from player import Player # one player places black pieces, the other player places white pieces

# initialize the Othello gameboard and positions
othelloBoard = Grid()
othelloBoard.findValidBlackPos()
othelloBoard.findValidWhitePos()

# initialize the player placing black pieces
player1Black = Player('B')
player1Black.setAvailablePositions(othelloBoard.getValidBlackPositions())
player1Black.setScore(othelloBoard.getTotalBlack())

# initialize the player placing white pieces
player2White = Player('W')
player2White.setAvailablePositions(othelloBoard.getValidWhitePositions())
player2White.setScore(othelloBoard.getTotalWhite())

# print initial greeting, initial Othello gameboard, and initial scores for Black/White
print("*** Welcome to Othello ***")
print()
othelloBoard.printGameBoard()
print("Black Score: " + str(player1Black.getScore()))
print("White Score: " + str(player2White.getScore()))
print()
print("Black goes first.")
print()

# run game until someone loses
while ((not player1Black.isLoser()) and (not player2White.isLoser())):

    # ******* Start Black's Turn ***************************************************************************
    print("* Valid positions for black listed below, positions are (row, column) pairs and in array notation, so add 1 to both row and column * ")
    player1Black.printAvailablePositions()
    blackRow = int(input("Enter a row 1-8 for your black piece:"))
    # ensure position is within valid grid boundaries
    blackRow = player1Black.checkPositionBoundary(blackRow, othelloBoard, 'row')

    blackCol = int(input("Enter a column 1-8 for you black piece:"))
    # ensure position is within valid grid boundaries
    blackCol = player1Black.checkPositionBoundary(blackCol, othelloBoard, 'column')

    othelloBoard.findValidBlackPos()
    player1Black.setAvailablePositions(othelloBoard.getValidBlackPositions())
    blackInsert = (blackRow - 1, blackCol - 1)

    # ensure row/column is a valid position on the board
    while blackInsert not in othelloBoard.getValidBlackPositions():
        # check if either player won
        if player1Black.isLoser():
            if player1Black.getScore() > player2White:
                print("Black wins! White loses")
            else:
                print("White wins! Black loses")
        elif player2White.isLoser():
            if player1Black.getScore() > player2White:
                print("Black wins! White loses")
            else:
                print("White wins! Black loses")

        else:
            print("* Invalid Position. Re-enter row and column * ")
            blackRow = int(input("Enter a row 1-8 for your black piece:"))
            # ensure position is within valid grid boundaries
            blackRow = player1Black.checkPositionBoundary(blackRow, othelloBoard, 'row')

            blackCol = int(input("Enter a column 1-8 for you black piece:"))
            # ensure position is within valid grid boundaries
            blackCol = player1Black.checkPositionBoundary(blackCol, othelloBoard, 'column')

        blackInsert = (blackRow - 1, blackCol - 1)

    # once position is valid, insert into the Othello board
    blackPiece = Piece(player1Black.getColor(), blackRow, blackCol)
    othelloBoard.insertPiece(blackPiece)

    # re-calculate score and valid positions for both black/white
    othelloBoard.calculatePieceCount()
    othelloBoard.findValidBlackPos()
    othelloBoard.findValidWhitePos()
    player1Black.setAvailablePositions(othelloBoard.getValidBlackPositions())
    player2White.setAvailablePositions(othelloBoard.getValidWhitePositions())
    player1Black.setScore(othelloBoard.getTotalBlack())
    player2White.setScore(othelloBoard.getTotalWhite())
    print()
    othelloBoard.printGameBoard()
    print("Black Score: " + str(player1Black.getScore()))
    print("White Score: " + str(player2White.getScore()))
    print()
    # *********** End Black's Turn ***************************************************************************

    # *********** Start White's Turn *************************************************************************
    print("* Valid positions for white listed below, positions are (row, column) pairs and in array notation, so add 1 to both row and column * ")
    player2White.printAvailablePositions()
    whiteRow = int(input("Enter a row 1-8 for your white piece:"))
    whiteRow = player2White.checkPositionBoundary(whiteRow, othelloBoard, 'row')

    whiteCol = int(input("Enter a column 1-8 for you white piece:"))
    whiteCol = player2White.checkPositionBoundary(whiteCol, othelloBoard, 'column')

    othelloBoard.findValidWhitePos()
    player2White.setAvailablePositions(othelloBoard.getValidWhitePositions())
    whiteInsert = (whiteRow - 1, whiteCol - 1)

    # ensure row/column is a valid position on the board
    while whiteInsert not in othelloBoard.getValidWhitePositions():

        # check if either player won
        if player1Black.isLoser():
            if player1Black.getScore() > player2White:
                print("Black wins! White loses")
            else:
                print("White wins! Black loses")
        elif player2White.isLoser():
            if player1Black.getScore() > player2White:
                print("Black wins! White loses")
            else:
                print("White wins! Black loses")

        print("* Invalid Position. Re-enter row and column * ")
        whiteRow = int(input("Enter a row 1-8 for your white piece:"))
        whiteRow = player2White.checkPositionBoundary(whiteRow, othelloBoard, 'row')

        whiteCol = int(input("Enter a column 1-8 for you white piece:"))
        whiteCol = player2White.checkPositionBoundary(whiteCol, othelloBoard, 'column')

        whiteInsert = (whiteRow - 1, whiteCol - 1)

    # once position is valid, insert into the Othello board
    whitePiece = Piece(player2White.getColor(), whiteRow, whiteCol)
    othelloBoard.insertPiece(whitePiece)

    # re-calculate score and valid positions for both black/white
    othelloBoard.calculatePieceCount()
    othelloBoard.findValidBlackPos()
    othelloBoard.findValidWhitePos()
    player1Black.setAvailablePositions(othelloBoard.getValidBlackPositions())
    player2White.setAvailablePositions(othelloBoard.getValidWhitePositions())
    player1Black.setScore(othelloBoard.getTotalBlack())
    player2White.setScore(othelloBoard.getTotalWhite())
    print()
    othelloBoard.printGameBoard()
    print("Black Score: " + str(player1Black.getScore()))
    print("White Score: " + str(player2White.getScore()))
    print()

    # check if either player won
    if player1Black.isLoser():
        if player1Black.getScore() > player2White:
            print("Black wins! White loses")
        else:
            print("White wins! Black loses")
    elif player2White.isLoser():
        if player1Black.getScore() > player2White:
            print("Black wins! White loses")
        else:
            print("White wins! Black loses")


