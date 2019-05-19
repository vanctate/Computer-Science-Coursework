/*
    Patrick Tate
    CSCI 3800 HW03 Problem 2
 */

/*
    - Node class to be used in conjuction with the CircularLinkedList class
    - Node contains two member variables, 'data' of type int, and nextPtr of type 'Node'
    - nextPtr points to the next Node in the linked list
 */
public class Node {

    private int data;
    private Node nextPtr;

    // default constructor
    public Node(){
        this.data = -1;
        this.nextPtr = null;
    }

    // getters
    public int getData() {
        return this.data;
    }
    public Node getNextPtr() {
        return this.nextPtr;
    }

    // setters
    public void setData(int data) {
        this.data = data;
    }
    public void setNextPtr(Node nextPtr) {
        this.nextPtr = nextPtr;
    }
}
