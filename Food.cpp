//
//  Food.cpp
//  glutapp
//
//  Created by Khin on 5/7/17.
//  Copyright © 2017 Angelo Kyrilov. All rights reserved.
//

#include "Food.h"

using namespace std;

Food::Food() {
	float i = 0.0f;
	for (i = -0.85f; i < -0.1f; i += 0.1) {                //1st horizontal
		myFood.push_back(Rect(i, 0.85, 0.02, 0.02));
	}for (i = 0.15f; i < 0.9f; i += 0.1) {
		myFood.push_back(Rect(i, 0.85, 0.02, 0.02));
	}
	myFood.push_back(Rect(-0.85, 0.75, 0.02, 0.02));    //2nd horizontal
	myFood.push_back(Rect(-0.35, 0.75, 0.02, 0.02));
	for (i = -0.15f; i < 0.2f; i += 0.1) {
		myFood.push_back(Rect(i, 0.75, 0.02, 0.02));
	}
	myFood.push_back(Rect(0.35, 0.75, 0.02, 0.02));
	myFood.push_back(Rect(0.85, 0.75, 0.02, 0.02));
	myFood.push_back(Rect(-0.85, 0.65, 0.02, 0.02));    //3rd horizontal
	for (i = -0.65f; i < -0.3f; i += 0.1) {
		myFood.push_back(Rect(i, 0.65, 0.02, 0.02));
	}
	myFood.push_back(Rect(-0.15, 0.65, 0.02, 0.02));
	myFood.push_back(Rect(0.15, 0.65, 0.02, 0.02));
	for (i = 0.35f; i < 0.7f; i += 0.1) {
		myFood.push_back(Rect(i, 0.65, 0.02, 0.02));
	}
	myFood.push_back(Rect(0.85, 0.65, 0.02, 0.02));
	myFood.push_back(Rect(-0.85, 0.55, 0.02, 0.02));    //4th horizontal
	myFood.push_back(Rect(-0.65, 0.55, 0.02, 0.02));
	myFood.push_back(Rect(-0.35, 0.55, 0.02, 0.02));
	myFood.push_back(Rect(-0.15, 0.55, 0.02, 0.02));
	myFood.push_back(Rect(0.15, 0.55, 0.02, 0.02));
	myFood.push_back(Rect(0.35, 0.55, 0.02, 0.02));
	myFood.push_back(Rect(0.65, 0.55, 0.02, 0.02));
	myFood.push_back(Rect(0.85, 0.55, 0.02, 0.02));
	myFood.push_back(Rect(-0.85, 0.45, 0.02, 0.02));    //5th horizontal
	myFood.push_back(Rect(-0.65, 0.45, 0.02, 0.02));
	myFood.push_back(Rect(-0.35, 0.45, 0.02, 0.02));
	myFood.push_back(Rect(-0.15, 0.45, 0.02, 0.02));
	myFood.push_back(Rect(0.15, 0.45, 0.02, 0.02));
	myFood.push_back(Rect(0.35, 0.45, 0.02, 0.02));
	myFood.push_back(Rect(0.65, 0.45, 0.02, 0.02));
	myFood.push_back(Rect(0.85, 0.45, 0.02, 0.02));
	myFood.push_back(Rect(-0.85, 0.35, 0.02, 0.02));    //6th horizontal
	for (i = -0.65f; i < -0.3f; i += 0.1) {
		myFood.push_back(Rect(i, 0.35, 0.02, 0.02));
	}
	myFood.push_back(Rect(-0.15, 0.35, 0.02, 0.02));
	myFood.push_back(Rect(0.15, 0.35, 0.02, 0.02));
	for (i = 0.35f; i < 0.7f; i += 0.1) {
		myFood.push_back(Rect(i, 0.35, 0.02, 0.02));
	}myFood.push_back(Rect(0.85, 0.35, 0.02, 0.02));
	myFood.push_back(Rect(-0.85, 0.25, 0.02, 0.02));    //7th horizontal
	for (i = -0.35f; i < 0.4f; i += 0.1) {
		myFood.push_back(Rect(i, 0.25, 0.02, 0.02));
	}myFood.push_back(Rect(0.85, 0.25, 0.02, 0.02));
	for (i = -0.85f; i < -0.2f; i += 0.1) {                //8th horizontal
		myFood.push_back(Rect(i, 0.15, 0.02, 0.02));
	}for (i = 0.25f; i < 0.9f; i += 0.1) {
		myFood.push_back(Rect(i, 0.15, 0.02, 0.02));
	}
	for (i = -0.85f; i < -0.2f; i += 0.2) {                 //9th horizontal
		myFood.push_back(Rect(i, 0.05, 0.02, 0.02));
	}for (i = 0.25f; i < 0.9f; i += 0.2) {
		myFood.push_back(Rect(i, 0.05, 0.02, 0.02));
	}
	for (i = -0.85f; i < -0.2f; i += 0.2) {                 //10th horizontal
		myFood.push_back(Rect(i, -0.05, 0.02, 0.02));
	}for (i = 0.25f; i < 0.9f; i += 0.2) {
		myFood.push_back(Rect(i, -0.05, 0.02, 0.02));
	}
	for (i = -0.85f; i < -0.2f; i += 0.2) {                 //11th horizontal
		myFood.push_back(Rect(i, -0.15, 0.02, 0.02));
	}for (i = 0.25f; i < 0.9f; i += 0.2) {
		myFood.push_back(Rect(i, -0.15, 0.02, 0.02));
	}
	myFood.push_back(Rect(-0.85, -0.25, 0.02, 0.02));    //12th horizontal
	for (i = -0.65f; i < -0.4f; i += 0.1) {
		myFood.push_back(Rect(i, -0.25, 0.02, 0.02));
	}for (i = -0.25f; i < 0.3f; i += 0.1) {
		myFood.push_back(Rect(i, -0.25, 0.02, 0.02));
	}for (i = 0.45f; i < 0.7f; i += 0.1) {
		myFood.push_back(Rect(i, -0.25, 0.02, 0.02));
	}
	myFood.push_back(Rect(0.85, -0.25, 0.02, 0.02));
	myFood.push_back(Rect(-0.85, -0.35, 0.02, 0.02));    //13th horizontal
	myFood.push_back(Rect(-0.25, -0.35, 0.02, 0.02));
	myFood.push_back(Rect(0.25, -0.35, 0.02, 0.02));
	myFood.push_back(Rect(0.85, -0.35, 0.02, 0.02));
	for (i = -0.85f; i < 0.9f; i += 0.1) {                 //14th horizontal
		myFood.push_back(Rect(i, -0.45, 0.02, 0.02));
	}
	myFood.push_back(Rect(-0.85, -0.55, 0.02, 0.02));    //15th horizontal
	myFood.push_back(Rect(-0.35, -0.55, 0.02, 0.02));
	myFood.push_back(Rect(0.35, -0.55, 0.02, 0.02));
	myFood.push_back(Rect(0.85, -0.55, 0.02, 0.02));
	for (i = -0.85f; i < -0.5f; i += 0.1) {                 //16th horizontal
		myFood.push_back(Rect(i, -0.65, 0.02, 0.02));
	}for (i = -0.35f; i < -0.1f; i += 0.1) {
		myFood.push_back(Rect(i, -0.65, 0.02, 0.02));
	}for (i = 0.15f; i < 0.4f; i += 0.1) {
		myFood.push_back(Rect(i, -0.65, 0.02, 0.02));
	}for (i = 0.55f; i < 0.9f; i += 0.1) {
		myFood.push_back(Rect(i, -0.65, 0.02, 0.02));
	}
	myFood.push_back(Rect(-0.85, -0.75, 0.02, 0.02));    //15th horizontal
	myFood.push_back(Rect(-0.55, -0.75, 0.02, 0.02));
	myFood.push_back(Rect(-0.15, -0.75, 0.02, 0.02));
	myFood.push_back(Rect(0.15, -0.75, 0.02, 0.02));
	myFood.push_back(Rect(0.55, -0.75, 0.02, 0.02));
	myFood.push_back(Rect(0.85, -0.75, 0.02, 0.02));
	for (i = -0.85f; i < 0.9f; i += 0.1) {                 //18th horizontal
		myFood.push_back(Rect(i, -0.85, 0.02, 0.02));
	}
}

void Food::build() {
	for (int i = 0; i < myFood.size(); i++)
		myFood[i].build();
}

Food::~Food() {

}
