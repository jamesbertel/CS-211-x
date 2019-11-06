#include <iostream>
#include <string>
using namespace std;
bool isPalindrome(const string s,int, string);

int main()
{
  string s;
  cout << "Enter String: ";
  getline(cin, s);
  string r = s;
  bool result = isPalindrome(s, 0,r);
  if(result==true)
    cout << "true\n";
  else
    cout << "false\n";

  return 0;
}

bool isPalindrome(string s, int i, string r)
{
  bool check = false;

  r[s.size()-i] = s[i];
  cout << i << " " << s.size() << " " << r[s.size()-i] << endl;
  
  if(s[i] != '\0')
    check = isPalindrome(s, i+1, r);
  
  cout << "s: " << s << endl << "r: " << r << endl;

  if(r==s)
    return true;


  //  if(s[i]!='\0')
  //check = isPalindrome(s, i+1, r);
}      
