#include"Pac.h"
#include<math.h>

Pac::Pac()
{
	// This decides Pac-Mans starting point
}

void Pac::build()
{
	float theta;

	glBegin(GL_POLYGON);                                        //include math.h and give a value for "rad" 
	for (theta = 0.0; theta <= 2 * pi; theta += 0.003)
	{
		glColor3f(0, 0, 1);
		glVertex2f(rad*cos(theta), rad*sin(theta));
	}
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0, 0, 0);
	glVertex2f(0, 0);
	for (theta = -mouthSize; theta <= mouthSize; theta += 0.003) // set mouthSize to some number i.e 0.6
	{
		glColor3f(0, 0, 0);
		glVertex2f(rad*cos(theta), rad*sin(theta));
	}
	glEnd();

	glFlush();

}

void Pac::reBuild() {
	// When the Pac Men die this will re draw them into the original starting point
}

Pac::~Pac() {}