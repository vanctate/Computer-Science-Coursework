/*
 - Patrick Tate
 - Final Project
 - CSCI 2312
 - Program written using Xcode on MacOS
 - Program Status: this program runs and compiles on the csegrid
 */

#include "Watervehicle.h"
#include <iostream>
#include "Computer.h"

//default constructor
WaterVehicle::WaterVehicle(){
    length = -1;
    name = "";
    hits = 0;
    sunk = false;
    startRow = -1;
    startCol = -1;
    orientation = '!';
    placed = false;
    occupied = true;
    space = false;
    message = true;
}

//custom constructor
WaterVehicle::WaterVehicle(std::string _name, int _length){
    length = _length;
    name = _name;
    hits = 0;
    sunk = false;
    startRow = -1;
    startCol = -1;
    orientation = '!';
    placed = false;
    occupied = false;
    space = false;
    message = true;
}

//custom constructor
WaterVehicle::WaterVehicle(std::string _name, int _length, int _sRow, int _sCol, char _orientation){
    name = _name;
    length = _length;
    startRow = _sRow;
    startCol = _sCol;
    orientation = _orientation;
    
    //length = -1;
    hits = 0;
    sunk = false;
    placed = false;
    occupied = false;
    space = false;
    message = true;
}

//ensure ship doesn't run out of array bounds
//returns true if there is space, false if there isn't
bool WaterVehicle::checkSpace(){
    bool space = false;
    
    //orientation = horizontal
    if (getOrientation() == 'h') {
        if ((getSCol() + getLength()) > 10) {
            setSpace(space);
        }//if not enough space
        else{
            space = true;
            setSpace(space);
        }
    }//if orientation = horizontal
    
    //orientation = vertical
    else if (getOrientation() == 'v'){
        if ((getSRow() + length) > 10) {
            setSpace(space);
        }//if not enoughs pace
        else{
            space = true;
            setSpace(space);
        }
    }//if orientation = vertical
    
    return space;
}

//overload the cout object to display the ship's info
std::ostream& operator<<(std::ostream& out, WaterVehicle& obj){
    char temp = obj.getSCol() + 65;//since columns are written by letter
    
    out << "Ship name: " << obj.getName() << std::endl;
    out << "Ship length: " << obj.getLength() << std::endl;
    out << "Starting row: " << obj.getSRow() + 1 << std::endl;
    out << "Starting column: " << temp << std::endl;
    if (obj.getOrientation() == 'h') {
        out << "Ship orientation: horizontal\n";
        out << "Total Hits Received: " << obj.getHits() << std::endl;
        if (obj.getHits() == obj.getLength()) {
            out << "Sunk: yes\n";
        }
        else if (obj.getHits() != obj.getLength()){
            out << "Sunk: no\n";
        }
    }//if
    else if (obj.getOrientation() == 'v'){
        out << "Ship orientation: vertical\n";
        out << "Total Hits Received: " << obj.getHits() << std::endl;
        if (obj.getHits() == obj.getLength()) {
            out << "Sunk: yes\n";
        }
        else if (obj.getHits() != obj.getLength()){
            out << "Sunk: no\n";
        }
    }//
    return out;
}

//generate random orientation for Computer class ships
void WaterVehicle::determineOrientation()
{
    //generate random number to determine orientation, 0 = h, 1 = v
    int randOrientation = (int)rand()%2;//random number between 0-1
    
    if (randOrientation == 0) {
        setOrientation('h');
    }
    else if (randOrientation == 1)
        setOrientation('v');
}

//generate random starting position for Computer class ships
void WaterVehicle::determineStartPos()
{
    int randRow = rand()%10;//random row 0-9
    int randCol = rand()%10;//random column 0-9
    
    setStartRow(randRow);
    setStartCol(randCol);
}
