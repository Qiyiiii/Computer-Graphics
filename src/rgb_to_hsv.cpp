#include "rgb_to_hsv.h"
#include <algorithm>
#include <cmath>
void rgb_to_hsv(
  const double r,
  const double g,
  const double b,
  double & h,
  double & s,
  double & v)
{
  ////////////////////////////////////////////////////////////////////////////
  // Replace with your code here:
  h = 0;
  s = 0;
  v = 0;
  double M = std::max({r,g,b});
  double m = std::min({r,g,b});
  double C = M - m;
  v = M;
  if (v==0){
    s = 0;  }
  else{
    s = C/v;
  }
  if(C == 0){
    h = 0;
  }
  else if (M == r){
    h = 60 * fmod((g-b)/C,6);
  }
  else if (M == r){
    h = 60 * (((b-r)/C)+2);
  }
  else{
    h = 60 * (((r-g)/C)+4);
  }


  if (h < 0){ //change h to positive degree
  
    h = 360 - h;
  }
  ////////////////////////////////////////////////////////////////////////////
}
