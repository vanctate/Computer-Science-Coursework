/*
 - Patrick Tate
 - HW07
 - CSCI 2421-001
 - Program written using Xcode on MacOS
 - Program Status: this program runs and compiles on the csegrid
 */

#include "functions.h"
#include "activity.h"
#include <string>
#include <fstream>
#include <iostream>
using namespace std;

//loads info from input file that contains arrival time and transaction length
//Activity objects are pushed into a priority queue where the lowest time has the highest priority
//each customer's wait time is recorded as well as the total customers served
//the average wait time is then calculated and displayed
void bankSim(priority_queue<Activity> &q)
{
    //temp object and associated variables
    Activity customer;
    int time, tranactionLength;
    
    //variables for the simulation to calculate total/average wait time and total customers
    int totalWait = 0;
    int currentDeparture;
    double totalCustomers = 0.0;
    
    //for first customer
    bool first = true;
    
    fstream inFile;
    inFile.open("input.txt");
    
    while (inFile >> time) {
        inFile >> tranactionLength;
        
        //first customer not dependant on any previous customers, no wait time
        if (first) {
            //first arrival
            customer.setEvent("Arrival");
            customer.setTime(time);
            customer.setRank(1000 - time);
            q.push(customer);
            
            currentDeparture = time + tranactionLength;//set for next arrival customer
            
            //first departure
            customer.setEvent("Departure");
            customer.setTime(time + tranactionLength);
            customer.setRank(1000 - currentDeparture);
            q.push(customer);
            
            totalCustomers++;
            first = false;//only need to run this block once
        }
        else{
            //if time > currentDeparture the line is empty so no wait time
            if (time > currentDeparture) {
                //arrival
                customer.setEvent("Arrival");
                customer.setTime(time);
                customer.setRank(1000 - time);
                q.push(customer);
                //departure
                customer.setEvent("Departure");
                customer.setTime(time + tranactionLength);
                customer.setRank(1000 - (time + tranactionLength));
                q.push(customer);
                currentDeparture = time + tranactionLength;//set for next arrival customer
                
                totalCustomers++;
            }//if customer arrives to an empty line ie no wait
            
            //line not empty when customer arrives
            else {
                //arrival
                customer.setEvent("Arrival");
                customer.setTime(time);
                customer.setRank(1000-time);
                q.push(customer);
                //departure
                customer.setEvent("Departure");
                customer.setTime(currentDeparture+tranactionLength);
                customer.setRank(1000-(currentDeparture+tranactionLength));
                q.push(customer);
                
                totalWait = totalWait + (currentDeparture - time);
                currentDeparture = currentDeparture + tranactionLength;//set for next arrival customer
                totalCustomers++;
            }//else customer has a wait
            
        }//else not first customer
        
    }//while

    //displaying simulation results
    cout << endl << "Output from processing the bank simulation:\n";
    cout << "Simulation Begins\n";
    while (!q.empty()) {
        cout << "Processing " << q.top().getEvent() << " event at time: " << q.top().getTime() << endl;
        q.pop();
    }//while
    
    cout << "Simulation Ends\n\n";
    cout << "Final Statistics:\n";
    cout << "\t" << "Total customers served: " << totalCustomers << endl;
    cout << "\t" << "Average wait time: " << totalWait/totalCustomers << endl << endl;
}
