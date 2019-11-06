#include <string>
using namespace std;

class Student
{
 private:
  string name;
  const long studentID;
  string major;
  string classification;
  int units;
  float tuition;
  static int totalNumofStudents;
  static int nextStudentID;
 public:
  Student();
  Student(string nm, string maj, string clss, int units);
  ~Student();
  void print();
  void getData();
};
