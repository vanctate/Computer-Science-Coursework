/*
 
 - Patrick Tate
 - 1411-004
 - Lab04
 - Lab Partner: Prin
 - Status: program runs and correctly calculates the value of pi
 - Description: this program will calculate an approximate value of pi based on the series
 4 * ((-1)^n)/(2n+1) where n is an integer the user picks
 
*/


#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
    char playAgain;
    
    //ensure the program runs at least once
    do {
        
        
        int userNum;    //takes the place of n in the series, & will determine how many iterations of the series to do
        
        cout << "Enter a whole number n, and I will calculate an approx value of pi using the series:\n";
        cout << endl << "4 * ((-1)^n)/(2n+1)\n" << endl << "Tip, choose a higher like 1000 or 10000 for greater accuracy\n";
        cin  >> userNum;
        
        
        double userPi = 0.0;//variable to hold the value of numerator/denomenator in the series
        double tempPi = 0.0;//variable to hold sum of numerator/denomenator in the series
        
        
        for (int i = 0; i < userNum; i++) {
            double numerator = pow(-1, i);
            double denomenator = ((2*i)+1);
            tempPi = (numerator/denomenator);
            userPi += tempPi;
        }
        double finalPi = (4*userPi);//variable to calculate the value of the series
        cout << endl << setprecision(15) << finalPi << endl;
        cout << "Again? Press any key to calculate again, press N or n to end.\n";
        cin  >> playAgain;
        
    } while ((playAgain != 'N') && (playAgain != 'n'));
    
    
return 0;
}
