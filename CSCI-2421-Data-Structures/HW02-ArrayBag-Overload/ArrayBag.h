//  All code written and created by Frank M. Carrano and Tim Henry, unless otherwise specified.
//  Copyright (c) 2016 __Pearson Education__. All rights reserved.
//  Modified by TAA to remove Template and Inheritance

/*
 - Patrick Tate
 - HW02
 - CSCI 2421-001
 - Program written using Xcode on MacOS
 - Program Status: this program runs and compiles on the csegrid
 */

/** @file ArrayBag.cpp */


#ifndef BAG_
#define BAG_

typedef int ItemType;
class ArrayBag
{
private:
    static const int DEFAULT_BAG_SIZE = 100;
    ItemType items[DEFAULT_BAG_SIZE]; // array of bag items
    int itemCount;                    // current count of bag items
    int maxItems;                     // max capacity of the bag
    
    // Returns either the index of the element in the array items that
    // contains the given target or -1, if the array does not contain
    // the target.
    int getIndexOf(const ItemType& target) const;
    
public:
    ArrayBag();
    
    int getCurrentSize() const;
    void displayItems();//written by Patrick Tate
    bool isEmpty() const;
    bool add(const ItemType& newEntry);
    bool remove(const ItemType& anEntry);
    void clear();
    bool contains(const ItemType& anEntry) const;
    int getFrequencyOf(const ItemType& anEntry) const;
    void loadBag(ArrayBag& _obj1, ArrayBag& _obj2);//written by Patrick Tate
    ArrayBag operator + (ArrayBag const &_obj1);//written by Patrick Tate
    ArrayBag operator - (ArrayBag const &_obj1);////written by Patrick Tate
};  // end Bag


#endif

