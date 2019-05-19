/*
 - Patrick Tate
 - HW05
 - CSCI 2312-002
 - Program written using Xcode on MacOS
 - Program Status: this program runs and compiles on the csegrid
 */
#include <string>
#include <iostream>
using namespace std;

//function runs if read in age value is not a valid int
//gives the user the option to either exit program or manually enter via keyboard
//checks to ensure user only enters a choice 1 or 2
//ensures a manually entered age is a positive int
//returns the correct age value
int checkAge(string animalType);

//function runs if read in weight value is not a valid int
//gives the user the option to either exit program or manually enter via keyboard
//checks to ensure user only enters a choice 1 or 2
//ensures a manually entered weight is a positive int
//returns the correct weight value
int checkWeight(string animalType);

//function runs if read in height value is not a valid int
//gives the user the option to either exit program or manually enter via keyboard
//checks to ensure user only enters a choice 1 or 2
//ensures a manually entered height is a positive int
//returns the correct height value
int checkHeight(string animalType);

//function runs if read in boolean value is not either TRUE or FALSE
//gives the user the option to either exit program or manually enter via keyboard
//checks to ensure user only enters a choice 1 or 2
//ensures a manually entered bool is all caps TRUE or FALSE
//returns the correct boolean value
bool checkBool(string animalType, string var);
