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

#include "ArrayBag.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <iterator>
using namespace std;


ArrayBag::ArrayBag() : itemCount(0), maxItems(DEFAULT_BAG_SIZE)
{
}  // end default constructor


int ArrayBag::getCurrentSize() const
{
    return itemCount;
}  // end getCurrentSize


bool ArrayBag::isEmpty() const
{
    return itemCount == 0;
}  // end isEmpty


bool ArrayBag::add(const ItemType& newEntry)
{
    bool hasRoomToAdd = (itemCount < maxItems);
    if (hasRoomToAdd)
    {
        items[itemCount] = newEntry;
        itemCount++;
    }  // end if
    
    return hasRoomToAdd;
}  // end add


bool ArrayBag::remove(const ItemType& anEntry)
{
    int locatedIndex = getIndexOf(anEntry);
    bool canRemoveItem = !isEmpty() && (locatedIndex > -1);
    if (canRemoveItem)
    {
        itemCount--;
        items[locatedIndex] = items[itemCount];
    }  // end if
    
    return canRemoveItem;
}  // end remove


void ArrayBag::clear()
{
    itemCount = 0;
}  // end clear


int ArrayBag::getFrequencyOf(const ItemType& anEntry) const
{
    int frequency = 0;
    int searchIndex = 0;
    while (searchIndex < itemCount)
    {
        if (items[searchIndex] == anEntry)
        {
            frequency++;
        }  // end if
        
        searchIndex++;
    }  // end while
    
    return frequency;
}  // end getFrequencyOf


bool ArrayBag::contains(const ItemType& anEntry) const
{
    return getIndexOf(anEntry) > -1;
}  // end contains

// private

int ArrayBag::getIndexOf(const ItemType& target) const
{
    bool found = false;
    int result = -1;
    int searchIndex = 0;
    // if the ArrayBag is empty, itemCount is zero, so loop is skipped
    while (!found && (searchIndex < itemCount))
    {
        if (items[searchIndex] == target)
        {
            found = true;
            result = searchIndex;
        }
        else
        {
            searchIndex++;
        }  // end if
    }  // end while
    
    return result;
}  // end getIndexOf

//function written by Patrick Tate
//loads 2 objects with ints from file
void ArrayBag::loadBag(ArrayBag &_obj1, ArrayBag &_obj2){
    
    std::fstream inFile;//input file variable to read in data from setInput.txt
    //open setInput.txt
    inFile.open("setInput.txt");
    
    //loads first line of numbers into object1's bag and second line of numbers into object2's bag
    for (int i = 0; i < 2; i++) {
        //the line of numbers is obtained as a string and then converted to an array of ints
        string temp;
        if (i == 0) {
            getline(inFile, temp);
            stringstream ss(temp);
            int element;
            while (ss >> element) {
                _obj1.add(element);
            }
        }
        if (i == 1) {
            getline(inFile, temp);
            stringstream ss(temp);
            int element;
            while (ss >> element) {
                _obj2.add(element);
            }//while
        }//if
    }//for
  
    inFile.close();//close file after reading in data
}

//written by Patrick Tate
void ArrayBag::displayItems(){
    for (int i = 0; i < getCurrentSize(); i++) {
        cout << items[i] << endl;
    }
}

//written by Patrick Tate
//returns the addition of two objects' bags, duplicates are deleted after the addition
//example, bag1 = [0,1,2,3,3], bag2 = [4,5,6,6], (bag1 + bag2 = [0,1,2,3,4,5,6]
ArrayBag ArrayBag:: operator+(ArrayBag const &_obj1){
    
    ArrayBag obj3;//the result of the addition is placed in obj3's bag
    
    //add items from object on right hand side to obj3
    for (int i = 0; i < _obj1.getCurrentSize(); i++) {
        obj3.add(_obj1.items[i]);
    }
    
    //add items from objects on left hand side to obj3
    for (int j = 0; j < itemCount; j++) {
        obj3.add(items[j]);
    }
    
    //delete duplicates from the remaining items in left hand side bag
    int total = obj3.getCurrentSize();
    for (int k = 0; k < total; k++) {
        int target = obj3.items[k];
        int appears = obj3.getFrequencyOf(target);
        if (appears > 1) {
            for (int j = 0; j < (appears - 1); j++) {
                obj3.remove(target);
            }//for
        }//if
    }//for
    
    return obj3;
}

//written by Patrick Tate
//returns the difference of two objects' bags, duplicates are deleted after subtraction
//ints are only deleted from left hand side if they also appear on the right hand side
//example, bag1 = [1,1,2,3] bag2 = [2,3,4] (bag1 - bag2 = 1)
ArrayBag ArrayBag:: operator -(ArrayBag const &_obj1){
    
    ArrayBag  obj3;//the result of the subtraction is placed in obj3's bag
    
    //set obj3 to the left hand side object
    for (int f = 0; f < itemCount; f++) {
        obj3.add(items[f]);
    }
    
    //check to see if right hand side items are in left hand side bag, if true then they are deleted
    int i = 0;
    while (i <= itemCount) {
        for (int j = 0; j < _obj1.itemCount; j++) {
            if (_obj1.items[j] == obj3.items[i]) {
                obj3.remove(obj3.items[i]);
            }//if
        }//for
        i++;
    }//while
    
    //delete duplicates from the remaining items in left hand side bag
    for (int k = 0; k < itemCount; k++) {
        int target = obj3.items[k];
        int appears = obj3.getFrequencyOf(target);
        if (appears > 1) {
            for (int j = 0; j < (appears - 1); j++) {
                obj3.remove(target);
            }//for
        }//if
    }//for
    
    return obj3;
}
