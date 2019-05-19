/*
 - Patrick Tate
 - Final Project
 - CSCI 2312
 - Program written using Xcode on MacOS
 - Program Status: this program runs and compiles on the csegrid
 */

#include "Player.h"
#ifndef User_h
#define User_h
class User : public Player
{
public:
    User();
    void displayYourGrid();//display user's ship grid
    
    //reads in ship name, starting position, and orientation
    //sets the user's Watervehicle ship values to those values as well
    void readInShips();
    
    //ship is placed in the grid if there is space and no other ship in that position
    void insertShip(WaterVehicle &obj);
    
    //inserts all 5 ships
    void insertShips();
    
    //User enters coordinates for attack
    //User is prevented from entering out of bounds values for attack
    //returns true if hit, false if miss
    bool generateAttack(class Computer &comp);
    
    //checks all of User's ships to see if they were hit/sunk and changes Computer's score accordingly
    void checkAllHits(class Computer &comp);
    
    //ensures there isn't already a ship in that grid position
    void areaOccupied(WaterVehicle &obj);
    
    //if there is bad info from the input file, the user can have ship placed randomly
    void placeShipRandomly(WaterVehicle &obj);
    
    //checks to see if position where ship is to be placed is already occupied by another ship
    bool checkOccupied(WaterVehicle &obj);
    
    //if input values from file read in are garbage, the user can exit or place ship randomly
    //counter's value determines which ship had the bad input
    void badInput(int counter);
};
#endif /* User_h */
