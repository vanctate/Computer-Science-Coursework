/*
 - Patrick Tate
 - Final Project
 - CSCI 2421
 - Program written using Xcode on MacOS
 - Program Status: program compiles and runs on the cse grid
 */

//To be used in conjunction with BSTree.h and BSTree.hpp
//If you modify this, please add your name and list any changes that you made
#ifndef NODE_H
#define NODE_H
#include <iostream>
#include <string>
using namespace std;

// A tree node class for ints

//Placeholder for a composite data type
struct GeneralData
{
    int number; //Update this to your data field
    string name;
};

//Actor-Actress struct by Patrick Tate
struct Actors
{
    int year;//int
    string award;
    bool isWinner;//read in as 0 or 1, bool
    string name;//will also be the key
    string film;
};

//Pictures struct by Patrick Tate
struct Pictures
{
    string name;//will also be the key
    int year;
    int nominations;//number of nominations received
    double rating;
    int duration;//minutes
    string genre1;
    string genre2;
    string release;//month
    int metacritic;//0-100
    string synopsis;
};


//Binary Tree Node
template <typename DATATYPE, typename KEYTYPE>
class Node {
private:
    KEYTYPE key;//what the BSTree of Node's is sorted on
    DATATYPE data;
    Node<DATATYPE, KEYTYPE> * left;
    Node<DATATYPE, KEYTYPE> * right;
    Node<DATATYPE, KEYTYPE> * parent;
public:
    Node() {left=nullptr; right=nullptr; parent = nullptr;};
    void setKey(KEYTYPE aKey) { key = aKey; };
    void setData(DATATYPE aData) { data = aData; }
    void setLeft(Node<DATATYPE, KEYTYPE> * aLeft) { left = aLeft; };
    void setRight(Node<DATATYPE, KEYTYPE> * aRight) { right = aRight; };
    void setParent(Node<DATATYPE, KEYTYPE> * aParent) { parent = aParent; };
    KEYTYPE Key() { return key; };
    DATATYPE Data() { return data; }
    Node<DATATYPE, KEYTYPE> * Left() { return left; };
    Node<DATATYPE, KEYTYPE> * Right() { return right; };
    Node<DATATYPE, KEYTYPE> * Parent() { return parent; };
};

#endif
