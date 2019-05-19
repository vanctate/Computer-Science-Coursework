/*
 - Patrick Tate
 - HW05
 - CSCI 2312-002
 - Program written using Xcode on MacOS
 - Program Status: this program runs and compiles on the csegrid
 */

#include "animal.h"
#include "functions.h"
#include <fstream>
#include <iostream>
#include <sstream>
using namespace std;

Horse::Horse()
{
    maneColor = "";
    height = -1;
    age = -1;
}

////read in values from file and sets Horse's private var to those values
void Horse::readInfo()
{
    //temp variables for file info
    string emptyLine, tempName, tempColor, tempManeColor, tempAge, tempHeight;
    //variables to check if age/weight values are not int values
    char isAge, isHeight;
    string animalType = "Horse";
    
    fstream inFile;//load input from file
    inFile.open("Horse.csv");
    
    //obtain info from file and store in temp variables
    getline(inFile, emptyLine);
    getline(inFile, tempName, ',');
    getline(inFile, tempColor, ',');
    getline(inFile, tempManeColor, ',');
    getline(inFile, tempAge, ',');
    getline(inFile, tempHeight, ',');
   
    inFile.close();
    isAge = tempAge[0];
    isHeight = tempHeight[0];
    
    try
    {
    if (!isdigit(isAge)) {
            throw animalType;
        }//if age != int value
    }//try
    catch(string e)
    {
        int validAge = checkAge(e);
        setAge(validAge);
    }//catch age
    
    try
    {
    if (!isdigit(isHeight)) {
            throw -1;
        }//if age != int value
    }
    catch(int e)
    {
        int validHeight = checkHeight("Horse");
        setHeight(validHeight);
    }//catch height
    
    //convert string age to int
    stringstream newAge(tempAge);
    int horseAge = 0;
    newAge >> horseAge;
    
    //convert string height to int
    stringstream newHeight(tempHeight);
    int horseHeight = 0;
    newHeight >> horseHeight;
    
    //set Horse's private variables to values from file
    setName(tempName);
    setColor(tempColor);
    setManeColor(tempManeColor);
    if (isdigit(isHeight)) {
        setHeight(horseHeight);
    }
    if (isdigit(isAge)) {
        setAge(horseAge);
    }
}

//displays Horse's private variable values
void Horse::printInfo()
{
    cout << "Horse Information:\n";
    cout << "Name: " << getName() << endl;
    cout << "Color: " << getColor() << endl;
    cout << "Mane Color: " << getManeColor() << endl;
    cout << "Age: " << getAge() << " (years)" << endl;
    cout << "Height: " << getHeight() << " (hands)" << endl;
}
