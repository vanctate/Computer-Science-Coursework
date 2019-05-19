/*
 - Patrick Tate
 - HW07
 - CSCI 2421-001
 - Program written using Xcode on MacOS
 - Program Status: this program runs and compiles on the csegrid
 */

#include <iostream>
#include <queue>
#include <fstream>
#include "activity.h"
#include "functions.h"
using namespace std;

int main() {
    priority_queue<Activity> q;
    bankSim(q);
    return 0;
}
