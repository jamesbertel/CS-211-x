//Thursday, 2/8/18 (Week 3)
#include <iostream>
#include <string>
using namespace std;

int main()
{
  string str; //string entered
  string str1; //string outputed
  string temp; //temporary string

  int space = 0; //holds index of space
  int fLet = 0; //first letter of the word

  cout << "Enter sentence: ";
  getline(cin, str); //gets entire string

  space = str.find(" ", space); //finds index of the first space 
  
  while(space != str.size()) 
    {
      if(space == str.npos) //if space is str.npos...
	  space = str.size(); //make space = str.size() instead

      temp = str.substr(fLet+1, space-(fLet+1)); //put part of the word into temp

      str1.append(temp); //add temp to str1
      str1.push_back( str[fLet] ); //add the first letter of the word into str1
      str1.append("ay "); //add "ay"

      fLet = space + 1; //first first letter of next word
      if(space != str.size())
	space = str.find(" ", space+1); //find next space as long as it exists
    }

  cout << str1 << endl << endl; //output line

  return 0;
}
