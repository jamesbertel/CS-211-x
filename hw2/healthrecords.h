#include "patient.h"
#include <vector>
using namespace std;

class HealthRecords
{
  friend int getAge(string date);

 private:
  vector <Patient> patientsRecords;

 public:
  void createNewPatient(string fName, string lName, long pSSN, char gen, string bday);
  void printAllPatients() const;
  void addPatientCheckup(long pNum, string cDate, double pHeight, double pWeight, double pCholesterol, double pHDL, double pTriglyceride, double pGlucose, string pBloodPressure);
  int getpatientsRecordsNum() const;
  void processTransactionFile(string fileName);
  void printPatientCheckupSummary(long pNum, string sDate);
  void printPatientHistory(long pNum) const;
  double getLDL(int x) const;
  double getCholHDL(int x) const;
  double getBMI(int x) const;
};
