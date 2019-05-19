/*
 - Patrick Tate
 - Final Project
 - CSCI 2312
 - Program written using Xcode on MacOS
 - Program Status: this program runs and compiles on the csegrid
 */

#include <string>
#include "Watervehicle.h"

#ifndef Player_h
#define Player_h
class Player{
    
protected:
    std::string name;
    char yourGrid[10][10];//grid where your ships are placed
    char attackGrid[10][10];//grid that keeps track of your attacks as hits or misses
    int score;//a Player wins when their score is equal to 17
    //each Player's fleet consists of these 5 ships
    WaterVehicle carrier;
    WaterVehicle battleship;
    WaterVehicle cruiser;
    WaterVehicle submarine;
    WaterVehicle destroyer;
    
public:
    Player();
    //get
    std::string getName(){return name;}
    int getScore(){return score;}
    WaterVehicle getCarrier(){return carrier;}
    WaterVehicle getBattleship(){return battleship;}
    WaterVehicle getCruiser(){return cruiser;}
    WaterVehicle getSubmarine(){return submarine;}
    WaterVehicle getDestroyer(){return destroyer;}
    //accessing and changing your grids
    char* getYourGrid(int row, int col){return &yourGrid[row][col];}
    char* getAttackGrid(int row, int col){return &attackGrid[row][col];}
    
    //set
    void setName(std::string _name){name = _name;}
    void setScore(int _score){score = _score;}
    void setCarrier(WaterVehicle _carrier){carrier = _carrier;}
    void setBattleship(WaterVehicle _battleship){battleship = _battleship;}
    void setCruiser(WaterVehicle _cruiser){cruiser = _cruiser;}
    void setSubmarine(WaterVehicle _submarine){submarine = _submarine;}
    void setDestroyer(WaterVehicle _destroyer){destroyer = _destroyer;}
    
    void printAttackGrid();
   
    //for printing a Player's fleet and grid
    friend std::ostream& operator<<(std::ostream& out, Player& obj);
};
#endif /* Player_h */

