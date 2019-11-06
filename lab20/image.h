#include <string>
using namespace std;

class Image //node class                                                                              
{
  friend class ImageViewer;

 private:
  string name; //include path
  double size; //in Kbytes
  string format; //jpg, bmp, png...
  string resolution; //1024x1024, 640x480, 3376x6000
  Image *previous; //pointer to previous Image node
  Image *next; //pointer to next Image node

 public:
  Image(string n, double s, string f, string r);
  Image(){};
};
