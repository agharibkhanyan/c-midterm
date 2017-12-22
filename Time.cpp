#include <iostream>
#include <iomanip>
#include "Time.h"

using namespace std;




//Constructor function to initialize private data
//remember a constructor is called whenever a new object of
//a class data type is instantiated, if a constructor is not defined the C++ do
//nothing constructor is run, it is better to ALWAYS have your own contructor
//once you have your own constructor the default is no longer available
//Constructors can and should be overloaded
//Constructors cannot be const since they always manipulate private data


Time::Time(int hour, int minute, int t)
{
    setTime(hour, minute, t);
}

/*SET FUNCTIONS: Never const since they need to modify private member data*/

//setTime function now is set up to enable cascading

Time& Time::setTime(int hour, int minute, int t)
{
    setHour(hour);
    setMinute(minute);
    setAP(t);
    return *this;
}

//setHour function is now set up to enable cascading
Time& Time::setHour(int h)
{
    hour = (h >= 0 && h < 12) ? h : 0;  //validates hour, if valid set to h, else set to 0
    return *this;
}

//setMinute function is now set up to enable cascading
Time& Time::setMinute(int m)
{
    minute = (m >= 0 && m < 12) ? m : 0;  //validates minute, if valid set to m, else set to 0
    return *this;
}
Time& Time::setAP(int ampm)
{
    ap = ampm;
    return *this;
}


//get Hour
int Time::getHour() const  //must be const since prototype is const
{
    return hour;
}

//get Minute
int Time::getMinute() const  //must be const since prototype is const
{
    return minute;
}

/*PRINT FUNCTIONS:  Normally do not modify private member data so should be const*/

void Time::printUniversal()const  //must be const since prototype is const
{
    cout << setfill('0') << setw(2) << hour << ":"
    << setw(2) << minute << ":" << endl;
}

void Time::printStandard()const  //must be const since prototype is const
{
    cout << ((hour == 0 || hour == 12) ? 12 : hour % 12) << ":"
    << setfill('0') << setw(2) << minute << ":"
    << setw(2) << (hour < 12 ? "AM" : "PM") << endl;
}

void Time::convertToUniversal()
{
    if (ap == 1 ) {
         ;
    }
    else if (ap == 2 )
    {
        hour = hour + 12;
    }
    
}
//make convert to universal then once its done make if statements
//inside ostream to check if its AM or PM
ostream &operator <<(ostream &output, const Time &time)
{
    if (time.ap == 1) {
        
        output << ((time.hour == 0 || time.hour == 12) ? 12 : time.hour % 12) << ":"
        << setfill('0') << setw(2) << time.minute << ":"
        << setw(2) << "AM";
    }
    else if (time.ap == 2) {
        output << ((time.hour == 0 || time.hour == 12) ? 12 : time.hour % 12) << ":"
        << setfill('0') << setw(2) << time.minute << ":"
        << setw(2) << "PM";
        
    }
    return output;
}

istream &operator >>(istream &input, Time &time)
{
    
    input >> setw(2) >> time.hour;
    if (time.hour >= 0 && time.hour <= 12) {
    }
    else {
        do {
            input >> setw(2) >> time.hour;
        } while (time.hour <= 0 || time.hour >= 12);
    }
    input.ignore(1);
    input >> setw(2) >> time.minute;
    if (time.minute >= 0 && time.minute <= 60) {
    }
    else {
        do {
            input >> setw(2) >> time.minute;
        } while (time.minute <= 0 || time.minute >= 60);
    }
    
    input.ignore(1);
    input >> setw(2) >> time.ap;
    if (time.ap == 1 || time.ap == 2) {
    }
    else {
        do {
            input >> setw(2) >> time.ap;
        } while (time.ap != 1 || time.ap != 2);
    }
    time.convertToUniversal();
    return input;
}
double Time::operator-(const Time &t2)
{
    string timeDiff;
    if (minute > t2.minute)
    {
        
        minute -=  t2.minute;
    }
    else if (minute<t2.minute)
    {
        minute = t2.minute - minute;
        
    }
    
    if (hour>t2.hour) {
        if (ap == t2.ap) {
            hour = hour - t2.hour;
        }
        else if (ap>t2.ap || ap<t2.ap)
            hour = hour - t2.hour + 12;
    }
    /*else if (time.ap<t2.ap)
     {
     difference->hour=time.hour-t2.hour;
     
     } */
    if (hour<t2.hour) {
        if (ap == t2.ap) {
            hour = t2.hour - hour;
        }
        else if (ap>t2.ap || ap<t2.ap)
            hour = t2.hour - hour + 12;
    }
  
    return hour+minute/60;
    
}
