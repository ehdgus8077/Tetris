#include "T_Block.h"


void T_Block::tetromino(){
      x_y[0][0]=0;
      x_y[0][1]=5;
      x_y[1][0]=1;
      x_y[1][1]=4;
      x_y[2][0]=1;
      x_y[2][1]=5;
      x_y[3][0]=1;
      x_y[3][1]=6;
      rotate_count=0;
  }
  void T_Block::color_(){
    color=COLOR_CYAN;
    color_no=16;
}
void T_Block::rotate(){
  rotate_count++;
  int count=0;
  switch (rotate_count%4) {
    case 1:
    if(board[x_y[0][0]+1][x_y[0][1]-1] == 0) count ++;
       if(board[x_y[1][0]-1][x_y[1][1]+1] == 0) count ++;
       if(board[x_y[3][0]+1][x_y[3][1]-1] == 0) count ++;

       if(count == 3){
         x_y[0][0] ++; x_y[0][1] --;
         x_y[1][0] --; x_y[1][1] ++;
         x_y[3][0] ++; x_y[3][1] --;

       }
       else
         rotate_count--;
    break;
    case 2:
    if(board[x_y[0][0]+1][x_y[0][1]+1] == 0) count ++;
    if(board[x_y[1][0]+1][x_y[1][1]+1] == 0) count ++;
    if(board[x_y[3][0]-1][x_y[3][1]-1] == 0) count ++;

    if(count == 3){
      x_y[0][0] ++; x_y[0][1] ++;
      x_y[1][0] ++; x_y[1][1] ++;
      x_y[3][0] --; x_y[3][1] --;

    }
    else
      rotate_count--;
    break;
    case 3:
    if(board[x_y[0][0]-1][x_y[0][1]+1] == 0) count ++;
      if(board[x_y[1][0]-1][x_y[1][1]-1] == 0) count ++;
      if(board[x_y[3][0]+1][x_y[3][1]+1] == 0) count ++;

      if(count == 3){
        x_y[0][0] --; x_y[0][1] ++;
        x_y[1][0] --; x_y[1][1] --;
        x_y[3][0] ++; x_y[3][1] ++;

      }
      else
        rotate_count--;
    break;

    case 0:
    if(board[x_y[0][0]-1][x_y[0][1]-1] == 0) count ++;
         if(board[x_y[1][0]+1][x_y[1][1]-1] == 0) count ++;
         if(board[x_y[3][0]-1][x_y[3][1]+1] == 0) count ++;

         if(count == 3){
           x_y[0][0] --; x_y[0][1] --;
           x_y[1][0] ++; x_y[1][1] --;
           x_y[3][0] --; x_y[3][1] ++;
        }
        else
          rotate_count--;
    break;
  }
}
