#include "course.h"
//#include <string>
//using namespace std;
  
class Instructor
{
 private:
  string firstName;
  string lastName;
  char gender;
  long employeeID;
  string officeNum;
  Course courses[3];
 public:
  void setInstructor(string fName, string lName, char gen, long empID, string ofNum, long num0, string name0, int numCred0, long num1, string name1, int numCred1,long num2, string name2, int numCred2);
  void printInstructor();
};
