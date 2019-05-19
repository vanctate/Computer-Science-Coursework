/*
    Patrick Tate
    CSCI 3800 HW03 Problem 3
 */

// Driver function to demo functionality of generic CircularLinkedList class
// CircularLinkedList can hold data of any type, int, char, string, etc

public class ListDemo {

    public static void main(String[] args) {

        CircularLinkedList myList = new CircularLinkedList();

        System.out.println("Demonstrating functionality of generic linked list.");
        System.out.println("List will contain '1,2,c'");
        myList.insertAtFront('c');
        myList.insertAtFront(2);
        myList.insertAtFront(1);
        myList.printCircular();
        myList.insertAtBack(4);
        System.out.println("After inserting 4 at the end, list will display '1,2,c,4");
        myList.printCircular();
        myList.insertAtFront('a');
        System.out.println("After inserting 'a' at the beginning, list will display 'a,1,2,c,4");
        myList.printCircular();
        System.out.println("Demonstrating shiftByOne function, list will display '4,a,1,2,c'");
        myList.shiftByOne();
        myList.printCircular();
        System.out.println("Inserting 'xyz' at position 4, list will display '4,0,1,xyz,2,c");
        myList.insertAtPosition("xyz", 4);
        myList.printCircular();
    }
}
