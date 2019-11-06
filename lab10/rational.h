//Tuesday, 2/27/18 (Week 6)

class RationalNumber
{
  friend void print(RationalNumber r);

 private:
  int numerator;
  int denominator;

 public:
  RationalNumber( int = 0, int = 1);
  RationalNumber operator-(RationalNumber rhs);
};
