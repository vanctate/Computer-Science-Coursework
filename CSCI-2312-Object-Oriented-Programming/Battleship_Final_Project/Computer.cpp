/*
 - Patrick Tate
 - Final Project
 - CSCI 2312
 - Program written using Xcode on MacOS
 - Program Status: this program runs and compiles on the csegrid
 */

#include "Computer.h"
#include <iostream>
using namespace std;

//instantiate 5 Watervehicle objects for the computer's fleet
Computer::Computer()
{
    name = "Computer";
    WaterVehicle carrier("Carrier", 5);
    setCarrier(carrier);
    WaterVehicle battleship("Battleship", 4);
    setBattleship(battleship);
    WaterVehicle cruiser("Cruiser", 3);
    setCruiser(cruiser);
    WaterVehicle submarine("Submarine", 3);
    setSubmarine(submarine);
    WaterVehicle destroyer("Destroyer", 2);
    setDestroyer(destroyer);
}

//randomly determines orientation, starting position
//while loop runs until there is space for that ship and the position isn't occupied by another ship
void Computer::placeShip(WaterVehicle &obj)
{
    do {
        obj.determineOrientation();
        obj.determineStartPos();
        obj.checkSpace();
        checkOccupied(obj);
    } while ((!obj.getSpace()) || (obj.getOccupied()));
}

//once the Watervehicle object is determined to be in legal position, it is inserted into the yourGrid
//'F' marks a ship that hasn't been hit yet, for example, a Destroyer ship is of length 2, so it
//takes up 2 spaces on the grid and will look like FF
void Computer::insertShip(WaterVehicle &obj)
{
    if (obj.getOrientation() == 'h') {
        for (int i = 0; i < obj.getLength(); i++) {
            *getYourGrid(obj.getSRow(), obj.getSCol() + i) = 'F';
        }//for
    }//if
    else if (obj.getOrientation() == 'v'){
        for (int i = 0; i < obj.getLength(); i++) {
            *getYourGrid(obj.getSRow() + i, obj.getSCol()) = 'F';
        }//for
    }//if
    obj.setPlaced(true);
}

//ensures that a ship's placement doesn't overlap at all with any other ship's location
//returns true if area isn't occupied, returns false if any section of placement is occupied
bool Computer::checkOccupied(WaterVehicle &obj)
{
    bool legal = true;
    
    //orientation = horizontal
    if (obj.getOrientation() == 'h') {
        for (int i = 0; i < obj.getLength(); i++) {
            if (*getYourGrid(obj.getSRow(), obj.getSCol() + i) == 'F') {
                obj.setOccupied(true);
                legal = false;
            }//if occupied
        }//for
    }//if horizontal
    
    //orientation = vertical
    if (obj.getOrientation() == 'v') {
        for (int i = 0; i < obj.getLength(); i++) {
            if (*getYourGrid(obj.getSRow() + i, obj.getSCol()) == 'F') {
                obj.setOccupied(true);
                legal = false;
            }//if occupied
        }//for
    }//if vertical
    if (legal) {
        obj.setOccupied(false);
    }
    return legal;
}

//places all 5 Watervehicle ships in random positions
bool Computer::placeShips()
{
    placeShip(carrier);
    insertShip(carrier);
   
    placeShip(battleship);
    insertShip(battleship);
   
    placeShip(cruiser);
    insertShip(cruiser);
   
    placeShip(submarine);
    insertShip(submarine);
    
    placeShip(destroyer);
    insertShip(destroyer);
    
    return true;
}

//printing computer's grid at the end
void Computer::printCompYourGrid()
{
    std::cout << "Grid Key: O = open position, F = occupied by a ship.\n";
    std::cout << "Grid Key: X = hit ship in that position, M = missed.\n\n";
    std::cout << "Computer's ship grid:" << std::endl << std::endl;
    std::string columns = "ABCDEFGHIJ";
    int rows[10] = {1,2,3,4,5,6,7,8,9,10};
    std::cout << "\t";
    
    for (int i = 0; i < 10; i++) {
        std::cout << columns[i] << "\t";
    }//for columns
    std::cout << std::endl << std::endl;
    
    for (int r = 0; r < 10; r++) {
        std::cout << rows[r];
        for (int c = 0; c < 10; c++) {
            cout << "\t" << *(getYourGrid(0 + r,0 + c));
        }//for columns
        std::cout << std::endl << std::endl;
    }//for rows
}

//randomly generate random row and random column
//determine if User object has a ship there
//change Computer's attack grid accordingly
//ensure each grid location is only attacked once
void Computer::generateAttack(User obj)
{
    int randRow, randCol;
    bool newShot = false;
    char temp;//for converting int column value to a letter to correspond with the grid
    do {
        randRow = (int)rand()%10;//random row 0-9
        randCol = (int)rand()%10;//random column 0-9
        if ((*getAttackGrid(randRow, randCol) != 'X') && (*getAttackGrid(randRow, randCol) != 'M')){
            newShot = true;
        }
    } while (newShot != true);//ensure spot is only attacked once
    
    temp = randCol + 65;//convert randCol to letter A-J for printing
    
    std::cout << "Computer attacking position: " << randRow+1 << temp << endl;
    
    if (*obj.getYourGrid(randRow, randCol) == 'O') {
        std::cout << "Computer missed!\n";
        *getAttackGrid(randRow, randCol) = 'M';//set attack grid to miss
    }//if Computer missed
    else if (*obj.getYourGrid(randRow, randCol) == 'F'){
        std::cout << "Computer got a hit!\n";
        *getAttackGrid(randRow, randCol) = 'X';//set attack grid to hit
    }//if Computer hit
  
}

