/*
 - Patrick Tate
 - HW03
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
    int length;//how many spaces ship takes up on grid
    int hits;//if hits == length, ship is sunk
    bool sunk;//set to true if shit is sunk
    int startRow;
    int startCol;
    char orientation;//either vertical or horizontal
    bool space;//is there space for the object?
    bool occupied;//is the grid area already occupied?
    bool placed;//false until ship is successfully placed on grid
public:
    WaterVehicle();
    WaterVehicle(std::string _name, int _length);
    void setName(std::string _name);
    void setLength(int _length){length = _length;}
    void setHits(int _hits){hits = _hits;}
    void setSunk(bool _sunk){sunk = _sunk;}
    void setStartRow(int _sRow){startRow = _sRow;}
    void setStartCol(int _sCol){startCol = _sCol;}
    void setOrientation(char _orientation){orientation = _orientation;}
    void setSpace(bool _space){space = _space;}
    void setOccupied(bool _occupied){occupied = _occupied;}
    void setPlaced(bool _placed){placed = _placed;}
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
    
    void placeShip(int ar[10][10]);//ship is placed on user's grid
    bool checkSpace();//boundary checking
    bool checkOccupied(int ar[10][10]);//check if user's grid already has ship in that location
    void obtainInfo(int ar[10][10]);//get ship placement info from user
    int checkHits(int userGrid[10][10], int torpedoGrid[10][10]);//determine how many times ship was hit
    void fillGrid(int ar[10][10]);//obtain info and place ship
    
    friend std::ostream& operator<<(std::ostream& out, WaterVehicle& obj);
};

#endif /* watervehicle_h */


