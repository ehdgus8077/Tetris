 #include "Tetris.h"


  Tetris::Tetris(){
    initscr();
    start_color();
    cbreak();
    refresh();
    score=0;
    height_= 22;
    width_ = 22;
    w= newwin(3,35,10,24);
    win_ = newwin(22,22,0,30);
    win_stat = newwin(20,20,3,60);
    infoPane_ = new InfoPane(1,1,25,5);
    helpPane_ = new HelpPane(1,6,25,12);
    nextPane_ = new NextPane(1,18,25,5);
    L_Block_ = new L_Block(0,30,22,22,&score,win_);
    Z_Block_ = new Z_Block(0,30,22,22,&score,win_);
    O_Block_ = new O_Block(0,30,22,22,&score,win_);
    T_Block_ = new T_Block(0,30,22,22,&score,win_);
    J_Block_ = new J_Block(0,30,22,22,&score,win_);
    I_Block_ = new I_Block(0,30,22,22,&score,win_);
    S_Block_ = new S_Block(0,30,22,22,&score,win_);
    file_check=0;
    for(int i=0;i<21;i++)
      for(int j=0;j<12;j++)
        board[i][j]=1;

    for(int i=0;i<20;i++)
      for(int j=1;j<11;j++)
        board[i][j]=0;

  }

  Tetris::~Tetris(){
    delete infoPane_;
    delete helpPane_;
    delete nextPane_;
    delete L_Block_;
    delete Z_Block_;
    delete O_Block_;
    delete J_Block_;
    delete T_Block_;
    delete S_Block_;
    delete I_Block_;
    endwin();
  }

bool Tetris::play(int key){


      if(key==(int)'q'){
        result();
        return true;
      }
      else{
        board_state();
        move_block->moveblock(key);
      }
        Z_Block_->draw();
        O_Block_->draw();
        T_Block_->draw();
        J_Block_->draw();
        S_Block_->draw();
        I_Block_->draw();
      if(L_Block_->draw()){
        result();
        return true;
      }
      if(move_block->check==1){
        move_block->check=0;

        move_b();
      }
      return false;
}

void Tetris::result(){
  int a;
  init_pair(9, COLOR_RED, COLOR_BLACK);
  wattron(w, COLOR_PAIR(9));
  box(win_, 0, 0);
  mvwprintw(w,0,0,"score is %d\npress any key to exit Tetris",score);
  wattroff(w, COLOR_PAIR(9));
  wrefresh(w);
  a=getch();
}

void Tetris::updateScreen(char * name){
  infoPane_->set_username(name);
  infoPane_->draw();
  helpPane_->draw();
  nextPane_->draw();
  board_state();
  move_b();
  move_block->moveblock('a');
  }
void Tetris::board_state(){
  init_pair(7, COLOR_BLACK, COLOR_BLACK);
  wattron(win_, COLOR_PAIR(7));
  box(win_, 0, 0);
  for (int i=1; i<height_-1; i++){
      mvwhline(win_, i, 1, ACS_CKBOARD, width_-2);
    }
  wattroff(win_, COLOR_PAIR(7));
  wrefresh(win_);

  init_pair(6, COLOR_GREEN, COLOR_BLACK);
  wattron(win_stat, COLOR_PAIR(6));
  box(win_stat, 0, 0);
  mvwprintw(win_stat, 0, 5, "STATISTICS");
  mvwprintw(win_stat,1,1,"SCORE :");
  mvwprintw(win_stat,1,8,"%d",score);
  wattroff(win_stat, COLOR_PAIR(6));
  wrefresh(win_stat);


}

void Tetris::move_b(){
    if(file_check)
        srand(seed);
    else
      srand((unsigned int)time(NULL));
      move_s= rand() % (0 + 7);
     switch (move_s) {
       case 0 :
         move_block=L_Block_;
       break;
       case 1 :
          move_block=Z_Block_;
        break;
       case 2 :
         move_block=S_Block_;
          break;
       case 3 :
        move_block=J_Block_;
       break;
       case 4 :
        move_block=T_Block_;
       break;
       case 5 :
         move_block=I_Block_;
       break;
       case 6 :
          move_block=O_Block_;
       break;
     }
     move_block->moveblock('a');
}

void Tetris::setseed(int seed_){
  seed=seed_;
  file_check=1;
}
