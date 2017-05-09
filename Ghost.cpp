#include"Ghost.h"

Ghost::Ghost(float x, float y) {
	a = x;                   
	b = y;
	pace = .01;
	speed = 1;
	up = down = left = right = false;
}
void Ghost::reBuild()
{

}
void Ghost::build(float r)
{	
	radius = r;
	float h = (.049 / 2.0);
	// Top half
	glBegin(GL_POLYGON);
	for (float theta = 0.0; theta <= 3.14; theta += 0.01)
	{
		glColor3d(1, 1, 1);
		glVertex2f(radius*cos(theta)+a, radius*sin(theta)+b);
	}
	glEnd();

	// Legs
	glBegin(GL_TRIANGLES);
	glColor3d(1, 1, 1); glVertex2f(a - .049, b); 
	glColor3d(1, 1, 1); glVertex2f(a - h, b); 
	glColor3d(1, 1, 1); glVertex2f(a - (.02+(h/2.0)), b-.049);

	glColor3d(1, 1, 1); glVertex2f(a - h, b);
	glColor3d(1, 1, 1); glVertex2f(a, b);
	glColor3d(1, 1, 1); glVertex2f(a - (h + (h / 2.0))+h, b - .049);

	glColor3d(1, 1, 1); glVertex2f(a, b);
	glColor3d(1, 1, 1); glVertex2f(a + h, b);
	glColor3d(1, 1, 1); glVertex2f(a - (h + (h / 2.0)) + .049, b - .049);

	glColor3d(1, 1, 1); glVertex2f(a + h, b);
	glColor3d(1, 1, 1); glVertex2f(a + .049, b);
	glColor3d(1, 1, 1); glVertex2f(a - (h + (h / 2.0)) + .049+h, b - .049);
	glEnd();
}

// Control Ghost
void Ghost::specialKeyPress(int key) {
	switch (key) {
	case GLUT_KEY_UP:
		b += pace*speed;
		break;
	case GLUT_KEY_DOWN:
		b -= pace*speed;
		break;
	case GLUT_KEY_LEFT:
		a -= pace*speed;
		break;
	case GLUT_KEY_RIGHT:
		a += pace*speed;
		break;
	}
}

float Ghost::get(char temp) {
	switch (temp) {
	case 'x':
		return a;
		break;
	case 'y':
		return b;
		break;
	}
}

void Ghost::set(char type, float temp) {
	switch (type) {
	case 'x':
		this->a = temp;
		break;
	case 'y':
		this->b = temp;
		break;
	case 's':
		speed = temp;
		break;
	}
}

Ghost::~Ghost() {

}

