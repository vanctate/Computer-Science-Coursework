/*
 - Patrick Tate
 - CSCI 1411-004
 - Lab 13
 - Description: This program defines a class called Scores that has private member variables to hold a students name and 3 quiz scores. In the main.cpp an array of two Score objects is created, and the user is prompted to enter each students name followed by their 3 quiz scores, quiz scores are out of 100, the program then displays each student's test scores and their average. The << operator is overloaded so a Scores object can be displayed with cout. A bubble sort function is added that sorts the array of Scores objects by name.
 - Lab Partner: Prin
 - Status: Program successfully compiles and runs
 */

#ifndef Scores_H
#define Scores_H

#include <string>

class Scores
{
private:
    std::string name;//hold students name
    double quiz1, quiz2, quiz3;//private variable for each quiz, total score out of 100
    
public:
    Scores();//defualt constructor
    Scores(std::string name, double quiz1, double quiz2, double quiz3);//constructor
    std::string getName(){return name;}
    void setName(std::string tempName){name = tempName;}
    double getQuiz1(){return quiz1;}
    double getQuiz2(){return quiz2;}
    double getQuiz3(){return quiz3;}
    void setQuiz(double q1, double q2, double q3){quiz1 = q1; quiz2 = q2; quiz3 = q3;}
    double getAverage();
};

#endif /* Header_h */

