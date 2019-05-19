/*
 - Patrick Tate
 - CSCI 1411-004
 - Lab 12
 - Description: This program defines a class called Scores that has private member variables to hold a students name and 3 quiz scores. In the main.cpp an array of two Score objects is created, and the user is prompted to enter each students name followed by their 3 quiz scores, quiz scores are out of 100, the program then displays each student's test scores and their average. It is a simple program that mainly uses the get and set member functions. The get and set member functions are simple so they are defined inline in the header. The constructors and the getAverage functions are defined in Scores.cpp
 - Lab Partner: Prin
 - Status: Program successfully compiles and runs
 */

#ifndef Header_h
#define Header_h

#include <string>
using namespace std;

class Scores
{
private:
    string name;//hold students name
    double quiz1, quiz2, quiz3;//private variable for each quiz, total score out of 100
    
public:
    Scores();//defualt constructor
    Scores(string name, double quiz1, double quiz2, double quiz3);//constructor
    string getName(){return name;}
    void setName(string tempName){name = tempName;}
    double getQuiz1(){return quiz1;}
    double getQuiz2(){return quiz2;}
    double getQuiz3(){return quiz3;}
    void setQuiz(double q1, double q2, double q3){quiz1 = q1; quiz2 = q2; quiz3 = q3;}
    double getAverage();
};

#endif /* Header_h */
