/*
 - Patrick Tate
 - HW05
 - CSCI 2312-002
 - Program written using Xcode on MacOS
 - Program Status: this program runs and compiles on the csegrid
 */

#include "functions.h"

//function runs if read in age value is not a valid int
//gives the user the option to either exit program or manually enter via keyboard
//checks to ensure user only enters a choice 1 or 2
//ensures a manually entered age is a positive int
//returns the correct age value
int checkAge(string animalType)
{
    int choice;
    int age;
    cout << "There was a problem with your " << animalType << " file.\n";
    cout << "Age is not an int value.\n";
    cout << "Would you like to quit program and fix the file, or manually enter a value?\n";
    cout << "Enter 1 to quit program, enter 2 to manually enter an int value.\n";
    cin >> choice;
    while ((choice < 1) || (choice > 2)) {
        cout << "Please enter a 1 or 2.\n";
        cin  >> choice;
        while (cin.fail()) {
            cin.clear();
            cin.ignore();
            cout << "Please enter a number and not a character.\n";
            cin  >> choice;
        }//while choice != int
    }//while choice < 1 or choice > 2
    
    if (choice == 1) {
        exit(0);
    }
    else if (choice == 2){
        cout << "Please enter the int value for the age.\n";
        cin  >> age;
        while (cin.fail()) {
            cin.clear();
            cin.ignore();
            cout << "Please enter a number and not a character.\n";
            cin  >> age;
        }//while choice != int
    }
    age = abs(age);//ensure age isn't negative
    return age;
}

//function runs if read in weight value is not a valid int
//gives the user the option to either exit program or manually enter via keyboard
//checks to ensure user only enters a choice 1 or 2
//ensures a manually entered weight is a positive int
//returns the correct weight value
int checkWeight(string animalType)
{
    int choice;
    int weight;
    cout << "There was a problem with your " << animalType << " file.\n";
    cout << "Weight is not an int value.\n";
    cout << "Would you like to quit program and fix the file, or manually enter a value?\n";
    cout << "Enter 1 to quit program, enter 2 to manually enter an int value.\n";
    cin >> choice;
    while ((choice < 1) || (choice > 2)) {
        cout << "Please enter a 1 or 2.\n";
        cin  >> choice;
        while (cin.fail()) {
            cin.clear();
            cin.ignore();
            cout << "Please enter a number and not a character.\n";
            cin  >> choice;
        }//while choice != int
    }//while choice < 1 or choice > 2
    
    if (choice == 1) {
        exit(0);
    }
    else if (choice == 2){
        cout << "Please enter the int value for the weight.\n";
        cin  >> weight;
        while (cin.fail()) {
            cin.clear();
            cin.ignore();
            cout << "Please enter a number and not a character.\n";
            cin  >> weight;
        }//while choice != int
    }
    weight = abs(weight);
    return weight;
}

//function runs if read in height value is not a valid int
//gives the user the option to either exit program or manually enter via keyboard
//checks to ensure user only enters a choice 1 or 2
//ensures a manually entered height is a positive int
//returns the correct height value
int checkHeight(string animalType)
{
    int choice;
    int height;
    cout << "There was a problem with your " << animalType << " file.\n";
    cout << "Height is not an int value.\n";
    cout << "Would you like to quit program and fix the file, or manually enter a value?\n";
    cout << "Enter 1 to quit program, enter 2 to manually enter an int value.\n";
    cin >> choice;
    while ((choice < 1) || (choice > 2)) {
        cout << "Please enter a 1 or 2.\n";
        cin  >> choice;
        while (cin.fail()) {
            cin.clear();
            cin.ignore();
            cout << "Please enter a number and not a character.\n";
            cin  >> choice;
        }//while choice != int
    }//while choice < 1 or choice > 2
    
    if (choice == 1) {
        exit(0);
    }
    else if (choice == 2){
        cout << "Please enter the int value for the height.\n";
        cin  >> height;
        while (cin.fail()) {
            cin.clear();
            cin.ignore();
            cout << "Please enter a number and not a character.\n";
            cin  >> height;
        }//while choice != int
    }//if choice == 2
    height = abs(height);//ensure height isn't negative
    return height;
}

//function runs if read in boolean value is not either TRUE or FALSE
//gives the user the option to either exit program or manually enter via keyboard
//checks to ensure user only enters a choice 1 or 2
//ensures a manually entered bool is all caps TRUE or FALSE
//returns the correct boolean value
bool checkBool(string animalType, string var)
{
    int choice;
    string freshwater;
    bool freshWaterVal;
    
    cout << "There was a problem with your " << animalType << " file.\n";
    cout << var << " is not a valid bool value.\n";
    cout << "Would you like to quit program and fix the file, or manually enter a value?\n";
    cout << "Enter 1 to quit program, enter 2 to manually enter an int value.\n";
    cin >> choice;
    while ((choice < 1) || (choice > 2)) {
        cout << "Please enter a 1 or 2.\n";
        cin  >> choice;
        while (cin.fail()) {
            cin.clear();
            cin.ignore();
            cout << "Please enter a number and not a character.\n";
            cin  >> choice;
        }//while choice != int
    }//while choice < 1 or choice > 2
    
    if (choice == 1) {
        exit(0);
    }
    else if (choice == 2){
        cout << "Please enter the bool value for " << var << "." << endl;
        cout << "Enter all caps TRUE or all caps FALSE.\n";
        cin  >> freshwater;
        while ((freshwater != "TRUE") && (freshwater != "FALSE")) {
            cout << "Please enter TRUE or FALSE.\n";
            cin  >> freshwater;
        }//while 
        if (freshwater == "TRUE") {
            freshWaterVal = true;
        }
        else if (freshwater == "FALSE"){
            freshWaterVal = false;
        }
    }//if choice == 2
    return freshWaterVal;
}
