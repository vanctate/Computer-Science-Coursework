/*
 - Patrick Tate
 - HW03
 - CSCI 2312
 - Program written using Xcode on MacOS
 - Program Status: this program runs and compiles on the csegrid
 */

#include "functions.h"
#include "watervehicle.h"
#include <iostream>
using namespace std;

//dispalys the user's grid
//1 = position occupied, 0 = position open
void displayGrid(int ar[10][10]){
    std::cout << "Grid Key: 0 = open position, 1 = occupied by a ship.\n\n";
    std::cout << "Your grid:" << std::endl << std::endl;
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
            std::cout << "\t" << ar[r][c];
        }//for columns
        std::cout << std::endl << std::endl;
    }//for rows
}

//random row for random torpedo shots
int randRows(){
    int randRow = (int)rand()%10;//random rows 0-9
    return randRow;
}

//random column for random torpedo shots
int randCols(){
    int randCol = (int)rand()%10;//random columns 0-9
    return randCol;
}

//adding 15 random torpedo shots to the torpedo grid
void addTorpedos(int ar[10][10]){
    int shots = 0;
    while (shots < 15) {
        int randRow = randRows();
        int randCol = randCols();
        if (ar[randRow][randCol] == 0) {
            ar[randRow][randCol] = 1;
            shots++;
        }//if
    }//while
}

//shows the randoml torpedo locations, 1 = torpedo, 0 = no torpedo
void displayTorpedoGrid(int ar[10][10]){
    std::cout << "Randomly generated torpedo Grid:" << std::endl << std::endl;
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
            std::cout << "\t" << ar[r][c];
        }//for columns
        std::cout << std::endl << std::endl;
    }//for rows
}

//instantiates an empty 10x10 grid for the user to fill and a 10x10 grid with 15 random "torpedo" shots
//instantiates 5 WaterVehicle objects, places them into the user's grid
//user's grid and torpedo grid are compared, if same element of both grids == 1 that counts as a hit
//if the total hits is equivalent to 17 the user loses
void playGame(WaterVehicle obj1, WaterVehicle obj2, WaterVehicle obj3, WaterVehicle obj4, WaterVehicle obj5){
    int userGrid[10][10] = {{0}, {0}};
    int torpedoGrid[10][10] = {{0}, {0}};
    addTorpedos(torpedoGrid);
    
    int score = 0;//player wins/loses if score == 17
    
    //show user's grid and place each ship on user's grid
    displayGrid(userGrid);
    obj1.fillGrid(userGrid);
    
    displayGrid(userGrid);
    obj2.fillGrid(userGrid);
    
    displayGrid(userGrid);
    obj3.fillGrid(userGrid);
    
    displayGrid(userGrid);
    obj4.fillGrid(userGrid);
    
    displayGrid(userGrid);
    obj5.fillGrid(userGrid);
    displayGrid(userGrid);
    
    displayTorpedoGrid(torpedoGrid);
    std::cout << std::endl;
    
    //calculate how many times each ship was hit and if it was sunk
    score += obj1.checkHits(userGrid, torpedoGrid);
    score += obj2.checkHits(userGrid, torpedoGrid);
    score += obj3.checkHits(userGrid, torpedoGrid);
    score += obj4.checkHits(userGrid, torpedoGrid);
    score += obj5.checkHits(userGrid, torpedoGrid);
    
    //display each ship's status
    std::cout << std::endl << std::endl;
    cout << obj1 << std::endl;
    cout << obj2 << std::endl;
    cout << obj3 << std::endl;
    cout << obj4 << std::endl;
    cout << obj5 << std::endl;
    
    if (score == 17) {
        std::cout << "Your entire fleet has been sunk. You lose.\n" << std::endl;
    }
    else{
        std::cout << "Your ships were hit " << score << " times.\n";
        std::cout << "But your entire fleet was not sunk. You win.\n";
    }
    
}

