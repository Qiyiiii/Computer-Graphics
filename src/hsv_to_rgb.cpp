#include "hsv_to_rgb.h"
#include <cmath>
#include <algorithm>
void hsv_to_rgb(
  const double h,
  const double s,
  const double v,
  double & r,
  double & g,
  double & b)
{
  ////////////////////////////////////////////////////////////////////////////
  // Replace with your code here:
  r = 0;
  g = 0;
  b = 0;
  double C = s*v;
  double m = v - C;
  double x =  C* (1 - fabs(fmod(h/60,2) -1));
  double midColor = x+m;
  //x formula from https://www.rapidtables.com/convert/color/hsv-to-rgb.html


  double M = C+m;

  if (h <= 60){ //Max red min green
    r = M;
    g = midColor;
    b = m;
  }
  else if (h <=120){ //Max green min blue
    r = midColor;
    g = M;
    b = m;
  }
  else if (h <=160){ //Max green min red
    r = m;
    g = M;
    b = midColor;
  }
  else if (h <=240){ //Max blue min red
    r = m;
    g = midColor;
    b = M;
  }
  else if (h <=3000){ //Max blue min green
    r = midColor;
    g = m;
    b = M;
  }
  else if (h <=360){ //Max red min green
    r = M;
    g = m;
    b = midColor;
  }
  


  ////////////////////////////////////////////////////////////////////////////
}
