/*
 - Patrick Tate
 - HW06
 - CSCI 2421-001
 - Program written using Xcode on MacOS
 - Program Status: this program runs and compiles on the csegrid
 */


#include "DictEntry.h"
#include "Dictionary.h"
#include <iostream>
#include <list>
#include <string>
#include <fstream>

using namespace std;

int main() {
    
    
    Dictionary myList;
    myList.loadLists();//load the Dictionary object's double linked lists with words from txt files
    
    cout << myList;//display list before sorting
    cout << endl;
    
    cout << "After sorting ";
    myList.sortDictionary();
    cout << myList << endl;
    
    cout << "After sorting Dictionary list, comparing lists from begining:\n";
    myList.compareListsForward();
    cout << endl << endl;
    cout << "After sorting, comparing lists from end (reverse):\n";
    myList.compareListsRev();
    
    return 0;
}

