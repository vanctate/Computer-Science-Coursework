/*
     - Patrick Tate
     - CSCI 1411-004
     - Description: This program asks the user for the total sides of dice and an integer value for the
     score goal. The roll dice function calculates a random number between 1 and the total number of sides
     on the dice. Each player starts at 0 and rolls until they get exactly the score goal. If any player
     goes above the score goal, their goal is reset to 0, and they start again. The only input
     the user enters is the dice sides and the score goal. Once the a player has won, the user is asked if
     they would like to play again.
     - Lab Partner: Prin
     - Status: successfully compiles and runs
*/


#include "Functions.hpp"

int main(){

    
    playGame();
    
    return 0;

}
