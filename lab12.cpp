#include <iostream>
using namespace std;
int sumDigits(int n);

int main()
{
  int num;
 
  cout << "Enter number: ";
  cin >> num;

  sumDigits(num);
  return 0;
}

int sumDigits (int n)
{
  int total;

  while (n != 0)
      {
        total += n % 10;
        n = n / 10;
      }

  cout << total << endl;
}
