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

	bool bPowerUp;			// Bizet's Power Up
	int bPowerUpTimer;		// Bizet's Power Up Timer

	Powerup* pUp1;
	Powerup* pUp2;
	Powerup* pUp3;
	Powerup* pUp4;
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
