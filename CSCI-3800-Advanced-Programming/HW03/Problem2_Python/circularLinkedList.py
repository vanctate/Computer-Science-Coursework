# Patrick Tate
# CSCI 3800
# HW03 Problem 2

from node import Node # because CircularLinkedList is composed of Nodes pointing to other nodes

# Class definition and implementation for a circular singly linked list (CircularLinkedList).
# The linked list is circular because the last element in the list points to the first element in the list,
# rather than null.
# Rather than the linked list containing a head pointer pointing to the first element in the list,
# CircularLinkedList has a "lastPtr" member variable that points to the last element in the list.
# This enables the functions insertAtFront and insertAtBack to run in constant speed O(1) rather than traversing the
# entire list.
# The CircularLinkedList class also has a member variable size to keep track of how many elements are in the list,
# which is useful for printing the list

class CircularLinkedList:

    # default initializer, set __lastPtr to None, set __size to 0
    def __init__(self):
        self.__lastPtr = None
        self.__size = 0

    def getLastPtr(self):
        return self.__lastPtr

    def getSize(self):
        return self.__size

    # inserts any data type into the first position of the linked list
    # time complexity for this function is constant time, 0(1)
    def insertAtFront(self, data):

        # node to be inserted in the front of the list
        nodePtr = Node()
        nodePtr.setData(data)

        # if list is empty, insert in the front
        if self.__lastPtr == None:
            self.__lastPtr = nodePtr
            nodePtr.setNextPtr(nodePtr)
            self.__size = self.__size + 1
        else:
            nodePtr.setNextPtr(self.__lastPtr.getNextPtr()) # set nodePtr's nextPtr to the first element in the list
            self.__lastPtr.setNextPtr(nodePtr) # set the last element in the list to point to nodePtr, now the first element in the list
            self.__size = self.__size + 1 # increment the list size to reflect the node added


    # inserts any data type into the last position of the linked list
    # time complexity for this function is constant time, O(1)
    def insertAtBack(self, data):

        # node to be inserted in the last position of the list
        nodePtr = Node()
        nodePtr.setData(data)

        # if list is empty insert to the front
        if self.__lastPtr == None:
            self.__lastPtr = nodePtr
            nodePtr.setNextPtr(nodePtr) # since list contains only 1 node, nodePtr points to itself
            self.__size = self.__size + 1 # increment list size
        else:
            nodePtr.setNextPtr(self.__lastPtr.getNextPtr())
            self.__lastPtr.setNextPtr(nodePtr)
            self.__lastPtr = nodePtr
            self.__size = self.__size + 1

    # inserts any data type before the specified position parameter
    # the first position in the linked list is position 1
    # if position == 0, an error message is printed
    # if the user enters a non 'int' type for the position parameter, an error message is printed
    def insertBeforePosition(self, data, position):
        # create node to insert
        newNode = Node()
        newNode.setData(data)

        # check if position parameter is of int type
        if not isinstance(position, int):
            print("Position parameter is of incorrect type, please enter an integer value.")

        elif position <= 0:
            print("Cannot insert before position 0. Position must be >= 1")

        elif self.__lastPtr is None:
            print("List is empty, cannot insert before a position in an empty list.")

        elif position > 0 and position <= self.__size:
            i = 0
            temp = self.__lastPtr
            prevPtr = None
            for i in range(position):
                prevPtr = temp
                temp = temp.getNextPtr()
            newNode.setNextPtr(temp)
            prevPtr.setNextPtr(newNode)
            self.__size = self.__size + 1

        elif position > self.__size:
            print("Position out of range, " + str(data) + " not inserted.")

    # delete the first element in the list
    def popFront(self):

        if self.__lastPtr is None:
            print("List empty, cannot remove.")
        else:
            temp = self.__lastPtr.getNextPtr()
            temp = temp.getNextPtr()
            self.__lastPtr.setNextPtr(temp)
            self.__size = self.__size - 1


    # shift each element in the list by 1 position, last element becomes first element, 2nd to last element becomes
    # last element, etc
    # for example, if list is a,b,c,d, after shiftByOne function, list will be d,a,b,c
    def shiftByOne(self):

        # variable to find the 2nd to last element in list
        tempPtr = self.__lastPtr.getNextPtr()

        # var to keep track of self.__lastPtr before it is moved
        temp2 = self.__lastPtr

        # iterate through list to find the 2nd to last element in the list
        while (tempPtr.getNextPtr() != self.__lastPtr):
            tempPtr = tempPtr.getNextPtr()
        # once the 2nd to last element in the list is found, set self._lastPtr to equal 2nd to last element
        self.__lastPtr = tempPtr

        # shift each element's nextPtr by 1
        while (temp2.getNextPtr() != self.__lastPtr):
            temp2 = temp2.getNextPtr()

    # prints the contents of the linked list once, from the first node to the last node
    def printCircular(self):
        count = 0 # for determining when to terminate while loop

        newNodePtr = self.__lastPtr.getNextPtr() # set newNodePtr to the first element in the list
        print(newNodePtr.getData(), end = ',')              # print the data from the first element
        newNodePtr = newNodePtr.getNextPtr()     # move newNodePtr to point to the second element
        count = count + 1                        # increment count to reflect 1 value printed

        # run loop to print the remaining elements of the list
        # loop terminates when newNodePtr points back to the beginning of the list (self.__headPtr)
        while (count < self.__size):
            if count == (self.__size - 1):
                print(newNodePtr.getData())
            else:
                print(newNodePtr.getData(), end = ',')
            newNodePtr = newNodePtr.getNextPtr()
            count = count + 1
