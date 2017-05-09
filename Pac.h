#ifndef GHOST_H
#define PAC_H

#include"Ghost.h"
#include "GlutApp.h"

// Focus on drawing Pac man first
class Pac
{
private:
	float c;		//location on board i.e x
	float d;		//location on board i.e y
	float angle;	//current direction of pacman
	float speed;	//speed of pacman
	float pi = 3.14f;
	float rad = .03f;
	float mouthSize = .6f;

public:
	// Don't use draw function, opens new window
	Pac(float x, float y);
	void build();
	void reBuild();
	bool contains(float x, float y);
	~Pac();

};


#endif