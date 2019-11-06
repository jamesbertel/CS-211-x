#include "instructor.h"
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

void Instructor::setInstructor(string fName, string lName, char gen, long empID, string ofNum, long num0, string name0, int numCred0, long num1, string name1, int numCred1, long num2, string name2, int numCred2)
{
  firstName = fName;
  lastName = lName;
  gender = gen;
  employeeID = empID;
  officeNum = ofNum;

  courses[0].setCourse(num0, name0, numCred0);
  courses[1].setCourse(num1, name1, numCred1);
  courses[2].setCourse(num2, name2, numCred2);
}
void Instructor::printInstructor()
{
  cout << endl;
  cout << left << setw(20) << "First name: " << right << firstName << endl;
  cout << left << setw(20) << "Last name: " << right <<  lastName << endl;
  cout << left << setw(20) << "Gender: " << right << gender << endl;
  cout << left << setw(20) << "Employee ID: " << right << employeeID << endl;
  cout << left << setw(20) << "Office #: " << right << officeNum << endl;

  courses[0].printCourse();
  courses[1].printCourse();
  courses[2].printCourse();
  cout << endl;
}