//checks if each of Computer's ships were hit and sets their hits variable accordingly
//also sets User's score to the total of all the hits
void Computer::checkAllHits(User &user)
{
    int totalHits = 0;
    int carrierHits = 0, battleshipHits = 0, cruiserHits = 0, submarineHits = 0, destroyerHits = 0;
    
    //check carrier hits ********************************************
    //if horizontal
    if (carrier.getOrientation() == 'h') {
        for (int i = 0; i < carrier.getLength(); i++) {
            if (*user.getAttackGrid(carrier.getSRow(), carrier.getSCol()+i) == 'X') {
                carrierHits++;
                //change Computer's grid to reflect the hit
                *getYourGrid(carrier.getSRow(), carrier.getSCol()+i) = 'X';
                carrier.setHits(carrierHits);
                //if ship was sunk display this message
                if (carrier.getMessage()) {
                    if (carrier.getHits() == carrier.getLength()) {
                        carrier.setSunk(true);
                        std::cout << "You sunk " << getName() << "'s " << carrier.getName() << ".\n";
                        carrier.setMessage(false);
                    }//if ship sunk
                }//if
            }//if
        }//for
        totalHits += carrierHits;//for setting User's score
    }// if horizontal
    //if vertical
    if (carrier.getOrientation() == 'v') {
        for (int i = 0; i < carrier.getLength(); i++) {
            if (*user.getAttackGrid(carrier.getSRow()+i, carrier.getSCol()) == 'X') {
                carrierHits++;
                //change Computer's grid to reflect the hit
                *getYourGrid(carrier.getSRow()+i, carrier.getSCol()) = 'X';
                carrier.setHits(carrierHits);
                //if ship was sunk display this message
                if (carrier.getMessage()) {
                    if (carrier.getHits() == carrier.getLength()) {
                        carrier.setSunk(true);
                        std::cout << "You sunk " << getName() << "'s " << carrier.getName() << ".\n";
                        carrier.setMessage(false);
                    }//if ship sunk
                }//if
            }//if
        }//for
        totalHits += carrierHits;//for setting User's score
    }//if vertical
    
    //check battleship hits ********************************************
    //if horizontal
    if (battleship.getOrientation() == 'h') {
        for (int i = 0; i < battleship.getLength(); i++) {
            if (*user.getAttackGrid(battleship.getSRow(), battleship.getSCol()+i) == 'X') {
                battleshipHits++;
                //change Computer's grid to reflect the hit
                *getYourGrid(battleship.getSRow(), battleship.getSCol()+i) = 'X';
                battleship.setHits(battleshipHits);
                //if ship was sunk display this message
                if (battleship.getMessage()) {
                    if (battleship.getHits() == battleship.getLength()) {
                        battleship.setSunk(true);
                        std::cout << "You sunk " << getName() << "'s " << battleship.getName() << ".\n";
                        battleship.setMessage(false);
                    }//if ship sunk
                }//if
            }//if
        }//for
        totalHits += battleshipHits;//for setting User's score
    }//if horizontal
    //if vertical
    if (battleship.getOrientation() == 'v') {
        for (int i = 0; i < battleship.getLength(); i++) {
            if (*user.getAttackGrid(battleship.getSRow()+i, battleship.getSCol()) == 'X') {
                battleshipHits++;
                //change Computer's grid to reflect the hit
                *getYourGrid(battleship.getSRow()+i, battleship.getSCol()) = 'X';//works
                battleship.setHits(battleshipHits);
                //if ship was sunk display this message
                if (battleship.getMessage()) {
                    if (battleship.getHits() == battleship.getLength()) {
                        battleship.setSunk(true);
                        std::cout << "You sunk " << getName() << "'s " << battleship.getName() << ".\n";
                        battleship.setMessage(false);
                    }//if ship sunk
                }//if
            }//if
        }//for
        totalHits += battleshipHits;//for setting User's score
    }//if vertical
    
    //check cruiser hits ********************************************
    //if horizontal
    if (cruiser.getOrientation() == 'h') {
        for (int i = 0; i < cruiser.getLength(); i++) {
            if (*user.getAttackGrid(cruiser.getSRow(), cruiser.getSCol()+i) == 'X') {
                cruiserHits++;
                //change Computer's grid to reflect the hit
                *getYourGrid(cruiser.getSRow(), cruiser.getSCol()+i) = 'X';
                cruiser.setHits(cruiserHits);
                //if ship was sunk display this message
                if (cruiser.getMessage()) {
                    if (cruiser.getHits() == cruiser.getLength()) {
                        cruiser.setSunk(true);
                        std::cout << "You sunk " << getName() << "'s " << cruiser.getName() << ".\n";
                        cruiser.setMessage(false);
                    }//if ship sunk
                }//if
            }//if
        }//for
        totalHits += cruiserHits;//for setting User's score
    }//if horizontal
    //if vertical
    if (cruiser.getOrientation() == 'v') {
        for (int i = 0; i < cruiser.getLength(); i++) {
            if (*user.getAttackGrid(cruiser.getSRow()+i, cruiser.getSCol()) == 'X') {
                cruiserHits++;
                //change Computer's grid to reflect the hit
                *getYourGrid(cruiser.getSRow()+i, cruiser.getSCol()) = 'X';
                cruiser.setHits(cruiserHits);
                //if ship was sunk display this message
                if (cruiser.getMessage()) {
                    if (cruiser.getHits() == cruiser.getLength()) {
                        cruiser.setSunk(true);
                        std::cout << "You sunk " << getName() << "'s " << cruiser.getName() << ".\n";
                        cruiser.setMessage(false);
                    }// if ship sunk
                }//if
            }//if
        }//for
        totalHits += cruiserHits;//for setting User's score
    }//if vertical
    
    //check submarine hits ********************************************
    //if horizontal
    if (submarine.getOrientation() == 'h') {
        for (int i = 0; i < submarine.getLength(); i++) {
            if (*user.getAttackGrid(submarine.getSRow(), submarine.getSCol()+i) == 'X') {
                submarineHits++;
                //change Computer's grid to reflect the hit
                *getYourGrid(submarine.getSRow(), submarine.getSCol()+i) = 'X';//works
                submarine.setHits(submarineHits);
                //if ship was sunk display this message
                if (submarine.getMessage()) {
                    if (submarine.getHits() == submarine.getLength()) {
                        submarine.setSunk(true);
                        std::cout << "You sunk " << getName() << "'s " << submarine.getName() << ".\n";
                        submarine.setMessage(false);
                    }//if ship sunk
                }//if
            }//if
        }//for
        totalHits += submarineHits;//for setting User's score
    }//if horizontal
    //if vertical
    if (submarine.getOrientation() == 'v') {
        for (int i = 0; i < submarine.getLength(); i++) {
            if (*user.getAttackGrid(submarine.getSRow()+i, submarine.getSCol()) == 'X') {
                submarineHits++;
                //change Computer's grid to reflect the hit
                *getYourGrid(submarine.getSRow()+i, submarine.getSCol()) = 'X';
                submarine.setHits(submarineHits);
                //if ship was sunk display this message
                if (submarine.getMessage()) {
                    if (submarine.getHits() == submarine.getLength()) {
                        submarine.setSunk(true);
                        std::cout << "You sunk " << getName() << "'s " << submarine.getName() << ".\n";
                        submarine.setMessage(false);
                    }//if ship sunk
                }//if
            }//if
        }//for
        totalHits += submarineHits;//for setting User's score
    }//if vertical
    
    //check destroyer hits ********************************************
    //if horizontal
    if (destroyer.getOrientation() == 'h') {
        for (int i = 0; i < destroyer.getLength(); i++) {
            if (*user.getAttackGrid(destroyer.getSRow(), destroyer.getSCol()+i) == 'X') {
                destroyerHits++;
                //change Computer's grid to reflect the hit
                *getYourGrid(destroyer.getSRow(), destroyer.getSCol()+i) = 'X';//works
                destroyer.setHits(destroyerHits);
                //if ship was sunk display this message
                if (destroyer.getMessage()) {
                    if (destroyer.getHits() == destroyer.getLength()) {
                        destroyer.setSunk(true);
                        std::cout << "You sunk " << getName() << "'s " << destroyer.getName() << ".\n";
                        destroyer.setMessage(false);
                    }//if ship sunk
                }//if
            }//if
        }//for
        totalHits += destroyerHits;//for setting User's score
    }//if horizontal
    //if vertical
    if (destroyer.getOrientation() == 'v') {
        for (int i = 0; i < destroyer.getLength(); i++) {
            if (*user.getAttackGrid(destroyer.getSRow()+i, destroyer.getSCol()) == 'X') {
                destroyerHits++;
                //change Computer's grid to reflect the hit
                *getYourGrid(destroyer.getSRow()+i, destroyer.getSCol()) = 'X';//works
                destroyer.setHits(destroyerHits);
                //if ship was sunk display this message
                if (destroyer.getMessage()) {
                    if (destroyer.getHits() == destroyer.getLength()) {
                        destroyer.setSunk(true);
                        std::cout << "You sunk " << getName() << "'s " << destroyer.getName() << ".\n";
                        destroyer.setMessage(false);
                    }//if ship sunk
                }//if
            }//if
        }//for
        totalHits += destroyerHits;//for setting User's score
    }//if vertical
    
    //set User's score to the total amount of hits
    user.setScore(totalHits);
}

