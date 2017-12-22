#include <iostream>
#include <iomanip>
using namespace std;
#include "Date.h"




//constructor validates month and calls utility function to validate day
Date::Date(int month, int day, int year)
{
    this->setDate(month, day, year);
    
}


Date& Date::setDate(int month, int day, int year)
{
    if(month > 0 && month <= 12)
    {
        this->setMonth(month);
        //month  = mn;
    }
    
    else
    {
        this->setMonth(1);
        //month = 1;
        //cout << "Month set to one - INVALID" << endl;  //BAD DESIGN!
    }
    
    this->setYear(year); // to validate year
    // year = yr;  //could also validate year
    
    this->setDay(day); // to validate day
    // day = checkDay(dy);  //to validate the day
    
    // cout << endl;
    return *this;
}

/*CONST PRINT FUNCTION -- removing print function
 void Date::print() const
 {
 cout << month << '/' << day << '/' << year << endl;
 }
 */
//PRIVATE COST UTILITY FUNCTION
int Date::checkDay(int testDay) const
{
    static const int daysPerMonth[13]= {0,31,28,31,30,31,30,31,31,30,31,30,31};
    
    if(testDay > 0 && testDay <= daysPerMonth[month])
    {
        return testDay;
    }
    
    //determine whether testDay is valid for a specific month
    if(month == 2 && testDay == 29 && (year  % 400 == 0 || (year % 4  == 0 && year % 100 != 0)))
    {
        return testDay;
    }
    
    cout << "Invalid Day " << testDay << " was set to 1" << endl;
    return 1;  //keep data in valid state
}

bool Date::operator>(const Date& date) const
{
    if (this->year > date.year)
    {
        return true;
    }
    else if (this->year == date.year)
    {
        if (this->month > date.month)
        {
            return true;
        }
        else if (this->year == date.year)
        {
            if (this->month < date.month)
            {
                return true;
            }
        }
    }
    return false;
}

bool Date::operator<(const Date& date) const
{
    return !(this->operator>(date));
}

bool Date::operator>=(const Date& date) const
{
    if (this->year > date.year)
    {
        return true;
    }
    
    else if (this->year == date.year)
    {
        if (this->month == date.month)
        {
            if (this->day > date.month)
            {
                return true;
            }
        }
    }
    else if (this->operator ==(date))
    {
        return true;
    }
    return false;
}

bool Date::operator<=(const Date& date) const
{
    return !(this->operator>=(date));
}

bool Date::operator == (const Date& date) const
{
    if (this->year == date.year)
    {
        if (this->month == date.month)
        {
            if (this->day == date.month)
            {
                return true;
            }
        }
    }
    return false;
}
bool Date::operator!=(const Date& date) const
{
    return !(this->operator==(date));
}
int Date::getMonth() const
{
    return this->month;
}
int Date::getDay() const
{
    return this->day;
}
int Date::getYear() const
{
    return this->year;
}
Date& Date::setMonth(int month)
{
    this->month = month;
    return *this;
}
Date& Date::setDay(int day)
{
    this->day = this->checkDay(day);
    return *this;
}
Date& Date::setYear(int year)
{
    this->year = year;
    return *this;
}

Date::~Date()
{}

ostream& operator<<(ostream& output, const Date& date)
{
    output<< date.month << '/' << date.day << '/' << date.year<< setfill('0');
    return output;
}
istream& operator >> (istream& input, Date& date)
{
    
    
    input >>setw(2)>> date.month;
    input.ignore(1);
    input>>setw(2)>> date.day;
    input.ignore(1);
    input >>setw(4)>>date.year;
    
    return input;
}
