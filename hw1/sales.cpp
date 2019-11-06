0/****************
James Bertel
CS 211
Dr. Mayssaa Al Najjar
Homework Assignment #1
****************/
#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
using namespace std;

struct Division
{
  string name; //name of the division
  double quarterlySales[4]; //division's sales of each quarter
};

vector<Division> divInfo; //vector for division information


int pos;
string temp;
fin >> temp;
fin >> pos;

if(vec.size() < pos)
  cout << "Error, cannot add word\n";
 else //vec.size > pos(ition)
   vec[pos] = temp;//Prototypes
void Display();
void Add(ifstream & fin);
void Search(ifstream & fin);
void Delete(ifstream & fin);
void Update(ifstream & fin);
void calculateTotalSales();
void highestLowestQuarter();
void Save();

int main()
{
  ifstream fin;
  string operation; //variable for commands such as "add", "display", "search", etc

  fin.open("DivisionsTrans.txt");
  cout << endl;

  if(!fin)
    cout << "Error: file DNE" << endl;
  else
    {
      fin >> operation; //put first command into operation
      while(fin)
	{ //call proper function based on command
	  if(operation=="display")
	    Display();
	  else if(operation=="add")
	    Add(fin);
	  else if(operation=="search")
	    Search(fin);
	  else if(operation=="delete")
	    Delete(fin);
	  else if(operation=="update")
	    Update(fin);
	  else if(operation=="calculateTotalSales")
	    calculateTotalSales();
	  else if(operation=="highestLowestQuarter")
	    highestLowestQuarter();
	  else if(operation=="save")
	    Save();
	  else
	    {cout << "ERROR: NO COMMAND. CHECK FILE." << endl; break;}

	  fin >> operation; //puts "add", "display", "search", etc into operation
	}
    }

  cout << endl;
  fin.close();
  return 0;
}

/********
This function saves the vector data to output file "DivisionsOut.txt"
********/
void Save()
{
  ofstream fout; //variable for output file
  fout.open("DivisionsOut.txt");

  //go through each division  
  for(int i = 0; i < divInfo.size(); i++)
    {
      fout << divInfo[i].name; //add division name

      //add each quarter for each division
      for(int r = 0; r < 4; r++)
	fout << " " << divInfo[i].quarterlySales[r];

      fout << " " << endl;
    }

  cout << "Divisions data successfully saved...\n";

  fout.close();
}

/********
This function determines and prints which quarters have the highest and lowerst amount of sales for the company
*********/
void highestLowestQuarter()
{
  double lowest, highest; //actual lowest and highest amounts 
  int highestQuarter, lowestQuarter; //which quarters were the lowest and highest

  //output header
  cout << fixed << setprecision(2) << endl;
  cout << left << setw(25) << "Division" << right;
  cout << setw(10) << "Highest" << setw(15) << "HighestAmt";
  cout << setw(10) << "Lowest" << setw(15) << "LowestAmt";
  cout << "\n-----------------------------------------------------------------------------\n";

  //go through each division
  for(int i = 0; i < divInfo.size(); i++)
    {
      //set variables to defaults
      lowest = divInfo[i].quarterlySales[0];
      highest = divInfo[i].quarterlySales[0];
      highestQuarter = 0;
      lowestQuarter = 0;

      //find lowest and highest of all quarters
      for(int r = 0; r < 4; r++)
	{
	  if(divInfo[i].quarterlySales[r] < lowest)
	    {	 
	      lowest = divInfo[i].quarterlySales[r];
	      lowestQuarter = r;
	    }
	  else if(divInfo[i].quarterlySales[r] > highest)
	    {
	      highest = divInfo[i].quarterlySales[r];
	      highestQuarter = r;
	    }
	}
      
      //output lows and highs for each division
      cout << left << setw(25) << divInfo[i].name << right;
      cout << setw(10) << highestQuarter + 1 << setw(15) << highest;
      cout << setw(10) << lowestQuarter + 1 << setw(15) << lowest << endl;
    }
  cout << endl;
}

/**********
This function calculates and prints the total sales for all divisions in the company
**********/
void calculateTotalSales()
{
  double totalSales = 0;

  //go through each division
  for(int i = divInfo.size() - 1; i >= 0; i--)
    {
      //add total from every division
      for(int r = 0; r < 4; r++)
	  totalSales += divInfo[i].quarterlySales[r];
    }

  cout << "Total sales of all divisions: " << totalSales << endl;
}

/**********
This function updates the quarterly sales of a Division.
**********/
void Update(ifstream & fin)
{
  string DivisionName;
  int Quarter; //quarter number
  double QuarterSales; //actual sales
  bool divisionFound = false; //keeps track if division was found
  int x; //position of Division name (if found)

  fin >> DivisionName; //gets name of division
  fin >> Quarter; //gets specific quarter number  
  fin >> QuarterSales; //gets amount to quarter update
  
  if(Quarter < 1 || Quarter > 4) //if quarter is not between 1 and 4
    cout << "No such quarter exists, division can not be updated\n";
  else
    {
      for(int i = 0; i < divInfo.size(); i++)
	{
	  x = divInfo[i].name.find(DivisionName, 0);
	  
	  if(x != divInfo[i].name.npos) //finds if the division exists
	    {
	      divisionFound = true;
	      divInfo[i].quarterlySales[Quarter-1] = QuarterSales;
	      cout << " successfully updated quarter " << Quarter << " sales to " << QuarterSales << endl;
	    }
	}
    }

  if(divisionFound==false) //If Division was never found
    cout << "No such divisions exists, can not be updated\n";
}

