#include <iostream>
#include <string>
using namespace std;

int numChars(string phrase, const char serach, int count);

int main()
{
  string phrase;
  char search;

  cout << "Enter phrase: ";
  getline(cin, phrase);
  cout << "Enter char: ";
  cin >> search;
  int count = 0;

  int num =numChars(phrase, search, count);
  cout << "The character '" << search << "' appears " << num << " times in the string " << phrase << endl;

  return 0;
}

int numChars(string phrase, const char search, int count)
{
  if(phrase.length() == 0)
    {
      return count;
    }
  else
    {
      if(phrase[0] == search)
	count++;
     
      phrase.erase(0, 1);
      return numChars(phrase, search, count);
    }      

  /*for(int i = 0; i < phrase.size(); i++)
    {
      if(phrase[i]==search)
	count++;
    }
  cout << count << endl;*/
}
