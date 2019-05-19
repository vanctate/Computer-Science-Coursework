/*
 - Patrick Tate
 - CSCI 1410-002
 - Programming Assignment 3
 - Status: program successfully compiles and runs
 - Developed using XCode on MacOS
 - This program uses two classes, a Dealer class and a Car class to read information from a file and store that information as a vector of Dealer objects, each which contain a dynamic array of Car objects. The user is prompted by a menu that repeats until the user selects 7 to exit. Option 1 reads in the data from the file and stores it in a vector. Option 2 displays all the Dealers to the user. Option 3 allows the user to choose a dealer by number, and then displays that Dealer's Car objects. Option 4 allows the user to to choose a Dealer by number and add a new Car object to that Dealer's dynamic array. Option 5 allows the user to choose a Dealer by number, and then that Dealer's Car objects are sorted by VIN in ascending order. Option 6 takes the vector of Dealers and sends each Dealer object and their Car objects to a new file. For the Dealer and Car class, the get and set functions are written inline during the class declartion in dealer.h, while the rest are defined in dealer.cpp. The functions used for options 1 - 6 are written in functions.h. The main.cpp implements all functions with a switch menu.
 */

#include <iostream>
#include "dealer.h"
#include "functions.h"
#include <vector>
#include <string>


using namespace std;

int main(){
    int userInput; //user entry to decide what option they would like
    
    vector <Dealer> dealersVector;//empty vector to hold data from dealers.txt
    
    do {           //using a do while loop to keep the program running until the user want it to end
        
        //basic menu display
        cout << "Welcome to Johnny Appleseed's car dealer emporium. Please select an option below.\n\n";
        cout << "Enter 1 to read dealers and cars from a file.\n";
        cout << "Enter 2 to display dealers.\n";
        cout << "Enter 3 to choose a dealer number, display cars.\n";
        cout << "Enter 4 to choose a dealer number, add a car.\n";
        cout << "Enter 5 to choose a dealer and sort cars by VIN.\n";
        cout << "Enter 6 to write dealers and cars to a file.\n";
        cout << "Enter 7 to exit.\n";
        cin  >> userInput;
        
        switch (userInput) {
            case 1 :
                //load vector with info from dealers.txt
                loadVector(dealersVector);
                break;
                
            case 2 :
                //display dealers
                showDealers(dealersVector);
                break;
                
            case 3 :
                //pick a dealer and display their cars
                displayCars(dealersVector);
                break;
                
            case 4 :
                //add a car to a specific dealer
                addCar(dealersVector);
                break;
                
            case 5 :
                //sort cars by VIN in ascending order
                bubbleSort(dealersVector);
                break;
                
            case 6 :
                //send vector of Dealers to new file
                sendFileout(dealersVector);
                break;
                
            case 7 :
                return 0;//exit program
                break;
                
            default :
                cout << "Invalid entry, please enter a valid value\n" << endl; //catch bad input from user
                break;
        }//switch
        
    } while (userInput != 7);
    
    return 0;
}
