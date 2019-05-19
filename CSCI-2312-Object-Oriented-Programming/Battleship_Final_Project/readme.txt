*******************************************************
*  Name      :  Patrick Tate
*  Student ID:  108350446
*  Class     :  CSC 2312-002
*  Due Date  :  April 4, 2018
*  Status    :  program runs and compiles on the csegrid
*******************************************************


                 Final Project Read Me
                 Extra Credit (ships sunk) completed


*******************************************************
*  Description of the program
*******************************************************

This program allows a user to play against a computer in the classic game of
Battleship. The user and the computer both have 5 ships, each of different
length, a ship of length 5 for example will take up 5 squares in the player's
grid. Each player has a 10x10 grid hidden from their opponent where they place
their ships. Once ships are placed, a turn consists of choosing a square within
their opponents grid to "fire" a missile. If there is a ship in that location,
it is counted as a hit, if a ship is hit in each square it resides in, the ship
is sunk, the player whose entire fleet is sunk first loses. The User's ship
placement and info are read in from a csv file shipPlacement.csv. The User's
function that reads in input from the file performs exception handling to
account for any bad input values. Error checking is performed throughout the
the program to ensure the User cannot enter negative values, attack out of
bounds, or enter garbage values. The Computer's ships are placed randomly and
its attacks are random, but checks are in place to ensure the Computer doesn't
attack the same spot more than once.

The extra credit of determining if a ship was sunk or not was completed. If a
ship receives as many hits as its length, then that ship was sunk.


*******************************************************
*  Source files
*******************************************************

Name:  main.cpp
   This is the driver program that calls the playGame() function.

Name:  Functions.h
   Contains the definition for playGame() function.

Name: Functions.cpp
   Defines and implements playGame() function. A User object and a Computer
   object are instantiated and the game runs in a while loop until one player's
   score reaches 17. Once a player wins, both the User's fleet and grids are
   displayed as well as the Computer's fleet and grids.

Name: Player.h
   Defines the base class of Player that both User and Computer inherit from.
   Each Player has 5 Watervehicle ships, a name, a score, and 2 grids, one grid
   for your ship placement, the other to keep track of your attacks.

Name: Player.cpp
    Defines and implements the Player class. The default constructor creates two
    empty grids, and the << operator is overloaded to print each Player's fleet.

Name: Computer.h
    Defines the Computer class that inherits from the Player class.

Name: Computer.cpp
    Defines and implements the Computer class. The default constructor
    instantiates 5 Watervehicle ships and sets the name to Computer. Functions
    are defined for randomly generated a shot, placing a ship on the Computer's
    grid, and a function to check all the hits each of Computer's ships receive.

Name: User.h
    Defines the User class that inherits from the Player class.

Name: User.cpp
        Defines and implements the User class. Functions are implemented for
        reading in ship placement info from shipPlacement.csv with exception
        handling, inserting ships on the grid so they don't overlap or run out
        of bounds, generating an attack so that the User only enters row values
        1-10 and column values A-J, and a function to check all the hits each of
        User's ships receive.

Name: Watervehicle.h
        Defines the Watervehicle class.

Name: Watervehicle.cpp
        Defines and implements the Watervehicle class. Default constructors and
        custom constructors are defined. Functions are written to ensure there
        is enough space for a ship on the grid, randomly determining orientation
        (v or h), and randomly determining starting location. The << operator
        is overloaded to display the ship's status (name, length, starting
        location, orientation, hits received, sunk/not sunk).

*******************************************************
*  Status of program
*******************************************************

   The program runs successfully.

   The program was developed and tested on Xcode using macOS.  It was
   compiled, run, and tested on csegrid.ucdenver.pvt.
