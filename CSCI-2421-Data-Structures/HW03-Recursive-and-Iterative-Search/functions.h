/*
 - Patrick Tate
 - HW03
 - CSCI 2421-001
 - Program written using Xcode on MacOS
 - Program Status: this program runs and compiles on the csegrid
 */

#ifndef functions_h
#define functions_h

#include <fstream>
#include <iostream>
#include <vector>
#include <string>

//load a vector with Vehicle objects from txt file
//vector is unsorted after this function
void loadVec(std::vector<Vehicle> &_vehicleVec){
    
    //temp Vehicle object and variables to hold input from txt file
    Vehicle tempVehicle;
    int tempYear;
    std::string tempMake, tempModel;
    
    //open txt file and obtain Vehicle information to pass to vector
    std::fstream inFile;
    inFile.open("vehiclein.txt");
    
    while (inFile >> tempYear) {
        
        //get vehicle info
        inFile.ignore();
        getline(inFile, tempMake);
        getline(inFile, tempModel);
        
        //set object's variables
        tempVehicle.setYear(tempYear);
        tempVehicle.setMake(tempMake);
        tempVehicle.setModel(tempModel);
      
        //add Vehicle object to vector of Vehicles
        _vehicleVec.push_back(tempVehicle);
        
    }//while
  
    inFile.close();
}

//sort vector of Vehicle objects
void sortVec(std::vector<Vehicle> &vehicleVec, int type){
    //sort by model
    if (type == 2) {
        for (int i = 0; i < vehicleVec.size() - 1; i++) {
            for (int flag = 0; flag < vehicleVec.size() - 1 -i; flag++) {
                if (vehicleVec[flag].getMake() > vehicleVec[flag+1].getMake()) {
                    std::swap(vehicleVec[flag], vehicleVec[flag+1]);
                }//if
            }//for
        }//for
    }//type == 2/make
    
    //sort by make
    if (type == 3) {
        for (int i = 0; i < vehicleVec.size() - 1; i++) {
            for (int flag = 0; flag < vehicleVec.size() - 1 -i; flag++) {
                if (vehicleVec[flag].getModel() > vehicleVec[flag+1].getModel()) {
                    std::swap(vehicleVec[flag], vehicleVec[flag+1]);
                }//if
            }//for
        }//for
    }//type == 3/model
    
    //sort by year
    if (type == 4) {
        for (int i = 0; i < vehicleVec.size() - 1; i++) {
            for (int flag = 0; flag < vehicleVec.size() - 1 -i; flag++) {
                if (vehicleVec[flag].getYear() > vehicleVec[flag+1].getYear()) {
                    std::swap(vehicleVec[flag], vehicleVec[flag+1]);
                }//if
            }//for
        }//for
    }//type == 4/year
}

//recursive binary search by make or model
int binSearchRec(std::vector<Vehicle> v, int first, int last, std::string target, int type){
    int index = 0;
    
    //searching by make
    if (type == 2) {
        if (first > last) {
            index = -1;//make not found
        }
        else
        {
            int mid = first + (last - first)/2;
            if (target == v[mid].getMake()) {
                index = mid;
            }
            else if (target < v[mid].getMake())
                index = binSearchRec(v, first, mid - 1, target, type);
            else if (target > v[mid].getMake())
                index = binSearchRec(v, mid + 1, last, target, type);
        }//else
    }//if type == 2/make
    
    //searching by model
    if (type == 3) {
        if (first > last) {
            index = -1;//model not found
        }
        else
        {
            int mid = first + (last - first)/2;
            if (target == v[mid].getModel()) {
                index = mid;
            }
            else if (target < v[mid].getModel())
                index = binSearchRec(v, first, mid - 1, target, type);
            else if (target > v[mid].getModel())
                index = binSearchRec(v, mid + 1, last, target, type);
        }//else
    }//if type == 3/model

    return index;
}

