/*
 - Patrick Tate
 - HW06
 - CSCI 2421-001
 - Program written using Xcode on MacOS
 - Program Status: this program runs and compiles on the csegrid
 */

#include "Dictionary.h"
#include "DictEntry.h"
#include <list>
#include <string>
#include <fstream>
#include <iostream>

//load the double linked lists dictionary and findWords from their corresponding txt files
void Dictionary::loadLists(){
    DictEntry temp;
    std::string tempWord;
    std::fstream inFile;
    
    for (int i = 0; i < 2; i++) {
        //load dictionary dll
        if (i == 0) {
            inFile.open("dictionary.txt");
            
            while (inFile >> tempWord) {
                temp.setWord(tempWord);
                dictionary.push_back(temp);
            }//while
            inFile.close();
        }//if i = 0 load dictionary
        
        //load findWords dll
        else if (i == 1){
            inFile.open("findwords.txt");
            
            while (inFile >> tempWord) {
                temp.setWord(tempWord);
                findWords.push_back(temp);
            }//while
            inFile.close();
        }//if i = 1 load find words
    }//for
}

//overload << operator to display each dll
std::ostream& operator << (std::ostream &out, Dictionary &obj){
    std::list<DictEntry>::iterator dictPtr;
    std::cout << "Dictionary List:\n";
    for (dictPtr = obj.dictionary.begin(); dictPtr != obj.dictionary.end(); dictPtr++) {
        out << dictPtr->getWord() << std::endl;
    }
    
    std::list<DictEntry>::iterator findPtr;
    std::cout << std::endl << "Find Words List:\n";
    for (findPtr = obj.findWords.begin(); findPtr != obj.findWords.end(); findPtr++) {
        out << findPtr->getWord() << std::endl;
    }
    return out;
}

//searches the dll dictionary for words in the dll findWords
//dictionary dll must be sorted first
//comparisons begin at the front of dictionary, and if the word is found, the amount of comparisons it took is printed
void Dictionary:: compareListsForward(){
    int count = 0;//how many comparisons it took to find the word
    
    //pointers to mover through each dll
    std::list<DictEntry>::iterator dictPtr;
    std::list<DictEntry>::iterator findPtr;
    
    //sort the dictionary dll before searching
    sortDictionary();
    
    //for each word in findWords
    for (findPtr = findWords.begin(); findPtr != findWords.end(); findPtr++) {
        count = 0;//reset counter for each word search
        
        //for each word in dictionary
        for (dictPtr = dictionary.begin(); dictPtr != dictionary.end(); dictPtr++) {
            
            if (dictPtr->getWord() == findPtr->getWord()) {
                count++;
                std::cout << "It took " << count << " comparisons to find: " << findPtr->getWord();
                std::cout << std::endl;
                break;
            }//if
            count++;//increment counter for each iteration
        }//for
    }//for 
}

//sorts the dictionary dll in alphabetical order
void Dictionary::sortDictionary(){
    dictionary.sort();
}

//searches the dll dictionary for words in the dll findWords
//dictionary dll must be sorted first
//comparisons begin at the back of dictionary, and if the word is found, the amount of comparisons it took is printed, and the word is output to a text file revsorted.txt
void Dictionary:: compareListsRev(){
    int count = 0;//how many comparisons it took to find the word
    
    //pointers to move through each dll
    std::list<DictEntry>::reverse_iterator dictPtr;
    std::list<DictEntry>::reverse_iterator findPtr;
    this->sortDictionary();
    
    //variable for sending data to file
    std::ofstream outFile;
    
    //add the new response and type to a new file
    outFile.open("revsorted.txt", std::fstream::app);
    std::string tempWord;
    
    //for each word in findWords dll
    for (findPtr = findWords.rbegin(); findPtr != findWords.rend(); findPtr++) {
        count = 0;//reset counter for each word search
        
        //for each word in dictionary dll
        for (dictPtr = dictionary.rbegin(); dictPtr != dictionary.rend(); dictPtr++) {
            
            if (dictPtr->getWord() == findPtr->getWord()) {
                tempWord = dictPtr->getWord();
                outFile << tempWord << " ";
                count++;
                std::cout << "It took " << count << " comparisons to find: " << findPtr->getWord();
                std::cout << std::endl;
                break;
            }//if
            count++;
        }//for
    }//for
    
    outFile.close();
}
