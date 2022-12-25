#include "over.h"
#include <iostream>
void over(
  const std::vector<unsigned char> & A,
  const std::vector<unsigned char> & B,
  const int & width,
  const int & height,
  std::vector<unsigned char> & C)
{
  C.resize(A.size());
  ////////////////////////////////////////////////////////////////////////////
  for (int i = 0; i<width; i++){
    for (int m = 0; m<height; m++){    
      //https://en.wikipedia.org/wiki/Alpha_compositing
      // std::cout << (double)A[(i+m*width)*4+3] <<" ";
      //alpha channel doesn't come with [0,1], why?
      double aa = A[(i+m*width)*4+3]/255.0; //alpha for a
      double ab = B[(i+m*width)*4+3]/255.0; //alpha for b
      C[(i+m*width)*4+3] = (aa + ab *(1-aa));
      double a0 = C[(i+m*width)*4+3];
      C[(i+m*width)*4] = (A[(i+m*width)*4]*aa + B[(i+m*width)*4]*ab*(1-aa))/a0;
      C[(i+m*width)*4+1] = (A[(i+m*width)*4+1]*aa + B[(i+m*width)*4+1]*ab*(1-aa))/a0;
      C[(i+m*width)*4+2] = (A[(i+m*width)*4+2]*aa + B[(i+m*width)*4+2]*ab*(1-aa))/a0;
      C[(i+m*width)*4+3] *= 255;

    }}
  ////////////////////////////////////////////////////////////////////////////
}
