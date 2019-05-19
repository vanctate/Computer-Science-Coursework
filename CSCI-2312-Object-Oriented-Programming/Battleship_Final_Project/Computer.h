/*
 - Patrick Tate
 - Final Project
 - CSCI 2312
 - Program written using Xcode on MacOS
 - Program Status: this program runs and compiles on the csegrid
 */

#include "Player.h"
#include "User.h"
#ifndef Computer_h
#define Computer_h

class Computer : public Player
{
public:
    Computer();//instantiates 5 ships with their name and legnth
    
    //sets up and places a single ship
    void placeShip(WaterVehicle &obj);
    
    //checks to see if position where ship is to be placed is already occupied by another ship
    bool checkOccupied(WaterVehicle &obj);
    
    //once ship position is deemed legal (enough space and not occupied)
    //the computer's yourGrid is changed to reflect that ship's position
    void insertShip(WaterVehicle &obj);
    
    //places all of Computer's 5 Watervehicle objects into its yourGrid
    bool placeShips();
    
    //printing at the end of the game
    void printCompYourGrid();
    
    //generates a single attack on opponent using rand numbers for row/columns
    //ensures the same position isn't attacked more than once
    void generateAttack(User obj);
   
    //checks if Computer's ships were hit by the user and changes User's score accordingly
    void checkAllHits(User &user);
};
#endif /* Computer_h */

