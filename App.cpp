#include "App.h"
#include "Ghost.h"
#include "Pac.h"
#include "Powerup.h"

App::App(const char* label, int x, int y, int w, int h): GlutApp(label, x, y, w, h){
    // Initialize state variables
    mx = 0.0;
    my = 0.0;
    
	#if defined WIN32
    //monalisa = loadTexture("..\\monalisa.bmp");
    wall = loadTexture("..\\wall.bmp");
	#else
	//monalisa = loadTexture("monalisa.bmp");
	wall = loadTexture("wall.bmp");
	#endif
    
    background = new TexRect(-1, 1, 2, 2);

	gameBoard = new Table();
	ghost = new Ghost(.0, .25);
	dots = new Food();              ////////Khin
	pacMan1 = new Pac(.85, .85);	// Original: -.1, -.1
	pacMan2 = new Pac(.85, -.85);
	pacMan3 = new Pac(-.85, .85);
	pacMan4 = new Pac(-.85, -.85);
	score = 0;
	
	// Setting up powerUp number 1, teleport
	bPowerUp = false;
	bPowerUpTimer = 2000;
	dots->myFood[0]->set('c', 0);

	// Henry power up
	dots->myFood[190 - 18]->set('c', 0);
	hPowerUp = false;
	hPowerUpTimer = 2000;

	dots->myFood[190 - 175]->set('c', 0);
	kPowerUp = false;
	kPowerUpTimer = 2000;

	dots->myFood[189]->set('c', 0);
	dPowerUp = false;
	dPowerUpTimer = 2000;

	size = 0;	// Size = 190

	p1Move = p2Move = p3Move = p4Move = 0;
}


GLuint App::loadTexture(const char *filename) {
    GLuint texture_id;
    glClearColor (0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_FLAT);
    glEnable(GL_DEPTH_TEST);
    
    RgbImage theTexMap( filename );
    
    // Pixel alignment: each row is word aligned (aligned to a 4 byte boundary)
    //    Therefore, no need to call glPixelStore( GL_UNPACK_ALIGNMENT, ... );
    
    
    glGenTextures( 1, &texture_id );
    glBindTexture( GL_TEXTURE_2D, texture_id );
    
    

    
    
    gluBuild2DMipmaps(GL_TEXTURE_2D, 3, theTexMap.GetNumCols(), theTexMap.GetNumRows(),
                      GL_RGB, GL_UNSIGNED_BYTE, theTexMap.ImageData() );
    
    return texture_id;
    
}

void App::draw() {

    // Clear the screen
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    // Set background color to black
    glClearColor(0.0, 0.0, 0.0, 1.0);
    
    // Set up the transformations stack
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

	ghost->build(.049);
	pacMan1->build();
	pacMan2->build();
	pacMan3->build();
	pacMan4->build();
	dots->build();                  ////////Khin
	gameBoard->build();

    
    // Set Color
    glColor3d(1.0, 1.0, 1.0);
    

    //glBindTexture( GL_TEXTURE_2D, monalisa );
    //painting->draw();
    
    
    glBindTexture( GL_TEXTURE_2D, wall );
    background->draw();
    
    
    glDisable(GL_TEXTURE_2D);
    
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

	ghost->set('x', ghost->get('x') - .049); ghost->set('y', ghost->get('y') + .049);
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
					bPowerUp = true;
				}
				if (ptr == dots->myFood[190 - 18]) {
					hPowerUp = true;
				}
				if (ptr == dots->myFood[190 - 175]) {
					kPowerUp = true;
				}
				if (ptr == dots->myFood[189]) {
					dPowerUp = true;
				}
				size++;
				delete ptr;
				//score++;
				if (!dPowerUp) {
					score++;
				}
				else if (dPowerUp) {
					score += 5;
				}
				cout << "Your current score is: " << score << endl;;
			}
		}
	}



	// Checks for death of player
	bool death1 = pacMan1->contains(ghost->get('x'), ghost->get('y'));
	bool death2 = pacMan2->contains(ghost->get('x'), ghost->get('y'));
	bool death3 = pacMan3->contains(ghost->get('x'), ghost->get('y'));
	bool death4 = pacMan4->contains(ghost->get('x'), ghost->get('y'));
	if (!bPowerUp && !hPowerUp && !kPowerUp) {
		if (death1) {
			delete ghost;
			exit(0);
		}
		if (death2) {
			delete ghost;
			exit(0);
		}
		if (death3) {
			delete ghost;
			exit(0);
		}
		if (death4) {
			delete ghost;
			exit(0);
		}
	}
	else if (bPowerUp) {
		if (death1) {
			pacMan1->set('x', -pacMan1->get('x'));
		};
		if (death2)
			pacMan2->set('x', -pacMan2->get('x'));
		if (death3)
			pacMan3->set('x', -pacMan3->get('x'));
		if (death4)
			pacMan4->set('x', -pacMan4->get('x'));
	}
	else if (hPowerUp) {
		if (death1)
			delete pacMan1;
		if (death2)
			delete pacMan2;
		if (death3)
			delete pacMan3;
		if (death4)
			delete pacMan4;
	}
	else if (kPowerUp) {
	}

	redraw();
}

