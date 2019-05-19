/*
 - Patrick Tate
 - HW05
 - CSCI 2421-001
 - Program written using Xcode on MacOS
 - Program Status: this program runs and compiles on the csegrid
 */

#include <iostream>
#include "LinkedList.h"
using namespace std;
int main() {
   
    cout << endl << endl;
    cout << "Program to demonstrate the functionality of my LinkedList class.\n";
    
    LinkedList myList;
    cout << endl << "Inserting char values c,b,a into front of list.\n";
    cout << "Now list should be in order a,b,c:\n";
    myList.insertAtFront('c');
    myList.insertAtFront('b');
    myList.insertAtFront('a');
    cout << myList << endl;
    
    cout << endl << "Now inserting z at the end of the list.\n";
    cout << "List should now be in order a,b,c,z:\n";
    myList.insertAtBack('z');
    cout << myList << endl;
    
    cout << endl << "Now deleting node in the front position.\n";
    cout << "List should now display b,c,z:\n";
    myList.deleteAtFront();
    cout << myList << endl;
    
    cout << endl << "Now deleting node in the back position.\n";
    cout << "List should now display b,c:\n";
    myList.deleteAtBack();
    cout << myList << endl;
    
    cout << endl << "Now inserting node into specific postion.\n";
    cout << "Inserting a node with data 'a' before position 1.\n";
    cout << "List should now display a,b,c:\n";
    myList.insertBeforePosition('a', 1);
    cout << myList << endl;
    
    cout << endl << "Now inserting node into specific postion.\n";
    cout << "Inserting a node with data 'x' before position 3.\n";
    cout << "List should now display a,b,x,c:\n";
    myList.insertBeforePosition('x', 3);
    cout << myList << endl;
    
    cout << endl << "Now attempting to insert a node at an out of bounds position.\n";
    cout << "Out of bounds error message should appear.\n";
    cout << "List will still display a,b,x,c:\n";
    myList.insertBeforePosition('z', 5);
    cout << myList << endl;
    
    cout << endl << "Now deleting the node in postion 3.\n";
    cout << "List should now display a,b,c:\n";
    myList.deletePosition(3);
    cout << myList << endl;
    
    cout << endl << "Now attempting to delete an out of bounds position.\n";
    cout << "Out of bounds error message should appear.\n";
    cout << "List will still display a,b,c:\n";
    myList.deletePosition(6);
    cout << myList << endl << endl;
    
    cout << "Now demonstrating the clear function.\n";
    cout << "No list will be printed and program will end.\n";
    myList.clear();
    cout << myList;
    
    
    return 0;
}

