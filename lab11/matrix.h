#include <iostream>
using namespace std;

class Matrix
{
  //stand alone & friends
  friend ostream& operator<<(ostream & os, const int temp[]);
  friend istream& operator>>(istream& is, int temp[]);

 private:
  int M[4][4]; //4 by 4 matrix of integers
 public:
  Matrix();
  //prototypes
  //operator-(int temp[]);
};
