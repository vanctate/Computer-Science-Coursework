/*
 - Patrick Tate
 - HW 6
 - CSCI 2312
 - Program written using Xcode on MacOS
 - Program Status: compiled, run, and tested on csegrid
 */

#ifndef student_h
#define student_h
#include <string>
#include <cstring>
#include <iostream>

struct Student{
    int id;
    char name[20];
};

std::ostream& operator << (std::ostream &out, Student s)
{
    out << s.name << "\t" << s.id;
    return out;
}

#endif /* student_h */
