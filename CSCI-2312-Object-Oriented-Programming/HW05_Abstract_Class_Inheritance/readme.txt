*******************************************************
*  Name      :  Patrick Tate
*  Student ID:  108350446
*  Class     :  CSC 2312-002
*  Due Date  :  March 28, 2018
*******************************************************


                 Read Me


*******************************************************
*  Description of the program
*******************************************************

This program uses the abstract base class Animal to serve as the base class for
the inherited classes Dog, Fish, Horse, Lizard, and Monkey. The Animal class
has member variables name and color, and pure virtual functions readInfo and
printInfo that are overridden in the derived classes. Each inherited animal
class reads in values from a file and sets its appropriate variables accordingly.
Each inherited class has exception handling to check the input from the file as
valid. The exceptions check for values that should be of type int but are not,
and if a class has a boolean they check to make sure the input values are either
TRUE or FALSE. If an exception is caught, the user is given the choice to either
exit the program and fix the file themselves, or manually enter the correct
value. The functions that handle these exceptions are in functions.h. The Dog
class has a function that subtracts 10 from the Dog's read in weight, the Horse
class has a function that adds 1 hand to the Horse's read in height, and the
Monkey class has a function that switches its endangered boolean value to the
opposite.


*******************************************************
*  Source files
*******************************************************

Name:  main.cpp
   This is the driver program that instantiates each object, loads their info,
   and prints their info.

Name:  animal.h
   Contains the definition for the abstract base class Animal, as well as the
   class definitions for Dog, Fish, Horse, Lizard, and Monkey.

Name: dog.cpp
   Defines and implements the Dog class. Functions are defined for loading in
   info with exception handling, and a function to subtract 10 from weight, and
   printing the object's info.

Name: fish.cpp
   Defines and implements the Fish class. Functions are defined for loading in
   info with exception handling, and printing the object's info.

Name: horse.cpp
    Defines and implements the Horse class. Functions are defined for loading in
    info with exception handling, printing the object's info, and adding 1 hand
    to the object's height.

Name: lizard.cpp
    Defines and implements the Lizard class. Functions are defined for loading
    in info with exception handling, and printing the object's info.

Name: monkey.cpp
    Defines and implements the Monkey class. Functions are defined for loading
    in info with exception handling, printing the object's info, and switching
    the endangered boolean to the opposite value.

Name: functions.cpp
    Defines and implements the functions for catching exceptions. 3 functions
    check for valid int values, checkAge, checkWeight, checkHeight, and one
    function checks to validate boolean values, checkBool.

*******************************************************
*  Status of program
*******************************************************

   The program runs successfully.

   The program was developed and tested on Xcode using macOS.  It was
   compiled, run, and tested on csegrid.ucdenver.pvt.
