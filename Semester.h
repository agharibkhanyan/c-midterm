//
//  Semester.hpp
//  midterm
//
//  Created by artur on 10/8/17.
//  Copyright © 2017 Artur. All rights reserved.
//

#ifndef Semester_h
#define Semester_h
#include "Date.h"
#include <iomanip>
#include <iostream>
#include "Time.h"
using namespace std;
class Semester
{
    
    
private:
    string semesterTitle;
    Date startDate;
    Date endDate;
    
public:
    Semester();
    Semester(const string&);
    Semester(string ,Date&, Date&);
    Semester(Date &startDate, Date &endDate, string);
    Semester& setSemester(string);
    string getSemester();
    Date getStartDate()const;
    Date getEndDate()const;
    ~Semester();
    friend ostream& operator<<(ostream &, const Semester &);
    friend istream& operator>>(istream &, Semester &);
    
};
#endif /* Semester_hpp */