void App::idle() {
	if (bPowerUp) {
		bPowerUpTimer--;
		if (!bPowerUpTimer) {
			bPowerUp = !bPowerUp;
		}
	}

	if (hPowerUp) {
		hPowerUpTimer--;
		pacMan1->color = true;
		if (!hPowerUpTimer) {
			hPowerUp = !hPowerUp;
		}
	}

	if (kPowerUp) {
		kPowerUpTimer--;
		if (!kPowerUpTimer)
			kPowerUp = !kPowerUp;
	}

	if (dPowerUp) {
		dPowerUpTimer--;
		if (!dPowerUpTimer)
			dPowerUp = !dPowerUp;
	}

	if (bPowerUp || hPowerUp || kPowerUp || dPowerUp) {
		pacMan1->color = true;
		pacMan2->color = true;
		pacMan3->color = true;
		pacMan4->color = true;
	}
	else {
		pacMan1->color = 0;
		pacMan2->color = 0;
		pacMan3->color = 0;
		pacMan4->color = 0;
	}

	// Ending of the game when food is finished
	if (size == 190) {
		cout << "Good job! You finished the game!" << endl;
		int temp;
		cin >> temp;
		exit(0);
	}

	// My attempt at making pacMan move
	srand((unsigned)time(0));
	int random_integer;
	bool tryAgain = true;

	while (tryAgain) {
		random_integer = rand() % 4;
		if(random_integer == 0)
			pacMan1->specialKeyPress(GLUT_KEY_RIGHT);
		if (random_integer == 1)
			pacMan1->specialKeyPress(GLUT_KEY_UP);
		if (random_integer == 2)
			pacMan1->specialKeyPress(GLUT_KEY_LEFT);
		if (random_integer == 3)
			pacMan1->specialKeyPress(GLUT_KEY_DOWN);
		tryAgain = contains(pacMan1->get('x'), pacMan1->get('y'), *pacMan1, random_integer);
	}
	
	tryAgain = true;
	while (tryAgain) {
		random_integer = rand() % 4;
		if (random_integer == 0)
			pacMan2->specialKeyPress(GLUT_KEY_RIGHT);
		if (random_integer == 1)
			pacMan2->specialKeyPress(GLUT_KEY_UP);
		if (random_integer == 2)
			pacMan2->specialKeyPress(GLUT_KEY_LEFT);
		if (random_integer == 3)
			pacMan2->specialKeyPress(GLUT_KEY_DOWN);
		tryAgain = contains(pacMan2->get('x'), pacMan2->get('y'), *pacMan2, random_integer);
	}

	tryAgain = true;
	while (tryAgain) {
		random_integer = rand() % 4;
		if (random_integer == 0)
			pacMan3->specialKeyPress(GLUT_KEY_RIGHT);
		if (random_integer == 1)
			pacMan3->specialKeyPress(GLUT_KEY_UP);
		if (random_integer == 2)
			pacMan3->specialKeyPress(GLUT_KEY_LEFT);
		if (random_integer == 3)
			pacMan3->specialKeyPress(GLUT_KEY_DOWN);
		tryAgain = contains(pacMan3->get('x'), pacMan3->get('y'), *pacMan3, random_integer);
	}

	tryAgain = true;
	while (tryAgain) {
		random_integer = rand() % 4;
		if (random_integer == 0)
			pacMan4->specialKeyPress(GLUT_KEY_RIGHT);
		if (random_integer == 1)
			pacMan4->specialKeyPress(GLUT_KEY_UP);
		if (random_integer == 2)
			pacMan4->specialKeyPress(GLUT_KEY_LEFT);
		if (random_integer == 3)
			pacMan4->specialKeyPress(GLUT_KEY_DOWN);
		tryAgain = contains(pacMan4->get('x'), pacMan4->get('y'), *pacMan4, random_integer);
	}

	redraw();
}

