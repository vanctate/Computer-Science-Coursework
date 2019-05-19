//  Patrick Tate
//  1411-004
//  Programming Assignment 2 Outline
//  Status: not running, just an outline


#include <iostream>
#include <string>
#include "functions.hpp"

using namespace std;

//struct to hold the string responses in file and their associated type of response(pos,neg,vague)
struct eightBall
{
    string response;    //hold the response
    int type;           //hold the type of response (positive = 1, negative = -1, vague = 0)
};

int main()
{
    
    char userInput; //user entry to decide what option they would like
    
    do {           //using a do while loop to keep the program running until the user want it to end
        
        //basic menu display
        cout << "Welcome to the Magic Eight Ball Please selection an option below.\n\n";
        cout << "Enter A to show the responses in our Magic Eight Ball file.\n";
        cout << "Enter B to play Magic Eight Ball.\n";
        cout << "Enter C to add responses to the Magic Eight Ball file.\n";
        cout << "Enter D to print out responses alphabetically.\n";
        cout << "Enter E to print out responses by type(positve, negative, vague).\n";
        cout << "Enter F to write questions with responses to a file.\n";
        cout << "Enter G to exit.\n";
        cin  >> userInput;
        userInput = toupper(userInput);//convert userInput to capital letter for easier comparisons
        
        switch (userInput) {
            case 'A' :
                //will use function showFile()
                cout << "show responses from file\n" << endl;   //read in responses from file
                break;
                
            case 'B' :
                //will use function play8ball()
                cout << "play Magic Eight Ball\n" << endl;   //play magic 8 ball
                break;
                
            case 'C' :
                //will use function addRes()
                cout << "add responses to magic 8 ball file\n" << endl;  //add responses
                break;
                
            case 'D' :
                //will use function showAlpha()
                cout << "print responses alphabetically\n" << endl;  //print responses from file alphabe
                break;
                
            case 'E' :
                //will use function showType()
                cout << "print responses by type.\n";
                
                break;
                
            case 'F' :
                //will use function addQA()
                cout << "write questions with responses to a file.\n";
                
                break;
                
            case 'G' :
                return 0;//exit program
                
                break;
                
            default :
                cout << "Invalid entry, please enter a valid value\n" << endl; //catch bad input from user
        }
        
    } while (userInput != 'G');
    
    return 0;
}





























