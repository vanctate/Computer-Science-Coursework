# Patrick Tate
# CSCI 3800 HW 4 Problem 4

# simple class to model a book author
# only one member variable, a string name for the author
class Author:

    def __init__(self, name="None"):
        self.__name = name

    def getName(self):
        return self.__name

    def setName(self, name):
        self.__name = name


