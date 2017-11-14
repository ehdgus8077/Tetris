#include "O_Block.h"


void O_Block::tetromino(){
  x_y[0][0]=0;
  x_y[0][1]=5;
  x_y[1][0]=0;
  x_y[1][1]=6;
  x_y[2][0]=1;
  x_y[2][1]=5;
  x_y[3][0]=1;
  x_y[3][1]=6;
  rotate_count=0;
  }
  void O_Block::color_(){
    color=COLOR_YELLOW;
    color_no=14;
}
void O_Block::rotate(){}
