#include "course.h"
#include <iomanip>
#include <iostream>
using namespace std;

void Course::setCourse(long cNum, string cName, int numCred)
{
  courseNumber = cNum;
  courseName = cName;
  numberOfCredits = numCred;
}

void Course::printCourse()
{
  cout << endl;
  cout << left << setw(20) << "Course number: " << right << courseNumber << endl;
  cout << left << setw(20) << "Course name: " << right << courseName << endl;
  cout <<  left << setw(20) << "Number of Credits: " << right << numberOfCredits << endl;
}

/*
void setInstructor(string fName, string lName, char gen, long empID, string ofNum, Course cos[])
{
  firstName = fname;
  lastName = lName;
  gender = gen;
  employeeID = empID;
  officeNum = ofNum;
}*/
