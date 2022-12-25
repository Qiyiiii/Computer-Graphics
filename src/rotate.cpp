#include "rotate.h"

void rotate(
  const std::vector<unsigned char> & input,
  const int width,
  const int height,
  const int num_channels,
  std::vector<unsigned char> & rotated)
{
  rotated.resize(height*width*num_channels);
  ////////////////////////////////////////////////////////////////////////////
  for (int i = 0; i<width; i++){
      for (int m = 0; m<height; m++){
        if(num_channels == 3){
          rotated[3*m+ 3*((width-i-1)*height)] = input[3*(i+m*width)];
          rotated[3*m+ 1+3*((width-i-1)*height)] = input[3*(i+m*width)+1];
          rotated[3*m+ 2+3*((width-i-1)*height)] = input[3*(i+m*width)+2];}


  
        else{
      rotated[m+(width-1-i) * height] = input[i+m*width];
    }
    }
    
  }
    
  ////////////////////////////////////////////////////////////////////////////
}
