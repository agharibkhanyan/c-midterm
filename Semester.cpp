//
//  Semester.cpp
//  midterm
//
//  Created by artur on 10/8/17.
//  Copyright © 2017 Artur. All rights reserved.
//

#include "Semester.h"
#include "Date.h"
#include "Time.h"
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

Semester::Semester()
{
    startDate = 0;
    endDate = 0;
    semesterTitle = "";
}
Semester::~Semester()
{
    
}
Semester::Semester(const string &sem)
{
    semesterTitle = sem;
}
Semester::Semester(string name,Date& s, Date& e)
:startDate(s), endDate(e)
{
    //name="Fall 2017";
    setSemester(name);
}

Semester::Semester(Date &start, Date &end, string sem)
: startDate(start), endDate(end)
{
    setSemester(sem);
}

Semester& Semester::setSemester(string sem)
{
    semesterTitle = sem;
    return *this;
}

Date Semester::getStartDate()const
{
    return startDate;
}
Date Semester::getEndDate()const
{
    return endDate;
}

string Semester::getSemester()
{
    return semesterTitle;
}

ostream& operator<<(ostream &output, const Semester &sem)
{
    output << "Semester:  " << sem.semesterTitle << " (" << sem.startDate << "-" << sem.endDate << ")";
    return output;
}

istream& operator>>(istream &input, Semester &sem)
{
   
    input >> sem.semesterTitle;
    input>>sem.startDate;
    input>>sem.endDate;
    cout << "\nEnter end date";
    //input >> setw(10) >> sem.startDate >> sem.endDate;
    //Semester(&start, &end);
    return input;
}
