#include "App.h"
#include "Ghost.h"
#include "Pac.h"

App::App(const char* label, int x, int y, int w, int h): GlutApp(label, x, y, w, h){
    // Initialize state variables
    mx = 0.0;
    my = 0.0;
	gameBoard = new Table();
	ghost = new Ghost(0,.25);
	dots = new Food();              ////////Khin
	pacMan1 = new Pac();
}

void App::draw() {

    // Clear the screen
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    // Set background color to black
    glClearColor(0.0, 0.0, 0.0, 0.0);
    
    // Set up the transformations stack
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
	ghost->build(.03);
	dots->build();                  ////////Khin
	pacMan1->build();
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
    
	gameBoard->contains(x, y);

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
	bool center = gameBoard->contains(ghost->get('x'), ghost->get('y'));
	bool tLeft, tRight, bLeft, bRight;

	ghost->set('x',ghost->get('x')-.03); ghost->set('y', ghost->get('y') + .03);
	tLeft = gameBoard->contains(ghost->get('x'), ghost->get('y'));

	ghost->set('x', ghost->get('x') + .06);
	tRight = gameBoard->contains(ghost->get('x'), ghost->get('y'));

	ghost->set('y', ghost->get('y') - .06);
	bRight = gameBoard->contains(ghost->get('x'), ghost->get('y'));

	ghost->set('x', ghost->get('x') - .06);
	bLeft = gameBoard->contains(ghost->get('x'), ghost->get('y'));

	ghost->set('x', ghost->get('x') + .03); ghost->set('y', ghost->get('y') + .03);

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

	redraw();
}