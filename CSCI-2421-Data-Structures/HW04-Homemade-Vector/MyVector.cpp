/*
 - Patrick Tate
 - HW04
 - CSCI 2421-001
 - Program written using Xcode on MacOS
 - Program Status: this program runs and compiles on the csegrid
 */

#include "MyVector.h"
#include <iostream>

//default constructor
HW4::MyVector::MyVector(){
    vec = new T[vsize];//instantiate an empty vector of size 0
}

//overload [] operator for indexing values
//Overall complexity: f(1) + f(1) + f(1) + f(1) = f(4)
//Big O is O(1) or constant time
HW4::T HW4::MyVector:: operator[] (int index){
    //although size is used as a comparison, time not dependant on size
    //f(1)
    if (index >= vsize) {
        std::cout << "Vector index out of bounds.\n";//happens once, f(1)
        exit(0);//f(1)
    }
    return vec[index];//f(1)
}

//determine if vector contains no elements
bool HW4::MyVector:: empty(){
    return vsize == 0;
}

//add item to the last element in vector
//Overall complexity: f(1) + f(1) + f(1) + f(1) + f(1) + f(1) = f(6)
//Big O is O(1) or constant time
void HW4::MyVector:: push_back(T value){
    
    //if vector contians no elements, create a vector of size 1 and add value to element 0
    //f(1) or constant time
    if (vsize == 0) {
        vsize = vsize + 1;//f(1)
        vec[0] = value;//f(1)
    }//if vector empty
    
    //if vector size != 0, increment vsize by 1 and add element to the (vsize - 1) position
    //f(1) or constant time
    else if (vsize != 0){
        vsize = vsize + 1;//f(1)
        vec[vsize - 1] = value;//f(1)
    }//if vector not empty
}

//remove last item from vector
//Overall complexity: f(1) + f(1) + f(1) + f(1) + f(1) + f(n) + f(1) + f(1) = f(7) + f(n)
//Big O is O(n) or linear time
void HW4::MyVector:: pop_back(){
    
    //f(1) or constant time
    if (vsize == 0) {
        std::cout << "Vector is empty.\n";//f(1)
    }//if vector is empty
    
    else if (vsize != 0){
        HW4::T *tempPtr = nullptr;//happens once f(1)
        vsize = vsize - 1;//f(1)
        //create new dynaic array to hold all itmes except the last item in vec[]
        tempPtr = new T[vsize];//f(1)
        //dependent on size n, so complexity is f(n)
        for (int i = 0; i < vsize; i++) {
            tempPtr[i] = vec[i];//f(1)
        }//for
        delete [] vec;
        vec = tempPtr;//f(1)
    }
}

//Overall complexity: f(1) + f(n) + f(1) + f(1) + f(1) = f(4) + f(n)
//Big O is O(n) or linear time
int HW4::MyVector:: search(T Value){
    //f(1) happens once
    int index = -1;//negative value to indicate value not found
    
    //linear search, dependent on size n, so f(n)
    for (int i = 0; i < vsize; i++) {
        //if statement not dependant on size, so f(1)
        if (Value == vec[i]) {
            index = i;//happens once, f(1)
        }//if found
    }//for
    
    return index;//f(1)
}
