#include "student.h"
#include <iostream>
using namespace std;

int main()
{
  Student stu1;
  stu1.print();

  Student stu2("unknown", "PHYS", "graduate", 0);
  stu2.print();

  stu2.getData(); //julia robertson
  stu2.print();

  cout << endl;

  return 0;
}
