//Tuesday, 2/13/18 (Week 4)
#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>
#include <cstdlib>
using namespace std;

struct Employee
{
  string name;
  long SSN;
  float grossIncome;
  float taxes;
};

void outputHeader();
void readData(vector<Employee> & employees, int & size);
float netIncome(Employee emps);
float tax(Employee emps);
void printData(const vector<Employee> & emps, const int & size);

int main()
{
  vector<Employee> employees;
  int size = 0; //size of the vector

  outputHeader();
  readData(employees, size);
  printData(employees, size);

  return 0;
}

void printData(const vector<Employee> & emps, const int & size)
{
  for(int i = 0; i < size; i++)
    {
      cout << fixed << setprecision(2);
      cout << left << setw(10) << emps[i].name << right;
      cout << setw(15) << emps[i].SSN;
      cout << setw(15) << emps[i].grossIncome; 
      cout << setw(10) << tax(emps[i]);
      cout << setw(15) << netIncome(emps[i]);
      cout << endl;
    }
}

float tax(Employee emps)
{
  float tax;
  return tax = emps.taxes * emps.grossIncome;
}

float netIncome(Employee emps)
{
  float netincome;
 
  emps.taxes *= emps.grossIncome;
  return netincome = emps.grossIncome - emps.taxes;
}

void readData(vector<Employee> & employees, int & size)
{
  ifstream emp;
  emp.open("employeeData.txt");
  if(!emp)
    {
      cout << "Cannot open input file" << endl;
      //exit(1);
    }
  else
    {
      Employee temp;
      emp >> temp.name;
      emp >> temp.SSN;
      emp >> temp.grossIncome;
      emp >> temp.taxes;

      while(emp)
	{
	  employees.push_back(temp);
	  emp >> temp.name;
	  emp >> temp.SSN;
	  emp >> temp.grossIncome;
	  emp >> temp.taxes;
	  size++;
	}
    }
  emp.close();
}


void outputHeader()
{
  cout << left << setw(10) << "Name" << setw(15) << "SSN";
  cout << right << setw(15) << "GrossIncome" << setw(10) << "Taxes";
  cout << setw(15) << "NetIncome" << endl;
  cout << "------------------------------------------------------------\n";
}
