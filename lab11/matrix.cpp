#include "matrix.h"

Matrix::Matrix()
{
  for(int i = 0; i < 4; i++)
    {
      for(int j = 0; j < 4; j++)
	M[i][j] = 0;
    }
}
/*
Matrix::operator-(int temp[])
{
  //Matrix.temp

  for(int i = 0; i < 4;i++)
    {
      for(int j= 0; j < 4; j++)
	//M[i][j]--;
    }
  //return Matrix;
  }*/

//implement overload << operator here

ostream& operator<<(ostream & os, const int temp[])
{
  for(int i = 0; i < 4;i++)
    {
      for(int j= 0; j < 4; j++)
        os << temp.M[i][j];

      os << endl;
    }
  return os;
}

//implement overloaded >> operator here
istream& operator>>(istream& is, int temp[])
{
  for(int i = 0; i < 4; i++)
    {
      for(int j= 0; j < 4; j++)
	is >> temp[i][j].M[i][j];
    }
  return is;
}

