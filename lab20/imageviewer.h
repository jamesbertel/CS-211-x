#include "image.cpp"

class ImageViewer
{
 private:
  Image* head; //pointer to list head
  Image * current; //pointer of current node
 public:
  ImageViewer();
  void addImage(string iName, double iSize, string iFormat, string iResolution);
  void viewImage(string iName);
  void viewNextImage();
  void viewPreviousImage();
  void deleteCurrentImage();
  void compressCurrentImage(double ration);
  void slideshow();
  void reverseSlideshow();
  void processTransactionFile();
};
