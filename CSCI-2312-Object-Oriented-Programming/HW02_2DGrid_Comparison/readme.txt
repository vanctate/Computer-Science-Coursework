*******************************************************
*  Name      : Patrick Tate
*  Student ID: 108350446
*  Class     : CSC 2312-002
*  Due Date  : Feb. 7, 2018
*******************************************************


                 Read Me


*******************************************************
*  Description of the program
*******************************************************

This program utilizes the Matrix class to create two grids, where a user
specifies rows and columns. The two grids are filled with 0's, and then 1/3 of
each grid is randomly filled with 1's. The two grids are then compared, if the
element in grid1 and the element in grid2 are both 1's, a 1 is placed in the
corresponding element of a third grid.


*******************************************************
*  Source files
*******************************************************

Name:  main.cpp
   This is the driver program that instantiates two Matrix objects, each with
   their own grid. Each object's grid is filled with 0's, then filled 1/3 with
   randomly placed 1's. The two grids are then compared and the resulting grid
   of the comparison is printed.

Name:  Matrix.h
   Contains the definition for the class Matrix.

Name: Matrix.cpp
   Defines and implements the Matrix class. Functions are defined for displaying
   a grid, filling a grid with 0's, randomly filling 1/3 of a grid with 1's, and
   comparing two grids.


*******************************************************
*  Status of program
*******************************************************

   The program runs successfully.

   The program was developed and tested on Xcode using macOS.  It was
   compiled, run, and tested on csegrid.ucdenver.pvt.
