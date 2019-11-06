#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Patient
{
private:
  long patientID;
  string name;
  char gender;
  string birthDate;

public:
  long getID(int i, Patient* array);
  string getname();
  char getgen();
  string getbday();
};

int main()
{
  const int SIZE = 4;
  //Declare an array of 4 pointers to objects of class Patient
  Patient *arrayptr;
  //Make the array point to 4 new Patient objects
  arrayptr = new Patient[SIZE];
  //Set the attributes of these objects to the following:
  
  long ID;
  string name, bday;
  char gen;

  for(int i = 0; i < SIZE; i++)
    {
      cout<< "Enter patient ID: ";
      cin >> getID(i, arrayptr);
    }

  //Display the data of each patient in a neat table format.
  cout << left << setw(10) << "ID" << setw(20) << "Name";
  cout << left << setw(15) << "Birth date" << "Gender" << endl;
 
  for(int i = 0; i < SIZE; i++)
    {
      ;//cout << left << setw(10) << getID(i);
      //cout << setw(20) << *(array.name + i);
      //cout << setw(15) << *(array.birthDate + i);
      //cout << *(array.gender + i)<< endl;
    }

  return 0;
}
long Patient::getID(int i, Patient* array)
{ return *(array.patientID+i); }


