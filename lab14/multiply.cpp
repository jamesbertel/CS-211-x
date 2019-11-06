#include <iostream>
using namespace std;

int recurse(const int x, int y, int sum);
//int z = 0;

int main()
{
  int x;
  int y;

  cout << "Enter x: ";
  cin >> x;
  cout << "Enter y: ";
  cin >> y;

  int sum = 0;
  int ans = recurse(x, y, sum);
  cout << ans << endl;
  return 0;
}

int recurse(const int x, int y, int sum)
{
  if(y == 0)
    return sum;
  else
    {
      sum += x;
      return recurse(x, y-1, sum);
    }
}
