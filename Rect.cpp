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
	glColor3d(x, 0.0, yy );

	// Top line
	glVertex2f(x, y);
	glVertex2f(x + w, y);

	glBegin(GL_POLYGON);
	glColor3d(xx + w, 0.0, yy);

	// Right line
	glVertex2f(x + w, y);
	glVertex2f(x + w, y - h);

	glBegin(GL_POLYGON);
	glColor3d(xx + w, 0.0, yy - h);


	// Bottom line
	glVertex2f(x + w, y - h);
	glVertex2f(x, y - h);

	glBegin(GL_POLYGON);
	glColor3d(x, 0.0, y - hh);

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
	if (temp) {
		if (col) {
			col = false; 
		}
		else {
			col = true;
		}
	}
}

Rect::~Rect() {

}