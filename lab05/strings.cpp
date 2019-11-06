#include <iostream>
#include <string>
using namespace std;

string ReplaceSubString(string str1, string str2, string str3);

int main()
{
  string string1, string2, string3;

  cout << "Enter the first string: ";
  getline(cin, string1);
  cout << "Enter the second string: ";
  getline(cin, string2);
  cout << "Enter the third string: ";
  getline(cin, string3);

  string string4 = ReplaceSubString(string1, string2, string3);
  
  cout << string4 << endl;
  return 0;
}

string ReplaceSubString(string str1, string str2, string str3)
{
  int how = str1.find(str2, 0);

      
  while(how != str1.npos)
    {
      str1.replace( str1.find(str2, 0), str2.size(), str3);
      how = str1.find(str2, how+1);
    }
  return str1;
}
