# Patrick Tate
# CSCI 3800 HW03 | Problem 1

# Import Piece class because the grid has many pieces
# when a piece is inserted into the grid, the piece's position in the grid is marked by the piece color, B or W
from piece import Piece

# class to represent an Othello gameboard
# the Othello gameboard is 8x8, and contains open spaces for piece placement, and positions marked B/W by pieces
# the gameboard keeps track of valid positions on it for B/W pieces
class Grid:

    # initialize a 2-d array with 'O' for open spaces
    # set the black and white pieces in the center of the board
    def __init__(self):

        # grid size is always 8x8
        self.__rows = 8
        self.__columns = 8

        # initialize an 8x8 2-d array with 'O' for open spaces
        self.__gameBoard = [['O', 'O', 'O', 'O', 'O', 'O', 'O', 'O'], ['O', 'O', 'O', 'O', 'O', 'O', 'O', 'O'],
                            ['O', 'O', 'O', 'O', 'O', 'O', 'O', 'O'], ['O', 'O', 'O', 'O', 'O', 'O', 'O', 'O'],
                            ['O', 'O', 'O', 'O', 'O', 'O', 'O', 'O'], ['O', 'O', 'O', 'O', 'O', 'O', 'O', 'O'],
                            ['O', 'O', 'O', 'O', 'O', 'O', 'O', 'O'], ['O', 'O', 'O', 'O', 'O', 'O', 'O', 'O']]

        # set the B/W pieces in the middle of the board
        self.__gameBoard[3][3] = 'W'
        self.__gameBoard[4][4] = 'W'
        self.__gameBoard[3][4] = 'B'
        self.__gameBoard[4][3] = 'B'

        # keep track of how many pieces on the board of each color
        # a player's score will be set to either totalBlack or totalWhite
        self.__totalBlack = 2
        self.__totalWhite = 2

        # keep a list of valid positions for white
        self.__validWhitePositions = []

        # keep a list of valid positions for black
        self.__validBlackPositions = []

    def getValidWhitePositions(self):
        return self.__validWhitePositions

    # used to determine when no more moves
    def getValidWhiteSize(self):
        return len(self.__validWhitePositions)

    def getValidBlackPositions(self):
        return self.__validBlackPositions

    def getValidBlackSize(self):
        return len(self.__validBlackPositions)

    def findValidWhitePos(self):
        # reset valid positions
        self.__validWhitePositions.clear()

        row = 0
        column = 0

        for row in range(self.__rows):
            for column in range(self.__columns):

                if self.__gameBoard[row][column] == 'B':
                    # check up for white then check down for open space with black in between
                    if ((row - 1) >= 0) and (self.__gameBoard[row - 1][column] == 'W'):
                        nextRow = row + 1
                        if (nextRow <= 7) and (self.__gameBoard[nextRow][column] == 'O'):
                            self.__validWhitePositions.append((nextRow, column))
                        else:
                            while ((nextRow < 7) and (self.__gameBoard[nextRow][column]) == 'B'):
                                nextRow = nextRow + 1
                                if self.__gameBoard[nextRow][column] == 'O':
                                    self.__validWhitePositions.append((nextRow, column))

                    # check below for white and down
                    elif ((row + 1) <= 7) and (self.__gameBoard[row + 1][column] == 'W'):
                        nextRow = row - 1
                        if (nextRow >= 0) and  (self.__gameBoard[nextRow][column] == 'O'):
                            self.__validWhitePositions.append((nextRow, column))
                        else:
                            while((nextRow > 0) and (self.__gameBoard[nextRow][column] == 'B')):
                                nextRow = nextRow - 1
                                if self.__gameBoard[nextRow][column] == 'O':
                                    self.__validWhitePositions.append((nextRow, column))

                    if ((column -1) >= 0) and (self.__gameBoard[row][column - 1] == 'W'):
                        nextCol = column + 1
                        if (nextCol <= 7) and (self.__gameBoard[row][nextCol] == 'O'):
                            self.__validWhitePositions.append((row, nextCol))
                        else:
                            while (nextCol < 7) and (self.__gameBoard[row][nextCol] == 'B'):
                                nextCol = nextCol + 1
                                if self.__gameBoard[row][nextCol] == 'O':
                                    self.__validWhitePositions.append((row, nextCol))

                    elif ((column + 1) <= 7) and (self.__gameBoard[row][column + 1] == 'W'):
                        nextCol = column - 1
                        if (nextCol >= 0) and (self.__gameBoard[row][nextCol] == 'O'):
                            self.__validWhitePositions.append((row, nextCol))
                        else:
                            while (nextCol > 0) and (self.__gameBoard[row][nextCol] == 'B'):
                                nextCol = nextCol - 1
                                if self.__gameBoard[row][nextCol] == 'O':
                                    self.__validWhitePositions.append((row, nextCol))




    def findValidBlackPos(self):
        # reset valid positions
        self.__validBlackPositions.clear()

        row = 0
        column = 0

        for row in range(self.__rows):
            for column in range(self.__columns):

                if self.__gameBoard[row][column] == 'W':
                    # check up for white then check down for open space with black in between
                    if ((row - 1) >= 0) and (self.__gameBoard[row - 1][column] == 'B'):
                        nextRow = row + 1
                        if (nextRow <= 7) and (self.__gameBoard[nextRow][column] == 'O'):
                            self.__validBlackPositions.append((nextRow, column))
                        else:
                            while ((nextRow < 7) and (self.__gameBoard[nextRow][column]) == 'W'):
                                nextRow = nextRow + 1
                                if self.__gameBoard[nextRow][column] == 'O':
                                    self.__validBlackPositions.append((nextRow, column))

                    # check below for white and down
                    elif ((row + 1) <= 7) and (self.__gameBoard[row + 1][column] == 'B'):
                        nextRow = row - 1
                        if (nextRow >= 0) and  (self.__gameBoard[nextRow][column] == 'O'):
                            self.__validBlackPositions.append((nextRow, column))
                        else:
                            while((nextRow > 0) and (self.__gameBoard[nextRow][column] == 'W')):
                                nextRow = nextRow - 1
                                if self.__gameBoard[nextRow][column] == 'O':
                                    self.__validBlackPositions.append((nextRow, column))

                    if ((column -1) >= 0) and (self.__gameBoard[row][column - 1] == 'B'):
                        nextCol = column + 1
                        if (nextCol <= 7) and (self.__gameBoard[row][nextCol] == 'O'):
                            self.__validBlackPositions.append((row, nextCol))
                        else:
                            while (nextCol < 7) and (self.__gameBoard[row][nextCol] == 'W'):
                                nextCol = nextCol + 1
                                if self.__gameBoard[row][nextCol] == 'O':
                                    self.__validBlackPositions.append((row, nextCol))

                    elif ((column + 1) <= 7) and (self.__gameBoard[row][column + 1] == 'B'):
                        nextCol = column - 1
                        if (nextCol >= 0) and (self.__gameBoard[row][nextCol] == 'O'):
                            self.__validBlackPositions.append((row, nextCol))
                        else:
                            while (nextCol > 0) and (self.__gameBoard[row][nextCol] == 'W'):
                                nextCol = nextCol - 1
                                if self.__gameBoard[row][nextCol] == 'O':
                                    self.__validBlackPositions.append((row, nextCol))

    def getRows(self):
        return self.__rows

    def getColumns(self):
        return self.__columns

    # scans the board and increments totalBlack/totalWhite as necessary
    def calculatePieceCount(self):

        # reset totalBlack/totalWhite so totals are accurate
        self.__totalBlack = 0
        self.__totalWhite = 0

        # scan board for 'B' and 'W' pieces and increment self.__totalBlack and self.__totalWhite as necessary
        row = 0
        column = 0
        for row in range(self.__rows):
            for column in range(self.__columns):
                if self.__gameBoard[row][column] == 'B':
                    self.__totalBlack = self.__totalBlack + 1
                elif self.__gameBoard[row][column] == 'W':
                    self.__totalWhite = self.__totalWhite + 1

    # used to set a player's score
    def getTotalBlack(self):
        return self.__totalBlack

    # used to set a player's score
    def getTotalWhite(self):
        return self.__totalWhite

    # checks to the left of a potential piece placement to determine if the placement is valid
    # -1 returned if invalid, >= 0 returned if position is valid
    # used in conjunction with insertPiece function
    def checkLeft(self, piece):
        position = -1  # unless checks are met, flag value of -1 is returned

        # check list boundary
        if (piece.getColumn() - 1) < 0:
            return -1
        if self.__gameBoard[piece.getRow()][piece.getColumn()] == 'O':
            if self.__gameBoard[piece.getRow()][piece.getColumn() - 1] == piece.getOppositeColor():
                scanLeft = piece.getColumn() - 2
                while (scanLeft >= 0):
                    if self.__gameBoard[piece.getRow()][scanLeft] == piece.getColor():
                        position = scanLeft
                        break
                    else:
                        scanLeft = scanLeft - 1

        return position

    def checkRight(self, piece):
        position = -1  # unless checks are met, flag value of -1 is returned

        # check list boundary
        if (piece.getColumn() + 1) > 7:
            return -1
        if self.__gameBoard[piece.getRow()][piece.getColumn()] == 'O':
            if self.__gameBoard[piece.getRow()][piece.getColumn() + 1] == piece.getOppositeColor():
                scanRight = piece.getColumn() + 2
                while (scanRight <= 7):
                    if self.__gameBoard[piece.getRow()][scanRight] == piece.getColor():
                        position = scanRight
                        break
                    else:
                        scanRight = scanRight + 1

        return position

    def checkUp(self, piece):
        position = -1  # unless checks are met, flag value of -1 is returned

        # check list boundary
        if (piece.getRow() - 1) < 0:
            return -1
        if self.__gameBoard[piece.getRow()][piece.getColumn()] == 'O':
            if self.__gameBoard[piece.getRow() - 1][piece.getColumn()] == piece.getOppositeColor():
                scanUp = piece.getRow() - 2
                while (scanUp >= 0):
                    if self.__gameBoard[scanUp][piece.getColumn()] == piece.getColor():
                        position = scanUp
                        break
                    else:
                        scanUp = scanUp - 1

        return position

    def checkDown(self, piece):
        position = -1  # unless checks are met, flag value of -1 is returned

        # check list boundary
        if (piece.getRow() + 1) > 7:
            return -1
        if self.__gameBoard[piece.getRow()][piece.getColumn()] == 'O':
            if self.__gameBoard[piece.getRow() + 1][piece.getColumn()] == piece.getOppositeColor():
                scanDown = piece.getRow() + 2
                while (scanDown < 8):
                    if self.__gameBoard[scanDown][piece.getColumn()] == piece.getColor():
                        position = scanDown
                        break
                    else:
                        scanDown = scanDown + 1

        return position

    # function should return some value so a while loop can be used to stay here while position != valid
    # checks should return True, no valid checks should return False
    def insertPiece(self, piece):

        # one of checkLeft, checkRight, checkUp, checkDown must be >= 0 for a valid position
        leftFlag = self.checkLeft(piece)
        rightFlag = self.checkRight(piece)
        upFlag = self.checkUp(piece)
        downFlag = self.checkDown(piece)

        # boundary checking done w/ player input

        if leftFlag >= 0:
            # insert piece
            self.__gameBoard[piece.getRow()][piece.getColumn()] = piece.getColor()
            # flip pieces in between
            flip = piece.getColumn() - 1
            while (flip > leftFlag):
                self.__gameBoard[piece.getRow()][flip] = piece.getColor()
                flip = flip - 1


        if rightFlag >= 0:
            # insert piece
            self.__gameBoard[piece.getRow()][piece.getColumn()] = piece.getColor()
            # flip pieces in between
            flip = piece.getColumn() + 1
            while (flip < rightFlag):
                self.__gameBoard[piece.getRow()][flip] = piece.getColor()
                flip = flip + 1


        if upFlag >= 0:
            # insert piece
            self.__gameBoard[piece.getRow()][piece.getColumn()] = piece.getColor()
            # flip pieces in between
            flip = piece.getRow() - 1
            while (flip > upFlag):
                self.__gameBoard[flip][piece.getColumn()] = piece.getColor()
                flip = flip - 1


        if downFlag >= 0:
            # insert piece
            self.__gameBoard[piece.getRow()][piece.getColumn()] = piece.getColor()
            # flip pieces in between
            flip = piece.getRow() + 1
            while (flip < downFlag):
                self.__gameBoard[flip][piece.getColumn()] = piece.getColor()
                flip = flip + 1


        if (leftFlag < 0) and (rightFlag < 0) and (upFlag < 0) and (downFlag < 0):
            # use while loop to keep prompting user
            print()
            print("*** Error: Invalid Position ***")

    # print the 2-d array gameboard in a readable format for the users
    def printGameBoard(self):

        # variables for printing the grid in a user friendly format
        columnNums = ["          ", 1, 2, 3, 4, 5, 6, 7, 8]
        columnBarrier = '-'
        rowBarrier = '|'

        # print the column header and column numbers
        print("               Columns")
        for elem in columnNums:
            print(str(elem), end=" ")
        print()

        # print space for formatting
        print("           ", end="")

        # print the column barriers
        i = 0
        for i in range(self.__columns):
            print(columnBarrier, end=" ")
        print()

        # print the grid/2-d array element values
        j = 0  # row
        k = 0  # column
        for j in range(self.__rows):
            if j == 3:
                print("Rows    " + str(j + 1) + rowBarrier + " ", end="")
            else:
                print("        " + str(j + 1) + rowBarrier + " ", end="")
            for k in range(self.__columns):
                print(str(self.__gameBoard[j][k]), end=" ")
            print()

        # print space after printing the grid
        print()
        print()


