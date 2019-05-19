/*
 - Patrick Tate
 - CSCI 1411-004
 - Lab 13
 - Description: This program defines a class called Scores that has private member variables to hold a students name and 3 quiz scores. In the main.cpp an array of two Score objects is created, and the user is prompted to enter each students name followed by their 3 quiz scores, quiz scores are out of 100, the program then displays each student's test scores and their average. The << operator is overloaded so a Scores object can be displayed with cout. A bubble sort function is added that sorts the array of Scores objects by name.
 - Lab Partner: Prin
 - Status: Program successfully compiles and runs
 */

#include <iostream>
#include <iomanip>
#include <string>
#include "Scores.h"
#include "Functions.h"

using namespace std;

int main() {
    
    const int SIZE = 2;//for the array size, for 2 students
    
    Scores tempStu;//temp object to hold info from user
    string tempStuName;//temp variable to hold student's name
    double Q1, Q2, Q3;//variables to hold temp student's quiz scores
    Scores stuArray[SIZE];//array of two Scores objects
    
    //get Scores object info from the user, set object to that data, and place object in the array
    for (int i = 0; i < SIZE; i++) {
        cout << "Enter the name for student " << i+1 << ".\n";
        getline(cin, tempStuName);
        cout << "Enter " << tempStuName << "'s grade for quiz 1.\n";
        cin  >> Q1;
        cout << "Enter " << tempStuName << "'s grade for quiz 2.\n";
        cin  >> Q2;
        cout << "Enter " << tempStuName << "'s grade for quiz 3.\n";
        cin  >> Q3;
        cin.ignore();
        tempStu.setName(tempStuName);//set temp student's name
        tempStu.setQuiz(Q1, Q2, Q3);//set temp student's quiz scores
        stuArray[i] = tempStu;//place temp student at element h in array
    
        cout << endl;//whitespace for spacing
    }
    
    //cycle through array and display each Scores object before sorting array
    cout << "Without sorting, your student's scores are:";
    for (int j = 0; j < SIZE; j++) {
        cout << setprecision(4) << endl << stuArray[j] << endl;
    }
    
    //sort array based on Scores object name
    bubbleSort(stuArray, SIZE);
    
    //cycle through the sorted array and display each Score object
    cout << "Sorted by name, your student's scores are:";
    for (int k = 0; k < SIZE; k++) {
        cout << setprecision(4) << endl << stuArray[k] << endl;
    }//for
    
    return 0;
}

