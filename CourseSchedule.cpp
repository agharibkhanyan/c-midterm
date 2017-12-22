//
//  CourseSchdule.cpp
//  midterm
//
//  Created by artur on 10/8/17.
//  Copyright © 2017 Artur. All rights reserved.
//

#include "CourseSchedule.h"
#include "Semester.h"
#include "Course.h"
#include "Date.h"
#include <iostream>
#include <string>
using namespace std;


CourseSchedule::CourseSchedule()
{
    Semester sem;
    semester = sem;
    name = "";
    maxSize = 0;
    ++numCourses;
    courseArr = new Course[maxSize];
    
    
    /* Course *courseArr;
     string name;
     Semester semester;
     int maxSize = 0;
     int numCourses = 0; *
     */
}
CourseSchedule::CourseSchedule(string name, string sem, int maxNum)
{
    this->name = name;
    semester = sem;
    courseArr = new Course[maxNum];
    ++numCourses;
}
CourseSchedule::~CourseSchedule()
{
    delete[] courseArr;
}
void CourseSchedule::setName(string stuName)
{
    name = stuName;
}
void CourseSchedule::setNumCourses(int num)
{
    numCourses = num;
}
void CourseSchedule::setMaxSize(int maxNum)
{
    maxSize - maxNum;
    
}
Semester CourseSchedule::getSemester()const
{
    return semester;
}
string CourseSchedule::getName()const
{
    return name;
}

int CourseSchedule::getNumCourses()const
{
    return numCourses;
}
//bool CourseSchedule::checkDate(const Semester& sem, const Date &start, const Date &end)const
//{
//bool semDate = false;

//start.getStartDate() && end.getEndDate() == sem.getSemester;
//}

/*The function should check to make sure that the start date of the class and/or the end date of the class are not outside the Semester Dates.
 For Example: If a Semester starts 09/03/17 and ends 12/15/17 the course cannot start 08/29/17 because that is BEFORE the semester starts.
 The idea is a student will not be able to add a course to their schedule if that course’s dates are outside the Semester beginning and end dates.
 (NOTE: I added this new this year, I think it should work but you may need to tweak it a bit, so this one will be flexible on number of parameters
 and implementation)*/

void CourseSchedule::addCourse(const Course &addClass)
{
    
    
        courseArr[size] = addClass;
        size++;
        ++numCourses;
    
    
}

ostream& operator<<(ostream& out, const CourseSchedule &obj)
{
    
    out << "CLASS SCHEDULE\n"
    << "-----------------------" << endl;
    out << "Name: " << obj.getName() << endl;
    out << "Semester :" << obj.getSemester() << endl
    << "Number of classes : " << obj.getNumCourses() << endl
    << "-----------------------------------------" << endl;
    out << "Course Info: " << obj.getCourseTitle() << endl
    << "# of Units: " << obj.getUnits() << endl
    << "Course Dates: " << obj.getStartDate() << obj.getEndDate() << endl
    << "Meeting Days: " << obj.getMeetingDays() << endl
    << "Daily Duration: " << (obj.getEndTime() - obj.getStartTime()) << endl;;
    
    for (int  i = 0; i < obj.numCourses; i++)
    {
        out << obj.courseArr[i];
    }
    return out;
    
    
    /*CLASS SCHEDULE
     -----------------------
     Name: Jane Doe
     Semester: Fall 2017 (09/03/17-12/18/17)
     Number of Classes: 2
     -----------------------------------------
     Course Info: CSIS 112 -- Java
     # of Units: 3.00
     Course Dates: 09/06/2017 – 10/15/17
     Meeting Days: MW
     Meeting Time: 10:45AM - 12:10PM
     Daily Duration: 1.42 hours
     Course Info: CSIS 154 -- C#
     */
}
/*Create a function named AddCourse that takes a Course as an argument and adds this course to the ClassSchedule array.
 NOTE: the course should not be added if its dates fall outside the semester dates (see #5 above).
 You do NOT need to allocate any new memory since we allocated a max size for our ClassSchedule array.
 As long as you didn’t make any of the Course member variables const you should be able to use memberwise assignment to add the course to the proper
 element of the array (numCourses is the current element) – you should add one to numCourses when you add a new Course to the ClassSchedule.*/
