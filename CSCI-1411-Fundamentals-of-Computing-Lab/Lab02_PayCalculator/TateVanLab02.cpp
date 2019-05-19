/*  
    Van Tate
    CSCI 1411-004
    Lab 02 - Employee Pay Rate Implementation 
    Lab Partner: Paul
 */
 
#include <iostream>
#include <string>

using namespace std;

int main()
{
    
    string firstName, lastName;
    double payRate, week1_hours, week2_hours, time_half_hours1, time_half_hours2, time_half_payRate, time_half_earnings, gross_pay, net_pay;
    double union_dues = 10.00, taxes = 0.75;
    
    //ask the user their name, hours worked, and pay rate
    cout << "Hello, please enter your first name\n";
    cin  >> firstName;
    cout << "Thank you " << firstName << ". Now please enter your last name\n";
    cin  >> lastName;
    cout << "Thank you " << firstName << " " << lastName << endl;
    cout << "Now please enter how many hours you worked in week 1.\n";
    cin  >> week1_hours;
    cout << "Thank you, now please enter your hours for week 2\n";
    cin  >> week2_hours;
    cout << "Thank you. Lastly, pleae enter your hourly pay rate\n";
    cin  >> payRate;
    
    //determine if employee earned time and half in week 1
    if (week1_hours > 40) {
        time_half_hours1 = week1_hours - 40;
    } else {
        time_half_hours1 = 0.0;
    }
    
    //deteremine if employee earned time and half in week 2
    if (week2_hours > 40) {
        time_half_hours2 = week2_hours - 40;
    } else {
        time_half_hours2 = 0.0;
    }
    
    //calculate time and half pay
    time_half_payRate = payRate * 1.5;
    time_half_earnings = (time_half_hours1 + time_half_hours2) * time_half_payRate;
    
    //calculate total pay before taxes and union dues
    gross_pay = ((week1_hours + week2_hours) * payRate) + ((time_half_hours1 + time_half_hours2) * time_half_payRate);
    
    cout << endl << "Your gross pay before taxes and union dues is: $" << gross_pay << endl << endl;
    
    //calculate net pay taking out taxes and union dues
    net_pay = (gross_pay * taxes) - (2 * union_dues);
    
    cout << "Your net pay is: $" << net_pay << endl << endl << "Thank you " << firstName <<  ", for a job well done." << endl << endl;
    
    
    
return 0;
}
