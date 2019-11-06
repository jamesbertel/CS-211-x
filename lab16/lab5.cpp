#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
  cout << fixed << setprecision(2);
  int SIZE;
  double sum = 0.00;

  cout << "Enter the number of monthly sales tobe input: ";
  cin >> SIZE;

  double* arrayptr;
  arrayptr = new double[SIZE];

  for(int i = 0; i < SIZE; i++)
    {
      cout << "Enter the monthly sales for month " << i+1 << ": $";
      cin >> *(arrayptr+i);
      sum += *(arrayptr+i);
    }

  cout << "The total saels for the year is: $" << sum << endl;
  cout << "The average monthly sale is: $:" << sum/SIZE << endl;

  delete [] arrayptr;

  return 0;
}
