#ifndef __NextPane_h__
#define __NextPane_h__
#include "Pane.h"
#include <ncurses.h>
class NextPane : public Pane {
public:  
	NextPane(int x, int y, int w, int h) : Pane(x,y,w,h){}
	void draw(); 
};
#endif
