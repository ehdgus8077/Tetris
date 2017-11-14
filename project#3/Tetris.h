#ifndef __Tetris_h__
#define __Tetris_h__
#include "Pane.h"
#include "InfoPane.h"
#include "HelpPane.h"
#include "NextPane.h"
#include "Block.h"
#include "L_Block.h"
#include "Z_Block.h"
#include "O_Block.h"
#include "T_Block.h"
#include "J_Block.h"
#include "S_Block.h"
#include "I_Block.h"
#include <fcntl.h>
#include <ctime>
#include <cstdlib>
class Tetris {
  int score;
  Pane *infoPane_, *helpPane_, *nextPane_;
  Block *L_Block_,*O_Block_,*J_Block_,*Z_Block_,*T_Block_,*S_Block_,*I_Block_;
  Block *move_block;
  WINDOW * w;
  WINDOW* win_stat;
  WINDOW* win_;
  int height_;
  int width_;
  int move_s;
  int file_check, seed;
public:
  Tetris();
  ~Tetris();
  void result();
  bool play(int);
  void updateScreen(char *);
  void board_state();
  void move_b();
  void setseed(int );
};

#endif
