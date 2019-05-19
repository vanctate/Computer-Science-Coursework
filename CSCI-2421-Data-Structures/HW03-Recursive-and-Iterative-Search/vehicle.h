/*
 - Patrick Tate
 - HW03
 - CSCI 2421-001
 - Program written using Xcode on MacOS
 - Program Status: this program runs and compiles on the csegrid
 */

#ifndef vehicle_h
#define vehicle_h

#include <string>
#include <vector>

class Vehicle
{
private:
    int year;
    std::string make;
    std::string model;

public:
    Vehicle();
    void setYear(int _year){year = _year;}
    void setMake(std::string _make){make = _make;}
    void setModel(std::string _model){model = _model;}
    int getYear(){return year;}
    std::string getMake(){return make;}
    std::string getModel(){return model;}
};


#endif /* vehicle_h */
