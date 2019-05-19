/*
 - Patrick Tate
 - 1410-002
 - Programming Assignment 2
 - Status: program runs, compiles, and works correctly
 - Developed in Xcode on Mac OS
 - This program simulates the Magic 8 Ball game. First the user must select option A in the menu to load an array of structs with the magic 8 ball file information. The user is prevented from playing magic 8 ball(option B) until they have loaded the array(option A). A random response is selected from the struct array by a random number function, this ensures the user gets a random response from the array for every question they ask. Option C lets users add responses and type(positive, negative, vague) to the struct array and adds them to the magic 8 ball file as well. MAXSIZE is set to 100, so the user is prevented from adding a 101st element. Option D sorts the responses alphabetically and displays them. Since lowercase letters > upper case letters, when the user is adding a new response they are instructed to begin each response with a capitol letter, the user is also prompted to keep response type(positive, negative, vague) all lowercase and one word. Option E prints out all the responses by type(positive, negative, vague). Option F uses a different struct to add questsions and anwers to a file and a new struct array.
 */

#include "functions.h"
#include <iostream>
#include <fstream>
#include <string>


using namespace std;

//loads the array with eightBall structs, currentSize is passed as a reference so its value changes, allowing the user to play 8 ball
void loadArray(eightBall eightBall[], int &currentSize){
    
    ifstream inFile;
    
    //open file and pass contents into array of structs
    inFile.open("8ball.txt");
    int i = 0;  //set counter to determine currentSize
    while (inFile.good()) {
        
        //get responses and types from list and put into struct array
        getline(inFile, eightBall[i].response);
        inFile >> eightBall[i].type;
        
        i++;
        inFile.ignore();
    }//while
    
    currentSize = i;//change currentSize so user can play game
    
    inFile.close();
    
    
    cout << endl << "Load successfull. You may now play Magic 8 Ball (option B).\n\n";
}

//play magic8ball, user asks a question and 8ball gives random response from the array
void playGame(eightBall eightBall[], int currentSize){
    string temp;
    cout << "Welcome to the Magic 8 Ball.\n";
    cout << "Please enter your question and I will respond.\n";
    cin.ignore();
    getline(cin, temp);
    
    int response;
    response = randNum(currentSize);
    cout << eightBall[response].response << endl << endl;//8ball responds with a random array element
}

//lets user play magic 8 ball if they have loaded the array with response info first
void canYouPlay(eightBall gameArray[], int currentSize)
{
    if (currentSize == 0) {
        cout << "You must load the responses first.\n";
        cout << "Select option A first, then you may play Magic 8 Ball.\n\n";
    }
    else
        playGame(gameArray, currentSize);
}

//displays contents of the array
void showArray(eightBall gameArray[], int currentSize)
{
    for (int i = 0; i < currentSize; i++) {
        cout << gameArray[i].response << endl;
        cout << gameArray[i].type << endl << endl;
    }
    cout << endl;
}

//used to generate a random number for a random array element selection
int randNum(int currentSize)
{
    //returns a random number from 0 to currentSize - 1
    //which is used to select a random element from the struct array
    int randGen = (rand()%currentSize);
    return randGen;
}

//bubble sort for sorting the array alphabetically by response, part D in the menu
void sortResponse(eightBall gameArray[], int currentSize)
{
    int maxElement;
    int index;
    
    for (maxElement = (currentSize - 1); maxElement > 0; maxElement--) {
        for (index = 0; index < maxElement; index++) {
            if (gameArray[index].response > gameArray[index + 1].response) {
                swap(gameArray[index].response, gameArray[index + 1].response);
                swap(gameArray[index].type, gameArray[index + 1].type);
            }//if
        }//for
    }//for
}

//used for bubble sort
void swap(string &a, string &b)
{
    string temp = a;
    a = b;
    b = temp;
}

//lets user enter new response/type and that new response/type is sent to a file to be stored
eightBall newResponse()
{
    ofstream outFile;
    
    eightBall temp;
    cout << "Enter the response, make sure to begin responses with a capital letter.\n";
    cin.ignore();
    getline(cin, temp.response);
    cout << "Now enter the type of response as one word, all lower case(positive, negative, vague).\n";
    cin  >> temp.type;
    
    //add the new response and type to a file
    outFile.open("8ballResponses.txt", fstream::app);
    
    outFile << temp.response << endl;
    outFile << temp.type << endl;
    
    outFile.close();
    
    return temp;
}

//adds a new response to the current 8ball struct array, part C int the menu
bool addResponse(eightBall respToAdd, eightBall gameArray[], int &currentSize, const int MAXSIZE)
{
    currentSize++;
    if (currentSize <= MAXSIZE) {
        gameArray[currentSize - 1] = respToAdd;
        return true;
    }
    else
        return false;
}

//prints responses by type(positive, negative, vague), part E in the menu
void showType(eightBall gameArray[], int currentSize)
{
    //display positive responses
    cout << endl << "Positive responses: " << endl;
    for (int i = 0; i < currentSize; i++) {
        if (gameArray[i].type == "positive") {
            cout << gameArray[i].response << endl;
        }//if
    }//for
    
    //display negative responses
    cout << endl << "Negative responses: " << endl;
    for (int i = 0; i < currentSize; i++) {
        if (gameArray[i].type == "negative") {
            cout << gameArray[i].response << endl;
        }//if
    }//for
    
    //display vague responses
    cout << endl << "Vague responses: " << endl;
    for (int i = 0; i < currentSize; i++) {
        if (gameArray[i].type == "vague") {
            cout << gameArray[i].response << endl;
        }//if
    }//for
    
    cout << endl;
}

//adds questions and answers to a new file ands stores them in a new array of question/answer structs
//part F in the menu
addQA addToFile(addQA new8ballQA[], int &sizeOf)
{
    ofstream outFile;
    
    addQA temp;
    cout << "Enter the question.\n";
    cin.ignore();
    getline(cin, temp.question);
    cout << "Now enter the response.\n";
    getline(cin, temp.response);
    
    //add the new response and type to a new file
    outFile.open("newQA.txt", fstream::app);
    
    outFile << temp.question << endl;
    outFile << temp.response << endl;
    
    outFile.close();
    
    return temp;
}

//loads an array of structs for question and anwers to new file (part F in menu)
bool loadQAarray(addQA newQA, addQA new8ballQA[], int &sizeOf, const int MAXSIZE)
{
    sizeOf++;
    if (sizeOf <= MAXSIZE) {
        new8ballQA[sizeOf - 1] = newQA;
        return true;
    }
    else
        return false;
}


