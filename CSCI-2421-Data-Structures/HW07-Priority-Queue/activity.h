/*
 - Patrick Tate
 - HW07
 - CSCI 2421-001
 - Program written using Xcode on MacOS
 - Program Status: this program runs and compiles on the csegrid
 */

#include <string>
#ifndef activity_h
#define activity_h
class Activity
{
private:
    int time;//time the arrival or departure takes place
    std::string event;//arrival or departure
    int rank;//for priority queue sorting
public:
    Activity();
    //get
    int getTime() const {return time;}
    std::string getEvent() const {return event;}
    //set
    void setTime(int _time){time = _time;}
    void setEvent(std::string _event){event = _event;}
    void setRank(int _rank){rank = _rank;}
    
    //for a priority queue of objects
    bool operator<(const Activity& rhs) const;
};
#endif /* activity_h */
