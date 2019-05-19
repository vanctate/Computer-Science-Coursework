/*
 - Patrick Tate
 - 1410-002
 - Programming Assignment 2
 - Status: program runs, compiles, and works correctly
 - Developed in Xcode on Mac OS
 - This program simulates the Magic 8 Ball game. First the user must select option A in the menu to load an array of structs with the magic 8 ball file information. The user is prevented from playing magic 8 ball(option B) until they have loaded the array(option A). A random response is selected from the struct array by a random number function, this ensures the user gets a random response from the array for every question they ask. Option C lets users add responses and type(positive, negative, vague) to the struct array and adds them to the magic 8 ball file as well. MAXSIZE is set to 100, so the user is prevented from adding a 101st element. Option D sorts the responses alphabetically and displays them. Since lowercase letters > upper case letters, when the user is adding a new response they are instructed to begin each response with a capitol letter, the user is also prompted to keep response type(positive, negative, vague) all lowercase and one word. Option E prints out all the responses by type(positive, negative, vague). Option F uses a different struct to add questsions and anwers to a file and a new struct array.
 */

#include <iostream>
#include <string>
#include "functions.h"

using namespace std;


int main()
{
    const int MAXSIZE = 100;//arbitrarily chose 100
    
    //variables for parts A-E
    eightBall newElement;
    eightBall gameArray[MAXSIZE];
    int currentSize = 0;
    
    //variables for part F
    //array of QA structs for option F, adding questions and anwers to a new file
    addQA newQA;
    addQA new8ballQA[MAXSIZE];
    int sizeOf = 0;
    
    char userInput; //variable for user to decide what option they would like from menu
    
    do {           //using a do while loop to keep the program running until the user wants it to end
        
        //basic menu display
        cout << "Welcome to the Magic Eight Ball. Please select an option below.\n";
        cout << "Enter capital or lowercase letters.\n";
        cout << "Note: make sure to load the responses (A), before playing the game (B).\n\n";
        cout << "Enter A to load responses from our Magic Eight Ball file.\n";
        cout << "Enter B to play Magic Eight Ball(must select A before this option).\n";
        cout << "Enter C to add responses a new Magic Eight Ball file.\n";
        cout << "Enter D to print out responses alphabetically.\n";
        cout << "Enter E to print out responses by type(positve, negative, vague).\n";
        cout << "Enter F to write questions with responses to a file.\n";
        cout << "Enter G to exit.\n";
        cin  >> userInput;
        userInput = toupper(userInput);//convert userInput to capital letter for easier comparisons
        
        switch (userInput) {
            case 'A' :
                //load contents of 8 ball responses from file into eighBall struct array
                //the user must run this to load the struct array before playing 8ball
                loadArray(gameArray, currentSize);
                break;
                
            case 'B' :
                //determine if user has loaded the array before playing
                //if user has selected A first, canYouPlay calls playGame fucntion
                canYouPlay(gameArray, currentSize);
                break;
                
            case 'C' :
                //add response to the array and the new response gets written to a new file as well
                if (currentSize < MAXSIZE) {
                    newElement = newResponse();
                    addResponse(newElement, gameArray, currentSize, MAXSIZE);
                }
                else
                    cout << "Sorry your list is full. No more can be added.\n";
                break;
                
            case 'D' :
                //print responses alphabetically
                sortResponse(gameArray, currentSize);
                showArray(gameArray, currentSize);
                break;
                
            case 'E' :
                //print responses by type (positive, negative, vague)
                showType(gameArray, currentSize);
                break;
                
            case 'F' :
                //lets user add question and anwers to new array and new file
                if (sizeOf < MAXSIZE) {
                    newQA = addToFile(new8ballQA, sizeOf);
                    loadQAarray(newQA, new8ballQA, sizeOf, MAXSIZE);
                }
                else
                    cout << "Sorry your list is full. No more can be added.\n";
                
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

