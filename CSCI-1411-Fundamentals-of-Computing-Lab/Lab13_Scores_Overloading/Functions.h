/*
 - Patrick Tate
 - CSCI 1411-004
 - Lab 13
 - Description: This program defines a class called Scores that has private member variables to hold a students name and 3 quiz scores. In the main.cpp an array of two Score objects is created, and the user is prompted to enter each students name followed by their 3 quiz scores, quiz scores are out of 100, the program then displays each student's test scores and their average. The << operator is overloaded so a Scores object can be displayed with cout. A bubble sort function is added that sorts the array of Scores objects by name.
 - Lab Partner: Prin
 - Status: Program successfully compiles and runs
 */

#ifndef Functions_h
#define Functions_h
#include "Scores.h"
#include <iostream>
using namespace std;

ostream& operator << (ostream &out, Scores &tempScores);//overload << operator for Scores objects
void bubbleSort(Scores scores[], int size);//sort Scores objects in array based on name

#endif /* Functions_h */
