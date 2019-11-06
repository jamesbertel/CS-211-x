#include "rational.h"

RationalNumber::RationalNumber(int n, int d)
{
  numerator = n;
  denominator = d;
}

RationalNumber RationalNumber:: operator-(RationalNumber rhs)
{
  RationalNumber r;

  numerator *= rhs.denominator;
  rhs.numerator *= denominator;
  r.denominator = denominator * rhs.denominator;
  r.numerator = numerator - rhs.numerator;

  return r;
}
