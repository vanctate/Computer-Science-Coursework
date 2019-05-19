# Patrick Tate
# CSCI 3800
# HW03 Problem 2

# driver to demonstrate functionality of the CircularLinkedList class

from node import Node
from circularLinkedList import CircularLinkedList

myList = CircularLinkedList() # instantiate empty list

# Demonstrating insertAtFront by inserting '3', '3', and '1' into the list
# after 1 is inserted, list will be in order '1,2,3'
myList.insertAtFront(3)
myList.insertAtFront(2)
myList.insertAtFront(1)

#print updated list after insertions
print("*** Printing CircularLinkedList. Will display '1,2,3' ***")
myList.printCircular()

# Demonstrating insertAtBack by inserting '4' in the last position
# after '4' is inserted, list will be in order '1,2,3,4'
myList.insertAtBack('4')

# print updated list after insertions
print()
print("*** Printing CircularLinkedList. Will display '1,2,3,4' ***")
myList.printCircular()

# Demonstrating shiftByOne function
# after shiftByOne function call, list will be in order '4,1,2,3'
myList.shiftByOne()

# print updated list after shiftByOne function call
print()
print("*** Printing CircularLinkedList after 'ShiftByOne' function. Will display '4,1,2,3' ***")
myList.printCircular()

# Demonstrating insertAtPosition function by inserting 0 into position 3
# after '0' is inserted, list will be in order '4,1,0,2,3'
myList.insertBeforePosition(0, 3)

# print updated list after insertAtPosition function call
print()
print("*** Printing CircularLinkedList. Will display '4,1,0,2,3' ***")
myList.printCircular()
print()
print("****** End of CircularLinkedList Demo ******")