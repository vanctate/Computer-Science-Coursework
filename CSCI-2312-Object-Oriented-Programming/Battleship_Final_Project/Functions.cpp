/*
 - Patrick Tate
 - Final Project
 - CSCI 2312
 - Program written using Xcode on MacOS
 - Program Status: this program runs and compiles on the csegrid
 */

#include <ctime>
#include <iostream>
#include <string>
#include "Watervehicle.h"
#include "Player.h"
#include "User.h"
#include "Computer.h"
#include "Functions.h"
using namespace std;

//creates a User object and a Computer object and runs the Battleship game
//the game runs until one player reaches a score of 17, sinking all their opponent's ships
void playGame()
{
    //instantiate Computer
    Computer comp;
    comp.placeShips();
    
    //instantiate User
    User user;
    user.readInShips();
    user.insertShips();
    string tempName;
    
    bool shot = false;//for displaying hit/miss message
    int flag = 0;
    cout << endl;
    
    //run game until one playe sinks all ships
    //each player's fleet has a total length of 17
    //game ends when one player's score equals 17
    cout << "*** Welcome to the game of Battleship ***\n";
    cout << "Enter your name.\n";
    getline(cin, tempName);
    user.setName(tempName);
    cout << "You will attack first, " << user.getName() << ".\n\n";
    
    while ((comp.getScore() != 17) || (user.getScore() != 17)) {
       
        cout << endl << endl;
        user.displayYourGrid();
        cout << endl;
        user.printAttackGrid();
        cout << endl;
        cout << user.getName() << "'s score = " << user.getScore() << endl;
        cout << "Computer's score = " << comp.getScore() << endl << endl;
        //display if shot was hit/miss, doesn't run until after first attack
        if (shot) {
            cout << "You got a hit!\n\n";
        }
        else if ((shot == false) && (flag != 0)){
            cout << "You missed!\n\n";
        }
        //escape keys
        cout << "Enter 99 when prompted for a row to exit the game.\n";
        cout << "Enter 'z' when prompted for a column to exit the game.\n\n";
        shot = user.generateAttack(comp);//get row/column from user for attack
        comp.checkAllHits(user);//checks if user's attack was successful and increments score if it was
        
        //check if user won
        if (user.getScore() == 17) {
            cout << endl << endl << "**** You won, congrats! ****\n\n";
            cout << "Computer's fleet status ******************************************";
            cout << endl << comp << endl;
            comp.printCompYourGrid();
            comp.printAttackGrid();
            cout << user.getName() << "'s fleet status ******************************************";
            cout << endl << user << endl;
            user.displayYourGrid();
            user.printAttackGrid();
            exit(0);
        }//if User wins
      
        comp.generateAttack(user);//randomly generated row/column for computer attack
        user.checkAllHits(comp);//checks if computer's attack was succesful and adds 1 to score if hit
        
        //check if computer won
        if (comp.getScore() == 17){
            cout << endl << "Computer beat you!\n\n";
            cout << "Computer's fleet status ******************************************";
            cout << endl << comp << endl;
            comp.printCompYourGrid();
            comp.printAttackGrid();
            cout << user.getName() << "'s fleet status ******************************************";
            cout << endl << user << endl;
            user.displayYourGrid();
            user.printAttackGrid();
            exit(0);
        }//if Computer wins
        flag = 999;//set flag to non 0 value so hit/miss message appears
    }//while
}
