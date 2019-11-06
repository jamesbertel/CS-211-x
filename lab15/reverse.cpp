#include <iostream>
#include <string>
using namespace std;

void reverse(const string & s, int i);

int main()
{
  string s;
  cout << "Enter String: ";
  getline(cin, s);
  reverse(s, 0);
  cout << "\ndone!\n";

  return 0;
}

void reverse(const string & s, int i)
{
  char item;
  item = s[i];
  if(s[i] != '\0')
    {
      reverse(s, i+1);
      cout << item;
    }
}
