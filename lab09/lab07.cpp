//Thursday, 2/15/18 (Week 4)
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

class Mortgage
{
private:
  double loan;
  double rate;
  int yr;
public:
  void setAttributes(double a, double r, int y);
  void displayAttributes();
  double monthlyPay();

};

double monthlyPay();

int main()
{
  Mortgage mort;
  double loan, rate;
  int year;
  do
    {
      cout << "Enter the loan amount in dollars: ";
      cin >> loan;
    }while(loan < 0);
  cout << "Enther the annual interest rate in decimal form: ";
  cin >> rate;
  cout << "Enter the length of the loan in years: ";
  cin >> year;

  mort.setAttributes(loan, rate, year);
  mort.displayAttributes();
  cout << "Monthly payment: $" << mort.monthlyPay() << endl;
  return 0;
}

void Mortgage::setAttributes(double a, double r, int y)
{
  loan = a;
  rate = r;
  yr = y;
}

void Mortgage::displayAttributes()
{
  cout << "\nPrinting loan summary information:\n" << fixed << setprecision(2);
  cout << "Loan amount: $" << loan << endl;
  cout << "Interest rate: " << (rate*100) << "%\n";
  cout << "Loan period: " << yr << " years\n";
}

double Mortgage::monthlyPay()
{
  double term = pow( (1 + (rate/12)), (12*yr) );
  return (loan * term * (rate/12))/(term-1);
}
