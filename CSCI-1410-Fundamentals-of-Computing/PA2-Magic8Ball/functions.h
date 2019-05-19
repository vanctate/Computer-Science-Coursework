/*
 - Patrick Tate
 - 1410-002
 - Programming Assignment 2
 - Status: program runs, compiles, and works correctly
 - Developed in Xcode on Mac OS
 - This program simulates the Magic 8 Ball game. First the user must select option A in the menu to load an array of structs with the magic 8 ball file information. The user is prevented from playing magic 8 ball(option B) until they have loaded the array(option A). A random response is selected from the struct array by a random number function, this ensures the user gets a random response from the array for every question they ask. Option C lets users add responses and type(positive, negative, vague) to the struct array and adds them to the magic 8 ball file as well. MAXSIZE is set to 100, so the user is prevented from adding a 101st element. Option D sorts the responses alphabetically and displays them. Since lowercase letters > upper case letters, when the user is adding a new response they are instructed to begin each response with a capitol letter, the user is also prompted to keep response type(positive, negative, vague) all lowercase and one word. Option E prints out all the responses by type(positive, negative, vague). Option F uses a different struct to add questsions and anwers to a file and a new struct array.
 */

#ifndef func_h
#define func_h
#include <string>

//struct to hold the string responses from file and their associated type of response(pos,neg,vague)
struct eightBall
{
    std::string response;    //hold the response
    std::string type;        //hold the type of response (positive, negative, vague)
};

//struct to for the new questions and answers sent to the file (option F in the menu)
struct addQA
{
    std::string question;//asking 8ball question
    std::string response;//8ball's response
};

void loadArray(eightBall gameArray[], int &currentSize);//loads array of structs w/ 8ball file info
void playGame(eightBall gameArray[], int currentSize);//plays magic 8 ball game
void canYouPlay(eightBall gameArray[], int currentSize);//lets user playGame if they loaded array first
void showArray(eightBall gameArray[], int currentSize);//displays contents of 8ball struct array
int randNum(int currentSize);//random number generated to select a random element in the response array
void sortResponse(eightBall gameArray[], int currentSize);//bubble sort responses alphabetically
void swap(std:: string &a, std:: string &b);//used in sort function
eightBall newResponse();//enables user to enter new response/type & sends it to a new file
bool addResponse(eightBall respToAdd, eightBall gameArray[], int &currentSize, const int MAXSIZE);//adds new response and response type to 8ball struct array
void showType(eightBall gameArray[], int currentSize);//display responses by type (pos,neg,vague)
addQA addToFile(addQA new8ballQA[], int &sizeOf);//adds questions/answers to new file (part F)
bool loadQAarray(addQA newQA, addQA new8ballQA[], int &sizeOf, const int MAXSIZE);//adds new QA to its array

#endif /* func_h */

