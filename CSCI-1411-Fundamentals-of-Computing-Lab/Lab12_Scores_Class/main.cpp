/*
 - Patrick Tate
 - CSCI 1411-004
 - Lab 12
 - Description: This program defines a class called Scores that has private member variables to hold a students name and 3 quiz scores. In the main.cpp an array of two Score objects is created, and the user is prompted to enter each students name followed by their 3 quiz scores, quiz scores are out of 100, the program then displays each student's test scores and their average. It is a simple program that mainly uses the get and set member functions. The get and set member functions are simple so they are defined inline in the header. The constructors and the getAverage functions are defined in Scores.cpp
 - Lab Partner: Prin
 - Status: Program successfully compiles and runs
 */

#include <iostream>
#include <iomanip>
#include <string>
#include "Scores.h"

int main() {
    
    const int SIZE = 2;//for the array size, for 2 students
    string tempStu;//temp variable to hold student's name
    double tempQ1, tempQ2, tempQ3;//temp quiz scores out of 100
    Scores stuArray[SIZE];//array of two Scores objects
    
    //get info from user
    for (int i = 0; i < SIZE; i++) {
        cout << "Enter the name for student " << i + 1 << ".\n";
        getline(cin, tempStu);
        cout << "Enter " << tempStu << "'s grade for test 1.\n";
        cin  >> tempQ1;
        cout << "Enter " << tempStu << "'s grade for test 2.\n";
        cin  >> tempQ2;
        cout << "Enter " << tempStu << "'s grade for test 3.\n";
        cin  >> tempQ3;
        cin.ignore();
        
        stuArray[i].setName(tempStu);//set student 1's name
        stuArray[i].setQuiz(tempQ1, tempQ2, tempQ3);//set student 1's quiz scores
    }//for
    
    cout << endl;//whitespace for spacing
    
    //display user information
    for (int j = 0; j < SIZE; j++) {
        cout << stuArray[j].getName() << "'s quiz scores are:\n";
        cout << "Quiz 1: " << stuArray[j].getQuiz1() << endl;
        cout << "Quiz 2: " << stuArray[j].getQuiz2() << endl;
        cout << "Quiz 3: " << stuArray[j].getQuiz3() << endl;
        cout << stuArray[j].getName() << "'s average quiz score is:\n";
        cout << setprecision(3) << stuArray[j].getAverage() << endl << endl;
    }//for
    
    
    return 0;
}
