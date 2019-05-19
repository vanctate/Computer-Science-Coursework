*******************************************************
*  Name      :  Patrick Tate
*  Student ID:  108350446
*  Class     :  CSCI 2421
*  Due Date  :  March 29 2018
*******************************************************


                 Read Me


*******************************************************
*  Description of the program
*******************************************************

This program utilizes the Activity class to run a bank simulation. A text file
containing arrival times and transaction lengths is read in. Each bank
"customer" is represented by 2 Activity objects(which contain an arrival time
or a departure time). Each Activity object is pushed into a priority queue
that is sorted based on time, where the lowest time has the highest priority.
The total number of customers is calculated as well as the average wait time.


*******************************************************
*  Source files
*******************************************************

Name:  main.cpp
   Main program. This is the driver program instantiates a priority queue and
   passes it to the bankSimulation function.

Name:  activity.h
   Contains the definition for the class Activity.

Name: activity.cpp
   Defines the default Activity constructor as well as the overloaded < operator
   used for sorting the priority queue of Activity objects.

Name: functions.h
    Contains the function prototype for the bankSimulation function.

Name: functions.cpp
    Defines and implements the bankSimulation function. A txt file of arrival
    times and transaction lengths are read in. Each customer is represented by
    two Activity objects that contain the arrival time or departure time. The
    total number of bank customers served is calculated as well as average wait
    time.


*******************************************************
*  Status of program
*******************************************************

   The program runs successfully.

   The program was developed and tested on Xcode using macOS.  It was
   compiled, run, and tested on csegrid.ucdenver.pvt.
