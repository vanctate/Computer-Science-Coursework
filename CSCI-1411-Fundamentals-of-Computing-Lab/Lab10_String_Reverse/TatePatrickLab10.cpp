/*
 - Patrick Tate
 - CSCI 1411-004
 - Lab 10
 - Description: This program prompts the user for a word and then returns that word in reverse. The user enters a string, which is then converted to a cstring, and passed as a pointer to a function that reverses the cstring, which is then displayed to the user.
 - Lab Partner: Prin
 - Status: Program successfully compiles and runs
 */

#include <iostream>
#include <string>

using namespace std;

//function to return a reversed cstring
char *reverseCString(char *cstring, unsigned long size);

int main() {

    char *word = nullptr;//used to store user's word into a cstring
    string yourString;//variable to hold word from the user

    cout << "Enter the word you want.\n";
    getline(cin, yourString);

    word = (char*)yourString.c_str();//convert user's word into a cstring

    unsigned long size = (yourString.size() + 1);//account for the /n character in cstring

    char *reverseString = nullptr;//variable to hold the reversed cstring

    reverseString = reverseCString(word, size);

    //display the reversed cstring
    for (int j = 0; j < size; j++) {
        cout << *(reverseString + j);
    }

    return 0;

}

//accepts a pointer to a cstring and returns the cstring in reverse
char *reverseCString(char *cstring, unsigned long size)
{
    char* backCString = new char[size];
    backCString[size -1] = '\n';

    for (int i = 0; i < size; i++) {
        backCString[size - i -2] = cstring[i];
    }
    return backCString;
}
