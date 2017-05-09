#ifndef SCORE_CPP
#define SCORE_CPP

#include <iostream>
#include "Food.h"
#include "score.h"

using namespace std;

int Score::score(bool flag) {
	points += 1;

	if (flag = true) {
		points += 2;
	}

	return points;

}

#endif
