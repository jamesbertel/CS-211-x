#include <iostream>
using namespace std;

int main()
{
  int result;
  int *one = 0;
  int *two = 0;
  int *three = 0;
  
  one = new int;
  two = new int;
  three = new int;

  cout << "Enter three integers: ";
  cin >> *one >> *two >> *three;

  int sum = *one + *two + *three

  cout << *one << " + " << *two << " + " << *three;
  cout << " = " << sum << endl;

  delete one; delete two; delete three;

  return 0;
}
