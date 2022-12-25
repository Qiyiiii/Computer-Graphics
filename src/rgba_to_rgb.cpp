#include "rgba_to_rgb.h"
#include <iostream>
#include "cmath"

void rgba_to_rgb(
  const std::vector<unsigned char> & rgba,
  const int & width,
  const int & height,
  std::vector<unsigned char> & rgb)
{
    
  rgb.resize(height*width*3);
  ////////////////////////////////////////////////////////////////////////////
  double a;
  for (int i = 0; i<width; i++){
    for (int m = 0; m<height; m++){
      rgb[3*(i+m*width)] = std::round(rgba[4*(i+m*width)] ); 
      rgb[3*(i+m*width)+1] = std::round(rgba[1+4*(i+m*width)]);
      rgb[3*(i+m*width)+2] = std::round(rgba[2+4*(i+m*width)]);
    }
  }

  
  // for (char i: rgba)
  //   std::cout << i << ' ';
  ////////////////////////////////////////////////////////////////////////////
}
