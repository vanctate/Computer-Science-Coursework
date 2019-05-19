/*
 - Patrick Tate
 - CSCI 1411-004
 - Lab 09
 - Description: This program uses an integer pointer to create a dynamic array of integer value test scores. The user is prompted to enter how many tests they have, an array of that size is created, and the user is then prompted to enter each test score. One function returns the average test score, while another function sorts the test scores in ascending order. The user is prevented from entering a negative test score. If a user enters a negative test score the program quits and the user must run the program again.
 - Lab Partner: Prin
 - Status: successfully compiles and runs
 */

#include <iostream>
using namespace std;

double calcAverage(int *, int size);//calculates average test scores
void sortTests(int *, int size);//selection sort tests in ascending order
void validEntry(int *, int size);//get test scores from user and ensure they are all positive

int main() {
    
    int *tests = nullptr;//used to create dynamic array
    int numTests;//for user to enter how many tests they have in array
    double average;
    
    cout << "Enter how many tests you have.\n";
    cin  >> numTests;
    
    tests = new int[numTests];//create dynamic array based on how many tests the user has
    
    //get each test score and store it in the array, exit program if user enters a negative test score
    validEntry(tests, numTests);
    
    //show test scores
    for (int j = 0; j < numTests; j++) {
        cout << "Test " << j+1 << "  is " << *(tests + j) << ".\n";
    }
    
    //calculate and display the average test score
    average = calcAverage(tests, numTests);
    cout << "Your average test score is " << average << endl;
    
    //sort tests in ascending order by score and display
    cout << "In ascending order the tests are:\n";
    sortTests(tests, numTests);
    for (int i = 0; i < numTests; i++) {
        cout << "Test  " << i+1 << " is " << *(tests + i) << endl;
    }
    
    delete [] tests;//free memory up after program is executed
    tests = nullptr;
    
    return 0;
}

double calcAverage(int *tests, int size)
{
    double total = 0.0, average;
    for (int i = 0; i < size; i++) {
        total += *(tests + i);
    }
    average = (total/size);
    return average;
}

//selection sort tests in ascending order
void sortTests(int *tests, int size)
{
    int startScan, minIndex, minValue;
    
    for (startScan = 0; startScan < (size - 1); startScan++) {
        minIndex = startScan;
        minValue = *(tests + startScan);
        for (int index = startScan + 1; index < size; index++) {
            if (*(tests + index) < minValue) {
                minValue = *(tests + index);
                minIndex = index;
            }//if
        }//for
        *(tests + minIndex) = *(tests + startScan);
        *(tests + startScan) = minValue;
    }//for
}

//ensure the user enters positive test scors, exits program is user enters a negative test score
void validEntry(int *tests, int size)
{
    
    for (int i = 0; i < size; i++) {
        cout << "Enter the value for test " << i+1 << "." << endl;
        cin  >> *(tests + i);
        if (*(tests + i) < 0) {
            cout << "Please enter only positive numbers.\n";
            cout << "Restart the program and try again.\n";
            exit (0);
        }//if
    }//for
}







