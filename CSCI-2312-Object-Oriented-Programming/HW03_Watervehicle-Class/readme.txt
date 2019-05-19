*******************************************************
*  Name      :  Patrick Tate
*  Student ID:  108350446
*  Class     :  CSC 2312-002
*  Due Date  :  Feb. 21, 2018
*******************************************************


                 Read Me


*******************************************************
*  Description of the program
*******************************************************

This program utilizes the WaterVehicle class to play a simplified version of the
Battleship game. The user has 5 "ships" which are WaterVehicle objects, each of
which have private member variables for length, starting location, hits, and if
they were sunk. The user's ships are placed in a two dimensional array. The
user is prevented from placing ships out of bounds or in a space already
occupied by another ship. Fifteen "torpedo" shots are then randomly generated in
another two dimensional grid. The two grids are compared, and each "hit" on a
ship is printed, as well as if the ship was sunk, and if the user won or lost.


*******************************************************
*  Source files
*******************************************************

Name:  main.cpp
   This is the driver program that creates two grids, the user grid and the
   "torpedo" grid. Functions are called to add "torpedos" and play the game.

Name:  waterVehicle.h
   Contains the definition for the class WaterVehicle.

Name: waterVehicle.cpp
   Defines and implements the waterVehicle class. Functions are defined for a
   custom constructor, placing each ship on the user's grid, functions to check
   if the ship runs out of bounds or if area is already occupied, and checking
   how many hits the ship received.

Name: functions.h
   Contains the definition for generating a random row and random column,
   displaying grids and comparing two grids.

Name: functions.cpp
    Defines and implements the functions for random rows/columns, displaying
    grids and comparing two grids.

*******************************************************
*  Status of program
*******************************************************

   The program runs successfully.

   The program was developed and tested on Xcode using macOS.  It was
   compiled, run, and tested on csegrid.ucdenver.pvt.
