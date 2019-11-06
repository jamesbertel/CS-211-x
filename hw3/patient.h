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
