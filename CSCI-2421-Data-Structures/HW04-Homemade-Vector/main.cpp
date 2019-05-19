/*
 - Patrick Tate
 - HW04
 - CSCI 2421-001
 - Program written using Xcode on MacOS
 - Program Status: this program runs and compiles on the csegrid
 */

#include "MyVector.h"
#include <iostream>

int main() {
    
    //a simple demo of the MyVector class functionality
    
    HW4::MyVector vec;//instantiate empty vector
    
    std::cout << std::endl;
    std::cout << "This program will demonstrate the MyVector class functionality.\n\n";
    std::cout << "Demonstrating the empty() function after initializing a new vector:\n";
    bool empty = vec.empty();
    if (empty) {
        std::cout << "Your new vector is empty.\n\n";
    }
    else if (!empty){
        std::cout << "This vector is not empty.\n\n";
    }
    
    HW4::T number = 111;
    vec.push_back(number);
    vec.push_back(222);
    vec.push_back(333);
    std::cout << "After adding 3 elements:\n";
    bool empty2 = vec.empty();
    if (empty2) {
        std::cout << "Your new vector is empty.\n\n";
    }
    else if (!empty2){
        std::cout << "This vector is not empty.\n\n";
    }
    std::cout << "Displaying the contents of non empty vector after using push_back function:\n";
    for (int i = 0; i < vec.size(); i++) {
        std::cout << vec[i] << std::endl;
    }
    std::cout << std::endl;
    
    std::cout << "Demonstrating the search function for the last element (333) in vector:\n";
    int found3 = vec.search(333);
    if (found3 < 0) {
        std::cout << "Item not found.\n";
    }
    else if (found3 >= 0){
        std::cout << "Item " << vec[found3] << " found at element " << found3 << std::endl;
    }
    
    std::cout << std::endl;
    std::cout << "Displaying vector after the pop_back function:\n";
    vec.pop_back();
    for (int i = 0; i < vec.size(); i++) {
        std::cout << vec[i] << std::endl;
    }
    
    std::cout << std::endl;
    std::cout << "Searching for 333 after using pop_back function:\n";
    int found2 = vec.search(333);
    if (found2 < 0) {
        std::cout << "Item 333 not found.\n";
    }
    else if (found2 >= 0){
        std::cout << "Item found at element: " << found2 << std::endl;
    }
    
    std::cout << std::endl;
    std::cout << "Attempting to display out of bounds element in vec [] overload:\n";
    std::cout << vec[2];
    
    return 0;
}
