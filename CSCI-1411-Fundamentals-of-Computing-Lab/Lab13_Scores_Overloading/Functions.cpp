/*
 - Patrick Tate
 - CSCI 1411-004
 - Lab 13
 - Description: This program defines a class called Scores that has private member variables to hold a students name and 3 quiz scores. In the main.cpp an array of two Score objects is created, and the user is prompted to enter each students name followed by their 3 quiz scores, quiz scores are out of 100, the program then displays each student's test scores and their average. The << operator is overloaded so a Scores object can be displayed with cout. A bubble sort function is added that sorts the array of Scores objects by name.
 - Lab Partner: Prin
 - Status: Program successfully compiles and runs
 */

#include "Functions.h"

//overload << operator for Scores objects
ostream& operator <<(ostream& out, Scores &tempScores)
{
    out << "Student Name: " << tempScores.getName() << endl;
    out << "Score quiz 1: " << tempScores.getQuiz1() << endl;
    out << "Score quiz 2: " << tempScores.getQuiz2()<< endl;
    out << "Score quiz 3: " << tempScores.getQuiz3()<< endl;
    out << "Aveage quiz score: " << tempScores.getAverage() << endl << endl; 
    return out;
}
 
//sort array based on student's name
void bubbleSort(Scores scores[], int size){
    
    int maxElement, index;//variables to find biggest element in array and its index
    Scores tempScores;//temp Scores object to hold sorted value
    
    for (maxElement = size - 1; maxElement > 0; maxElement--) {
        for (index = 0; index < maxElement; index++) {
            if (scores[index].getName() > scores[index + 1].getName()) {
                tempScores = scores[index];
                scores[index] = scores[index + 1];
                scores[index + 1] = tempScores;
            }//if
        }//for
    }//for    
}
