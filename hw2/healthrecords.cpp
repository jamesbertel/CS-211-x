#include "healthrecords.h"
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

/************************
This function creates a new Patient object by calling the appropriate constructor.
You should validate the given patient's data before creating a new object.
You should NOT create a new object if pSSN matches an existing patient's SSN (just print an error)
Otherwise, you should create an object and add it to the patientRecords vector,
  and display a message that the patient object was successfully added.
***********************/
void HealthRecords::createNewPatient(string fName, string lName, long pSSN, char gen, string bday)
{
  bool patientFound = false;

  for(int i = 0; i < patientsRecords.size(); i++)
    {
      if(patientsRecords[i].getSSN() == pSSN)
	{
	  patientFound = true;
	  cout << "error: Patient already exists!\n";
	  break;
	}
    }

  if(patientFound==false)
    {
      Patient temp(fName, lName, pSSN, gen, bday);
      patientsRecords.push_back(temp);
      cout << "patient successfully added\n";
    }
}


/**********
This functions prints basic info about ALL patients in patientsREcords vector.
If there are no patients, its prints an error message.
**********/
void HealthRecords::printAllPatients() const
{
  if(patientsRecords.size()==0)
    cout << "Error: No patients.\n";
  else
    {
      for(int i = 0; i < patientsRecords.size(); i++)
	{
	  cout << left << setw(10) << patientsRecords[i].getpatientAccountNum();
	  cout << setw(10) << patientsRecords[i].getfirstName();
	  cout << " " << setw(10) << patientsRecords[i].getlastName();
	  cout << setw(10) << patientsRecords[i].getgender();
	  cout << setw(10) << patientsRecords[i].getbirthDate();
	}
    }
}


/**********
This function creates a Checkup object and adds it to the patient's lsit of checkups, that is, to the vector of patientsCheckups for the patient account whose number is pNu.
Ensure that patient account # is valid before adding the checkup to the patientCheckups vector.
Display a message that the checkup entry is successfully added.
Otherwise, you should not add any object to the vector and should print appropriate error messages.
 *********/
void HealthRecords::addPatientCheckup(long pNum, string cDate, double pHeight, double pWeight, double pCholesterol, double pHDL, double pTriglyceride, double pGlucose, string pBloodPressure)
{
  bool patientFound = false;
  
  for(int i = 0; i < patientsRecords.size(); i++)
    {
      if(patientsRecords[i].getpatientAccountNum() == pNum)
        {
          patientFound = true;
          cout << "error: Patient already exists!\n";
          break;
        }
    }

  if(patientFound==false)
    {
      Checkup temp = Checkup(cDate, pHeight, pWeight, pCholesterol, pHDL, pTriglyceride, pGlucose, pBloodPressure);

      for(int i = 0; i < patientsRecords.size(); i++)
	{
	  if(patientsRecords[i].getpatientAccountNum() == pNum)
	    {
	      patientsRecords[i].pushpatientCheckups(temp);
	      cout << "Successfully added patient\n";
	    }
	}
    }
}

/**************
This function should first search for the patient whose account number is pNum and specifically for the checkup held on sDate. If no such entry is found, you should print an appropriate message. If an entry is found, you should print a detailed summary of that checkup along with medical warnings to the patient. This includes displaying personal information, test results and final notes to patient.
**************/
void HealthRecords::printPatientCheckupSummary(long pNum, string sDate) 
{
  int x = -1;
  for(int i = 0; i < patientsRecords.size(); i++)
    {
      if(patientsRecords[i].getpatientAccountNum() == pNum)
        {
          x = i;
	}
    }
  if(x==-1)
    cout << "Error: Patient not found\n";
  else
    patientsRecords[x].PatientCheckupSummary(sDate);

}
/*************
This function prints the medical history of a specific patient whose patient account number is pNum. This includes printing a patient’s general information followed by a medical summary report. General information includes the patient’s first name, last name, gender, and date of birth. The medical report includes a table summarizing all the patient’s test results.
***************/
void HealthRecords::printPatientHistory(long pNum) const
{

  int x = -1; //
  
  for(int i = 0; i < patientsRecords.size(); i++)
    {
      if(patientsRecords[i].getpatientAccountNum() == pNum)
	{
	  x = i;
	}
    }
  
  if(x != -1)
    ;//patientsRecords[x].PatientHistory();
  else 
    cout << "Error: No patient with that account number" << endl;
}

/*************
This function processes the transaction file
*************/
void HealthRecords::processTransactionFile(string fileName)
{
  ifstream fin;
  string operation, fName, lName, date, mmhg;
  char gen;
  int num;
  double cholesterol, height, weight, pHDL, trig, glucose;
  fin.open(fileName.c_str());
  cout << endl;

  if(!fin)
    cout << "Error: file DNE" << endl;
  else
    {
      fin >> operation; //put first command into operation
      while(fin)
        { //call proper function based on command
          if(operation=="CreateNewPatient")
	    {
	      fin >> fName;
	      fin >> lName;
	      fin >> num;
	      fin >> gen;
	      fin >> date;
	      createNewPatient(fName, lName, num, gen, date);
	    }
          else if(operation=="PrintAllPatients")
	    printAllPatients();
          else if(operation=="AddPatientCheckup")
	    {
	      fin >> num;
	      fin >> date;
	      fin >> height;
	      fin >> weight;
	      fin >> cholesterol;
	      fin >> pHDL;
	      fin >> trig;
	      fin >> glucose;
	      fin >> mmhg;
	      //addPatientCheckup(num, date, height, weight, cholesterol, pHDL, trig, glucose, mmhg);
	    }
          else if(operation=="PrintPatientHistory")
	    {
	      fin >> num;
	      //printPatientHistory(num);
	    }
          else if(operation=="PrintPatientCheckupSummary")
	    {
	      fin >> num;
	      fin >> date;
	      //printPatientCheckupSummary(num, date);
	    }
          else
            {cout << "ERROR: NO COMMAND. CHECK FILE." << endl; break;}

          fin >> operation; //puts next command into operation
        }
    }

  cout << endl;
  fin.close();
}

/*****************

CONSTRUCTOR

*****************/


/*
double HealthRecords::getLDL(int x) const
{ return patientsRecords[x].getPatientCheckups(x).getcholesterol() - (patientsRecords[x].getPatientCheckups(x).gettrig() / 5) - patientsRecords[x].getPatientCheckups(x).gethdl(); }

double HealthRecords::getCholHDL(int x) const
{ return patientsRecords[x].getPatientCheckups(x).getcholesterol() / patientsRecords[x].getPatientCheckups(x).gethdl(); }

double HealthRecords::getBMI(int x) const
{ return patientsRecords[x].getPatientCheckups(x).getweight() * 703 / patientsRecords[x].getPatientCheckups(x).getheight(); }
*/
