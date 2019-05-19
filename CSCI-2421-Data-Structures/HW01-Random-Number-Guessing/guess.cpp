/*
 - Patrick Tate
 - HW01 CSCI 2421
 - Program written using XCode on MacOS
 - Program Status: this program runs and compiles on the csegrid
 */

#include "guess.h"
#include <ctime>
#include <cstdlib>
#include <iostream>
using namespace std;

//default constructor
Guess::Guess(){
    totalNums = -1;
    range = -1;
    std::vector<int> randVec;
    std::vector<int> guessVec;
}

//fills a vector of user defined size totalNums with random numbers in range of 1-range
std::vector<int> Guess::createRandVec(int range, int totalNums){
    
    srand (time(NULL));//seed the random number
    
    std::vector<int> randVec;
    
    //populate randVec with random integers 1 - range
    for (int i = 0; i < totalNums; i++) {
        int randGen = ((int)rand()%range) + 1;
        randVec.push_back(randGen);
    }//for
    
    return randVec;
}

//fills a vector of user defined size with the user's guesses
std::vector<int> Guess::createGuessVec(int totalNums){
    std::vector<int> tempVec;
    for (int i = 0; i < totalNums; i++) {
        int input;
        cout << "Enter you guess for number " << i + 1 << ".\n";
        cin  >> input;
        tempVec.push_back(input);
    }
    return tempVec;
}

//obtain user input and set object's range and totalNums
void Guess::userInput(Guess &obj){
    int range, totalNums;
    
    cout << "Enter how many random numbers you want to guess.\n";
    cin  >> totalNums;
    //acount for negative values
    if (totalNums < 0) {
        cout << "Please enter a positive number.\n";
        obj.playGame();
    }
    cout << "Enter the range for your numbers.\n";
    cin  >> range;
    //account for negative values
    if (range < 0) {
        cout << "Please enter a positive number.\n";
        obj.playGame();
    }
    
    obj.setRange(range);
    obj.setTotalNums(totalNums);
    
}

//starts the game
void Guess::playGame(){
    
    Guess gameplay;
  
    userInput(gameplay);
    compareVec(gameplay);
    
}

//compares the user's guess vector with the random number vector
//user has 3 chances to guess the correct numbers
void Guess::compareVec(Guess obj){
    
    char playAgain;
    int tries = 0;
    
    obj.setRandVec(obj.createRandVec(obj.getRange(), obj.getTotalNums()));//create the random number vector
    
    do {
        int guessCorrect = 0;//user wins when guessCorrect == totalNums
        vector<int> userVec = obj.createGuessVec(obj.getTotalNums());//get user guesses & store in vector
        obj.setGuessVec(userVec);
        
        vector<int> tempVec = obj.getRandVec();//create a copy of randomVec for comparisons
        
        //for each element in randVec
        for (int j = 0; j < obj.getTotalNums(); j++) {
            
            //for each element in guessVec
            for (int k = 0; k < tempVec.size(); k++){
                
                if (obj.getGuessVec()[j] == tempVec[k]) {
                    tempVec.erase(tempVec.begin() + k);//delete that element to account for duplicates
                    guessCorrect++;
                    if (guessCorrect == obj.getTotalNums()) {
                        cout << "congrats you win.\n";
                        cout << "play again?\n";
                        cin  >> playAgain;
                        tolower(playAgain);
                        if (playAgain == 'y') {
                            obj.playGame();
                        }//if
                        else exit(0);
                    }//if
                    break;//exit loop to begin searching for next guessVec element
                }//if
            }//for
        }//for
        
        cout << "you made " << guessCorrect << " correct guesses.\n";
        obj.getGuessVec().clear();//clear guess vector for next round of guesses
        tempVec.clear();//clear temp random vector for next round of comparisons
        tries++;
        if (tries == 3) {
            cout << "Sorry you lost. Play again?\n";
            cin >> playAgain;
            tolower(playAgain);
            if (playAgain == 'y') {
                obj.playGame();
            }//if
        }//if
    } while (tries < 3);
}

