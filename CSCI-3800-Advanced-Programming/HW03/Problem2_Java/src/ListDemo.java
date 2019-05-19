/*
    Patrick Tate
    CSCI 3800 HW03 Problem 2
 */

// Driver function to demo functionality of CircularLinkedList class

public class ListDemo {

    public static void main(String[] args) {

        CircularLinkedList myList = new CircularLinkedList();

        myList.insertAtFront(3);
        myList.insertAtFront(2);
        myList.insertAtFront(1);
        myList.printCircular();
        myList.insertAtBack(4);
        System.out.println("After inserting 4 at the end");
        myList.printCircular();
        myList.insertAtFront(0);
        System.out.println("After inserting 0 at the beginning");
        myList.printCircular();
        System.out.println("Demonstrating shiftByOne function, list will display '4,0,1,2,3'");
        myList.shiftByOne();
        myList.printCircular();
        System.out.println("Inserting 99 at position 4");
        myList.insertAtPosition(99, 4);
        myList.printCircular();
    }
}
