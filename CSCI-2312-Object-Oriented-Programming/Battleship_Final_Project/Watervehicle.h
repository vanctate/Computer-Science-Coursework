/*
 - Patrick Tate
 - Final Project
 - CSCI 2312
 - Program written using Xcode on MacOS
 - Program Status: this program runs and compiles on the csegrid
 */

#include <string>
#include <iostream>
#ifndef watervehicle_h
#define watervehicle_h

class WaterVehicle
{
private:
    std::string name;
    int length;//how many spaces the ship takes up on grid
    int hits;//if hits == length, ship is sunk
    bool sunk;//set to true if shit is sunk
    int startRow;//starting row 1-10 for user but 0-9 for array notation
    int startCol;//starting column A-J for user but 0-9 for array notation
    char orientation;//either vertical 'v' or horizontal 'h'
    bool space;//is there space for the object?
    bool occupied;//is the grid area already occupied?
    bool placed;//false until ship is successfully placed on grid
    bool message;//sending a message when ship is sunk
public:
    WaterVehicle();
    WaterVehicle(std::string _name, int _length);
    WaterVehicle(std::string _name, int _length, int _sRow, int _sCol, char _orientation);
    //set
    void setName(std::string _name){name = _name;}
    void setLength(int _length){length = _length;}
    void setHits(int _hits){hits = _hits;}
    void setSunk(bool _sunk){sunk = _sunk;}
    void setStartRow(int _sRow){startRow = _sRow;}
    void setStartCol(int _sCol){startCol = _sCol;}
    void setOrientation(char _orientation){orientation = _orientation;}
    void setSpace(bool _space){space = _space;}
    void setOccupied(bool _occupied){occupied = _occupied;}
    void setPlaced(bool _placed){placed = _placed;}
    //get
    std::string getName(){return name;}
    int getLength(){return length;}
    int getHits(){return hits;}
    bool getSunk(){return sunk;}
    int getSRow(){return startRow;}
    int getSCol(){return startCol;}
    char getOrientation(){return orientation;}
    bool getSpace(){return space;}
    bool getOccupied(){return occupied;}
    bool getPlaced(){return placed;}
    bool getMessage(){return message;}
    void setMessage(bool _message){message = _message;}
    //boundary checking
    bool checkSpace();
    //printing ship's info
    friend std::ostream& operator<<(std::ostream& out, WaterVehicle& obj);
    //generate random number to determine Computer's ships orientation
    void determineOrientation();
    //generate random startRow/startCol for Computer's ships
    void determineStartPos();
    //ensures ship isn't overlapping anywhere with another ship
    bool checkOccupied(class Computer obj);
};
#endif /* watervehicle_h */
