#ifndef POWERUP_H
#define POWERUP_H
#include"Ghost.h"#include "GlutApp.h"

class Powerup
{
private:
	float e;
	float f;
	float pi = 3.14f;
	float rad = .02f;
	int points;
public:
	Powerup(float x, float y);
	bool contains(float x, float y);
	void build();
	int DoublePts();
	~Powerup();
};
#endif