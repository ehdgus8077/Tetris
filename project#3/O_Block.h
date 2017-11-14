#ifndef __O_Block_h__
#define __O_Block_h__
#include <ncurses.h>
#include "Block.h"
class O_Block : public Block
{
private:
  int pre_x_y[4][4];
  int rotate_count;

public:
  O_Block(int x, int y, int w, int h,int *score, WINDOW* w2) : Block(x, y, w, h,score,w2){
    rotate_count=0;
    tetromino();
    color_();
  }
    void tetromino();
    void color_();
    void rotate();
};


#endif
