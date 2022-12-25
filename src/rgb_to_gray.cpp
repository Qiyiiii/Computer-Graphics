#include "rgb_to_gray.h"

void rgb_to_gray(
  const std::vector<unsigned char> & rgb,
  const int width,
  const int height,
  std::vector<unsigned char> & gray)
{
  gray.resize(height*width);
  ////////////////////////////////////////////////////////////////////////////
  for (int i = 0; i<width; i++){
    for (int m = 0; m<height; m++){
      gray[(i+m*width)] = (rgb[3*(i+m*width)])*0.212 + (rgb[1+ 3*(i+m*width)])*0.7152+ (rgb[2+ 3*(i+m*width)])*0.0722;
    }
    }
    }
  ////////////////////////////////////////////////////////////////////////////



