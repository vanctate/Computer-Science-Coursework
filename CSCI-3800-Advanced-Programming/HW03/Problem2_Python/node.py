# Patrick Tate
# CSCI 3800
# HW03 Problem 2

# Node class to be utilized in conjunction with the CircularLinkedList class
# Node has two member variables, 'data' which can store any data/values
# and 'nextPtr' which points to the next node in the class

class Node:

    # default initializer
    def __init__(self):
        self.__data = None
        self.__nextPtr = None # points to the next node in the linked list

    def setData(self, data):
        self.__data = data

    def setNextPtr(self, nextPtr):
        self.__nextPtr = nextPtr

    def getData(self):
        return self.__data

    def getNextPtr(self):
        return self.__nextPtr