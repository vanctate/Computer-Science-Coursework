/*
 - Patrick Tate
 - HW 6
 - CSCI 2312
 - Program written using Xcode on MacOS
 - Program Status: compiled, run, and tested on csegrid
 */


#ifndef list_h
#define list_h
#include <iostream>
#include <cstring>

template <typename DATA>
struct Node{
    DATA data;
    Node<DATA> *nextPtr = nullptr;
};

template <typename DATA>
class List
{
private:
    Node<DATA> *headPtr;
public:
    List();
    ~List();
    List(const List<DATA> &list);//copy constructor, deep copy
    List<DATA>& operator=(const List<DATA> &list);//deep copy
    void clear();//clears the list, used in destructor
    bool insertBack(DATA data);//inserts nodes into the back of the list
    bool push_front(DATA data);//pushes data, not nodes, at the front of the list
    bool push_back(DATA data);//pushes data, not nodes, at the back of the list
    bool pop_front() throw(int);//removes data from the front of the list, sets data to -1
    bool pop_back() throw(int);//removes data from the end of the list, setting data to -1
    void printList(std::ostream &out);
};

#endif /* list_h */
