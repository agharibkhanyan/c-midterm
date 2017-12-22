//
//  Course.cpp
//  midterm
//
//  Created by artur on 10/8/17.
//  Copyright © 2017 Artur. All rights reserved.
//

#include "Course.h"
#include <iostream>

using namespace std;

Course::Course()
{
    courseTitle = "";
    courseNumber = 0;
    units = 0;
    meetingDays = "";
}


Course::Course(int num, double un, string tit, string days,Date &startD,Date &endD,Time &startT,Time &endT)
: startDate(startD), startTime(startT), endTime(endT), endDate(endD)
{
    
    
    setCourseNumber(num);
    setCourseTitle(tit);
    setUnits(un);
    setMeetingDays(days);
    
}
/*Course::Course(int num=139, double un=3, string tit="csis 137", string days="TTh",Date &startD,Date &endD=,Time &startT,Time &endT)
: courseNumber(139), units(un) ,startDate(startD), startTime(startT), endTime(endT), endDate(endD)
{
    
    
    setCourseNumber(num=139);
    setCourseTitle(tit);
    setUnits(un);
    setMeetingDays(days);
    
}*/



Course& Course::setCourse(int num, double un, string tit, string days, Time &startTime,Time &endTime, Date &startDate,Date &endDate)

{
    //duration = startTime - endTime;
    
    setCourseNumber(num);
    setCourseTitle(tit);
    setUnits(un);
    setMeetingDays(days);
    return *this;
}
Time Course::operator-(const Course &obj)
{
    Time difference(startTime - obj.startTime);
    
    
    return difference;
    //difference = startTime - obj.startTime;
}

Course& Course::setMeetingDays(string days)
{
    meetingDays = days;
    return *this;
}
Course& Course::setCourseTitle(string tit)
{
    courseTitle = tit;
    return *this;
}

Course& Course::setUnits(double un)
{
    units = un;
    return *this;
}

Course& Course::setCourseNumber(int num)
{
    courseNumber = num;
    return *this;
}
void Course::calcDailyDuration(double d)
{
    dailyDuration=startTime-endTime;
    
}
void Course::setStartTime(Time &t)
{
    startTime=t;
}
void Course::setEndTime(Time &t)
{
    endTime=t;
}
void Course::setStartDate(Date &d)
{
    startDate=d;
}
void Course::setEndDate(Date &d)
{
    endDate=d;
}
Time Course::getEndTime()const
{
    return endTime;
}
Time Course::getStartTime()const
{
    return startTime;
}
Date Course::getEndDate()const
{
    return endDate;
}
Date Course::getStartDate()const
{
    return startDate;
}
double Course::getUnits()const
{
    return units;
}
int Course::getCourseNumber()const
{
    if (courseNumber<0) {
        return 0;
    }
    return courseNumber;
}

string Course::getCourseTitle()const
{
    return courseTitle;
    
}
string Course::getMeetingDays()const
{
    return meetingDays;
}

Course::~Course()
{
    cout << "\nA class has been deleted";
}
ostream& operator<<(ostream &output, const Course &course)
{
    output << "\nCourse Info: " << course.courseTitle;
    output << "\n# of Units:  " << course.units; 
    output << "\nCourse Dates:  " << course.startDate << "-" << course.endDate;
    output << "\nMeeting Times:  " << course.startTime << "-" << course.endTime;
    output << "\nMeeting Days:  " << course.meetingDays;
    output << "\nDuration:  " << course.dailyDuration;
    return output;
}
