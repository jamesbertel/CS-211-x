#include "rational.h"
#include <iostream>
using namespace std;

void print(RationalNumber r)
{
  cout << r.numerator << "/" << r.denominator << endl;
}

int main()
{
  RationalNumber r1( 7, 3), r2( 3, 9 ), r3;
  r3 = r1 - r2;

  print(r3);

  return 0;
}
