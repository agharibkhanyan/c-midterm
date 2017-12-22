#ifndef CourseSchedule_H
#define CourseSchedule_H
#include "Semester.h"
#include "Course.h"
#include "Date.h"
#include <iostream>
#include <string>
using namespace std;

class CourseSchedule : public Course
{
    
    friend ostream& operator<<(ostream&, const CourseSchedule&);
    //friend ostream& operator<<(ostream&, const CourseScheudle&)
private:
    Course *courseArr;
    string name;
    Semester semester;
    int maxSize = 0;
    int numCourses = 0;
     int size=0;
    
public:
    CourseSchedule();
    CourseSchedule(string, string, int);
    ~CourseSchedule();
    string getName()const;
    Semester getSemester()const;
    int getNumCourses()const;
    void setName(string);
    //void setSemester(Semester);
    void setMaxSize(int);
    void setNumCourses(int);
    //	bool checkDate(const Semester&, const Date&, const Date&)const;
    void addCourse(const Course&);
};
#endif /* CourseSchdule_hpp */



/*The CourseSchedule class should have the following member functions:
 1. Create a constructor that:
 o Takes three arguments and sets the following member variables appropriately:
 the student name, the Semester, and the maximum number of courses the student is allowed to take.
 o The constructor should set numCourses equal to zero since at this point no specific courses have been added to the student’s schedule
 o The constructor should dynamically allocate the array of courses to be “maxSize” big (so dynamically allocate an array of maxSize Course instances)
 2. Create a destructor that de-allocates memory appropriately when a CourseSchedule is destroyed.
 If you have any memory issues you can always put a print in here to help test.
 3. Create get functions for the following member variables: the student name, the Semester (reuse code do NOT recreate the Semester data type here),
 and the number of courses.*/

/*A CourseSchedule is a data type that is a list (array) of Course data types.
 You will need to have a pointer to a Course data type so our list (array) can be of any size.
 This is similar to what you did in Homework #2 except for your array is of type Course instead of type int.
 
 Create a class CourseSchedule with the following member variables:
 ? A student name (the name of the student this schedule is for)
 ? A Semester object (see above)
 ? A pointer to a Course
 **This will allow you to dynamically allocate memory so the class will work for any size student schedule
 (the student can have as many classes as they want on their schedule)
 5
 ? a maxSize variable that indicates the maximum number of courses that can be added to this student schedule (the array of Courses)
 ? a numCourses variable that keeps track of how many courses have been added to the student schedule (the array of Courses)*/
