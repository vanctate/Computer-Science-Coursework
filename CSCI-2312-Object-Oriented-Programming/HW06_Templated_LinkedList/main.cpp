/*
 - Patrick Tate
 - HW 6
 - CSCI 2312
 - Program written using Xcode on MacOS
 - Program Status: compiled, run, and tested on csegrid
 */

#include <iostream>
#include "list.h"
#include "list.hpp"
#include "student.h"
#include <fstream>
#include <cstring>

using namespace std;

int main() {
    
    List<int> *myList1 = new List<int>;
    cout << "Inserting 1, 2, and 3 into myList1:\n";
    myList1->insertBack(1);
    myList1->insertBack(2);
    myList1->insertBack(3);
    myList1->printList(cout);
    cout << endl;
    
    cout << "Using push_front function to change data in the first node of myList1:\n";
    myList1->push_front(99);
    myList1->printList(cout);
    cout << endl;
    
    cout << "Using push_back function to change data in the last node of myList1:\n";
    myList1->push_back(101);
    myList1->printList(cout);
    cout << endl;
    
    cout << "Using copy construtor to copy values from myList1 into myList2:\n";
    List<int> *myList2(myList1);
    myList2->printList(cout);
    cout << endl;
    
    cout << "Using overloaded = operator to copy myList1 into myList3:\n";
    List<int> *myList3 = myList1;
    myList3->printList(cout);
    cout << endl;

    cout << "Using pop_front function to remove data in the first node of myList1.\n";
    cout << "By removing data we set it's value to -1:\n";
    try{
    myList1->pop_front();
    }//try
    catch(int e){
        cout << "empty list.\n";
    }//catch
    myList1->printList(cout);
    cout << endl;
    
    cout << "Using pop_back function to remove data in the last node of myList1.\n";
    cout << "By removing data we set it's value to -1:\n";
    try{
        myList1->pop_back();
    }
    catch(int e){
        cout << "empty list.\n";
    }
    myList1->printList(cout);
    cout << endl;
    
    cout << "Using clear function to clear myList1:\n";
    myList1->clear();
    myList1->printList(cout);
    cout << endl;
    
    cout << "Demonstrating exception handling of pop_front:\n";
    try{
        myList1->pop_front();
    }
    catch(int e){
        cout << "exception caught: empty list.\n";
    }
    
    cout << endl;

    myList2 = nullptr;
    myList3 = nullptr;
    delete myList2;
    delete myList3;
    
    //utilizing Student struct in student.h for the binary file
    cout << "Reading in from binary file:\n";
    fstream inFile("students.dat", ios::out | ios::in | ios::binary | ios::trunc);
    List<Student> stuList;
    Student s;
    
    strcpy(s.name, "Ashly");
    s.id = 111;
    inFile.write((char *)&s, sizeof(Student));
    
    strcpy(s.name, "Jennifer");
    s.id = 222;
    inFile.write((char *)&s, sizeof(Student));
    
    strcpy(s.name, "Xavier");
    s.id = 333;
    inFile.write((char *)&s, sizeof(Student));
    
    inFile.seekg(ios::beg);
    while (inFile.read((char *)&s, sizeof(Student)))
    {
        stuList.insertBack(s);
    }
    
    inFile.close();
    stuList.printList(cout);
    
    return 0;
}
