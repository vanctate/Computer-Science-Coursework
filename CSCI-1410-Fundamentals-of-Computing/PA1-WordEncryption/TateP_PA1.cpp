/*
 
 -  Patrick Tate
 -  Last Date Modified: September 17 2017
 -  Programming Assignment 1: Encryption
 -  Description: this program encrypts & decrypts single word strings and characters. The user enters
    the word/character they want encrypted or decrypted, along with a numeric key, and the word is
    encrypted or decrypted accordingly. For example, if the user enters the word "Climbing" to be 
    encrypted with a key of 3, the word "ingClimb" will be returned. Likewise, if the user enters the
    character 'A' to be encrypted with a key of 2, the character 'C' will be returned. The decryption
    reverses both of the examples.
 -  Status: program successfully compiles, runs, encrypts and decrypts single word strings and characters
 -  CSCI 1410-002
 
*/


#include <iostream>
#include <string>
#include <cmath>

using namespace std;

void encryptWord(string &, int &);  //function to encrypt single word string
void decryptWord(string &, int &);  //function to decrypt single word string
void encryptChar(string &, int &);  //function to encrypt single letter character
void decryptChar(string &, int &);  //function to decrypt single letter character

int main()
{
    string userWord, temp;
    int userKey;
    
    int userInput = 0;  //initialize userInput variable to ensure it doesn't contain a garbage value
    while(userInput != 5) {     //ensure program runs at least once
        
        cout << "Welcome to encryption. Please selection an option below." << endl << endl;
        cout << "Enter 1 to encrypt entire word." << endl;
        cout << "Enter 2 to decrypt entire word." << endl;
        cout << "Enter 3 to encrypt each letter rotation" << endl;
        cout << "Enter 4 to decrypt each letter rotation" << endl;
        cout << "Enter 5 to exit" << endl;
        cin  >> userInput;
        
        switch (userInput) {
            case 1 :
                cout << "Please enter the single word you would like to encrypt.\n";
                cin  >> userWord;
                cout << "Now please enter the numeric key for encryption.\n";
                cin  >> userKey;
                //encrypt the user's word
                encryptWord(userWord, userKey);
                
                break;
            
            case 2 :
                cout << "Please enter the word you want to decrypt.\n";
                cin  >> userWord;
                cout << "Now pleaes enter the key for the decryption.\n";
                cin  >> userKey;
                //decrypt the user's word
                decryptWord(userWord, userKey);
                
                break;
                
            case 3 :
                cout << "Please enter the letter you want to encrypt.\n";
                cin  >> userWord;
                cout << "Now please enter the encryption key.\n";
                cin  >> userKey;
                //encrypt the user's character
                encryptChar(userWord, userKey);
                
                break;
                
            case 4 :
                cout << "Please enter the character you want to decrypt.\n";
                cin  >> userWord;
                cout << "Now please enter the key for the decryption.\n";
                cin  >> userKey;
                //decrypt the user's character
                decryptChar(userWord, userKey);
                
                break;
            
            case 5 :
                return 0;  //exit program
                break;
                
            default :   //account for invalid entries 
                cout << "Invalid entry, please enter a valid value\n" << endl;  //validate user input
        }//switch
        
    }//while
    
    return 0;
}

void encryptWord(string &userWord, int &userKey)
{
    string temp = userWord;
    for (int i = 0; i < userWord.size(); i++) {
        temp[(i+userKey)%userWord.size()] = userWord[i];
    }
    cout << "Your word is encrypted and now reads as: " << temp << endl << endl;
}

void decryptWord(string &userWord, int &userKey)
{
    string temp = userWord;
    for (int i =0; i < userWord.size(); i++){
        temp[((i-userKey)+userWord.size())%userWord.size()] = userWord[i];
    }
    cout << "Your word is decrypted and reads as: " << temp << endl << endl;
}

void encryptChar(string &userWord, int &userKey)
{
    userKey = userKey % 'z';//distance between key and z
    for (int i =0; i < userWord.size(); i++) {
        if('z' - userWord[i] >= userKey){
            userWord[i] = userWord[i]+userKey;
        }
        else {
            userWord[i]=(userWord[i]+'A'-1+userKey)%'z';
        }
    }
    
    cout << "Your letter is now encrypted and is now: " << userWord << endl << endl;
}

void decryptChar(string &userWord, int &userKey)
{
    userKey = userKey % 'z';//distance between key and z
    for (int i = 0; i < userWord.size(); i++) {
        if (userWord[i]-'A' >= userKey) {
            userWord[i] = userWord[i]-userKey;
        }
        else {
            
            userWord[i] = ('z'-'A'+1)+(abs(userKey-userWord[i]))%'z';
            
        }
    }
    
    cout << "Your decrypted letter is: " << userWord << endl << endl;
}




