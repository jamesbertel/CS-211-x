#include <iostream>
using namespace std;

int main()
{
  int value1 = 5, value2 = 15;
  int *p1, *p2;
  p1 = &value1;
  p2 = &value2;
  *p1 = 10;
  *p2 = *p1;
  cout << *p1 << " " << *p2;
  p1 = p2;
  cout << *p1 << " " << *p2;
  *p1 = 20;
  cout << "value1==" << value1 << "/ value2==" << value2;

  return 0;
}
