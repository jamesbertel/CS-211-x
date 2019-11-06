#include <string>
using namespace std;

class Checkup
{
 private:
  string checkupDate;
  double height;
  double weight;
  double cholesterol;
  double hdlCholesterol;
  double triglycerides;
  double  glucose;
  string bloodPressure;
 public:
  Checkup();
  void setCheckup(string cDate, double pHeight, double pWeight, double pCholesterol, double pHDL, double pTriglyceride, double pGlucose, string pBloodPressure);
  Checkup(string cDate, double pHeight, double pWeight, double pCholesterol, double pHDL, double pTriglyceride, double pGlucose, string BloodPressure);
  double getheight() const;
  double getweight() const;
  double getcholesterol() const;
  double gethdl() const;
  double gettrig() const;
  double getglucose() const;
  string getbloodPressure() const;
  string getcheckupDate();
};
