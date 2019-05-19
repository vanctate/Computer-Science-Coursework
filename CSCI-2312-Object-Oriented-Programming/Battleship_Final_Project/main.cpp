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
int main() {
    
    srand(static_cast<unsigned int>(time(NULL)));//seed the random numbers
    
    playGame();
   
    return 0;
}
