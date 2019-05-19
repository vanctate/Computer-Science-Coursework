/*
 - Patrick Tate
 - CSCI 1410-002
 - Programming Assignment 3
 - Status: program successfully compiles and runs
 - Developed using XCode on MacOS
 - This program uses two classes, a Dealer class and a Car class to read information from a file and store that information as a vector of Dealer objects, each which contain a dynamic array of Car objects. The user is prompted by a menu that repeats until the user selects 7 to exit. Option 1 reads in the data from the file and stores it in a vector. Option 2 displays all the Dealers to the user. Option 3 allows the user to choose a dealer by number, and then displays that Dealer's Car objects. Option 4 allows the user to to choose a Dealer by number and add a new Car object to that Dealer's dynamic array. Option 5 allows the user to choose a Dealer by number, and then that Dealer's Car objects are sorted by VIN in ascending order. Option 6 takes the vector of Dealers and sends each Dealer object and their Car objects to a new file. For the Dealer and Car class, the get and set functions are written inline during the class declartion in dealer.h, while the rest are defined in dealer.cpp. The functions used for options 1 - 6 are written in functions.h. The main.cpp implements all functions with a switch menu.
 */

#ifndef functions_h
#define functions_h
#include "dealer.h"
#include <vector>
#include <fstream>
#include <string>

//option 1 in main, pass empty vector by reference to change its contents
void loadVector(std::vector<Dealer> &dealers){
    
    //temp Car object and its associated data
    Car tempCar;
    std::string tempVin;
    std::string tempMake;
    std::string tempModel;
    int tempYear;
    double tempPrice;
    
    //temp Dealer object and its associated data
    Dealer tempDealer;
    Car *carPtr;
    std::string dealerName;
    int dealerNum, numOfCars;
    
    std::fstream inFile;//input file variable to read in data from dealers.txt
    
    //open dealers.txt and pass info into vector
    inFile.open("/Users/Van/Documents/CU_Denver/1410Computing/PA/PA3/dealers.txt");
    while(inFile.good()){
        
        //get Dealer info from dealers.txt
        getline(inFile, dealerName);
        inFile >> dealerNum;
        inFile >> numOfCars;
        inFile.ignore();
        
        //set temp Dealer object data to file data
        tempDealer.setDealerName(dealerName);
        tempDealer.setDealerNumber(dealerNum);
        tempDealer.setNumOfCars(numOfCars);
        
        //use empty Car object pointer to create dynamic array of Car objects
        carPtr = new Car[numOfCars];
        
        //loop through the Dealer object's number of cars, and store each Car object in the dynamic array
        for (int i = 0; i < numOfCars; i++) {
            getline(inFile, tempVin);
            getline(inFile, tempMake);
            getline(inFile, tempModel);
            inFile >> tempYear;
            inFile >> tempPrice;
            inFile.ignore();
            
            tempCar.setVin(tempVin);
            tempCar.setMake(tempMake);
            tempCar.setModel(tempModel);
            tempCar.setYear(tempYear);
            tempCar.setPrice(tempPrice);
            
            carPtr[i] = tempCar;//store each new Car object in the dynamic array
        }//for
        
        tempDealer.setCarArrayPtr(carPtr);//set Dealer object's car pointer to carPtr
        
        dealers.push_back(tempDealer);//add each dealer to the vector
        
    }//while
    std::cout << "Load successful.\n";
    std::cout << "Read in " << dealers.size() << " dealers." << std::endl;
    
    inFile.close();//close file after reading in data
}

//option 2, display dealers
void showDealers(std::vector<Dealer> dealers){
    
    for (int i = 0; i < dealers.size() ; i++) {
        std::cout << dealers[i];
    }
}

//option 3, choose a dealer and display that dealer's cars
void displayCars(std::vector<Dealer> dealers){
    //variables to hold which dealer user wants to search and an index for its position
    int dealerNum, dealerIndex = 0;
    Car *carArrayPtr;//Car pointer to store dealer object's pointer
    bool found = false;
    
    //search for dealer number
    std::cout << "Enter the dealer number whos cars you would like to see.\n";
    std::cin  >> dealerNum;
    std::cin.ignore();
    for (int i = 0; i < dealers.size(); i++) {
        if (dealers[i].getDealerNumber() == dealerNum ) {
            dealerIndex = i;
            found = true;
        }//if
    }//for
    if (!found) {
        std::cout << "Sorry, that dealer is not found.\n";//dealer number not found
    }
    else
    {
        //set dummy pointer to the dealer's pointer
        carArrayPtr = dealers[dealerIndex].getCarArrayPtr();
        
        //display dealer's cars
        for (int i = 0; i < dealers[dealerIndex].getNumOfCars(); i++) {
            std::cout << carArrayPtr[i];
        }//for
    }//else
}

