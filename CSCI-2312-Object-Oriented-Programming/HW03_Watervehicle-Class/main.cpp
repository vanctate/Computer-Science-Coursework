/*
 - Patrick Tate
 - HW03
 - CSCI 2312
 - Program written using Xcode on MacOS
 - Program Status: this program runs and compiles on the csegrid
 */

#include <iostream>
#include <ctime>
#include "watervehicle.h"
#include "functions.h"
using namespace std;

int main() {
    
    srand (time(NULL));//seed the random numbers
    
    WaterVehicle carrier("carrier", 5), battleship("battleship", 4);
    WaterVehicle cruiser("cruiser", 3), submarine("submarine", 3), destroyer("destroyer", 2);
    
    playGame(carrier, battleship, cruiser, submarine, destroyer);
   
    return 0;
}

