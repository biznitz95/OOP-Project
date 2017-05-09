#include"Pac.h"
#include<math.h>
#include"Ghost.h"

Pac::Pac(float x, float y)
{
	c = x;
	d = y;
	speed = .2;
	pace = .01;
	color = false;
	timer = 10;// This decides Pac-Mans starting point
}

void Pac::build()
{
	float theta;

	glBegin(GL_POLYGON);
	for (theta = 0.0; theta <= 2.0f * pi; theta += 0.003f)
	{
		glColor3f(1, 1, 0);
		if (color) {
			glColor3d(0, 0, 1);
			timer--;
		}

		glVertex2f(rad*cos(theta) + c, rad*sin(theta) + d);


	}
	glEnd();

}

void Pac::specialKeyPress(int key) {
	switch (key) {
	case GLUT_KEY_UP:
		d += pace*speed;
		break;
	case GLUT_KEY_DOWN:
		d -= pace*speed;
		break;
	case GLUT_KEY_LEFT:
		c -= pace*speed;
		break;
	case GLUT_KEY_RIGHT:
		c += pace*speed;
		break;
	}
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

void Pac::set(char type, float temp) {
	switch (type) {
	case 'x':
		this->c = temp;
		break;
	case 'y':
		this->d = temp;
		break;
	case 'c':
		col = true;
	}
}

float Pac::get(char type) {
	switch (type) {
	case 'x':
		return c;
		break;
	case 'y':
		return d;
		break;
	}
}
Pac::~Pac() {}