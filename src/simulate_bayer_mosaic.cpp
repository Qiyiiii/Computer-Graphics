#include "simulate_bayer_mosaic.h"

void simulate_bayer_mosaic(
  const std::vector<unsigned char> & rgb,
  const int & width,
  const int & height,
  std::vector<unsigned char> & bayer)
{
  bayer.resize(width*height);
  ////////////////////////////////////////////////////////////////////////////
  for (int i = 0; i<width; i++){
    for (int m = 0; m<height; m++){
      if (m%2 == 0){  //g and b
        if (i % 2 == 0){ //g
          bayer[(i+m*width)] = rgb[3*(i+m*width)+1];
        }
        else{//b
          bayer[(i+m*width)] = rgb[3*(i+m*width)+2];

        }}
        else{ //r,g
          if(i%2 == 0){
            bayer[(i+m*width)] = rgb[3*(i+m*width)];
          }
          else{
            bayer[(i+m*width)] = rgb[3*(i+m*width)+1];
          }

        }

      }

    }
  }
  ////////////////////////////////////////////////////////////////////////////

