//Time Class Definition with const member functions

#ifndef TIME_H
#define TIME_H

#include<iostream>

using namespace std;

class Time
{
   
    
private:
    int hour;  //0-23 (24 hour clock format)
    int minute; //0-59
    int ap;
    
public:
    //default constructor
   
    Time(int = 1, int = 55, int = 2);
    //set functions - not const since they modify private data
    //The & return type enables cascading
    
    Time& setTime(int, int, int);
    Time& setHour(int);
    Time& setMinute(int);
    Time& setAP(int);
    Time& getTime()const;
    //get functions - (normally always declared const)
    int getHour() const;
    int getMinute() const;
    
    
    //print functions - (normally always declared const since they do not modify private members, merely inspect
    void printUniversal() const;
    void printStandard()const;
    void convertToUniversal();
    
    double operator-(const Time &);
    friend ostream& operator<<(ostream &, const Time &);
    friend istream& operator>>(istream &, Time &);
};

#endif
