/*
 - Patrick Tate
 - HW02
 - CSCI 2312
 - Program written using Xcode on MacOS
 - Program Status: this program runs and compiles on the csegrid
 */

#include <iostream>
#include "Matrix.h"
#include <ctime>
#include <cstdlib>
using namespace std;

int main() {
    srand (time(NULL));//seed the random numbers
    
    char playAgain;
    
    do{
    cout << "Welcome to the grid comparison program.\n\n";
    
    //create two objects and fill their grids with 0's
    Matrix object1, object2;
    cout << "Enter your information for grid 1.\n";
    object1.fillGrids(object1);
    cout << endl;
    cout << "Enter your information for grid 2.\n";
    object2.fillGrids(object2);
    
    //display both grids
    cout << "Grid 1 before adding random 1's:\n";
    object1.displayGrid(object1);
    cout << endl;
    cout << "Grid 2 before adding random 1's:\n";
    object2.displayGrid(object2);

    cout << endl;
    
    //populate 1/3 of both grids with 1's in random locations
    object1.addOnes(object1);
    object2.addOnes(object2);
    
    //display both grids with their randomly placed 1's
    cout << "Grid 1 after adding random 1's:\n";
    object1.displayGrid(object1);
    cout << endl;
    cout << "Grid 2 after adding random 1's:\n";
    object2.displayGrid(object2);
    
    //display comparison results
    cout << endl << "The matrix comparison is:" << endl;
    object1.compareVec(object1, object2);
    cout << endl << "Would you like to play again?\n";
    cout << "Enter 'y' or 'Y' to play again. Press any other key to exit.\n";
    cin  >> playAgain;
    playAgain = tolower(playAgain);
        
    }while(playAgain == 'y');
    
    return 0;
}
