#ifndef __HelpPane_h__
#define __HelpPane_h__
#include "Pane.h"
#include <ncurses.h>
class HelpPane : public Pane {
public:  
	HelpPane(int x, int y, int w, int h) : Pane(x,y,w,h){} 
	void draw();  
};
#endif
