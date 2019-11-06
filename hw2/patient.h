#include "checkup.h"
#include <string>
#include <vector>
using namespace std;

class Patient
{
private:
  const long patientAccountNum; //=nextPatientAccountNum
  string firstName;
  string lastName;
  long SSN;
  char gender;
  string birthDate;
  vector <Checkup> patientCheckups;
  static long nextPatientAccountNum;

public:
  Patient();
  Patient(string fName, string lName, long pSSN, char gen, string bday);
  void getPatient(long pNum, string fName, string lName, long pSSN, char gen, string bday, long nextpNum);
  long getSSN() const;
  long getpatientAccountNum() const;
  string getfirstName() const;
  char getgender() const;
  string getlastName() const;
  string getbirthDate() const;
  void  pushpatientCheckups(Checkup temp);
  Checkup getPatientCheckups(int x) const;
  double getheight(int x) const;
  double getweight(int x) const;
  int getAge(string date);
  void PatientCheckupSummary(string sDate);
  void PatientHistory();
  double getCholHDL(int x) const;
  double getLDL(int x) const;
  double getBMI(int x) const;
};

