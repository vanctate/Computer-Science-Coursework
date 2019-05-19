/*
 - Patrick Tate
 - HW03
 - CSCI 2312
 - Program written using Xcode on MacOS
 - Program Status: this program runs and compiles on the csegrid
 */

#include "watervehicle.h"
#include <iostream>

//default constructor
WaterVehicle::WaterVehicle(){
    int length = 0;
    std::string name = "";
    int hits = 0;
    bool sunk = false;
    int startRow = -1;
    int startCol = -1;
    char orientation = '!';
    bool placed = false;
}

//custom constructor
WaterVehicle::WaterVehicle(std::string _name, int _length){
    length = _length;
    name = _name;
    int hits = 0;
    bool sunk = false;
    int startRow = -1;
    int startCol = -1;
    char orientation = '!';
    bool placed = false;
}

//obtain starting location, orientation, and direction from user
//accounts for negative or out of bounds values in the user grid
void WaterVehicle::obtainInfo(int ar[10][10]){
    
    do {
        int sRow;
        char orientation;//vertical or horizontal
        char sCol;
        std::cout << "Enter placement for " << getName() << ", which takes up " << getLength() << " spaces.\n";
        do {
            std::cout << "Enter the starting row (1-10) for " << getName() << ".\n";
            std::cin  >> sRow;
            sRow = sRow - 1;//for array notation
            if (sRow < 0) {
                std::cout << "Please enter a positive number between 1 - 10.\n";
            }
            if (sRow > 9) {
                std::cout << "Please enter a number between 1 - 10.\n";
            }
        } while ((sRow < 0) || (sRow > 9));
        setStartRow(sRow);
        do {
            std::cout << "Enter the starting column (A - J) for " << getName() << ".\n";
            std::cin  >> sCol;
            sCol = toupper(sCol);
            sCol = sCol - 65;//for array notation
            if ((sCol < 0) || (sCol > 10)) {
                std::cout << "Please enter a column between A - J.\n";
            }
        } while ((sCol < 0) || (sCol > 9));
        setStartCol(sCol);
        std::cout << "Enter " << getName() << "'s placement orientation.\n";
        std::cout << "'v' for vertical, 'h' for horizontal.\n";
        std::cout << "Ships placed horizontally fill spaces to their right.\n";
        std::cout << "Ships placed vertically automatically fill spaces downward.\n";
        std::cin  >> orientation;
        orientation = tolower(orientation);//in case they entered a capital letter
        setOrientation(orientation);
        checkSpace();
        checkOccupied(ar);
    } while ((!getSpace()) || (! getOccupied()));
}

//first make sure there is space for the ship length based on staring row/column
bool WaterVehicle::checkSpace(){
    bool space = false;
    
    //orientation = horizontal
    if (getOrientation() == 'h') {
        if ((getSCol() + getLength()) > 10) {
            std::cout << "There is not enough space for a " << getName() << " in that position.\n";
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
            std::cout << "There is not enough space for a " << getName() << " in that direction.\n";
            setSpace(space);
        }//if not enoughs pace
        else{
            space = true;
            setSpace(space);
        }
    }//if orientation = vertical
    
    return space;
}

//after checking if ship fits in space, check to see if area is occupied
bool WaterVehicle::checkOccupied(int (*ar)[10]){
    bool placed = true;
    
    //orientation = horizontal
    if (getOrientation() == 'h') {
        for (int i = 0; i < getLength(); i++) {
            if (ar[getSRow()][getSCol() + i] == 1) {
                placed = false;
            }//if occupied
        }//for
    }//if horizontal
    
    //orientation = vertical
    if (getOrientation() == 'v') {
        for (int i = 0; i < getLength(); i++) {
            if (ar[getSRow() + i][getSCol()] == 1) {
                placed = false;
            }//if occupied
        }//for
    }//if vertical
    
    //send message to user if area is occupied
    if (placed == false) {
        std::cout << "That space is already occupied, please select a new location.\n";
    }
    setOccupied(placed);
    return placed;
}

//inserts the ship length/orientation into the user's grid
void WaterVehicle::placeShip(int ar[10][10]){
    if ((getSpace()) && (getOccupied())) {
        
        //orientation = vertical
        if (getOrientation() == 'v') {
            for (int i = 0; i < length; i++) {
                ar[getSRow() + i][getSCol()] = 1;
            }//for
        }//if
        
        //orientation = horizontal
        else if (getOrientation() == 'h'){
            for (int i = 0; i < length; i++) {
                ar[getSRow()][getSCol() + i] = 1;
            }//for
        }//if
    }// space and not occupied
    setPlaced(true);
}

//checks how many times object was hit, and if it was sunk
int WaterVehicle::checkHits(int userGrid[10][10], int torpedoGrid[10][10]){
    int totalHits = 0;//for keeping track of a players total score
    
    //horizontal
    if (this->getOrientation() == 'h') {
        for (int i = 0; i < this->length; i++) {
            if ((userGrid[this->getSRow()][this->getSCol()+i] == 1) && (torpedoGrid[this->getSRow()][this->getSCol() +i]) == 1) {
                totalHits++;
                this->setHits(totalHits);
                if (this->getHits() == this->getLength()) {
                    this->setSunk(true);
                }//if ship is sunk
            }//if
        }//for
    }// if horizontal
    
    //vertical
    if (this->getOrientation() == 'v') {
        for (int i = 0; i < this->length; i++) {
            if ((userGrid[this->getSRow()+i][this->getSCol()] == 1) && (torpedoGrid[this->getSRow()+i][this->getSCol()] == 1)) {
                totalHits++;
                this->setHits(totalHits);
                if (this->getHits() == this->getLength()) {
                    this->setSunk(true);
                }//if ship is sunk
            }//if
        }//for
    }//if vertical
    return totalHits;
}

//obtain info from user about where to place ship
//once determined ship is in allowable position, the ship is placed on the user grid
void WaterVehicle::fillGrid(int ar[10][10]){
    obtainInfo(ar);
    placeShip(ar);
}

//overload the cout object
std::ostream& operator<<(std::ostream& out, WaterVehicle& obj){
    
    out << "Ship name: " << obj.getName() << std::endl;
    out << "Ship length: " << obj.getLength() << std::endl;
    out << "Starting row: " << obj.getSRow() + 1 << std::endl;
    out << "Starting column: " << obj.getSCol() + 1 << std::endl;
    if (obj.getOrientation() == 'h') {
        out << "Ship orientation: horizontal.\n";
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
