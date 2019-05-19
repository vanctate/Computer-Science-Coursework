/*
 - Patrick Tate
 - CSCI 1411-004
 - Lab 12
 - Description: This program defines a class called Scores that has private member variables to hold a students name and 3 quiz scores. In the main.cpp an array of two Score objects is created, and the user is prompted to enter each students name followed by their 3 quiz scores, quiz scores are out of 100, the program then displays each student's test scores and their average. It is a simple program that mainly uses the get and set member functions. The get and set member functions are simple so they are defined inline in the header. The constructors and the getAverage functions are defined in Scores.cpp
 - Lab Partner: Prin
 - Status: Program successfully compiles and runs
 */

#include "Scores.h"

// default constructor
Scores::Scores()
{
    name = "";
    quiz1 = 0.0;
    quiz2 = 0.0;
    quiz3 = 0.0;
}

//constructor
Scores::Scores(string p_name, double q1, double q2, double q3)
{
    name = p_name;
    quiz1 = q1;
    quiz2 = q2;
    quiz3 = q3;
}

//average quiz score function
double Scores::getAverage(){
    return ((quiz1 + quiz2 + quiz3)/3);
}

