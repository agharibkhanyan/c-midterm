//
//  Course.hpp
//  midterm
//
//  Created by artur on 10/8/17.
//  Copyright © 2017 Artur. All rights reserved.
//

#ifndef Course_h
#define Course_h
#include "Time.h"
#include "Date.h" 
#include <stdio.h>
#include <iomanip>
#include <iostream>
using namespace std;
class Course
{
private:
    Date startDate, endDate;
    Time startTime, endTime;
    int courseNumber;
    double units;
    double dailyDuration;
    string meetingDays;
    string courseTitle;
    
public:
    Course();
    
    Course(int num, double un, string tit, string days, Date &, Date &,Time &,Time
           &);
   /* Course(int num=137, double un=3, string tit="CSIS 137", string days="TTH", Date &, Date &,Time &,Time
           &);*/
    Course& setCourse(int, double, string, string, Time &,Time &, Date &,Date&);
    Course& setCourseNumber(int);
    Course& setUnits(double);
    Course& setMeetingDays(string);
    Course& setCourseTitle(string);
    int getCourseNumber()const;
    void calcDailyDuration(double);
    double getUnits()const;
    string getMeetingDays()const;
    string getCourseTitle()const;
    ~Course();
    Date getStartDate()const;
    Date getEndDate()const;
    Time getStartTime()const;
    Time getEndTime()const;
    void setEndTime(Time &);
    void setStartTime(Time &);
    void setStartDate(Date &);
    void setEndDate(Date &);
    Time operator-(const Course&);
    friend ostream &operator<<(ostream &, const Course &);

};


#endif /* Course_hpp */
