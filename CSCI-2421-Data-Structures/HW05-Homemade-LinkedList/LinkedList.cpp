/*
 - Patrick Tate
 - HW04
 - CSCI 2421-001
 - Program written using Xcode on MacOS
 - Program Status: this program runs and compiles on the csegrid
 */

#include "LinkedList.h"
#include <iostream>

LinkedList:: LinkedList(){
    headPtr = nullptr;
}

bool LinkedList::insertAtFront(char value){
    
    Node *n;//create a node pointer
    n = new Node;//create new node
    n->data = value;//set data of new node
    n->nextPtr = headPtr;//set new node's nextPtr to the head
    headPtr = n;//set head to newly inserted node
    
    return true;
}

bool LinkedList::insertAtBack(char value){
    Node *n;//create node pointer
    Node *last = headPtr;//pointer to move through the list until the end
    n = new Node;//create new node to be inserted last
    n->data = value;//set data
    n->nextPtr = nullptr;//set nextPtr to nullPtr to signify end of list
    
    //if list is empty
    if (headPtr == nullptr) {
        headPtr = n;
        return true;
    }
    else{
        //move through the list until the end is reached
        last = headPtr;
        //dependant on size n so f(n) linear time
        while (last->nextPtr != nullptr) {
            last = last->nextPtr;
        }//while
    }//else
    
    //after reaching the end, set the end of the list to Node n, n-> points to null signifying end
    last->nextPtr = n;

    return true;
}

bool LinkedList::deleteAtFront(){
    if (headPtr == nullptr) {
        std::cout << "List is empty.\n";
        return false;
    }
    else {
        Node *n = headPtr;
        headPtr = headPtr->nextPtr;
        delete n;
    }
    return true;
}

bool LinkedList::deleteAtBack(){
    Node* currentPtr;
    Node* prevPtr = nullptr;
    
    if (headPtr == nullptr) {
        std::cout << "List empty.\n";
        return false;
    }
    //if only 1 node in list
    else if (headPtr->nextPtr == nullptr){
        currentPtr = headPtr;
        headPtr = nullptr;
        delete currentPtr;
    }//else only 1 node
    
    else{
        //move to the end of the list
        currentPtr = headPtr;
        while (currentPtr->nextPtr != nullptr) {
            prevPtr = currentPtr;
            currentPtr = currentPtr->nextPtr;
        }//while
        prevPtr->nextPtr = nullptr;
        delete currentPtr;
    }//else more than 1 node
    
    return true;
}

//first node after head is 1
bool LinkedList::deletePosition(int index){
    Node *currentPtr = headPtr;
    //if list is empty
    if (headPtr == nullptr) {
        std::cout << "List already empty.\n";
        return false;
    }
    //cannot delete a node in front of position 1
    if (index == 0) {
        std::cout << "Cannot delete position 0.\n";
        return false;
    }
    //first node
    if (index == 1) {
        headPtr = currentPtr->nextPtr;
        delete currentPtr;
        return true;
    }
    //if index is > 2 loop will move currentPtr accordingly
    for (int i = 0; i < (index - 2); i++) {
        currentPtr =  currentPtr->nextPtr;
        //catch if index is out of bounds
        if ((currentPtr == nullptr) || (currentPtr->nextPtr == nullptr)) {
            std::cout << "Position out of bounds.\n";
            return false;
        }//if
    }//for
    
    Node *temp = currentPtr->nextPtr;
    currentPtr->nextPtr = temp->nextPtr;
    delete temp;
    return true;

}

//first node in list is position 1
bool LinkedList::insertBeforePosition(char value, int index){
    Node *n = new Node;
    n->data = value;
    Node *tempPtr = headPtr;
    
    //cannot insert before a position if list is empty
    if (headPtr == nullptr) {
        std::cout << "List empty.\n";
        return false;
    }
    
    //cannot insert before head
    if (index == 0) {
        std::cout << "Cannot insert before head.\n";
        return false;
    }
    
    //inserting in the front
    if (index == 1) {
        n->nextPtr = headPtr;
        headPtr = n;
        return true;
    }
    
    //if index is > 2 loop will move temptPtr accordingly
    for (int i = 0; ((i< (index - 2)) && (tempPtr != nullptr)); i++) {
        tempPtr = tempPtr->nextPtr;
    }
    //catch if index is out of bounds
    if ((tempPtr == nullptr) || (tempPtr->nextPtr == nullptr)) {
        std::cout << "Position out of bounds.\n";
        return false;
    }
    n->nextPtr = tempPtr->nextPtr;
    tempPtr->nextPtr = n;
    
    return true;
}

std::ostream& operator<<(std::ostream& out, LinkedList &list){
    Node *tempPtr = list.getHeadPtr();
    while (tempPtr != nullptr) {
        out << tempPtr->data << std::endl;
        tempPtr = tempPtr->nextPtr;
    }
    return out;
}

void LinkedList::clear(){
    
    Node *currentPtr = headPtr;
    while (headPtr != nullptr) {
        headPtr = headPtr->nextPtr;
        
        //return node to the system
        currentPtr->nextPtr = nullptr;
        delete currentPtr;
        currentPtr = headPtr;
    }//while
    headPtr = nullptr;
}

LinkedList::~LinkedList(){
    clear();
}
 
