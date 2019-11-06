#include "student.h"
#include <iomanip>
#include <iostream>
using namespace std;

int Student::totalNumofStudents = 0;
int Student::nextStudentID = 10000;

Student::Student(): studentID(nextStudentID)
{
  totalNumofStudents++;
  nextStudentID++;

  name = "unknown";
  major = "CS";
  classification = "undergraduate";
  units = 12;
  tuition = 0;
}

Student::Student(string nm, string maj, string clss, int unts): studentID(nextStudentID)
{
  totalNumofStudents++;
  nextStudentID;

  name = nm;
  major = maj;
  classification = clss;
  units = unts;
  tuition = 0;
}

void Student::print()
{
  cout << endl;
  cout << "==============================================\n";
  cout << left << setw(20) << "Name: " << right << name << endl;
  cout << left << setw(20) << "Student ID: " << right << studentID << endl;
  cout << left << setw(20) << "Major: " << right << major << endl;
  cout << left << setw(20) << "Classification: " << right << classification << endl;
  cout << left << setw(20) << "# of Units: " << right << units << endl;
  cout << left << setw(20) << "Tuition: " << right << "$" << tuition << endl;
  cout << left << setw(20) << "Total # of Stu: " << right << totalNumofStudents << endl;
  cout << left << setw(20) << "nextStudentID" << right << nextStudentID << endl;
}

void Student::getData()
{
  cout << "\nEnter name: ";
  getline(cin,  name);
  cout << "Enter major: ";
  cin >> major;
  cout << "Enter classification (undergraduate or graduate): ";
  cin >> classification;
  cout << "Enter # of units taken: ";
  cin >> units;
}

Student::~Student()
{
  totalNumofStudents--;
}
