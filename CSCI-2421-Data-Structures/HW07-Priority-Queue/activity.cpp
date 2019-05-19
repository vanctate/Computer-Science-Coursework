/*
 - Patrick Tate
 - HW07
 - CSCI 2421-001
 - Program written using Xcode on MacOS
 - Program Status: this program runs and compiles on the csegrid
 */

#include "activity.h"

Activity::Activity()
{
    time = -1;
    event = "";
    rank = -1;
}

//overloads the < operator for a priority queue of Activity objects
//Activity objects with the highest rank pushed to top of the queue
//if rank is equal, the arrival event gets higher precedence
bool Activity:: operator<(const Activity& rhs) const
{
    if (rank != rhs.rank) {
        return rank < rhs.rank;
    }
    else
        return event > rhs.event;
    //return rank < rhs.rank;
}
