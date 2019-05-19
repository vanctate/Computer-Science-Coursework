/*
 - Patrick Tate
 - HW03
 - CSCI 2312
 - Program written using Xcode on MacOS
 - Program Status: this program runs and compiles on the csegrid
 */

#include "watervehicle.h"
#ifndef functions_h
#define functions_h

void displayGrid(int ar[10][10]);//show user's grid
int randRows();//randomly generated row for "torpedo" shots
int randCols();//randomly generated column for "torpedo" shots
void addTorpedos(int ar[10][10]);//add 15 "torpedo" shots in random locations
void displayTorpedoGrid(int ar[10][10]);
void playGame(WaterVehicle obj1, WaterVehicle obj2, WaterVehicle obj3, WaterVehicle obj4, WaterVehicle obj5);

#endif /* functions_h */
