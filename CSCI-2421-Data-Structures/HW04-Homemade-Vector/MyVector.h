/*
 - Patrick Tate
 - HW04
 - CSCI 2421-001
 - Program written using Xcode on MacOS
 - Program Status: this program runs and compiles on the csegrid
 */

#ifndef MYVECTOR_
#define MYVECTOR_
/*Defines a MyVector type which mirrors the STL vector class.  It uses templates and dynamic memory allocation*/

namespace HW4
{
typedef int T;
class MyVector
{
private:
    int vsize = 0;
    T* vec = nullptr;

public:
    MyVector();
    T operator[] (int index);//overload [] operator
    void pop_back();
    void push_back(T value);
    int size(){return vsize;}
    bool empty();
    int search(T Value);
    
};

}//namespace
#endif
