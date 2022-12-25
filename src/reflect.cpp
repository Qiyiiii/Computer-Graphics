#include "reflect.h"

void reflect(
  const std::vector<unsigned char> & input,
  const int width,
  const int height,
  const int num_channels,
  std::vector<unsigned char> & reflected)
{
  reflected.resize(width*height*num_channels);
  ////////////////////////////////////////////////////////////////////////////
  for (int i = 0; i<width; i++){
      for (int m = 0; m<height; m++){
        if(num_channels == 3){
          reflected[3*(i+m*width)] = input[3*((m+1)*width) - 3*i-3];
          reflected[3*(i+m*width)+1] =  input[3*((m+1)*width )- 3*i-2];
          reflected[3*(i+m*width) + 2] = input[3*((m+1)*width) - 3*i-1];
    }
        else{
      reflected[(i+m*width)] = input[3*((m+1)*width) - i - 1];
    }
    }
    
  }
  ////////////////////////////////////////////////////////////////////////////
}
