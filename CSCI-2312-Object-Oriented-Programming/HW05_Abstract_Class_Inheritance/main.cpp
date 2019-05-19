/*
 - Patrick Tate
 - HW05
 - CSCI 2312-002
 - Program written using Xcode on MacOS
 - Program Status: this program runs and compiles on the csegrid
 */

#include <iostream>
#include "animal.h"
using namespace std;

int main() {
    
    Dog doggo;
    doggo.readInfo();
    doggo.subtractTen();
    doggo.printInfo();
    cout << endl;
    
    Fish fishy;
    fishy.readInfo();
    fishy.printInfo();
    cout << endl;
    
    Horse horsey;
    horsey.readInfo();
    horsey.addOne();
    horsey.printInfo();
    cout << endl;
    
    Lizard lizzy;
    lizzy.readInfo();
    lizzy.printInfo();
    cout << endl;
    
    Monkey hanuman;
    hanuman.readInfo();
    hanuman.changeEndangered();
    hanuman.printInfo();
    cout << endl;
    
    return 0;
}
