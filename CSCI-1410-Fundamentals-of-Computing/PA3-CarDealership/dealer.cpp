/*
 - Patrick Tate
 - CSCI 1410-002
 - Programming Assignment 3
 - Status: program successfully compiles and runs
 - Developed using XCode on MacOS
 - This program uses two classes, a Dealer class and a Car class to read information from a file and store that information as a vector of Dealer objects, each which contain a dynamic array of Car objects. The user is prompted by a menu that repeats until the user selects 7 to exit. Option 1 reads in the data from the file and stores it in a vector. Option 2 displays all the Dealers to the user. Option 3 allows the user to choose a dealer by number, and then displays that Dealer's Car objects. Option 4 allows the user to to choose a Dealer by number and add a new Car object to that Dealer's dynamic array. Option 5 allows the user to choose a Dealer by number, and then that Dealer's Car objects are sorted by VIN in ascending order. Option 6 takes the vector of Dealers and sends each Dealer object and their Car objects to a new file. For the Dealer and Car class, the get and set functions are written inline during the class declartion in dealer.h, while the rest are defined in dealer.cpp. The functions used for options 1 - 6 are written in functions.h. The main.cpp implements all functions with a switch menu.
 */

#include "dealer.h"
//default constructors for Car and Dealer class as well as ostream overloading for both classes

Dealer::Dealer(){
    name = "";
    number = -1;
    numOfCars = -1;
    CarArrayPtr = nullptr;
}

Car::Car(){
    vin = "";
    make = "";
    model = "";
    year = -1;
    price = -1.0;
}

Dealer::Dealer(std::string dName, int dNumber, int dNumCars, Car *carPtr){
    name = dName;
    number = dNumber;
    numOfCars = dNumCars;
    CarArrayPtr = carPtr;
}

Car::Car(std::string cVin, std::string cMake, std::string cModel, int cYear, double cPrice){
    vin = cVin;
    make = cMake;
    model = cModel;
    year = cYear;
    price = cPrice;
}

std::ostream& operator<<(std::ostream& out, Dealer dDealer){
    out << "Dealer name: " << dDealer.getDealerName() << std::endl << "Dealer number: " << dDealer.getDealerNumber() << std::endl
    << "Dealer's number of cars: " << dDealer.getNumOfCars() << std::endl;
    
 return out;
}
std::ostream& operator<<(std::ostream& out, Car cCar){
    
    out << cCar.getVin() << std::endl;
    out << cCar.getMake() << std::endl;
    out << cCar.getModel() << std:: endl;
    out << cCar.getYear() << std::endl;
    out << "$" << cCar.getPrice() << std:: endl;
    
    return out;
}
