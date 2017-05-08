#ifndef GHOST_H
#define PAC_H

#include"Ghost.h"
#include "GlutApp.h"

// Focus on drawing Pac man first
class Pac
{
private:
	float x;		//location on board i.e x
	float y;		//location on board i.e y
	float angle;	//current direction of pacman
	float speed;	//speed of pacman
	float pi = 3.14;
	float rad = .03;
	float mouthSize = .6;
	
public:
	// Don't use draw function, opens new window
    Pac();
	void build();
	void reBuild();
    ~Pac(void);   
    
};


#endif