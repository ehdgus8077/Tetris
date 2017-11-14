#include "Pane.h"
#include "InfoPane.h"
#include "HelpPane.h"
#include "NextPane.h"
#include "Tetris.h"
#include "Block.h"
#include "L_Block.h"
#include "Z_Block.h"
#include "O_Block.h"
#include "T_Block.h"
#include "J_Block.h"
#include "S_Block.h"
#include "I_Block.h"
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <sys/select.h>
#include <termios.h>
#include <stropts.h>
#include <unistd.h>
#include <sys/select.h>
using namespace std;

int board[21][12];

int kbhit(void)
{
    struct timeval tv;
    fd_set read_fd;

    tv.tv_sec=0;
    tv.tv_usec=0;
    FD_ZERO(&read_fd);
    FD_SET(0,&read_fd);

    if(select(1, &read_fd, NULL, NULL, &tv) == -1)
        return 0;

    if(FD_ISSET(0,&read_fd))
        return 1;

    return 0;
}

int main(int argc, char* argv[])
{
    bool Gameover=false;
    int cur_key;
    char key;
    char user[8];
    ifstream inStream;
    int seed;
    if(argc > 1)
    {
        inStream.open(argv[1]);
        inStream >> user;
        inStream >> seed;
    }
    else
    {
        cout<<"테트리스 게임을 시작합니다. 사용자의 이름을 입력하세요."<<endl;
        cout<<"이름: ";
        cin >>user;
    }
    Tetris t;
    t.updateScreen(user);
    if(argc > 1)
        t.setseed(seed);
    keypad(stdscr,TRUE);
    while(!Gameover)
    {
        if (argc > 1)
        {
            inStream >> key;
            usleep(200000);
            Gameover = t.play(key);
        }
        else
        {
            if(kbhit())
            {

                cur_key = getch();

                if(cur_key==KEY_DOWN)
                    key='g';
                else if(KEY_LEFT==cur_key)
                    key='l';
                else if(KEY_RIGHT==cur_key)
                    key='r';
                else if(cur_key==' ')
                    key='d';
                else if(cur_key==KEY_UP)
                    key='t';
                else
                    key=(char)cur_key;
            }
            else
            {
                key='g';
                usleep(200000);
            }

            Gameover = t.play(key);
        }

    }
    return 0;
}
