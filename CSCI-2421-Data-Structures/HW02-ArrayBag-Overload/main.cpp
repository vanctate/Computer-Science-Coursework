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
#include <iostream>
using namespace std;

int main() {
    
    ArrayBag obj1, obj2;
    obj1.loadBag(obj1, obj2);//load each object's bag with line of numbers from txt file
    
    cout << "Items in object 1:\n";
    obj1.displayItems();
    cout << endl;
    cout << "Items in object 2:\n";
    obj2.displayItems();
    cout << endl;
    
    ArrayBag obj3 = obj1 - obj2;
    cout << "Object 1 - Object 2:\n";
    obj3.displayItems();
    
    cout << endl;
    
    cout << "Object 1 + Object 2:\n";
    ArrayBag obj4 = obj1 + obj2;
    obj4.displayItems();
    
    return 0;
}
