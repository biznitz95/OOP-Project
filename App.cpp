#include "App.h"
#include "Ghost.h"
#include "Pac.h"
#include "Powerup.h"

using namespace std;

App::App(const char* label, int x, int y, int w, int h): GlutApp(label, x, y, w, h){
    // Initialize state variables
    mx = 0.0;
    my = 0.0;
	gameBoard = new Table();
	ghost = new Ghost(0,.25);
	dots = new Food();              ////////Khin
	pacMan1 = new Pac(-.1, -.1);	// Original: -.1, -.1
	pacMan2 = new Pac(-.1, .1);
	pacMan3 = new Pac(.1, -.1);
	pacMan4 = new Pac(.1, .1);
	myScore = new Score();
	myScore->points = 0;
	score = 0;
	pUp = 0;
	bPowerUp = false;
	bPowerUpTimer = 5000;
	// Setting up powerUp number 1, super speed
	dots->myFood[0]->set('c', 0);

	pUp1 = new Powerup(.85, .85);
	pUp2 = new Powerup(-.85, .85);
	pUp3 = new Powerup(-.85, -.85);
	pUp4 = new Powerup(.85, -.85);

	size = 0;	// Size = 190
}

void App::draw() {

    // Clear the screen
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    // Set background color to black
    glClearColor(0.0, 0.0, 0.0, 0.0);
    
    // Set up the transformations stack
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
	ghost->build(.049);
	dots->build();                  ////////Khin
	pacMan1->build();
	pacMan2->build();
	pacMan3->build();
	pacMan4->build();
	pUp1->build();
	pUp2->build();
	pUp3->build();
	pUp4->build();
	gameBoard->build();

    // We have been drawing everything to the back buffer
    // Swap the buffers to see the result of what we drew
    glFlush();
    glutSwapBuffers();
}

void App::mouseDown(float x, float y){
    // Update app state
    mx = x;
    my = y;

    // Redraw the scene
    redraw();
}

void App::mouseDrag(float x, float y){
    // Update app state
    mx = x;
    my = y;
    
    // Redraw the scene
    redraw();
}

void App::keyPress(unsigned char key) {
    if (key == 27){
        // Exit the app when Esc key is pressed
        exit(0);
    }
}


void App::specialKeyPress(int key) {
	ghost->specialKeyPress(key);

	float t = .049 * 2.0;

	bool center = gameBoard->contains(ghost->get('x'), ghost->get('y'));
	bool tLeft, tRight, bLeft, bRight;

	ghost->set('x',ghost->get('x')-.049); ghost->set('y', ghost->get('y') + .049);
	tLeft = gameBoard->contains(ghost->get('x'), ghost->get('y'));

	ghost->set('x', ghost->get('x') + t);
	tRight = gameBoard->contains(ghost->get('x'), ghost->get('y'));

	ghost->set('y', ghost->get('y') - t);
	bRight = gameBoard->contains(ghost->get('x'), ghost->get('y'));

	ghost->set('x', ghost->get('x') - t);
	bLeft = gameBoard->contains(ghost->get('x'), ghost->get('y'));

	ghost->set('x', ghost->get('x') + .049); ghost->set('y', ghost->get('y') + .049);

	if (center || tLeft || tRight || bRight || bLeft) {
		switch (key) {
		case GLUT_KEY_UP:
			ghost->specialKeyPress(GLUT_KEY_DOWN);
			break;
		case GLUT_KEY_DOWN:
			ghost->specialKeyPress(GLUT_KEY_UP);
			break;
		case GLUT_KEY_LEFT:
			ghost->specialKeyPress(GLUT_KEY_RIGHT);
			break;
		case GLUT_KEY_RIGHT:
			ghost->specialKeyPress(GLUT_KEY_LEFT);
			break;
		}
	}

	float xPos, yPos;
	xPos = ghost->get('x') - .049;
	yPos = ghost->get('y') + .049;
	Rect* ptr;
	for (int i = 0; i < dots->myFood.size(); i++) {
		ptr = dots->myFood[i];
		float x, y;
		x = dots->myFood[i]->get('x');
		y = dots->myFood[i]->get('y');
		if (x >= xPos && x <= xPos + (2.0*.049)) {
			if (y <= yPos && y >= yPos - (2.0*.049)) {
				if (ptr == dots->myFood[0]) {
					cout << "Power up Activated!" << endl;
					bPowerUp = true;
				}
				size++;
				delete ptr;
				if (!pUp)
					score++;
				else
					score += 2;
				cout << "Your current score is: " << score << endl;;
			}
		}
	}

	// Checks for death of player
	if (!bPowerUp) {
		bool death1 = pacMan1->contains(ghost->get('x'), ghost->get('y'));
		if (death1)
			delete ghost;
		bool death2 = pacMan2->contains(ghost->get('x'), ghost->get('y'));
		if (death2)
			delete ghost;
		bool death3 = pacMan3->contains(ghost->get('x'), ghost->get('y'));
		if (death3)
			delete ghost;
		bool death4 = pacMan4->contains(ghost->get('x'), ghost->get('y'));
		if (death4)
			delete ghost;
	}
	else {
		bool death1 = pacMan1->contains(ghost->get('x'), ghost->get('y'));
		if (death1) {
			pacMan1->set('x', -pacMan1->get('x'));
		};
		bool death2 = pacMan2->contains(ghost->get('x'), ghost->get('y'));
		if (death2) 
			pacMan2->set('x', -pacMan2->get('x'));
		bool death3 = pacMan3->contains(ghost->get('x'), ghost->get('y'));
		if (death3)
			pacMan3->set('x', -pacMan3->get('x'));
		bool death4 = pacMan4->contains(ghost->get('x'), ghost->get('y'));
		if (death4)
			pacMan4->set('x', -pacMan4->get('x'));
	}

	bool pUp_consume1 = pUp1->contains(ghost->get('x'), ghost->get('y'));
	if (pUp_consume1) {
		delete pUp1;
		pacMan1->color = true;
		pacMan2->color = true;
		pacMan3->color = true;
		pacMan4->color = true;
	}
	bool pUp_consume2 = pUp2->contains(ghost->get('x'), ghost->get('y'));
	if (pUp_consume2) {
		delete pUp2;
		pacMan1->color = true;
		pacMan2->color = true;
		pacMan3->color = true;
		pacMan4->color = true;
	}
	bool pUp_consume3 = pUp3->contains(ghost->get('x'), ghost->get('y'));
	if (pUp_consume3) {
		delete pUp3;
		pacMan1->color = true;
		pacMan2->color = true;
		pacMan3->color = true;
		pacMan4->color = true;
	}
	bool pUp_consume4 = pUp4->contains(ghost->get('x'), ghost->get('y'));
	if (pUp_consume4) {
		delete pUp4;
		pacMan1->color = true;
		pacMan2->color = true;
		pacMan3->color = true;
		pacMan4->color = true;
	}

	redraw();
}

void App::idle() {
	if (bPowerUp) {
		cout << "Timer: " << bPowerUpTimer << endl;
		bPowerUpTimer--;
		if (!bPowerUpTimer)
			bPowerUp = !bPowerUp;
	}

	// Ending of the game when food is finished
	if (size == 190) {
		cout << "Good job! You finished the game!" << endl;
		int temp;
		cin >> temp;
		exit;
	}
}