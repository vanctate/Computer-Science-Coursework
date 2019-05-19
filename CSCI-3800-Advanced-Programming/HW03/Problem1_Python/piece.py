# Patrick Tate
# CSCI 3800 HW03 | Problem 1

# class to represent a black or white piece to be inserted into an Othello gameboard
# piece has a color(B/w), and a row and column in array notation, to be used with the Grid class
class Piece:

    # subtract 1 from row and column for array notation
    def __init__(self, color, row, column):
        self.__color = color # char value 'B' or 'W'
        self.__row = row - 1
        self.__column = column - 1

    def setRow(self, row):
        self.__row = row

    def setColumn(self, column):
        self.__column = column

    def getRow(self):
        return self.__row

    def getColumn(self):
        return self.__column

    def getColor(self):
        return self.__color

    # used in the Grid class when a valid move flips the colors of the trapped pieces
    def getOppositeColor(self):
        if self.__color == 'B':
            return 'W'
        elif self.__color == 'W':
            return 'B'
        else:
            print("*** Error: Invalid color values ***")
            return 'E'

    # used in the Grid class when a valid move flips the colors of the trapped pieces
    def flipColor(self):
        if self.__color == 'B':
            self.__color = 'W'
        elif self.__color == 'W':
            self.__color = 'B'
        else:
            print("*** Error: Invalid color values ***")


