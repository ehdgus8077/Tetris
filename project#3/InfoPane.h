#ifndef __InfoPane_h__
#define __InfoPane_h__
#include "Pane.h"
#include <ncurses.h>
class InfoPane : public Pane {
private:
	char username[8];
public:
	InfoPane(int x, int y, int w, int h) : Pane(x,y,w,h){}
	void draw();
	void set_username(char * );
};
#endif
