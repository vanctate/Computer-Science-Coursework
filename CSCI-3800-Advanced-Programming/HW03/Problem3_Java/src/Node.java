/*
    Patrick Tate
    CSCI 3800 HW03 Problem 3
 */

/*
    - Generic Node class to be used in conjunction with the CircularLinkedList class
    - Node contains two member variables, generic 'data' which can hold any data type,
    - and nextPtr of type 'Node<T>'
    - nextPtr points to the next Node in the linked list
 */
public class Node<T> {

    private T data; // generic data of type T
    private Node<T> nextPtr;

    // default constructor
    public Node(){
        this.data = null;
        this.nextPtr = null;
    }

    // getters
    public T getData() {
        return this.data;
    }
    public Node getNextPtr() {
        return this.nextPtr;
    }

    // setters
    public void setData(T data) {
        this.data = data;
    }
    public void setNextPtr(Node<T> nextPtr) {
        this.nextPtr = nextPtr;
    }
}
