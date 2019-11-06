#include "patient.h"
//#include "checkup.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>
long Patient::nextPatientAccountNum = 5000; //sets static variable

/****************

CONSTRUCTORS

****************/

Patient::Patient():patientAccountNum(nextPatientAccountNum)
{
  //patientAccountNum = 0;// nextPatientAccountNum;                                                                                                                                                         
  firstName = "John";
  lastName = "Doe";
  SSN = 000000000;
  gender = 'X';
  birthDate = "MM/DD/YYYY";
  patientCheckups;
  nextPatientAccountNum += 2;
}

Patient::Patient(string fName, string lName, long pSSN, char gen, string bday):patientAccountNum(nextPatientAccountNum)
{
  firstName = fName;
  lastName = lName;
  SSN = pSSN;
  gender = gen;
  birthDate = bday;
  patientCheckups;
  nextPatientAccountNum += 2;
}

/****************

GETS AND SETS

****************/

long Patient::getSSN() const
{ return SSN; }

long Patient::getpatientAccountNum() const
{ return patientAccountNum; }

string Patient::getfirstName() const
{ return firstName; }

string Patient::getlastName() const
{ return lastName; }

char Patient::getgender() const
{ return gender; }

string Patient::getbirthDate() const
{ return birthDate; }

int Patient::getAge(string date)
{
  string pYear = birthDate.substr(4, 6);
  string pMonth = birthDate.substr(2, 0);
  string pDay = birthDate.substr(2, 3);

  string tYear = date.substr(4, 6);
  string tMonth = date.substr(2, 0);
  string tDay = date.substr(2, 3);

  stringstream bMon(pMonth);
  stringstream tMon(tMonth);
  int bmonth;
  bMon >> bmonth;
  int tmonth;
  tMon >> tmonth;

  stringstream beDay(pDay);
  stringstream toDay(tDay);
  int beday;
  beDay >> beday;
  int tday;
  toDay >> tday;

  stringstream bday(pYear);
  stringstream today(tYear);
  int byr;
  bday >> byr;
  int tyr;
  today >> tyr;

  int age = tyr - byr;
  if(bmonth > tmonth)
    age--;
  else if(bmonth==tmonth && tday < beday)
    age--;

  return age;
}

void Patient::pushpatientCheckups(Checkup temp)
{ patientCheckups.push_back(temp); }

Checkup Patient::getPatientCheckups(int x) const
{ return patientCheckups[x]; }

double Patient::getLDL(int x) const
{ return patientCheckups[x].getcholesterol() - (patientCheckups[x].gettrig() / 5) - patientCheckups[x].gethdl(); }

double Patient::getCholHDL(int x) const
{ return patientCheckups[x].getcholesterol() / patientCheckups[x].gethdl(); }

double Patient::getBMI(int x) const
{ return patientCheckups[x].getweight() * 703 / patientCheckups[x].getheight(); }




/*******************

OTHER FUNCTIONS

*******************/

void Patient::PatientCheckupSummary(string sDate)
{
  int x = -1;
  for(int i = 0; i < patientCheckups.size() && x == -1; i++)
    {
      if(patientCheckups[i].getcheckupDate() == sDate)
	{
	  x = i;
	}
    }
  if(x==-1)
    cout << "Error: Patient not found\n";
  else
    {
      cout << firstName << " " << lastName << endl;
      cout << "Born on " << birthDate << ", " << gender << endl;
      
      cout << getAge(sDate) << " years old, " << patientCheckups[x].getheight() << ", " << patientCheckups[x].getweight() << " pounds\n";
      
      cout << endl << endl << setw(30) << sDate << endl;
      cout << "--------------------------------------------------------------" << endl;
      
      cout << left << setw(20) << "Total Cholesterol" << setw(10) << patientCheckups[x].getcholesterol() << endl;
      cout << "(Reference Range: 125-199mg/dL)" << endl;
      
      cout << left << setw(20) << "HDL Cholesterol" << setw(10) << patientCheckups[x].gethdl() <<endl;
      cout << "(Reference Range: > or = 40 mg/dL)" << endl;

      cout << left << setw(20) << "LDL Cholesterol";
      cout << setw(10) << getLDL(x) << endl;
      cout << "(Reference Range: < 130 mg/dL)" << endl;

      cout << left << setw(20) << "Cholesterol/HDL Ratio" << setw(10) << getCholHDL(x) << endl;
      cout << "(Reference Range: < or = 5.0)" << endl;

      cout << left << setw(20) << "Glucose" << setw(10) << patientCheckups[x].getglucose() << endl;
      cout << "(Reference Range: 65-99 mg/dL)" << endl;

      cout << left << setw(20) << "Blood Pressure" << setw(10) << patientCheckups[x].getbloodPressure() << endl;
      cout << "(Reference Range: < 120/80 mmHg)" << endl;

      cout << left << setw(20) << "Body Mass Index" << setw(10) << getBMI(x) << endl;
      cout << "(Reference Range: 18.5-24.9)" << endl;

      cout << "--------------------------------------------------------------" << endl;
      cout << "Notes to patient:\n";

      if(patientCheckups[x].getcholesterol() > 125 || patientCheckups[x].getcholesterol() < 199)
        cout << " -  is at a high risk of coronary heart disease\n";
      else if(patientCheckups[x].gethdl() < 40)
        cout << " -  is at a high risk of coronary heart disease\n";
      else if(patientCheckups[x].gettrig() > 150)
        cout << " -  is at a high risk of coronary heart disease\n";
      else if(getLDL(x) > 130)
        cout << " -  is at a high risk of coronary heart disease\n";
      else if(getCholHDL(x) > 5.0)
        cout << " -  is at a high risk of coronary heart disease\n";
      else if(patientCheckups[x].getglucose() < 65 || patientCheckups[x].getglucose() > 99)
        cout << " -  is at a high risk of coronary heart disease\n";

      //if(patientCheckups(x).getbloodPressure() > 120/80)                                                                                                                            
      //cout << " -  may have hypertension\n";                                                                                                                                                              

      if(getBMI(x) < 18.5)
        cout << " -  is underweight with increased risk of electrolyte imbalances and osteoporosis”.";
      else if(getBMI(x) > 24.9)
        cout << " -  is overweight with increased risk for health conditions such as heart disease, stroke…\n";

      cout << "--------------------------------------------------------------" << endl;
    }
}

