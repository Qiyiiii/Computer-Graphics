#include "hue_shift.h"
#include "hsv_to_rgb.h"
#include "rgb_to_hsv.h"
#include <cmath>
#include <algorithm>
void hue_shift(
  const std::vector<unsigned char> & rgb,
  const int width,
  const int height,
  const double shift,
  std::vector<unsigned char> & shifted)
{
  shifted.resize(rgb.size());
  ////////////////////////////////////////////////////////////////////////////
  for (int i = 0; i<width; i++){
    for (int m = 0; m<height; m++){
      double r = rgb[(m*width+i)*3];
      double g = rgb[(m*width+i)*3+1];
      double b = rgb[(m*width+i)*3+2];
      double h = 0;
      double s = 0;
      double v = 0;
      rgb_to_hsv(r,g,b,h,s,v);
      h = fmod(h+shift,360);
      hsv_to_rgb(h,s,v,r,g,b);
      shifted[(m*width+i)*3] = r;
      shifted[(m*width+i)*3+1] = g;
      shifted[(m*width+i)*3+2] = b;
    }
  }
  ////////////////////////////////////////////////////////////////////////////
}
