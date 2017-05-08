#ifndef GHOST_H
#define GHOST_H

#include "GlutApp.h"
#include "Rect.h"

// Focus on Drawing the Ghost for now
class Ghost
{
	// These are good enough for now work with these
    float a;		//location on board i.e x
    float b;		//location on board i.e y
	float pace;
    float speed;	//speed of pacman
	float radius;

public:  
	// Don't use Draw function, opens new window
    Ghost(float x, float y);		//constructor, needs to be named Ghost() lol
    void reBuild();	//function reinitializes pacman
    void build(float r);	//function draws pacman
	void specialKeyPress(int key);	// Controls movement
	float get(char temp);
	void set(char type, float temp);
	~Ghost();		// Need a Destructor too
};
#endif