bool App::contains(float x, float y, Pac temp, int ran) {
	float t = .03f * 2.0;	// Pac radius is .03f

	bool tLeft, tRight, bLeft, bRight;

	temp.set('x', temp.get('x') - .03); temp.set('y', temp.get('y') + .03);
	tLeft = gameBoard->contains(temp.get('x'), temp.get('y'));

	temp.set('x', temp.get('x') + t);
	tRight = gameBoard->contains(temp.get('x'), temp.get('y'));

	temp.set('y', temp.get('y') - t);
	bRight = gameBoard->contains(temp.get('x'), temp.get('y'));

	temp.set('x', temp.get('x') - t);
	bLeft = gameBoard->contains(temp.get('x'), temp.get('y'));

	temp.set('x', temp.get('x') + .03); temp.set('y', temp.get('y') + .03);

	if (tLeft || tRight || bRight || bLeft) {
		switch (ran) {
		case GLUT_KEY_UP:
			temp.specialKeyPress(GLUT_KEY_DOWN);
			break;
		case GLUT_KEY_DOWN:
			temp.specialKeyPress(GLUT_KEY_UP);
			break;
		case GLUT_KEY_LEFT:
			temp.specialKeyPress(GLUT_KEY_RIGHT);
			break;
		case GLUT_KEY_RIGHT:
			temp.specialKeyPress(GLUT_KEY_LEFT);
			break;
		}
		return true;
	}

	// Checks for death of player
	bool death1 = pacMan1->contains(ghost->get('x'), ghost->get('y'));
	bool death2 = pacMan2->contains(ghost->get('x'), ghost->get('y'));
	bool death3 = pacMan3->contains(ghost->get('x'), ghost->get('y'));
	bool death4 = pacMan4->contains(ghost->get('x'), ghost->get('y'));
	if (!bPowerUp && !hPowerUp && !kPowerUp) {
		if (!bPowerUp && !hPowerUp && !kPowerUp) {
			if (death1) {
				delete ghost;
				exit(0);
			}
			if (death2) {
				delete ghost;
				exit(0);
			}
			if (death3) {
				delete ghost;
				exit(0);
			}
			if (death4) {
				delete ghost;
				exit(0);
			}
		}
	}
	else if (bPowerUp) {
		if (death1) {
			pacMan1->set('x', -pacMan1->get('x'));
		};
		if (death2)
			pacMan2->set('x', -pacMan2->get('x'));
		if (death3)
			pacMan3->set('x', -pacMan3->get('x'));
		if (death4)
			pacMan4->set('x', -pacMan4->get('x'));
	}
	else if (hPowerUp) {
		if (death1)
			delete pacMan1;
		if (death2)
			delete pacMan2;
		if (death3)
			delete pacMan3;
		if (death4)
			delete pacMan4;
	}
	else if (kPowerUp) {
	}

	return 0;
}