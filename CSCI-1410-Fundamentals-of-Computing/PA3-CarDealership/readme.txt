*******************************************************
*  Name      :  Patrick Tate
*  Student ID:
*  Class     :  CSCI 1410
*  Due Date  :  December 1st, 2017
*******************************************************


                 Read Me


*******************************************************
*  Description of the program
*******************************************************

This program uses two classes, a Dealer class and a Car class to read
information from a file and store that information as a vector of Dealer
objects, each which contain a dynamic array of Car objects. The user is
prompted by a menu that repeats until the user selects 7 to exit. Option 1
reads in the data from the file and stores it in a vector. Option 2 displays
all the Dealers to the user. Option 3 allows the user to choose a dealer by
number, and then displays that Dealer's Car objects. Option 4 allows the user to
to choose a Dealer by number and add a new Car object to that Dealer's dynamic
array. Option 5 allows the user to choose a Dealer by number, and then that
Dealer's Car objects are sorted by VIN in ascending order. Option 6 takes the
vector of Dealers and sends each Dealer object and their Car objects to a new
file. For the Dealer and Car class, the get and set functions are written
inline during the class declaration in dealer.h, while the rest are defined in
dealer.cpp. The functions used for options 1 - 6 are written in functions.h.
The main.cpp implements all functions with a switch menu.


*******************************************************
*  Source files
*******************************************************

Name:  main.cpp
   Main program. This is the driver program that calls sub-functions
   to read data from an input file of Dealers and their associated Cars.

Name:  dealer.h
   Contains the definition for the Car and Dealer classes.

Name: functions.h
   Defines and implements the functions for the Car and Dealer classes.

Name: dealer.cpp
   Default constructors for Car and Dealer classes as well as ostream overloading
   for both classes


*******************************************************
*  Status of program
*******************************************************

   The program runs successfully.

   The program was developed and tested on Xcode using macOS.  It was
   compiled, run, and tested on csegrid.ucdenver.pvt.
