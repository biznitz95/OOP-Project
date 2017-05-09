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
	bool col;
	float pace;
	bool edible;
	int timer;
public:
	// Don't use draw function, opens new window
	Pac(float x, float y);
	void specialKeyPress(int key);
	void build();
	void reBuild();
	bool contains(float x, float y);
	bool color;
	void set(char type, float temp);
	float get(char type);
	~Pac();

};


#endif