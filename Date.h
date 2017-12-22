#ifndef DATE_H
#define DATE_H
#include <iomanip>
#include <iostream>
#include <stdio.h>
#include "Time.h"
using namespace std;



class Date
{
    
    
    //overloaded << function, must be global
    
private:
    int month; //1-12
    int day; //1-31 depending on month
    int year; //any year
    
    //utility function to check if day is proper for month and year
    int checkDay(int) const;
    
    
    
    
    
    
public:
    Date(int = 1, int = 1, int = 1990);  //default constructor
    Date& setDate(int, int, int);
    //void print() const;-- removing print function
    
    int getMonth() const;
    int getDay() const;
    int getYear() const;
    
    Date& setMonth(int);
    Date& setDay(int);
    Date& setYear(int);
    bool operator>(const Date&) const;
    bool operator<(const Date&) const;
    bool operator>=(const Date&) const;
    bool operator<=(const Date&) const;
    bool operator==(const Date&) const;
    bool operator!=(const Date&) const;
    ~Date();
    friend ostream& operator<<(ostream&, const Date&);
    friend istream& operator>>(istream&, Date&);
};
















#endif
