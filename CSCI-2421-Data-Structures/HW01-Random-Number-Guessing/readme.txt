*******************************************************
*  Name      :   Patrick Tate
*  Student ID:   108350446
*  Class     :   CSC 2421
*  Due Date  :   Feb. 01, 2018
*******************************************************


                 Read Me


*******************************************************
*  Description of the program
*******************************************************

This program is a game where the user inputs how many random numbers they want
to guess(totalNums), and the user also inputs the range for the random numbers
1 - "range." A vector is created with "totalNums" random numbers in the range
of 1 - "range." The user then has 3 chances to guess all the numbers correctly.
The user has a guessCorrect variable that increments by 1 for each correct
guess, when guessCorrect is equivalent to totalNums, the user wins. If the user
hasn't guessed all the correct numbers after 3 attempts, they lose. The program
accounts for duplicates, for example if the random numbers are 2,2,3, and the
user guesses 2,1,0, the user will get only 1 guess correct.


*******************************************************
*  Source files
*******************************************************

Name:  main.cpp
   Main program.  This is the driver program that instantiates an object of the
 Guess class and calls the playGame function on that object.

Name:  guess.h
   Contains the definition for the class Guess.

Name: guess.cpp
   Defines and implements the Guess class. Functions are defined for obtaining
   user input, creating a random number vector, a guess vector, comparing
   vectors, and playing the game.


*******************************************************
*  Status of program
*******************************************************

   The program runs successfully.

   The program was developed and tested on Xcode using macOS.  It was
   compiled, run, and tested on csegrid.ucdenver.pvt.
