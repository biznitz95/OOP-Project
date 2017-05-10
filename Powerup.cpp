#include"Powerup.h"
#include<math.h>
#include"Ghost.h"
#include"Table.h"
Powerup::Powerup(float x, float y)
{
	e = x;
	f = y;
}
void Powerup::build()
{
	float theta;
	glBegin(GL_POLYGON);
	for (theta = 0.0; theta <= 2.0f * pi; theta += 0.003f)
	{
		glColor3f(0, 1, 0);
		glVertex2f(rad*cos(theta) + e, rad*sin(theta) + f);
	}
	glEnd();
}
bool Powerup::contains(float x, float y) {
	if (x >= this->e - rad && x <= this->e + rad) {
		if (y <= this->f + rad && y >= this->f - rad) {
			return true;
		}
		else
			return false;
	}
	else
		return false;
}
Powerup::~Powerup() {}

int Powerup::DoublePts()
{
	return points * 2;
}