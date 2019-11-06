//Tuesday, 1/30/18 (Week 2)
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

string removeSpace(string string1);

int main()
{
  string string1;

  cout << "Please enter a phrase: ";
  getline(cin, string1);

  string word = removeSpace(string1);

  cout << "The resulting phrase is: " << word << endl;

  return 0;
}

string removeSpace(string string1)
{
  stringstream word;
  string temp;
  
  word << string1;
  string1 = "";

  while(word >> temp)
    {
      string1 += temp;
    } 

  return string1;
}
