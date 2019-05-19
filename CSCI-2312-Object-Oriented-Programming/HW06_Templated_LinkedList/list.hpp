/*
 - Patrick Tate
 - HW 6
 - CSCI 2312
 - Program written using Xcode on MacOS
 - Program Status: compiled, run, and tested on csegrid
 */

#include "list.h"

using namespace std;

//default constructor
template <typename DATA>
List<DATA>::List()
{
    headPtr = nullptr;
}

//destructor
template <typename DATA>
List<DATA>::~List<DATA>()
{
    clear();
}

//copy constructor, performs a deep copy
template <typename DATA>
List<DATA>::List(const List<DATA> &list):headPtr(nullptr)
{
    Node<DATA> *n = list.headPtr;
    while (n != nullptr) {
        insertBack(n->data);
        n = n->nextPtr;
    }//while
}

//overloaded = operator, performs a deep copy
template <typename DATA>
List<DATA>& List<DATA>::operator=(const List<DATA> &list)
{
    clear();//ensure list is empty before copying new contents in
    Node<DATA> *currentPtr = list.headPtr;
    headPtr = currentPtr;
    while (currentPtr != nullptr) {
        insertBack(currentPtr->data);
        currentPtr = currentPtr->nextPtr;
    }
    return *this;
}

//deletes the entire contents of the list
template <typename DATA>
void List<DATA>::clear()
{
    Node<DATA> *currentPtr = headPtr;
    while (headPtr != nullptr) {
        headPtr = headPtr->nextPtr;
        
        //return node to the system
        currentPtr->nextPtr = nullptr;
        delete currentPtr;
        currentPtr = headPtr;
    }//while
    headPtr = nullptr;
}

//inserts nodes into the back of the list
template <typename DATA>
bool List<DATA>::insertBack(DATA data)
{
    Node<DATA> *n;//create node pointer
    Node<DATA> *last;//pointer to move through the list until the end
    n = new Node<DATA>;//create new node to be inserted last
    n->data = data;//set data
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
    
    //after reaching the end, set the end of the list to Node n, n->next points to null signifying end
    last->nextPtr = n;
    n->nextPtr = nullptr;
    
    return true;
}

//pushes data, not nodes, on the front of the list
template <typename DATA>
bool List<DATA>::push_front(DATA data)
{
    Node<DATA> *n;//create a node pointer
    n = headPtr;//set node pointer to first node
    n->data = data;//set new data of first node
    
    return true;
}

//pushes data, not nodes, on the back of the list
template <typename DATA>
bool List<DATA>::push_back(DATA data)
{
    Node<DATA> *tempPtr = headPtr;
    while (tempPtr->nextPtr != nullptr) {
        tempPtr = tempPtr->nextPtr;
    }//while
    tempPtr->data = data;
    return true;
}

//removes data from the front of the list
//"removing" is setting data to -1 because csegrid wouldn't accept NULL value
//throws an exception if list is empty
template <typename DATA>
bool List<DATA>::pop_front() throw(int)
{
    if (headPtr == nullptr) {
        throw -1;
        return false;
    }
    else{
        Node<DATA> *n;//create a node pointer
        n = headPtr;//set node pointer to first node
        n->data = -1;//set new data of first node
        return true;
    }
}

//removes data from the back of the list
//"removing" is setting data to -1 because csegrid wouldn't accept NULL value
//throws an exception if list is empty
template <typename DATA>
bool List<DATA>::pop_back() throw(int)
{
    if (headPtr == nullptr){
        throw -1;
        return false;
    }
    else{
        Node<DATA> *tempPtr = headPtr;
        while (tempPtr->nextPtr != nullptr) {
            tempPtr = tempPtr->nextPtr;
        }//while
        tempPtr->data = -1;
        return true;
    }
}

//prints list from the begining
template <typename DATA>
void List<DATA>::printList(std::ostream &out)
{
    if (headPtr == nullptr) {
        out << "Empty list.\n";
    }
    else{
    Node<DATA> *tempPtr = headPtr;
    while (tempPtr != nullptr) {
        out << tempPtr->data << endl;
        tempPtr = tempPtr->nextPtr;
        }//while
    }//else
}

