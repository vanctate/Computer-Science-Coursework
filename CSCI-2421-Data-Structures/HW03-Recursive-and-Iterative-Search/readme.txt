*******************************************************
*  Name      :  Patrick Tate
*  Student ID:  108350446
*  Class     :  CSC 2421
*  Due Date  :  Feb. 15 2018
*******************************************************


                 Read Me


*******************************************************
*  Description of the program
*******************************************************

This program uses the Vehicle class to read in vehicle information from a file,
where each Vehicle object has a make, model and year associated with it. A sort
function is overloaded so that a vector of Vehicle objects can be sorted either
by make, model, or year, where make and model are strings, and year is an int.
There is also an overloaded binary recursive search and an overloaded binary
iterative search. This program presents the user with a menu and lets them
search for a vehicle by make, model, or year, either using the recursive binary
search or the iterative binary search.


*******************************************************
*  Source files
*******************************************************

Name:  main.cpp
   Main program.  This is the driver program that presents the user with a menu
   to choose what kind of search they want to do.

Name:  vehicle.h
   Contains the definition for the class Vehicle.

Name: vehicle.cpp
   Defines the default constructor the the vehicle class.

Name: functions.h
   Contains the functions to load a vector of Vehicle objects from a txt file,
   the overloaded sort function, and the overloaded recursive binary search, and
   iterative binary search.


*******************************************************
*  Status of program
*******************************************************

   The program runs successfully.

   The program was developed and tested on Xcode using macOS.  It was
   compiled, run, and tested on csegrid.ucdenver.pvt.