void Patient::PatientHistory()
{
  cout << fixed << setprecision(2);
  cout << firstName << " " << lastName << endl;
  cout << "Born on " << birthDate << ", " << getgender() << endl;
  cout << "\t\t\t\t\t";

  for(int i = 0; i < patientCheckups.size(); i++)
    {
      //cout << patientCheckups[i].getCheckupDate() << "\t";
    }

  cout << endl;
  cout << "-----------------------------------------------------------------------------------" << endl;


  cout << left << setw(20) << "Total Cholesterol" << setw(10);
  for(int i = 0; i < patientCheckups.size(); i++)
    {
      cout << patientCheckups[i].getcholesterol() << "\t";
    }
  cout << left << setw(10) << "\n(Reference Range: 125-199mg/dL)" << endl << endl;

  cout << left << setw(10) << "HDL Cholesterol" << setw(10);
  for(int i = 0; i < patientCheckups.size(); i++)
    {
      cout << patientCheckups[i].gethdl() << "\t";
    }
  cout << left << setw(10) << "\n(Reference Range: > or = 40 mg/dL)" << endl << endl;

  cout << left << setw(10) << "Triglycerides" << setw(10);
  for(int i = 0; i < patientCheckups.size(); i++)
    {
      cout << patientCheckups[i].gettrig() << "\t";
    }
  cout << left << setw(10) << "\n(Reference Range: < 150mg/dL)" << endl << endl;

  cout << left << setw(10) << "LDL Cholesterol" << setw(10);
  for(int i = 0; i < patientCheckups.size(); i++)
    {
      cout << getLDL(i) << "\t";
    }
  cout << left << setw(10) << "\n(Reference Range: < 130 mg/dL)" << endl << endl;

  cout << left << setw(10) << "Cholesterol/HDL Ratio" << setw(10);
  for(int i = 0; i < patientCheckups.size(); i++)
    {
      cout <<getCholHDL(i) << "\t";
    }
  cout << left << setw(10) << "\n(Reference Range: < or = 5.0)" << endl << endl;

  cout << left << setw(10) << "Glucose \t\t\t\t";
  for(int i = 0; i < patientCheckups.size(); i++)
    {
      cout << patientCheckups[i].getglucose() << "\t";
    }

  cout << left << setw(10) << "\n(Reference Range: 65-99 mg/dL)" << endl << endl;

  cout << left << setw(10) << "Blood Pressure" << setw(10);
  for(int i = 0; i < patientCheckups.size(); i++)
    {
      cout << patientCheckups[i].getbloodPressure() << "\t";
    }
  cout << left << setw(10) << "\n(Reference Range: 120/80 mmHg)" << endl << endl;

  cout << left << setw(10) << "Body Mass Index" << setw(10);
  for(int i = 0; i < patientCheckups.size(); i++)
    {
      cout << getBMI(i) << "\t";
    } 
  cout << left << setw(10) << "\n(Reference Range: 18.5-24.9)" << endl;
  
}
