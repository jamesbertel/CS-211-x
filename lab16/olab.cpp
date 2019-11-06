#include <iostream>
using namespace std;

int main()
{
  double values[6] = {10, 20, 30, 40, 50, 60};
  double *valptr= values;
  cout << 3*values[1] + valptr[3] + *(valptr + 2) << endl;
  return 0;
}
