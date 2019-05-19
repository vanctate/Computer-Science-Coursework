/*
 - Patrick Tate
 - Final Project
 - CSCI 2312
 - Program written using Xcode on MacOS
 - Program Status: this program runs and compiles on the csegrid
 */

#include "Player.h"
#include "Watervehicle.h"

Player:: Player()
{
    score = 0;
    
    //create empty yourGrid, O = open space, F = filled
    for (int r = 0; r < 10; r++) {
        for (int c = 0; c < 10; c++) {
            yourGrid[r][c] = 'O';
        }//for columns
    }//for row
    
    //create empty attackGrid, O = open space, X = hit, M = miss
    for (int r = 0; r < 10; r++) {
        for (int c = 0; c < 10; c++) {
            attackGrid[r][c] = 'O';
        }//for columns
    }//for row
}

void Player::printAttackGrid()
{
    std::cout << "Grid Key: O = open position, F = occupied by a ship.\n";
    std::cout << "Grid Key: X = hit ship in that position, M = missed.\n\n";
    std::cout << getName() << "'s Attack Grid:" << std::endl << std::endl;
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
            std::cout << "\t" << *(getAttackGrid(0 + r,0 + c));
        }//for columns
        std::cout << std::endl << std::endl;
    }//for rows
}

//for displaying a Player's fleet and both grids
std::ostream& operator<<(std::ostream& out, Player& obj)
{
    out << obj.carrier << std::endl;
    out << obj.battleship << std::endl;
    out << obj.cruiser << std::endl;
    out << obj.submarine << std::endl;
    out << obj.destroyer << std::endl;
    
    return out;
}

