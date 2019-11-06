//Thursday, 1/25/18 (Week 1)
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

int main()
{

  ifstream fin;
  ofstream fout;

  int account;
  string type;
  double startBal;
  double deposit;
  double withdrawal;
  double endBal;
  const double P_INTEREST = .05;
  const double C_INTEREST = .03;
  const double B_INTEREST = .01;

  fin.open("accounts.txt");

  if(!fin)
    fout << "File not found" << endl;
  else
    {
      fout.open("accountsOut.txt");

      fout << fixed << setprecision(2);
      fout << left << setw(10) << "Account" << setw(10) << "Type" << right << setw(15) << "Start Balance";
      fout << setw(15) << "Deposit" << setw(15) << "Withdrawal" << setw(15) << "End Balance" << endl;
      fout << "-------------------------------------------------------------------------------" << endl;

      fin >> account;
      fin >> type;
      fin >> startBal;
      fin >> deposit;
      fin >> withdrawal;

      while(fin)
	{
	  fout << left << setw(10) << account << setw(10) << type << right << setw(15) << startBal;
	  fout << setw(15) << deposit << setw(15) << withdrawal;

	  endBal = startBal + deposit - withdrawal;
	  
	  if(type=="Premium")
	    endBal += endBal*P_INTEREST;
	  else if(type=="Choice")
	    endBal += endBal*C_INTEREST;
	  else //type == "Basic"
	    endBal += endBal*B_INTEREST;

	  fout << setw(15) << endBal << endl;

	  fin >> account;
	  fin >> type;
	  fin >> startBal;
	  fin >> deposit;
	  fin >> withdrawal;	  
	}

      fin.close();
      fout.close();

    }

  return 0;
}
