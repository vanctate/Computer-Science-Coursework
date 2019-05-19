/*
 - Patrick Tate
 - CSCI 1411-004
 - Description: This program asks the user how many random numbers they want and their maximum value random number. The program then prints out however many random numbers the user wanted in the range of 1 - maxrand, and also prints out the average of these random numbers. The program loops until the user decides to exit.
 - Lab Partner: Prin
 - Status: successfully compiles and runs
 */

#include <iostream>
#include <cmath>

using namespace std;

//function to generate random number within the user defined range
int RandVGen(int&);

//function to play the game of asking user for random numbers, max rand, and displaying the average
void playGame();

int main()
{
    
    playGame();
    
    
}

int RandVGen(int &MaxRandV)
{
    //returns a random number from 1 - max rand chosen by user
    int randGen = (rand()%MaxRandV) + 1;
    return randGen;
}


void playGame(){
    
    char again = 'y';   //var to let user decide to keep playing
    
    while (again == 'y') {
        
        int randValues, maxRand;    //variables to hold how many random values and max random user wants
        
        cout << "Enter how many random numbers you want.\n";
        cin  >> randValues;
        cout << "Now enter the highest random number value you want to set.\n";
        cin  >> maxRand;
        cout << "Now I will display your " << randValues << " random values and their average.\n";
        
        double randSum = 0.0;//var to hold sums of the rands before their average is calculated
        
        int tempRand = 0;//var to hold each new rand value
        
        //loop to generate each random number and sum them
        for (int i = 0; i < randValues; i++) {
            tempRand = RandVGen(maxRand);
            cout << "Rand value " << (i+1) << " is " << tempRand << "." << endl;
            randSum += tempRand;
        }
        
        double randAv = (randSum/randValues);
        
        cout << endl << "The average of these numbers is " << randAv << endl;
        cout << "Play again? Enter y or Y to play again, enter any key to exit.\n";
        cin  >> again;
        again = tolower(again);//convert again to lowercase so only one logical comparison is need in while
    }//while

    
}

