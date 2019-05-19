//
//  Functions.cpp
//  TatePLab05
//
//  Created by Patrick Tate on 9/21/17.
//  
//

#include "Functions.hpp"
#include <iostream>
#include <cmath>

using namespace std;

int rollDice(int &diSides)
{
    int randomNumber = (rand()%(diSides)+1);//give random number a range of 1 - diSides
    return randomNumber;
    
}

void playGame(){
    
    //get values from the user for dice sides and score goal for the game
    int diSides, scoreGoal;
    cout << "Enter a number for the sides of di you would like.\n";
    cin  >> diSides;
    cout << "Now enter an int value for the score goal\n";
    cin  >> scoreGoal;
    cout << "Now we play a game to reach " << scoreGoal << "." << endl;
    cout << "You must get exactly " << scoreGoal << ". If you go over your score resets to 0.\n";
    
    //initialize both players score totals to 0 so they don't contain a garbage value
    int p1Score = 0, p2Score = 0;
    
    char playAgain = 'y';
    //option to see if the users want to play again
    while (playAgain == 'y') {
        
        //one turn for player 1
        p1Score += rollDice(diSides);//sum player 1's score
        cout << "player 1 score = " << p1Score << endl;
        if (p1Score == scoreGoal) {
            cout << "Congrats player1 wins!\n" << "Play again? Enter y to play again.\n";
            cout << "Enter any key to quit program.\n";
            cin  >> playAgain;
            if (playAgain == 'y') {
                playGame();
            }
            else
            exit(0);//exit program when prompted by user
        }
        else if (p1Score > scoreGoal){//reset player1's score if they go above score goal
            p1Score = 0;
        }
        
        //one turn for player 2
        p2Score += rollDice(diSides);//sum player 2's score
        cout << "player 2 score = " << p2Score << endl << endl;
        if (p2Score == scoreGoal) {
            cout << "Congrats player2 wins!\n" << "Play again? Enter y to play again.\n";
            cout << "Enter any key to quit the program.\n";
            cin  >> playAgain;
            if (playAgain == 'y') {
                playGame();
            }
            else
            exit(0);//exit program when prompted by user
        }
        else if (p2Score > scoreGoal){//reset player2's score if they go above score goal
            p2Score = 0;
        }
        
    }//while
}
