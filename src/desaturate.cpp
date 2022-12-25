#include "desaturate.h"
#include "hsv_to_rgb.h"
#include "rgb_to_hsv.h"

void desaturate(
  const std::vector<unsigned char> & rgb,
  const int width,
  const int height,
  const double factor,
  std::vector<unsigned char> & desaturated)
{
  desaturated.resize(rgb.size());
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
      s *= 1- factor;
      hsv_to_rgb(h,s,v,r,g,b);
      desaturated[(m*width+i)*3] = r;
      desaturated[(m*width+i)*3+1] = g;
      desaturated[(m*width+i)*3+2] = b;}
  ////////////////////////////////////////////////////////////////////////////
}
}