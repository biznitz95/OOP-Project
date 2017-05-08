#include"Ghost.h"

Ghost::Ghost(float x, float y) {
	a = x;                   
	b = y;
	pace = .05;
	speed = 1;
}
void Ghost::reBuild()
{

}
void Ghost::build(float r)
{	
	radius = r;

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
	glColor3d(1, 1, 1); glVertex2f(a - .03, b); 
	glColor3d(1, 1, 1); glVertex2f(a - .015, b); 
	glColor3d(1, 1, 1); glVertex2f(a - (.015+(.015/2.0)), b-.03);

	glColor3d(1, 1, 1); glVertex2f(a - .015, b);
	glColor3d(1, 1, 1); glVertex2f(a, b);
	glColor3d(1, 1, 1); glVertex2f(a - (.015 + (.015 / 2.0))+.015, b - .03);

	glColor3d(1, 1, 1); glVertex2f(a, b);
	glColor3d(1, 1, 1); glVertex2f(a + .015, b);
	glColor3d(1, 1, 1); glVertex2f(a - (.015 + (.015 / 2.0)) + .03, b - .03);

	glColor3d(1, 1, 1); glVertex2f(a + .015, b);
	glColor3d(1, 1, 1); glVertex2f(a + .03, b);
	glColor3d(1, 1, 1); glVertex2f(a - (.015 + (.015 / 2.0)) + .045, b - .03);
	glEnd();
}

// Control Ghost
void Ghost::specialKeyPress(int key) {
	switch (key) {
	case GLUT_KEY_UP:
		std::cout << "Up key pressed" << std::endl;
		b += pace*speed;
		break;
	case GLUT_KEY_DOWN:
		std::cout << "Down key pressed" << std::endl;
		b -= pace*speed;
		break;
	case GLUT_KEY_LEFT:
		std::cout << "Left key pressed" << std::endl;
		a -= pace*speed;
		break;
	case GLUT_KEY_RIGHT:
		std::cout << "Right key pressed" << std::endl;
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

