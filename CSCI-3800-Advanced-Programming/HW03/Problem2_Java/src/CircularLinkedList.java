/*
    Patrick Tate
    CSCI 3800 HW03 Problem 2
 */

/*

Class definition and implementation for a circular singly linked list (CircularLinkedList).
The linked list is circular because the last element in the list points to the first element in the list,
rather than null. Rather than the linked list containing a head pointer pointing to the first element in the list,
CircularLinkedList has a "lastPtr" member variable that points to the last element in the list.
This enables the functions insertAtFront and insertAtBack to run in constant speed O(1) rather than traversing the
entire list.
The CircularLinkedList class also has a member variable size to keep track of how many elements are in the list,
which is useful for printing the list
 */

public class CircularLinkedList {

    public Node lastPtr; // points to the last element in the linked list
    public int size;     // keeps track of how many elements are in the list, useful when printing the list

    // default constructor
    public CircularLinkedList(){
        this.lastPtr = null;
        this.size = 0;
    }

    // getters
    public Node getLastPtr(){
        return this.lastPtr;
    }
    public int getSize(){
        return this.size;
    }

    // insert a Node into the last position of the linked list
    // time complexity is constant time O(1)
    public void insertAtBack(int data){
        // Node to be inserted as the last element
        Node nodePtr = new Node();
        nodePtr.setData(data);

        // check if list is empty
        if (this.lastPtr == null){
            this.lastPtr = nodePtr;
            nodePtr.setNextPtr(nodePtr);
            this.size++;
        }
        else {
            nodePtr.setNextPtr(this.lastPtr.getNextPtr());
            this.lastPtr.setNextPtr(nodePtr);
            this.lastPtr = nodePtr;
            this.size++;
        }

    }

    // insert a Node into the first position of linked list
    // time complexity is constant time O(1)
    public void insertAtFront(int data){
        // Node to be inserted as the first element
        Node nodePtr = new Node();
        nodePtr.setData(data);

        // check if list is empty
        if (this.lastPtr == null){
            this.lastPtr = nodePtr;
            nodePtr.setNextPtr(nodePtr);
            this.size++;
        }
        else {
            nodePtr.setNextPtr(this.lastPtr.getNextPtr());
            this.lastPtr.setNextPtr(nodePtr);
            this.size++;
        }
    }

    // insert a Node before any given position
    // first element in the list is 1 rather than 0
    // if 'position' paramter is <= 0 or > listSize an error message is printed
    public void insertAtPosition(int data, int position){
        // Node to be inserted before the given position
        Node nodePtr = new Node();
        nodePtr.setData(data);

        // check if list is empty
        if (this.lastPtr == null){
            System.out.println("Empty list, cannot insert at given position");
        }
        else if (position <= 0 || position > this.size){
            System.out.println("Position out of range, enter a valid position");
        }
        else {
            Node temp = this.lastPtr;
            Node prevPtr = new Node();

            // start at the beginning of the list and run loop until ...
            for(int i = 0; i < position; i++){
                prevPtr = temp;
                temp = temp.getNextPtr();
            }

            nodePtr.setNextPtr(temp);
            prevPtr.setNextPtr(nodePtr);
            this.size++;
        }
    }
    // shifts the contents of each element in the list by, the last element will become the first element, the frst
    // element will become the second, etc, for example, if the list contained values 1,2,3,4, after shiftByOne
    // function, the list will be 4,1,2,3
    public void shiftByOne(){

        // variable to find the 2nd to last element in list
        Node tempPtr = this.lastPtr.getNextPtr();

        // var to keep track of this.__lastPtr before it is moved
        Node temp2 = this.lastPtr;

        // iterate through list to find the 2nd to last element in the list
        while (tempPtr.getNextPtr() != this.lastPtr){
            tempPtr = tempPtr.getNextPtr();
        }
        // once the 2nd to last element in the list is found, set this._lastPtr to equal 2nd to last element
        this.lastPtr = tempPtr;

        // shift each element's nextPtr by 1
        while (temp2.getNextPtr() != this.lastPtr){
            temp2 = temp2.getNextPtr();
        }
    }

    public void printCircular(){
        int count = 0;

        Node currentNode = new Node();
        currentNode = this.lastPtr.getNextPtr();
        System.out.println(currentNode.getData());
        currentNode = currentNode.getNextPtr();
        count++;

        while (count < this.size) {
            System.out.println(currentNode.getData());
            currentNode = currentNode.getNextPtr();
            count++;
        }
    }

} // CircularLinkedList class definition
