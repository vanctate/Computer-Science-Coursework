# Patrick Tate
# CSCI 3800 HW03 | Problem 1

from grid import Grid # for checking piece placement boundaries


# class used to represent an Othello player, who will control either black or white pieces
# each Player object has a color(black/white), a score, and a list of available positions they can place
# the game ends when a player has no available positions, and whoever has the highest score wins
class Player:

    def __init__(self, color):
        self.__color = color
        self.__score = 0
        self.__availablePositions = []

    def getColor(self):
        return self.__color

    def setScore(self, score):
        self.__score = score

    def getScore(self):
        return self.__score

    def setAvailablePositions(self, availablePositions):
        self.__availablePositions = availablePositions

    def getAvailablePositions(self):
        return self.__availablePositions

    def printAvailablePositions(self):
        print(str(self.__availablePositions))

    def getAvailablePositionSize(self):
        return len(self.__availablePositions)

    def isLoser(self):
        return len(self.__availablePositions) == 0

    # ensures the row and column the player wants to insert a piece at is within the gameboard's boundary
    def checkPositionBoundary(self, position, othelloBoard, rowOrColumn):

        # check to ensure row/column is within grid boundary
        while ((position <= 0) or (position > othelloBoard.getRows())):
            print("*** Invalid Entry: enter an int value 1-8 for the " + rowOrColumn + " ***" )
            position = int(input("Enter a value 1-8 for the " + rowOrColumn))
        return position

