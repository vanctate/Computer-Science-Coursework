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

Lizard::Lizard()
{
    habitat = "";
    isProtected = false;
    weight = -1;
}

////read in values from file and sets Lizard's private var to those values
void Lizard::readInfo()
{
    //temp variables for file info
    string emptyLine, tempName, tempColor, tempHabitat, tempProtected, tempWeight;
    //variables to check if age/weight values are not int values
    char isWeight;
    string animalType = "Lizard", prot = "isProtected";
    
    fstream inFile;//load input from file
    inFile.open("Lizard.csv");
        
    //obtain info from file and store in temp variables
    getline(inFile, emptyLine);
    getline(inFile, tempName, ',');
    getline(inFile, tempColor, ',');
    getline(inFile, tempHabitat, ',');
    getline(inFile, tempProtected, ',');
    getline(inFile, tempWeight, ',');
        
    inFile.close();
    isWeight = tempWeight[0];
    
    try//ensure weight is valid int value
    {
        if (!isdigit(isWeight)) {
            throw -1;
        }//if weight != int value
    }
    catch(int e)
    {
        int validWeight = checkWeight(animalType);
        setWeight(validWeight);
    }//catch weight
    
    try//ensure predator bool value is either TRUE or FALSE
    {
        if ((tempProtected == "TRUE") || (tempProtected == "FALSE")) {
        }
        else {
            throw -1;
        }
    }//try
    catch(int e)
    {
        bool validProtected = checkBool("Lizard", prot);
        setProtected(validProtected);
    }//catch isProtected
    
    //convert string weight to int
    stringstream newWeight(tempWeight);
    int lizardWeight = 0;
    newWeight >> lizardWeight;
    
    //set Lizard's private variables to file values
    setName(tempName);
    setColor(tempColor);
    setHabitat(tempHabitat);
    if (isdigit(isWeight)) {
        setWeight(lizardWeight);
    }
    
    //only need to check true because protected already set to false
    if (tempProtected == "TRUE") {
        setProtected(true);
    }
    
}

//displays Lizard's private variable values
void Lizard::printInfo()
{
    bool tempProtected = getProtected();
    cout << "Lizard information:\n";
    cout << "Name: " << getName() << endl;
    cout << "Color: " << getColor() << endl;
    cout << "Habitat: " << getHabitat() << endl;
    cout << "Protected: " << convertBool(tempProtected) << endl;
    cout << "Weight: " << getWeight() << " (ounces)" << endl;
}

//converts bool values to TRUE/FALSE for user friendly reading
string Lizard::convertBool(bool _value)
{
    if (_value)
        return "TRUE";
    else
        return "FALSE";
}
