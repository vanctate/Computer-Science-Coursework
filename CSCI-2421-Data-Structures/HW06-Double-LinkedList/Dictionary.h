/*
 - Patrick Tate
 - HW06
 - CSCI 2421-001
 - Program written using Xcode on MacOS
 - Program Status: this program runs and compiles on the csegrid
 */
#include <list>
#include <string>
#include "DictEntry.h"

#ifndef Dictionary_h
#define Dictionary_h

class Dictionary {
private:
    std::list<DictEntry> dictionary;//create dll named dictionary to store words from dictionary.txt
    std::list<DictEntry> findWords;//create dll of find words from findwords.txt
    
public:
    void loadLists();//load each dll with words from txt files
    friend std::ostream& operator << (std::ostream &out, Dictionary &obj);//overload << operator
    void compareListsForward();//search dictionary dll for words from findWords, starting at front
    void sortDictionary();
    void compareListsRev();//search dictionary dll for words from findWords, starting at back
};

#endif /* Dictionary_h */
