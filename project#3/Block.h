#ifndef __Block_h__
#define __Block_h__
#include <ncurses.h>
extern int board[][12];
class Block
{
protected:
    int x_y[4][4];
    WINDOW* win_;
    int height_;
    int width_;
    int *score;
    int color;
    int color_no;
    int rotate_count;
public:
    Block(int , int , int , int , int*, WINDOW*);
    ~Block();
    int check;
    bool draw();
    void move_draw();
    void moveblock(char);
    void clear();
    virtual void color_(){}
    virtual void tetromino(){}
    virtual void rotate(){}
};


#endif
