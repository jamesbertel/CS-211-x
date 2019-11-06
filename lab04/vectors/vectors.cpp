//Tuesday 2/6/18 (Week 3)
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

void insert(vector <string> & v, string word, const int index);
void delFunc(vector <string> & v, const int index);
void print(const vector <string> & v);

int main()
{
  vector <string> V;
  string command;
  string word;
  int num; 

  ifstream fin;
  fin.open("vectorData.txt");

  if(!fin)
    cout << "File not found" << endl;
  else
    {
      fin >> command;
      while(fin)
	{
	  //fin >> command;
	  if(command=="Insert")
	    { 
	      fin >> word;
	      fin >> num;
	      insert(V, word, num);
	    }
	  else if(command=="Delete")
	    {
	      fin >> num;
	      delFunc(V, num);
	    }
	  else if(command=="Print")
	    print(V);
	  else
	    cout << "error" << endl;

	  fin >> command;
	}
      
    }

  fin.close();
  return 0;
}

void insert(vector <string> & v, string word, const int index)
{
  if(index > v.size())
    cout << "Error: Could not add at " << index << endl;
  else
    v.insert(v.begin()+index, word);
}

void delFunc(vector <string> & v, const int index)
{
  if(index >= v.size())
    cout << "Error: Could not delete at " << index << endl;
  else
    v.erase(v.begin()+index);
}

void print(const vector <string> & v)
{
  cout << endl;
  for(int i = 0; i < v.size(); i++)
    cout << v[i] << " ";
  cout << endl;
}

