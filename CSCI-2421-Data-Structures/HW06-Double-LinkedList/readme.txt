*******************************************************
*  Name      :  Patrick Tate
*  Student ID:  108350446
*  Class     :  CSCI 2421
*  Due Date  :  March 8th 2018
*******************************************************


                 Read Me


*******************************************************
*  Description of the program
*******************************************************

This program utilizes the Dictionary class to read in two lists of words, each
stored in a separate stl double linked list. The Dictionary class contains two
functions that search the sorted list "dictionary" to see if it contains words
from the second list "findWords", and how many iterations it took to find the
word. The first function utilizes an stl iterator to search the list from the
beginning, and the second function utilizes an stl reverse iterator to search
the list from the back, and if the word is found in both lists it is written out
to a new file called revsorted.txt


*******************************************************
*  Source files
*******************************************************

Name:  main.cpp
   Main program. This is the driver program that demonstrates the correct
   functionality of the Dictionary member functions.

Name:  Dictionary.h
   Contains the definition for the class Dictionary.

Name: Dictionary.cpp
   Defines the functions to load the lists of words, search from the front,
   search from the back, and the overloaded << operator, and sort the dictionary
   double linked list.

Name: DictEntry.h
    Each list in the Dictionary class is of type DictEntry, where DictEntry
    contains the string value of the word as well as the definition. For this
    program we only utilized the string definition. The < operator and the <<
    operator are both overloaded in the DictEntry class.


*******************************************************
*  Status of program
*******************************************************

   The program runs successfully.

   The program was developed and tested on Xcode using macOS.  It was
   compiled, run, and tested on csegrid.ucdenver.pvt.
