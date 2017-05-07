#ifndef GHOST_H
#define GHOST_H

#include "GlutApp.h"

// Focus on Drawing the Ghost for now
class Ghost
{
	// These are good enough for now work with these
    float a;		//location on board i.e x
    float b;		//location on board i.e y
    float angle;	//current direction of pacman
    float speed;	//speed of pacman

public:  
	// Don't use Draw function, opens new window
    Ghost();		//constructor, needs to be named Ghost() lol
    void reBuild();	//function reinitializes pacman
    void build();	//function draws pacman
	~Ghost();		// Need a Destructor too
};
#endif