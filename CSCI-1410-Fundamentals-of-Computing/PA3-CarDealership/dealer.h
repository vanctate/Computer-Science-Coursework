/*
 - Patrick Tate
 - CSCI 1410-002
 - Programming Assignment 3
 - Status: program successfully compiles and runs
 - Developed using XCode on MacOS
 - This program uses two classes, a Dealer class and a Car class to read information from a file and store that information as a vector of Dealer objects, each which contain a dynamic array of Car objects. The user is prompted by a menu that repeats until the user selects 7 to exit. Option 1 reads in the data from the file and stores it in a vector. Option 2 displays all the Dealers to the user. Option 3 allows the user to choose a dealer by number, and then displays that Dealer's Car objects. Option 4 allows the user to to choose a Dealer by number and add a new Car object to that Dealer's dynamic array. Option 5 allows the user to choose a Dealer by number, and then that Dealer's Car objects are sorted by VIN in ascending order. Option 6 takes the vector of Dealers and sends each Dealer object and their Car objects to a new file. For the Dealer and Car class, the get and set functions are written inline during the class declartion in dealer.h, while the rest are defined in dealer.cpp. The functions used for options 1 - 6 are written in functions.h. The main.cpp implements all functions with a switch menu.
 */

#ifndef dealer_h
#define dealer_h
#include <string>
#include <iostream>

class Car
{
private:
    std::string vin;
    std::string make;
    std::string model;
    int year;
    double price;
public:
    Car();//default constructor
    Car(std::string cVin, std::string cMake, std::string cModel, int cYear, double cPrice);//constructor
    void setVin(std::string cVin){vin = cVin;}
    void setMake(std::string cMake){make = cMake;}
    void setModel(std::string cModel){model = cModel;}
    void setYear(int cYear){year = cYear;}
    void setPrice(double cPrice){price = cPrice;}
    std::string getVin() const
    { return vin;}
    std::string getMake() const
    { return make;}
    std::string getModel() const
    { return model;}
    int getYear() const
    { return year;}
    double getPrice() const
    { return price;}
    friend std::ostream& operator<<(std::ostream& out, Car cCar);
};

class Dealer
{
private:
    std::string name;
    int number;
    int numOfCars;
    Car *CarArrayPtr;
public:
    Dealer();//default constructor
    Dealer(std::string dName, int dNumber, int dNumCars, Car *carPtr);//constructor
    void setDealerName(std::string dName){name = dName;}
    void setDealerNumber(int dNumber){number = dNumber;}
    void setCarArrayPtr(Car *dCarArrayPtr){CarArrayPtr = dCarArrayPtr;}
    void setNumOfCars(int pNumOfCars){numOfCars = pNumOfCars;}
    std::string getDealerName() const
    { return name;}
    int getDealerNumber() const
    { return number;}
    Car* getCarArrayPtr() const
    { return CarArrayPtr;}
    int getNumOfCars() const
    { return numOfCars;}
    friend std::ostream& operator<<(std::ostream& out, Dealer dDealer);
};

#endif /* dealer_h */
