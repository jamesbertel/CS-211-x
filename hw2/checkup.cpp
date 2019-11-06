#include "checkup.h"

Checkup::Checkup(string cDate, double pHeight, double pWeight, double pCholesterol, double pHDL, double pTriglyceride, double pGlucose, string pBloodPressure)
{
  checkupDate = cDate;
  height = pHeight;
  weight = pWeight;
  cholesterol = pCholesterol;
  hdlCholesterol = pHDL;
  triglycerides = pTriglyceride;
  glucose = pGlucose;
  bloodPressure = pBloodPressure;
}

Checkup::Checkup()
{
  checkupDate = "DD/MM/YYYY";
  height = 0.0;
  weight = 000.0;
  cholesterol = 0;
  hdlCholesterol = 0;
  triglycerides = 0;
  glucose = 0;
  bloodPressure = "00 mmHg";
}

double Checkup::getheight() const
{ return height; }

double Checkup::getweight() const
{ return weight; }

double Checkup::getcholesterol() const
{ return cholesterol; }

double Checkup::gethdl() const
{ return hdlCholesterol; }

double Checkup::gettrig() const
{ return triglycerides; }

double Checkup::getglucose() const
{ return glucose; }

string Checkup::getbloodPressure() const
{ return bloodPressure; }

string Checkup::getcheckupDate()
{
  return checkupDate;
}
