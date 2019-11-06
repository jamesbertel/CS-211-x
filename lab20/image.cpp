#include "image.h"

Image::Image(string n, double s, string f, string r)
{
  name = n;
  size = s;
  format = f;
  resolution = r;
  next = NULL;
  previous = NULL;
}
