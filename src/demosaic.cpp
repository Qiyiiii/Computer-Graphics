#include "demosaic.h"

bool notout(
  int width,
  int height,
  int i,
  int m)
  {
  if (i<0 || i > width-1){
    return false;
  }
  if (m<0 || m > height-1){
    return false;
  }
  return true;
  }
void demosaic(
  const std::vector<unsigned char> & bayer,
  const int & width,
  const int & height,
  std::vector<unsigned char> & rgb)
{
  rgb.resize(width*height*3);
  ////////////////////////////////////////////////////////////////////////////
  int a[2] = {-1,1};

    for (int i = 0; i<width; i++){
    for (int m = 0; m<height; m++){
      if (m%2 == 0){  //g and b
        if (i % 2 == 0){ //g
          rgb[3*(i+m*width)+1] = bayer[i+m*width];

          int b=0; //blue num
          int blue_in = 0; //blue intensity 
          for (int n = 0; n < 2; n++){
            if (notout(width,height,i+a[n],m)){
              b++;
              blue_in += bayer[i + a[n]+m*width]; //blue value from left and right
            }
          }
          rgb[3*(i+m*width)+2] = blue_in/b;

          int r=0; //red num
          int red_in = 0; //red intensity 
          for (int n = 0; n < 2; n++){
            if (notout(width,height,i,m+a[n])){
              r++;
              red_in += bayer[i +(m+a[n])*width]; //red value from up and down
            }
          }
          rgb[3*(i+m*width)] = red_in/r;

          

        }
        else{//b
          rgb[3*(i+m*width)+2] = bayer[i+m*width];

          int g=0; //grean num
          int green_in = 0; //green intensity 
          for (int n = 0; n < 2; n++){
            if (notout(width,height,i+a[n],m)){
              g++;
              green_in += bayer[i + a[n]+m*width]; //grean value from left and right
            }
          }
          for (int n = 0; n < 2; n++){
            if (notout(width,height,i,m+a[n])){
              g++;
              green_in += bayer[i +(m+a[n])*width];  //grean value from up and down
            }
          }
          rgb[3*(i+m*width)+1] = green_in/g;


          int r=0; //red num
          int red_in = 0; //red intensity 
          for (int n = 0; n < 2; n++){
            for (int n1 = 0; n1 < 2; n1++){
            if (notout(width,height,i+a[n],m+a[n1])){ //red from 4 corners
              r++;
              red_in += bayer[i +a[n] +(m+a[n1])*width];
            }
          }}
          rgb[3*(i+m*width)] = red_in/r;

        }}
        else{ //r,g
          if(i%2 == 0){ //r
            rgb[3*(i+m*width)] = bayer[i+m*width];

            int g=0; //grean num
          int green_in = 0; //green intensity 
          for (int n = 0; n < 2; n++){
            if (notout(width,height,i+a[n],m)){ 
              g++;
              green_in += bayer[i + a[n]+m*width];//green from left and right
            }
          }
          for (int n = 0; n < 2; n++){
            if (notout(width,height,i,m+a[n])){
              g++;
              green_in += bayer[i +(m+a[n])*width];//green from up and down
            }
          }
          rgb[3*(i+m*width)+1] = green_in/g;

          int b = 0;//blue num
          int blue_in = 0; //blue intensity
          for (int n = 0; n < 2; n++){
            for (int n1 = 0; n1 < 2; n1++){
            if (notout(width,height,i+a[n],m+a[n1])){ //blue from 4 corners
              b++;
              blue_in += bayer[i +a[n] +(m+a[n1])*width];
            }
          }}
          rgb[3*(i+m*width)+2] = blue_in/b;

          

          }
          else{ //g
          rgb[3*(i+m*width)+1] = bayer[i+m*width];

          int r=0; //red num
          int red_in = 0; //red intensity 
          for (int n = 0; n < 2; n++){
            if (notout(width,height,i+a[n],m)){ //red from left and right
              r++;
              red_in += bayer[i + a[n]+m*width];
            }
          }
          rgb[3*(i+m*width)] = red_in/r;

          int b=0; //blue num
          int blue_in = 0; //blue intensity 
          for (int n = 0; n < 2; n++){
            if (notout(width,height,i,m+a[n])){ //blue from  up and down
              b++;
              blue_in += bayer[i +(m+a[n])*width];
            }
          }
          rgb[3*(i+m*width)+2] = blue_in/b;

            
          }

        }

      }

    }
  ////////////////////////////////////////////////////////////////////////////
}
