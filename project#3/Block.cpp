#include "Block.h"
Block::Block(int x, int y, int w, int h, int* num,WINDOW* window)
{

    height_=h;
    width_=w;
    win_ = window;
    tetromino();
    score=num;
    check=0;
    color_();
    rotate_count=0;


}
Block::~Block()
{
  delwin(win_);
}

bool Block::draw()
{
    init_pair(color_no, color, COLOR_BLACK);
    wattron(win_, COLOR_PAIR(color_no));
    box(win_,0,0);
    for (int i=1; i<height_-1; i++)
        for(int j=2; j<22; j+=2)
        {
            if(board[i-1][j/2]==color_no)
                mvwhline(win_, i, j-1, ACS_CKBOARD, 2);

        }
    wattroff(win_, COLOR_PAIR(color_no));
    wrefresh(win_);
    if(board[0][4]!=0||board[0][5]!=0||board[1][4]!=0||board[1][5]!=0)
        return true;
    return false;
}
void Block::move_draw()
{
    init_pair(color_no, color, COLOR_BLACK);
    wattron(win_, COLOR_PAIR(color_no));
    box(win_,0,0);
    for (int i=1; i<height_-1; i++)
        for(int j=2; j<22; j+=2)
        {
            for(int k=0; k<4; k++)
            {
                if(x_y[k][0]==i-1&&x_y[k][1]==j/2)
                    mvwhline(win_, i, j-1, ACS_CKBOARD, 2);
            }

        }
    wattroff(win_, COLOR_PAIR(color_no));
    wrefresh(win_);
}
void Block::moveblock(char input)
{
    int count=0;

    switch(input)
    {
    case 't':
        rotate();
        move_draw();
        break;
    case 'l':
        for(int i=0; i<4; i++)
        {
            if( board[x_y[i][0]][x_y[i][1]-1] == 0) count++;
        }
        if(count==4)
            for(int i=0; i<4; i++) x_y[i][1]--;
        move_draw();
        break;
    case 'r':
        for(int i=0; i<4; i++)
        {
            if(board[x_y[i][0]][x_y[i][1]+1] == 0) count++;
        }
        if(count==4)
            for(int i=0; i<4; i++) x_y[i][1]++;
        move_draw();
        break;
    case 'g':
        for(int i=0; i<4; i++)
        {
            if(board[x_y[i][0]+1][x_y[i][1]] == 0) count++;
        }
        if(count==4)
        {
            for(int i=0; i<4; i++) x_y[i][0]++;
            move_draw();
        }
        else
        {
            for(int i=0; i<4; i++)
            {
                board[x_y[i][0]][x_y[i][1]]=color_no;
            }
            clear();
        }
        break;
    case 'd':
        while(true)
        {
            count=0;
            for(int i=0; i<4; i++)
            {
                if(board[x_y[i][0]+1][x_y[i][1]] == 0) count++;
            }

            if(count==4)
                for(int i=0; i<4; i++)
                    x_y[i][0]++;
            else
            {
                for(int i=0; i<4; i++)
                {
                    board[x_y[i][0]][x_y[i][1]]=color_no;
                }

                clear();

                break;
            }

        }
        break;
      default:
        move_draw();
        break;
    }

}
void Block::clear()
{
    check=1;
    tetromino();
    int sum=0;
    int row =19;
    while(true)
    {
        sum=0;
        for(int i=1; i<11; i++)
        {
            if(board[row][i]!=0)
                sum++;
        }
        if(sum==0)
        {

            break;
        }
        else if(sum==10)
        {

            (*score)+=1;

            for(int i=row-1; i>-1; i--)
                for(int j=1; j<11; j++)
                {
                    board[i+1][j]=board[i][j];

                }
            for(int i=1; i<11; i++)
            {
                board[0][i]=0;

            }
        }
        else
        {
            row--;
        }


    }
}
