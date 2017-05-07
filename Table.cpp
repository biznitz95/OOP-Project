#include "Table.h"

using namespace std;

Table::Table() {
	rect1 = new Rect(-1, 1, 2, .1);		myRects.push_back(rect1);	// Top edge
	rect2 = new Rect(-1, 1, .1, 2);		myRects.push_back(rect2);	// Left edge
	rect3 = new Rect(1, 1, -.1, 2);		myRects.push_back(rect3);	// Right edge	
	rect4 = new Rect(-1, -1, 2, -.1);	myRects.push_back(rect4);	// Bottom edge
	rect5 = new Rect(-.1, .9, .2, .1);	myRects.push_back(rect5);	// Middle top square
	rect6 = new Rect(-.1, .7, .2, .4);	myRects.push_back(rect6);	// Middle Middle Top Rectangle
	rect7 = new Rect(-.2, .2, .4, .4);	myRects.push_back(rect7);	// Middle Middle Square
	rect8 = new Rect(-.2, -.3, .4, .1); myRects.push_back(rect8);	// Middle Middle Bottom Rectangle
	rect9 = new Rect(-.3, -.5, .6, .1);	myRects.push_back(rect9);	// Middle Bottom Rectangle
	rect10 = new Rect(-.1, -.6, .2, .2);myRects.push_back(rect10);	// Middle Bottom Bottom Square
	
	// Right Side 
	rect11 = new Rect(.2, .8, .1, .5);	myRects.push_back(rect11);	
	rect12 = new Rect(.4, .8, .4, .1);	myRects.push_back(rect12);
	rect13 = new Rect(.4, .6, .2, .2);	myRects.push_back(rect13);
	rect14 = new Rect(.7, .7, .1, .4);	myRects.push_back(rect14);
	rect15 = new Rect(.4, .3, .4, .1);	myRects.push_back(rect15);
	rect16 = new Rect(.3, .1, .1, .5);	myRects.push_back(rect16);	
	rect17 = new Rect(.5, .1, .1, .3);	myRects.push_back(rect17);	
	rect18 = new Rect(.7, .1, .1, .5);	myRects.push_back(rect18);		
	rect19 = new Rect(.3, -.3, .5, .1);	myRects.push_back(rect19);	
	rect20 = new Rect(.4, -.5, .4, .1); myRects.push_back(rect20);	
	rect21 = new Rect(.4, -.6, .1, .1);	myRects.push_back(rect21);	
	rect22 = new Rect(.2, -.7, .3, .1);	myRects.push_back(rect22);	
	rect23 = new Rect(.6, -.7, .2, .1); myRects.push_back(rect23);	
	
	// Left Side
	rect24 = new Rect(-.3, .8, .1, .5);	myRects.push_back(rect24);
	rect25 = new Rect(-.8, .8, .4, .1);	myRects.push_back(rect25);
	rect26 = new Rect(-.6, .6, .2, .2);	myRects.push_back(rect26);
	rect27 = new Rect(-.8, .7, .1, .4);	myRects.push_back(rect27);
	rect28 = new Rect(-.8, .3, .4, .1);	myRects.push_back(rect28);
	rect29 = new Rect(-.4, .1, .1, .5);	myRects.push_back(rect29);
	rect30 = new Rect(-.6, .1, .1, .3);	myRects.push_back(rect30);
	rect31 = new Rect(-.8, .1, .1, .5);	myRects.push_back(rect31);
	rect32 = new Rect(-.8, -.3, .5, .1);myRects.push_back(rect32);
	rect33 = new Rect(-.8, -.5, .4, .1);myRects.push_back(rect33);
	rect34 = new Rect(-.5, -.6, .1, .1);myRects.push_back(rect34);
	rect35 = new Rect(-.5, -.7, .3, .1);myRects.push_back(rect35);
	rect36 = new Rect(-.8, -.7, .2, .1);myRects.push_back(rect36); 
}

void Table::build() {
	for (int i = 0; i < myRects.size(); i++)
		myRects[i]->build();
}

Table::~Table() {

}