//recursive binary search by year
int binSearchRec(std::vector<Vehicle> v, int first, int last, int target){
    int index = 0;
    if (first > last) {
        index = -1;//year not found
    }
    else
    {
        int mid = first + (last - first)/2;
        if (target == v[mid].getYear()) {
            index = mid;
        }
        else if (target < v[mid].getYear())
            index = binSearchRec(v, first, mid - 1, target);
        else if (target > v[mid].getYear())
            index = binSearchRec(v, mid + 1, last, target);
    }
    return index;
}

//iterative search by make/model
int binSearchIter(std::vector<Vehicle> v, std::string target, int type){
   
    int first = 0;
    int last = v.size() - 1;
    int middle;
    int position = -1;//returns -1 if make/model not found
    bool found = false;
    
    //by make
    if (type == 2) {
        while (!found && (first <= last)) {
            middle = (first + last)/2;
            if (v[middle].getMake() == target) {
                found = true;
                position = middle;
            }//
            else if (v[middle].getMake() > target)
                last = middle - 1;
            else
                first = middle + 1;
        }//while
    }//if type == 2/make
    
    //by model
    else if (type == 3){
        while (!found && (first <= last)) {
            middle = (first + last)/2;
            if (v[middle].getModel() == target) {
                found = true;
                position = middle;
            }//
            else if (v[middle].getModel() > target)
                last = middle - 1;
            else
                first = middle + 1;
        }//while
    }//else if type == 3/model
    return position;
}

//iterative search by year
int binSearchIter(std::vector<Vehicle> v, int target){
    int first = 0;
    int last = v.size() - 1;
    int middle;
    int position = -1;//returns -1 if year not found
    bool found = false;
    
    while (!found && (first <= last)) {
        middle = (first + last)/2;
        if (v[middle].getYear() == target) {
            found = true;
            position = middle;
        }//
        else if (v[middle].getYear() > target)
            last = middle - 1;
        else
            first = middle + 1;
    }//while
    return position;
}

//used in sorting functions
void swap(Vehicle &a, Vehicle &b){
    Vehicle temp = a;
    a = b;
    b = temp;
}

//shows the Vehicle info the user searched for if found
void displaySearch(std::vector<Vehicle> vehicleVec, int type, int position){
    //by make
    if (type == 2) {
        if (position >= 0) {
            std::cout << "Vehicle make found:" << std::endl;
            std::cout << "\t\t" << vehicleVec[position].getMake() << std::endl;
            std::cout << "\t\t" << vehicleVec[position].getModel() << std::endl;
            std::cout << "\t\t" << vehicleVec[position].getYear() << std::endl;
        }//if
        else{
            std::cout << "Sorry, vehicle make not found.\n";
        }//else
    }//if type == 2/make
    
    //by model
    else if (type == 3){
        if (position >= 0) {
            std::cout << "Vehicle model found:" << std::endl;
            std::cout << "\t\t" << vehicleVec[position].getMake() << std::endl;
            std::cout << "\t\t" << vehicleVec[position].getModel() << std::endl;
            std::cout << "\t\t" << vehicleVec[position].getYear() << std::endl;
        }
        else{
            std::cout << "Sorry, vehicle model not found.\n";
        }
    }//if type == 3/model
    
    //by year
    else if (type == 4){
        if (position >= 0) {
            std::cout << "Vehicle year found:" << std::endl;
            std::cout << "\t\t" << vehicleVec[position].getMake() << std::endl;
            std::cout << "\t\t" << vehicleVec[position].getModel() << std::endl;
            std::cout << "\t\t" << vehicleVec[position].getYear() << std::endl;
        }
        else{
            std::cout << "Sorry, vehicle year not found.\n";
        }
    }//if type == 4/year
}

//display vector in unsortd order for user reference
void displayVec(std::vector<Vehicle> v){
    for (int i = 0; i < v.size(); i++) {
        std::cout << v[i].getMake() << std::endl;
        std::cout << v[i].getModel() << std::endl;
        std::cout << v[i].getYear() << std::endl << std::endl;
    }//for
}
#endif /* functions_h */
