//  Patrick Tate
//  1411-004
//  Programming Assignment 3 Outline
//  Status: not running, just an outline

#ifndef dealer_h
#define dealer_h
#include <string>

class Car
{
private:
    std::string vin;
    std::string make;
    std::string model;
    int year;
    double price;
public:
    void setVin(std::string);
    void setMake(std::string);
    void setModel(std::string);
    void setYear(int);
    void setPrice(double);
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
};

class Dealer
{
private:
    std::string name;
    int number;
public:
    void setName(std::string);
    void setNumber(int);
    std::string getName() const
    { return name;}
    int getNumber() const
    { return number;}
};

#endif /* dealer_h */