//option 4, choose dealer and add a car
void addCar(std::vector<Dealer> &dealers){
    //variables to hold which dealer user wants to search and an index for its position
    int dealerNum, dealerIndex = 0;
    Car *carArrayPtr;
    Car carToAdd;
    bool found = false;
    
    //new car info
    std::string vin;
    std::string make;
    std::string model;
    int year;
    double price;

    //find out what dealer the user wants to add to
    std::cout << "Enter the dealer number that you'd like to add a car to.\n";
    std::cin  >> dealerNum;
    std::cin.ignore();
    for (int i = 0; i < dealers.size(); i++) {
        if (dealers[i].getDealerNumber() == dealerNum ) {
            dealerIndex = i;
            found = true;
        }//if
    }//for
    if (!found) {
        std::cout << "Sorry, that dealer is not found.\n";
    }
    else
    {
        //get new car info from user
        std::cout << "Enter the car VIN.\n";
        getline(std::cin, vin);
        std::cout << "Enter the car make.\n";
        getline(std::cin, make);
        std::cout << "Enter the car model.\n";
        getline(std::cin, model);
        std::cout << "Enter the car year.\n";
        std::cin  >> year;
        std::cout << "Enter the car price.\n";
        std::cin  >> price;
        std::cin.ignore();
        carToAdd.setVin(vin);
        carToAdd.setMake(make);
        carToAdd.setModel(model);
        carToAdd.setYear(year);
        carToAdd.setPrice(price);
        
        int setFlag = (dealers[dealerIndex].getNumOfCars() + 1);//for adding 1 to dealer object's dynamic array
        carArrayPtr = new Car[setFlag];//create new dynamic array 1 size bigger than previous, to hold new car
        
        //copy Dealer object's dynamic array info
        for (int i = 0; i < dealers[dealerIndex].getNumOfCars(); i++) {
            carArrayPtr[i] = dealers[dealerIndex].getCarArrayPtr()[i];
        }
        
        carArrayPtr[setFlag - 1] = carToAdd;//add new Car objec to dynamic array
        
        dealers[dealerIndex].setCarArrayPtr(carArrayPtr);//set Dealer object's carArrayPtr to the new dynamic array containing new car
        int newNumCars = (dealers[dealerIndex].getNumOfCars() + 1);//increment Dealer object's number of cars
        dealers[dealerIndex].setNumOfCars(newNumCars);//set Dealer object's numOfCars to the new number
        
    }//else
}

//option 5, sort cars by VIN in ascending order
void bubbleSort(std::vector<Dealer> &dealers){

    Car tempCar;//temp Scores object to hold sorted value
    int dealerNum, dealerIndex;//variables to find biggest VIN in array and its index
    bool found = true;//flag for whether dealer was found or not
    Car *carArrayPtr = nullptr;//dummy pointer to hold dynamic array info
    std::string maxElement;
    
    std::cout << "Enter the dealer number that you'd like to sort the cars by VIN.\n";
    std::cin  >> dealerNum;
    std::cin.ignore();
    for (int i = 0; i < dealers.size(); i++) {
        if (dealers[i].getDealerNumber() == dealerNum ) {
            dealerIndex = i;
            found = true;
        }//if
    }//for
    if (!found) {
        std::cout << "Sorry, that dealer is not found.\n";
    }
    else
    {
        carArrayPtr = new Car[dealers[dealerIndex].getNumOfCars()];
        
        for (int i = 0; i < dealers[dealerIndex].getNumOfCars(); i++) {
            carArrayPtr[i] = dealers[dealerIndex].getCarArrayPtr()[i];
        }//for
        
        int flag;//used to determine dynamic array elements
        
        for (int j = 0; j < dealers[dealerIndex].getNumOfCars() - 1; j++) {
            for (flag = 0; flag < dealers[dealerIndex].getNumOfCars() - 1 - j; flag++) {
                if (carArrayPtr[flag].getVin() > carArrayPtr[flag + 1].getVin()) {
                    std::swap(carArrayPtr[flag], carArrayPtr[flag + 1]);
                }//if
            }//for
        }//for
    }//else
    dealers[dealerIndex].setCarArrayPtr(carArrayPtr);
}

//used for bubble sort in option 5
void swap(Car &a, Car &b){
    Car temp = a;
        a = b;
        b = temp;
}

//option 6, write vector of dealer object's and their cars to new file
void sendFileout(std::vector<Dealer> &dealers){
    
    //variable for sending data to file
    std::ofstream outFile;
    
    //add the new response and type to a new file
    outFile.open("/Users/Van/Desktop/newDealers.txt", std::fstream::app);
    
    //start loop to get dealer's info, and then the dealer's cars
    for (int i = 0; i < dealers.size(); i++) {
        
        //send dealer's info to new file
        outFile << dealers[i].getDealerName() << std::endl;
        outFile << dealers[i].getDealerNumber() << std::endl;
        outFile << dealers[i].getNumOfCars() << std::endl;
        
        //send each car's info to the file in order
        for (int j = 0; j < dealers[i].getNumOfCars(); j++) {
            outFile << dealers[i].getCarArrayPtr()[j];
        }//for
    }//for
    
    outFile.close();//close file
}

#endif /* functions_h */
