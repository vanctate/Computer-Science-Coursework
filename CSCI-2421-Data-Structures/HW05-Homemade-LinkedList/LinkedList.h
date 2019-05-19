/*
 - Patrick Tate
 - HW05
 - CSCI 2421-001
 - Program written using Xcode on MacOS
 - Program Status: this program runs and compiles on the csegrid
 */
#include <iostream>

struct Node
{
    char data = 0;
    Node* nextPtr = nullptr;
};

class LinkedList
{
private:
    Node *headPtr;
    Node *n;
public:
    LinkedList();
    ~LinkedList();
    
    bool insertAtFront(char value);
    Node* getHeadPtr(){return headPtr;}
    void clear();
    
    bool insertBeforePosition(char value, int index);
    //first Node after headptr is 1
    //false if pos zero or out of range
    bool insertAtBack(char value);
    bool deleteAtFront();
    bool deletePosition(int index);
    //first Node after headptr is 1
    //false if pos zero or out of range
    bool deleteAtBack();
    //false if empty
    friend std::ostream& operator << (std::ostream &out, LinkedList &list);
};

