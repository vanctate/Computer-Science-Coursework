*******************************************************
*  Name      :  Patrick Tate
*  Student ID:  108350446
*  Class     :  CSC 2312-002
*  Due Date  :  April 26, 2018
*******************************************************


                 Read Me


*******************************************************
*  Description of the program
*******************************************************

This program utilizes a templated List class made from scratch, not the stl List
class, to demonstrate the functionality of a linked list. The function insertBack
pushes nodes into the back of the list. Following best practices there is a copy
constructor that performs a deep copy of a List object, an overloaded = operator
that also performs a deep copy of a List object, and a destructor that calls the
clear function for pointers that lose scope. There are also functions push_front
that pushes data, not nodes, into the front of the list, push_back that pushes
data, not nodes, into the back of the list, pop_front which removes data from
the front of the list, in this case removing is setting the data value to -1
because the csegrid did not accept the NULL value, pop_back which removes data
from the back of the list, and a printList function. The functionality of each
of these functions is demonstrated in main.cpp as well as reading in data from
a binary file students.dat. The binary file is placed in a List of Students,
where Students is a struct with a char array and an int id.


*******************************************************
*  Source files
*******************************************************

Name:  main.cpp
   This is the driver program that demonstrates the functionality of the templated
   List class. A List of ints is created, the copy constructor is used to create
   a second List with the same values, and a third List utilizes the overloaded
   = operator to copy the values from the first List as well. The insertBack,
   push_front, push_back, pop_front, pop_back, printList, and clear functions
   are all demonstrated. Exception handling is performed on the pop_front and
   pop_back functions. Lastly, a list of Students is read in from a binary file
   students.dat and is placed into a List of Students and printed.

Name:  list.h
   Contains the definition for the templated List class.

Name: list.hpp
   Defines and implements the templated List class.

Name: student.h
   Contains the definition for the Student struct which contains a char array
   for a Student's name, and an int id. The >> operator is overloaded for
   printing the List of Students.

*******************************************************
*  Status of program
*******************************************************

   The program runs successfully.

   The program was developed and tested on Xcode using macOS.  It was
   compiled, run, and tested on csegrid.ucdenver.pvt.
