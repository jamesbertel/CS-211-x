//Tuesday, 1/20/18 (Week 2)
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

void minMaxAvg(int n1, int n2, int n3, int&min, int&max, double&avg);

int main()
{  
  int n1;
  int n2;
  int n3;

  int max;
  int min;
  double avg;

  cout << "Please enter 3 numbers: ";
  cin >> n1 >> n2 >> n3;

  minMaxAvg(n1, n2, n3, max, min, avg);
  
  cout << left << setw(15) << "The average is:";
  cout << right << setw(15) << fixed << setprecision(2) << avg << endl;
  cout << left << setw(15) << "The min is:";
  cout << right << setw(15) << min << endl;
  cout << left << setw(15) << "The max is:";
  cout << right << setw(15) << max << endl << endl;

  return 0;
}

void minMaxAvg(int n1, int n2, int n3, int&max, int&min, double&avg)
{
  min = n1;
  max = n1;

  if(n2 < min)
    min = n2;
  else if(n2 > max)
    max = n2;

  if(n3 < min)
    min = n3;
  else if(n3 > max)
    max = n3;

  avg = (double)(n1+n2+n3)/3;
}
