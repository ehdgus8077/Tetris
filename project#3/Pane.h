#ifndef __Pane_h__
#define __Pane_h__
#include <ncurses.h>
class Pane {
protected:
	int width_, height_;
	int x_, y_;
	WINDOW *win_;
public:
	Pane(int x, int y, int w, int h) :x_(x), y_(y), width_(w), height_(h){
                win_ = newwin(h, w, y, x);
        }

 	virtual ~Pane(){
		delwin(win_);
	 }
	virtual void draw(){
		box(win_, 0, 0);
 		wrefresh(win_);
 	 }
	 virtual void set_username(char * name){}
};
#endif