/************
This function deletes an existing Division entry specified by its Division name
************/
void Delete(ifstream & fin)
{
  string DivisionName; //hold the Division name
  int Quarter; //specific quarter to update
  double QuarterSales; //amount to update quarter
  bool divisionFound = false; //keeps track if division was found
  int x; //position of Division name (if found) 

  fin >> DivisionName; //puts division name into string 

  for(int i = divInfo.size()-1; i >= 0; i--)
    {
      x = divInfo[i].name.find(DivisionName, 0); //finds Division name

      if(x != divInfo[i].name.npos) //if Division name found,
	{
	  divisionFound = true;
	  divInfo.erase( divInfo.begin() + i);
	  cout << " successfully deleted\n";
	}
    }

  if(divisionFound==false) //if Division was never found
    cout << "No such division exist, can not be deleted\n";
}

/*************
This function searches and returns all Divisions who match a DivisionName
*************/
void Search(ifstream & fin)
{
  string DivisionName;
  fin >> DivisionName;

  int x; //position of Division name (if found)
  int counter = 0; //number of divisions found in search

  for(int i = 0; i < divInfo.size(); i++)
    {
      x = divInfo[i].name.find(DivisionName, 0);

      if(x != divInfo[i].name.npos)
	{
	  counter++;

	    if(counter==1) //output header once
	    {
	      cout << fixed << setprecision(2) << endl;
	      cout << left << setw(25) << "Division" << right;
	      cout << setw(10) << "Quarter1" << setw(10) << "Quarter2";
	      cout << setw(10) << "Quarter3" << setw(10) << "Quarter4";
	      cout << setw(13) << "Total Sales" << endl;
	      cout << "-----------------------------------------------------------------------------\n";
	    }
	    //output division info
	  cout << left << setw(25) << divInfo[i].name << right;
	  cout << setw(10) << divInfo[i].quarterlySales[0] << setw(10) << divInfo[i].quarterlySales[1];
	  cout << setw(10) << divInfo[i].quarterlySales[2] << setw(10) << divInfo[i].quarterlySales[3];
	  cout << setw(13) << divInfo[i].quarterlySales[0]+divInfo[i].quarterlySales[1]+divInfo[i].quarterlySales[2]+divInfo[i].quarterlySales[3] << endl;
	}
    }

  if(counter==0)//if no divisions were found
    cout << "No such division exists";

  cout << endl;
}

/*****************
This function adds one division to the main vector, using a temporary struct
*****************/
void Add(ifstream & fin)
{
  Division temp; //temporary struct to put division info into
  bool sales = true; //sales==true if all quarterly sales are valid

  //put division information into temporary structure
  fin >> temp.name;                             
  fin >> temp.quarterlySales[0]; fin >> temp.quarterlySales[1];
  fin >> temp.quarterlySales[2]; fin >> temp.quarterlySales[3];
  
  //check that all quarterly sales are valid
  for(int i = 0; i < 4; i++)
    {
      if(temp.quarterlySales[i] < 0)
	{
	  sales = false; //set valid sales to false
	  break; //break out of loop
	}
    }
  
  if(sales == false) //if any sales numbers are invalid
    cout << "Invalid data, can not be added to divisions\n";
  else //if all sales are valid
    {
      //checks for capitalization to find spaces
      for(int i = 1; i < temp.name.size(); i++)
	{
	  //if any characters are capitalized, add a space
	  if(temp.name[i] < 'a')
	    {
	      temp.name.insert(i, " ");
	      i++;
	    }
	}

      //puts valid division info into vector
      divInfo.push_back(temp);

      //output message of success
      cout << " successfully added to divisions...\n";
    }
}

/************
This function displays all divisions in the vector
***********/
void Display()
{
  //output header
  cout << fixed << setprecision(2) << endl;
  cout << left << setw(25) << "Division" << right;
  cout << setw(10) << "Quarter1" << setw(10) << "Quarter2";
  cout << setw(10) << "Quarter3" << setw(10) << "Quarter4";
  cout << setw(13) << "Total Sales" << endl;
  cout << "-----------------------------------------------------------------------------\n"; 
  
  for(int i = 0; i < divInfo.size(); i++)
    {
      //output struct, one division at a time
      cout << fixed << setprecision(2);
      cout << left << setw(25) << divInfo[i].name << right;
      cout << setw(10) << divInfo[i].quarterlySales[0] << setw(10) << divInfo[i].quarterlySales[1];
      cout << setw(10) << divInfo[i].quarterlySales[2] << setw(10) << divInfo[i].quarterlySales[3];
      cout << setw(13) << divInfo[i].quarterlySales[0]+divInfo[i].quarterlySales[1]+divInfo[i].quarterlySales[2]+divInfo[i].quarterlySales[3] << endl;
    }
  cout << endl;
}
