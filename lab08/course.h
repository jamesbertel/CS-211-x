#include <string>
using namespace std;

class Course
{
 private:
  long courseNumber;
  string courseName;
  int numberOfCredits;
 public:
  void setCourse(long cNum, string cName, int numCred);
  void printCourse();
};
