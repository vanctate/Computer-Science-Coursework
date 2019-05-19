/*
 - Patrick Tate
 - HW07
 - CSCI 2421-001
 - Program written using Xcode on MacOS
 - Program Status: this program runs and compiles on the csegrid
 */
#include <queue>
#include "activity.h"

//loads info from input file that contains arrival time and transaction length
//Activity objects are pushed into a priority queue where the lowest time has the highest priority
//each customer's wait time is recorded as well as the total customers served
//the average wait time is then calculated and displayed
void bankSim(std::priority_queue<Activity> &q);
