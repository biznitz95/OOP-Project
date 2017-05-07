#ifndef TABLE_H
#define TABLE_H

#include "Rect.h"
#include <vector>

class Table {
private:
	Rect* rect1;	Rect* rect9;	Rect* rect17;	Rect* rect25;	Rect* rect33;
	Rect* rect2;	Rect* rect10;	Rect* rect18;	Rect* rect26;	Rect* rect34;
	Rect* rect3;	Rect* rect11;	Rect* rect19;	Rect* rect27;	Rect* rect35;
	Rect* rect4;	Rect* rect12;	Rect* rect20;	Rect* rect28;	Rect* rect36;
	Rect* rect5;	Rect* rect13;	Rect* rect21;	Rect* rect29;
	Rect* rect6;	Rect* rect14;	Rect* rect22;	Rect* rect30;
	Rect* rect7;	Rect* rect15;	Rect* rect23;	Rect* rect31;
	Rect* rect8;	Rect* rect16;	Rect* rect24;	Rect* rect32;
	std::vector<Rect*> myRects;

public:
	Table();
	void build();
	~Table();
};

#endif