#ifndef App_hpp
#define App_hpp

#include "GlutApp.h"
#include "Pac.h"
#include "Ghost.h"
#include "Table.h"
#include "Food.h"
#include "score.h"
#include "Powerup.h"

class App: public GlutApp {
    // Maintain app state here
    float mx;
    float my;
	Table* gameBoard;
	Ghost* ghost;
	Food* dots;
	Score* myScore;
	int score;
	bool pUp;
	Pac* pacMan1;
	Pac* pacMan2;
	Pac* pacMan3;
	Pac* pacMan4;

	bool bPowerUp;			// Bizet's Power Up: teleport pacman elsewhere when touched
	int bPowerUpTimer;		// Bizet's Power Up Timer

	bool hPowerUp;			//kill pacman instead when touched
	int hPowerUpTimer;
	Powerup* pUp2;

	bool kPowerUp;			//run through pacman without dying
	int kPowerUpTimer;

	bool dPowerUp;			//double the points
	int dPowerUpTimer;

	int size;
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
};

#endif
