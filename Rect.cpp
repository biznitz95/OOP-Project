#include "Rect.h"
#include "GlutApp.h"



Rect::Rect(float x, float y, float w, float h) {
	this->x = x;
	this->y = y;
	this->w = w;
	this->h = h;
	col = false;
}

void Rect::build() {
	float xx, yy, ww, hh;
	xx = std::abs(x);
	yy = std::abs(y);
	ww = std::abs(w);
	hh = std::abs(h);

	// Yellow Square
	glBegin(GL_POLYGON);
	glColor3d(x, 0.0, yy); 
	if (col) glColor3d(1, 1, 1);

	// Top line
	glVertex2f(x, y);
	glVertex2f(x + w, y);

	glBegin(GL_POLYGON);
	glColor3d(xx + w, 0.0, yy);
	if (col) glColor3d(1, 1, 1);

	// Right line
	glVertex2f(x + w, y);
	glVertex2f(x + w, y - h);

	glBegin(GL_POLYGON);
	glColor3d(xx + w, 0.0, yy - h);
	if (col) glColor3d(1, 1, 1);

	// Bottom line
	glVertex2f(x + w, y - h);
	glVertex2f(x, y - h);

	glBegin(GL_POLYGON);
	glColor3d(x, 0.0, y - hh);
	if (col) glColor3d(1, 1, 1);

	// Left line
	glVertex2f(x, y - h);
	glVertex2f(x, y);

	glEnd();
}

void Rect::set(char type, float temp) {
	switch (type) {
		case 'x':
			this->x = temp;
			break;
		case 'y':
			this->y = temp;
			break;
		case 'w':
			w = temp;
			break;
		case 'h':
			h = temp;
			break;
		case 'c':
			col = true;
	}
}

float Rect::get(char type) {
	switch (type) {
	case 'x':
		return x;
		break;
	case 'y':
		return y;
		break;
	case 'w':
		return w;
		break;
	case 'h':
		return h;
		break;
	}
}

bool Rect::contains(float x, float y) {
	if (x >= this->x && x <= this->x + w) {
		if (y <= this->y && y >= this->y - h) {
			return true;
		}
		else
			return false;
	}
	else
		return false;
}

void Rect::change(bool temp) {

}

void Rect::changeColor() {
	glColor3d(1, 1, 1);
}

Rect::~Rect() {

}
