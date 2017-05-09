//
//  Food.h
//  glutapp
//
//  Created by Khin on 5/7/17.
//  Copyright © 2017 Angelo Kyrilov. All rights reserved.
//
#ifndef FOOD_H
#define FOOD_H

#include "Food.h"
#include <vector>
#include "Rect.h"

class Food {
public:
	std::vector<Rect*> myFood;
public:
	Food();
	void build();
	~Food();
};

#endif
