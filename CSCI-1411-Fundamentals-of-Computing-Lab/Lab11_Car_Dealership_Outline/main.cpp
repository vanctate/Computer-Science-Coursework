//  Patrick Tate
//  1411-004
//  Programming Assignment 3 Outline
//  Status: not running, just an outline

#include <iostream>
#include "dealer.h"
using namespace std;

int main() {
    char userInput; //user entry to decide what option they would like
    
    do {           //using a do while loop to keep the program running until the user want it to end
        
        //basic menu display
        cout << "Welcome to car dealership. Please selection an option below.\n\n";
        cout << "Enter A to read dealers and cars from a file.\n";
        cout << "Enter B to display dealers.\n";
        cout << "Enter C to choose a dealer number, display cars.\n";
        cout << "Enter D to choose a dealer number, add a car.\n";
        cout << "Enter E to choose a dealer and sort cars by VIN.\n";
        cout << "Enter F to write dealers and cars to a file.\n";
        cout << "Enter G to exit.\n";
        cin  >> userInput;
        userInput = toupper(userInput);//convert userInput to capital letter for easier comparisons
        
        switch (userInput) {
            case 'A' :
                //function to read in dealer and car info from file
                break;
                
            case 'B' :
                //function to display dealers
                break;
                
            case 'C' :
                //function to choose a dealer and display cars
                break;
                
            case 'D' :
                //function to choose a dealer and add a new car
                break;
                
            case 'E' :
               //function to choose a dealer and sort cars by VIN
                break;
                
            case 'F' :
                //function to write dealers and cars to a file
                break;
                
            case 'G' :
                return 0;//exit program
                break;
                
            default :
                cout << "Invalid entry, please enter a valid value\n" << endl; //catch bad input from user
        }//switch
        
    } while (userInput != 'G');
    
    return 0;
}
