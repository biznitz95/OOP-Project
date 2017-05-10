#ifndef App_hpp
#define App_hpp

#include "GlutApp.h"
#include "RgbImage.h"
#include "TexRect.hpp"
#include "Pac.h"
#include "Ghost.h"
#include "Table.h"
#include "Food.h"
#include "score.h"
#include "Powerup.h"
#include <cstdlib>
#include <ctime>

class App: public GlutApp {
    // Maintain app state here
    float mx;
    float my;
	Table* gameBoard;
	Ghost* ghost;
	Food* dots;
	int score;
	Pac* pacMan1;
	Pac* pacMan2;
	Pac* pacMan3;
	Pac* pacMan4;

	bool bPowerUp;			// Bizet's Power Up: teleport pacman elsewhere when touched
	int bPowerUpTimer;		// Bizet's Power Up Timer

	bool hPowerUp;			//kill pacman instead when touched
	int hPowerUpTimer;

	bool kPowerUp;			//run through pacman without dying
	int kPowerUpTimer;

	bool dPowerUp;			//double the points
	int dPowerUpTimer;

	int size;

	bool p1Move, p2Move, p3Move, p4Move;
	int p1Num, p2Num, p3Num, p4Num;
public:
    // Constructor, to initialize state
    App(const char* label, int x, int y, int w, int h);
    
    // These are the events we want to handle
	void draw();
	void keyPress(unsigned char key);
	void mouseDown(float x, float y);
	void mouseDrag(float x, float y);
	void specialKeyPress(int key);
	void idle();
	bool contains(float x, float y, Pac temp, int ran);
    
    GLuint loadTexture(const char* filename);
    
    GLuint monalisa;
    GLuint wall;
    
    
    TexRect* painting;
    TexRect* background;
};

#endif
