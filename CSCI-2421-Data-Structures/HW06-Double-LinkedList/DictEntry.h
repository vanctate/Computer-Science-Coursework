/*
 - Patrick Tate
 - HW06
 - CSCI 2421-001
 - Program written using Xcode on MacOS
 - Program Status: this program runs and compiles on the csegrid
 */

#ifndef DICTENTRY_
#define DICTENTRY_
#include <string>
#include <list>
#include <iostream>

typedef std::string wordType;
class DictEntry
{
private:
    wordType word;
    wordType definition;
   
public:
    DictEntry(){word = ""; definition = "";}
   
    //overload stream operator
    friend std::ostream& operator << (std::ostream &out, DictEntry const &dictEntry){
        out << dictEntry.word << std::endl;
        return out;
    }
    wordType getWord(){return word;}
    void setWord(wordType _word){word = _word;}
    wordType getDef(){return definition;}
    void setDef(wordType _def){definition = _def;}
    
    //overload < operator for sorting function
    bool operator < (const DictEntry &entry) const {
        return (word < entry.word);}
    
};
#endif
