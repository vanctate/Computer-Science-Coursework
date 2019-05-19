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

Monkey::Monkey()
{
    wild = false;
    home = "";
    endangered = false;
    age = -1;
}

//read in values from file and sets Monkey's private variables to those values
void Monkey::readInfo()
{
    //temp variables for file info
    string emptyLine, tempName, tempColor, tempAge, tempWild, tempHome, tempEndangered;
    //variables to check if age/weight values are not int values
    char isAge;
    string animalType = "Monkey", wild = "wild", isEndangered = "endangered";
    
    fstream inFile;//load input from file
    inFile.open("Monkey.csv");
    
    //obtain info from file and store in temp variables
    getline(inFile, emptyLine);
    getline(inFile, tempName, ',');
    getline(inFile, tempColor, ',');
    getline(inFile, tempAge, ',');
    getline(inFile, tempWild, ',');
    getline(inFile, tempHome, ',');
    getline(inFile, tempEndangered);
    
    inFile.close();
    isAge = tempAge[0];
    
    try//ensure age is valid int value
    {
        if (!isdigit(isAge)) {
            throw animalType;
        }//if age != int value
    }//try
    catch(string e)
    {
        int validAge = checkAge(e);
        setAge(validAge);
    }//catch
    
    try//ensure wild boolean value is valid
    {
        if ((tempWild == "TRUE") || (tempWild == "FALSE")) {
        }
        else {
            throw -1;
        }
    }//try
    catch(int e)
    {
        bool validWild = checkBool("Monkey", wild);
        setWild(validWild);
    }
    
    try
    {
        if ((tempEndangered == "TRUE") || (tempEndangered == "FALSE")) {
        }
        else {
            throw 'v';
        }
    }//try
    catch(char e)
    {
        bool validEndangered = checkBool("Monkey", isEndangered);
        setEndangered(validEndangered);
    }
    
    
    
    //convert age string to int
    stringstream newAge(tempAge);
    int monkeyAge = 0;
    newAge >> monkeyAge;
    
    //set Monkey's private variables to file values
    setName(tempName);
    setColor(tempColor);
    setHome(tempHome);
    if (isdigit(isAge)) {
        setAge(monkeyAge);
    }
    
    //set wild
    //only need to test for true since wild set to false in default constructor
    if (tempWild == "TRUE") {
        setWild(true);
    }
    
    //set endangered
    //only need to test for true since endangered set to false in default constructor
    if (tempEndangered == "TRUE") {
        setEndangered(true);
    }
    
}

//displays Monkey's private variable values
void Monkey::printInfo()
{
    //temp bool values for printing user friendly version
    bool tempWild = getWild();
    bool tempEndangered = getEndangered();
    
    cout << "Monkey Information:\n";
    cout << "Name: " << getName() << endl;
    cout << "Color: " << getColor() << endl;
    cout << "Age: " << getAge() << endl;
    cout << "Wild: " << convertBool(tempWild) << endl;
    cout << "Home: " << getHome() << endl;
    cout << "Endangered: " << convertBool(tempEndangered) << endl;
    
}

//converts bool values to TRUE/FALSE for user friendly reading
string Monkey::convertBool(bool _value)
{
    if (_value)
        return "TRUE";
    else
        return "FALSE";
}

//switches the bool value endangered to the oppositve bool value
void Monkey::changeEndangered()
{
    if (endangered)
        setEndangered(false);
    else
        setEndangered(true);
}
