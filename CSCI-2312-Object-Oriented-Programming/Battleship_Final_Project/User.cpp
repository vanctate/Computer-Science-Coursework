/*
 - Patrick Tate
 - Final Project
 - CSCI 2312
 - Program written using Xcode on MacOS
 - Program Status: this program runs and compiles on the csegrid
 */

#include "User.h"
#include "Player.h"
#include "Computer.h"
#include "Watervehicle.h"
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

User:: User()
{
    
}

//display User's ship grid
void User::displayYourGrid()
{
    std::cout << "Grid Key: O = open position, F = occupied by a ship.\n";
    std::cout << "Grid Key: X = hit ship in that position, M = missed.\n\n";
    std::cout << getName() << "'s ship grid:" << std::endl << std::endl;
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

//reads in info about the user's 5 ships
//exception handling is performed to ensure there is no bad input
//exception handling checks to ensure no array value beyond 0-9, orientation is 'h' or 'v'
//and that int values are ints
void User::readInShips()
{
    fstream inFile;
    string csvDescription;
    string name;
    string startLoc;
    string orientation;
    
    inFile.open("shipPlacement.csv");
    getline(inFile, csvDescription);//get rid of first line description
    
    int counter = 0;//for determining/setting length & which ship had bad input from file
    while (getline(inFile, name, ',')) {
        
        getline(inFile,startLoc, ',');
        getline(inFile, orientation);
        
        //ensure proper starting location values
        try
        {
        if (!isdigit(startLoc[1])) {
            throw counter;
        }
        else if (!isalpha(startLoc[0])){
            throw counter;
        }
        
        bool input;//set to true if orientation isn't h or v
            
        //read in flips it, usually row,col but read in is A1
        int col = startLoc[0] - 65;//- 65 for array notation
        //ensure starting column is A-J
        if ((col < 0) || col > 9) {
                throw counter;
        }
        int row = startLoc[1] - 49;//- 49 for array notation
        char _orientation = orientation[0];
        _orientation = tolower(_orientation);
        //ensure orientation is either h or v
        if ((_orientation == 'h') || (_orientation == 'v')) {
                input = false;
        }
        else{
                input = true;
        }
        if (input) {
            throw counter;
        }
        
        //counter determines which ship is being read in
        if (counter == 0) {
            WaterVehicle tempShip("Carrier", 5, row, col, _orientation);
            setCarrier(tempShip);
        }
        else if (counter == 1){
            WaterVehicle tempShip("Battleship", 4, row, col, _orientation);
            setBattleship(tempShip);
        }
        else if (counter == 2){
            WaterVehicle tempShip("Cruiser", 3, row, col, _orientation);
            setCruiser(tempShip);
        }
        else if (counter == 3){
            WaterVehicle tempShip("Submarine", 3, row, col, _orientation);
            setSubmarine(tempShip);
        }
        else if (counter == 4){
            WaterVehicle tempShip("Destroyer", 2, row, col, _orientation);
            setDestroyer(tempShip);
        }
       
        counter++;
        }//try
        catch(int e)
        {
            badInput(e);
            counter++;
        }
    }
    inFile.close();
}

//once a ship is determined legal it is inserted into the grid
void User::insertShip(WaterVehicle &obj)
{
    //check if ship is already in that position
    if (obj.getOrientation() == 'h') {
        for (int i = 0; i < obj.getLength(); i++) {
            if (*getYourGrid(obj.getSRow(), obj.getSCol() + i) == 'F') {
                areaOccupied(obj);
            }
        }//for
    }//if
    else if (obj.getOrientation() == 'v'){
        for (int i = 0; i < obj.getLength(); i++) {
            if (*getYourGrid(obj.getSRow() + i, obj.getSCol()) == 'F') {
                areaOccupied(obj);
            }
        }//for
    }//if
    
    if (obj.getOrientation() == 'h') {
        for (int i = 0; i < obj.getLength(); i++) {
            *getYourGrid(obj.getSRow(), obj.getSCol() + i) = 'F';
        }//for
        obj.setPlaced(true);
    }//if
    else if (obj.getOrientation() == 'v'){
        for (int i = 0; i < obj.getLength(); i++) {
            *getYourGrid(obj.getSRow() + i, obj.getSCol()) = 'F';
        }//for
        obj.setPlaced(true);
    }//if
    
}

//inserts all 5 ships
void User::insertShips()
{
    insertShip(carrier);
    insertShip(battleship);
    insertShip(cruiser);
    insertShip(submarine);
    insertShip(destroyer);
}

//gets row/column from User and checks if there is a ship in Computer's grid at that location
//if 99 is entered for the row or lowercase 'z' is entered for column, game quits
//User is prevented from entering a row less than 1 and greater than 10
//User is also prevented from entering a char when an int is required
bool User::generateAttack(class Computer &comp)
{
    bool shot = false;
    int tempRow;
    char tempCol;
    
    std::cout << "Time to enter your attack coordinates.\n";
    do {
        std::cout << "Enter the row 1-10 for your attack.\n";
        std::cin  >> tempRow;
        if (tempRow == 99) {
            exit(99);
        }
        //from stackoverflow, catches if a user inputs a character
        while (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore();
            std::cout << "Please enter a number and not a character.\n";
            std::cin  >> tempRow;
        }
        if ((tempRow < 1) || (tempRow > 10)) {
            std::cout << "Please enter a number 1-10.\n";
        }
    } while ((tempRow < 1) || (tempRow > 10));
    
    tempRow = tempRow - 1;//change to array coordinate
    
    do {
        std::cout << "Enter the column A-J for your attack.\n";
        std::cin  >> tempCol;
        if (tempCol == 'z') {
            exit(99);
        }
        tempCol = toupper(tempCol);//allow for entering of capital or lowercase values
        tempCol = tempCol - 65;//for array notation
        if ((tempCol < 0) || (tempCol > 9)) {
            std::cout << "Please enter a character A-J.\n";
        }
    } while ((tempCol < 0) || (tempCol > 9));
    
    
    if (*comp.getYourGrid(tempRow, tempCol) == 'O') {
        //std::cout << "You missed!\n";
        *getAttackGrid(tempRow, tempCol) = 'M';//set attack grid to miss
    }
    else if (*comp.getYourGrid(tempRow, tempCol) == 'F'){
        //std::cout << "You got a hit!\n";
        *getAttackGrid(tempRow, tempCol) = 'X';//set attack grid to hit
        shot = true;
    }
    return shot;
}

//checks if each of User's ships were hit and sets their hits variable accordingly
//if a ship was hit, it checks if it was also sunk
//also sets Computer's score to the total of all the hits
void User::checkAllHits(class Computer &comp)
{
    int totalHits = 0;
    int carrierHits = 0, battleshipHits = 0, cruiserHits = 0, submarineHits = 0, destroyerHits = 0;
    
    //check carrier hits ********************************************
    //if horizontal
    if (carrier.getOrientation() == 'h') {
        for (int i = 0; i < carrier.getLength(); i++) {
            if (*comp.getAttackGrid(carrier.getSRow(), carrier.getSCol()+i) == 'X') {
                carrierHits++;
                //change User's grid to reflect the hit
                *getYourGrid(carrier.getSRow(), carrier.getSCol()+i) = 'X';
                carrier.setHits(carrierHits);
                //if ship was sunk display this message
                if (carrier.getMessage()) {
                    if (carrier.getHits() == carrier.getLength()) {
                        carrier.setSunk(true);
                        std::cout << "Computer sunk " << getName() << "'s " << carrier.getName() << ".\n";
                        carrier.setMessage(false);
                    }//if ship sunk
                }//if
            }//if
        }//for
        totalHits += carrierHits;//for setting Computer's score
    }//if horizontal
    //if vertical
    if (carrier.getOrientation() == 'v') {
        for (int i = 0; i < carrier.getLength(); i++) {
            if (*comp.getAttackGrid(carrier.getSRow()+i, carrier.getSCol()) == 'X') {
                carrierHits++;
                //change User's grid to reflect the hit
                *getYourGrid(carrier.getSRow()+i, carrier.getSCol()) = 'X';
                carrier.setHits(carrierHits);
                //if ship was sunk display this message
                if (carrier.getMessage()) {
                    if (carrier.getHits() == carrier.getLength()) {
                        carrier.setSunk(true);
                        std::cout << "Computer sunk " << getName() << "'s " << carrier.getName() << ".\n";
                        carrier.setMessage(false);
                    }//if ship sunk
                }//if
            }//if
        }//for
        totalHits += carrierHits;//for setting Computer's score
    }//if vertical
    
    //check battleship hits ********************************************
    //if horizontal
    if (battleship.getOrientation() == 'h') {
        for (int i = 0; i < battleship.getLength(); i++) {
            if (*comp.getAttackGrid(battleship.getSRow(), battleship.getSCol()+i) == 'X') {
                battleshipHits++;
                //change User's grid to reflect the hit
                *getYourGrid(battleship.getSRow(), battleship.getSCol()+i) = 'X';
                battleship.setHits(battleshipHits);
                //if ship was sunk display this message
                if (battleship.getMessage()) {
                    if (battleship.getHits() == battleship.getLength()) {
                        battleship.setSunk(true);
                        std::cout << "Computer sunk " << getName() << "'s " << battleship.getName() << ".\n";
                        battleship.setMessage(false);
                    }//if ship sunk
                }//if
            }//if
        }//for
        totalHits += battleshipHits;//for setting Computer's score
    }//if horizontal
    //if vertical
    if (battleship.getOrientation() == 'v') {
        for (int i = 0; i < battleship.getLength(); i++) {
            if (*comp.getAttackGrid(battleship.getSRow()+i, battleship.getSCol()) == 'X') {
                battleshipHits++;
                //change User's grid to reflect the hit
                *getYourGrid(battleship.getSRow()+i, battleship.getSCol()) = 'X';
                battleship.setHits(battleshipHits);
                //if ship was sunk display this message
                if (battleship.getMessage()) {
                    if (battleship.getHits() == battleship.getLength()) {
                        battleship.setSunk(true);
                        std::cout << "Computer sunk " << getName() << "'s " << battleship.getName() << ".\n";
                        battleship.setMessage(false);
                    }//if ship sunk
                }//if
            }//if
        }//for
        totalHits += battleshipHits;//for setting Computer's score
    }//if vertical
    
    //check cruiser hits ********************************************
    //if horizontal
    if (cruiser.getOrientation() == 'h') {
        for (int i = 0; i < cruiser.getLength(); i++) {
            if (*comp.getAttackGrid(cruiser.getSRow(), cruiser.getSCol()+i) == 'X') {
                cruiserHits++;
                //change User's grid to reflect the hit
                *getYourGrid(cruiser.getSRow(), cruiser.getSCol()+i) = 'X';
                cruiser.setHits(cruiserHits);
                //if ship was sunk display this message
                if (cruiser.getMessage()) {
                    if (cruiser.getHits() == cruiser.getLength()) {
                        cruiser.setSunk(true);
                        std::cout << "Computer sunk " << getName() << "'s " << cruiser.getName() << ".\n";
                        cruiser.setMessage(false);
                    }//if ship sunk
                }//if
            }//if
        }//for
        totalHits += cruiserHits;//for setting Computer's score
    }//if horizontal
    //if vertical
    if (cruiser.getOrientation() == 'v') {
        for (int i = 0; i < cruiser.getLength(); i++) {
            if (*comp.getAttackGrid(cruiser.getSRow()+i, cruiser.getSCol()) == 'X') {
                cruiserHits++;
                //change User's grid to reflect the hit
                *getYourGrid(cruiser.getSRow()+i, cruiser.getSCol()) = 'X';
                cruiser.setHits(cruiserHits);
                //if ship was sunk display this message
                if (cruiser.getMessage()) {
                    if (cruiser.getHits() == cruiser.getLength()) {
                        cruiser.setSunk(true);
                        std::cout << "Computer sunk " << getName() << "'s " << cruiser.getName() << ".\n";
                        cruiser.setMessage(false);
                    }//if ship sunk
                }//if
            }//if
        }//for
        totalHits += cruiserHits;//for setting Computer's score
    }//if vertical
    
    //check submarine hits ********************************************
    //if horizontal
    if (submarine.getOrientation() == 'h') {
        for (int i = 0; i < submarine.getLength(); i++) {
            if (*comp.getAttackGrid(submarine.getSRow(), submarine.getSCol()+i) == 'X') {
                submarineHits++;
                //change User's grid to reflect the hit
                *getYourGrid(submarine.getSRow(), submarine.getSCol()+i) = 'X';
                submarine.setHits(submarineHits);
                //if ship was sunk display this message
                if (submarine.getMessage()) {
                    if (submarine.getHits() == submarine.getLength()) {
                        submarine.setSunk(true);
                        std::cout << "Computer sunk " << getName() << "'s " << submarine.getName() << ".\n";
                        submarine.setMessage(false);
                    }//if ship sunk
                }//if
            }//if
        }//for
        totalHits += submarineHits;//for setting Computer's score
    }//if horizontal
    //if vertical
    if (submarine.getOrientation() == 'v') {
        for (int i = 0; i < submarine.getLength(); i++) {
            if (*comp.getAttackGrid(submarine.getSRow()+i, submarine.getSCol()) == 'X') {
                submarineHits++;
                //change User's grid to reflect the hit
                *getYourGrid(submarine.getSRow()+i, submarine.getSCol()) = 'X';
                submarine.setHits(submarineHits);
                //if ship was sunk display this message
                if (submarine.getMessage()) {
                    if (submarine.getHits() == submarine.getLength()) {
                        submarine.setSunk(true);
                        std::cout << "Computer sunk " << getName() << "'s " << submarine.getName() << ".\n";
                        submarine.setMessage(false);
                    }//if ship sunk
                }//if
            }//if
        }//for
        totalHits += submarineHits;//for setting Computer's score
    }//if vertical
    
    //check destroyer hits ********************************************
    //if horizontal
    if (destroyer.getOrientation() == 'h') {
        for (int i = 0; i < destroyer.getLength(); i++) {
            if (*comp.getAttackGrid(destroyer.getSRow(), destroyer.getSCol()+i) == 'X') {
                destroyerHits++;
                //change User's grid to reflect the hit
                *getYourGrid(destroyer.getSRow(), destroyer.getSCol()+i) = 'X';
                destroyer.setHits(destroyerHits);
                //if ship was sunk display this message
                if (destroyer.getMessage()) {
                    if (destroyer.getHits() == destroyer.getLength()) {
                        destroyer.setSunk(true);
                        std::cout << "Computer sunk " << getName() << "'s " << destroyer.getName() << ".\n";
                        destroyer.setMessage(false);
                    }//if ship sunk
                }//if
            }//if
        }//for
        totalHits += destroyerHits;//for setting Computer's score
    }//if horizontal
    //if vertical
    if (destroyer.getOrientation() == 'v') {
        for (int i = 0; i < destroyer.getLength(); i++) {
            if (*comp.getAttackGrid(destroyer.getSRow()+i, destroyer.getSCol()) == 'X') {
                destroyerHits++;
                //change User's grid to reflect the hit
                *getYourGrid(destroyer.getSRow()+i, destroyer.getSCol()) = 'X';
                destroyer.setHits(destroyerHits);
                //if ship was sunk display this message
                if (destroyer.getMessage()) {
                    if (destroyer.getHits() == destroyer.getLength()) {
                        destroyer.setSunk(true);
                        std::cout << "Computer sunk " << getName() << "'s " << destroyer.getName() << ".\n";
                        destroyer.setMessage(false);
                    }//if ship sunk
                }//if
            }//if
        }//for
        totalHits += destroyerHits;//for setting Computer's score
    }//if vertical
    
    //set Computer's score to the total hits received
    comp.setScore(totalHits);
}

//if position on the grid is already occupied, user has the choice to exit or have ship randomly placed
void User::areaOccupied(WaterVehicle &obj){
    int choice;
    cout << "Can't place a " << obj.getName() << " in that position.\n";
    cout << "Enter 1 to exit program and fix the input file.\n";
    cout << "Enter 2 to have your " << obj.getName() << " placed randomly.\n";
    cin  >> choice;
    if (choice == 1) {
        exit(1);
    }
    else if (choice == 2){
        placeShipRandomly(obj);
    }
    while ((choice < 1) || (choice > 2)) {
        cout << "Enter 1 or 2\n";
        cin  >> choice;
        if (choice == 1) {
            exit(1);
        }
        else if (choice == 2){
            placeShipRandomly(obj);
        }
        while (cin.fail()) {
            cin.clear();
            cin.ignore();
            cout << "Please enter a number and not a character.\n";
            cin  >> choice;
            if (choice == 1) {
                exit(1);
            }
            else if (choice == 2){
                placeShipRandomly(obj);
            }
        }//while choice != int
    }
   
    cin.ignore();
}

void User::placeShipRandomly(WaterVehicle &obj)
{
    cout << "Randomly placing " << obj.getName() << endl;
    cout << "This may affect your other ship placements.\n\n";
    do {
        obj.determineOrientation();
        obj.determineStartPos();
        obj.checkSpace();
        checkOccupied(obj);
    } while ((!obj.getSpace()) || (obj.getOccupied()));
    
    //set the User's watervehicle to that ship
    if (obj.getName() == "Carrier") {
        setCarrier(obj);
    }
    else if (obj.getName() == "Battleship"){
        setBattleship(obj);
    }
    else if (obj.getName() == "Cruiser"){
        setCruiser(obj);
    }
    else if (obj.getName() == "Submarine"){
        setSubmarine(obj);
    }
    else if (obj.getName() == "Destroyer"){
        setDestroyer(obj);
    }
}

//ensures that a ship's placement doesn't overlap at all with any other ship's location
//returns true if area isn't occupied, returns false if any section of placement is occupied
bool User::checkOccupied(WaterVehicle &obj)
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

void User::badInput(int counter)
{
    int choice;
    cout << "There was a problem with your input file.\n";
    cout << "Enter 1 to exit program and fix the input file.\n";
    cout << "Enter 2 to have your ship placed randomly.\n";
    cin  >> choice;
    if (choice == 1) {
        exit(1);
    }
    else if (choice == 2){
        if (counter == 0) {
            carrier.setName("Carrier");
            carrier.setLength(5);
            placeShipRandomly(carrier);
        }
        else if (counter == 1){
            battleship.setName("Battleship");
            battleship.setLength(4);
            placeShipRandomly(battleship);
        }
        else if (counter == 2){
            cruiser.setName("Cruiser");
            cruiser.setLength(3);
            placeShipRandomly(cruiser);
        }
        else if (counter == 3){
            submarine.setName("Submarine");
            submarine.setLength(3);
            placeShipRandomly(submarine);
        }
        else if (counter == 4){
            destroyer.setName("Destroyer");
            destroyer.setLength(2);
            placeShipRandomly(destroyer);
        }
    }
    while ((choice < 1) || (choice > 2)) {
        cout << "Enter 1 or 2\n";
        cin  >> choice;
        if (choice == 1) {
            exit(1);
        }
        else if (choice == 2){
            if (counter == 0) {
                carrier.setName("Carrier");
                carrier.setLength(5);
                placeShipRandomly(carrier);
            }
            else if (counter == 1){
                battleship.setName("Battleship");
                battleship.setLength(4);
                placeShipRandomly(battleship);
            }
            else if (counter == 2){
                cruiser.setName("Cruiser");
                cruiser.setLength(3);
                placeShipRandomly(cruiser);
            }
            else if (counter == 3){
                submarine.setName("Submarine");
                submarine.setLength(3);
                placeShipRandomly(submarine);
            }
            else if (counter == 4){
                destroyer.setName("Destroyer");
                destroyer.setLength(2);
                placeShipRandomly(destroyer);
            }
        }
        while (cin.fail()) {
            cin.clear();
            cin.ignore();
            cout << "Please enter a number and not a character.\n";
            cin  >> choice;
            if (choice == 1) {
                exit(1);
            }
            else if (choice == 2){
                if (counter == 0) {
                    carrier.setName("Carrier");
                    carrier.setLength(5);
                    placeShipRandomly(carrier);
                }
                else if (counter == 1){
                    battleship.setName("Battleship");
                    battleship.setLength(4);
                    placeShipRandomly(battleship);
                }
                else if (counter == 2){
                    cruiser.setName("Cruiser");
                    cruiser.setLength(3);
                    placeShipRandomly(cruiser);
                }
                else if (counter == 3){
                    submarine.setName("Submarine");
                    submarine.setLength(3);
                    placeShipRandomly(submarine);
                }
                else if (counter == 4){
                    destroyer.setName("Destroyer");
                    destroyer.setLength(2);
                    placeShipRandomly(destroyer);
                }
            }
        }//while choice != int
    }//while
    
    cin.ignore();
    
}
