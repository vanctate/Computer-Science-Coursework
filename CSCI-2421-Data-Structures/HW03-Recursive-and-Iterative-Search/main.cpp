/*
 - Patrick Tate
 - HW03
 - CSCI 2421-001
 - Program written using Xcode on MacOS
 - Program Status: this program runs and compiles on the csegrid
 */

#include "vehicle.h"
#include "functions.h"
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {

    vector<Vehicle> vehicleVec;
    int choice = 0;//switch case variable
    
    //variables to specify type for overloaded functions
    //specifies whether to sort by make, model, or year
    //specifies whether to search by make or model since both are string values
    int make = 2, model = 3, year = 4;
   
    do {
        
        loadVec(vehicleVec);//load vector with Vehicle objects in unsorted order
        
        cout << "This program demonstrates recursive and iterative binary search functions.\n";
        cout << "Please select an option below.\n";
        cout << "Enter 1 to display vehicles in unsorted order.\n";
        cout << "Enter 2 to recursive search for a vehicle by make.\n";
        cout << "Enter 3 to recursive search for a vehicle by model.\n";
        cout << "Enter 4 to recursive search for a vehicle by year.\n";
        cout << "Enter 5 to iterative search for a vehicle by make.\n";
        cout << "Enter 6 to iterative search for a vehicle by model.\n";
        cout << "Enter 7 to iterative search for a vehicle by year.\n";
        cout << "Enter 8 to exit program.\n";
        cin  >> choice;
        
        switch (choice) {
            case 1:
                displayVec(vehicleVec);
                break;
            
            case 2:{
                string target;
                sortVec(vehicleVec, make);
                cout << "Enter the vehicle make you wish to recursively search for.\n";
                cin.ignore();
                getline(cin, target);
                int found = binSearchRec(vehicleVec, 0, vehicleVec.size() - 1, target, make);
                displaySearch(vehicleVec, make, found);
                break;
            }//case 2
                
            case 3:{
                string target;
                sortVec(vehicleVec, model);
                cout << "Enter the vehicle model you wish to recursively search for.\n";
                cin.ignore();
                getline(cin, target);
                int found = binSearchRec(vehicleVec, 0, vehicleVec.size() - 1, target, model);
                displaySearch(vehicleVec, model, found);
                break;
                
            }//case 3
                
            case 4:{
                sortVec(vehicleVec, year);
                int target;
                cout << "Enter the year you want to recursivley search for.\n";
                cin  >> target;
                int found = binSearchRec(vehicleVec, 0, vehicleVec.size() - 1, target);
                displaySearch(vehicleVec, year, found);
                break;
            }//case 4
                
            case 5:{
                sortVec(vehicleVec, make);
                string target;
                cout << "Enter the make you want to iteratively search for.\n";
                cin.ignore();
                getline(cin, target);
                int found = binSearchIter(vehicleVec, target, make);
                displaySearch(vehicleVec, make, found);
                break;
            }//case 5
            
            case 6:{
                sortVec(vehicleVec, model);
                string target;
                cout << "Enter the model you want to iteratively search for.\n";
                cin.ignore();
                getline(cin, target);
                int found = binSearchIter(vehicleVec, target, model);
                displaySearch(vehicleVec, model, found);
                break;
            }//case 6
                
            case 7:{
                sortVec(vehicleVec, year);
                int target;
                cout << "Enter the year you want to iteratively search for.\n";
                cin  >> target;
                int found = binSearchIter(vehicleVec, target);
                displaySearch(vehicleVec, year, found);
                break;
            }//case 7
                
            case 8:
                exit;
                break;
            default:
                cout << "Invalid entry, please enter a number between 1 - 8.\n";
                break;
        }
        vehicleVec.clear();
    } while (choice != 8);
    
    return 0;
}
