#include"Pac.h"
#include<math.h>
#include"Ghost.h"

Pac::Pac(float x, float y)
{
	c = x;
	d = y;
	speed = 1;              // This decides Pac-Mans starting point
}

void Pac::build()
{
	float theta;

	glBegin(GL_POLYGON);                                        
	for (theta = 0.0; theta <= 2.0f * pi; theta += 0.003f)
	{
		glColor3f(1, 1, 0);
		glVertex2f(rad*cos(theta) + c, rad*sin(theta) + d);
	}
	glEnd();

}
bool Pac::contains(float x, float y) {
	if (x >= this->c - rad && x <= this->c + rad) {
		if (y <= this->d + rad && y >= this->d - rad) {
			return true;
		}
		else
			return false;
	}
	else
		return false;
}
void Pac::reBuild() {

}

Pac::~Pac() {}