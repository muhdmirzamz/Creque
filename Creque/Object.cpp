//
//  Object.cpp
//  Creque
//
//  Created by Muhd Mirza on 22/11/14.
//  Copyright (c) 2014 Muhd Mirza. All rights reserved.
//

#include "Object.h"

Object::Object() {
	
}

void Object::setObjectCoordinates(int x, int y) {
	_rect.x = x;
	_rect.y = y;
}

void Object::setObjectSize(int w, int h) {
	_rect.w = w;
	_rect.h = h;
}

void Object::setObjectColour(int r, int g, int b) {
	_r = r;
	_g = g;
	_b = b;
}

void Object::setSpeed(int speed) {
	_speed = speed;
}

void Object::move() {
	_rect.x += _speed;
}

bool Object::didCollideWithRightOfWindow(int windowWidth) {
	if (getXPos() + getWidth() >= windowWidth) {
		return true;
	}
	
	return false;
}

bool Object::didCollideWithLeftOfWindow() {
	if (getXPos() <= 0) {
		return true;
	}
	
	return false;
}

bool Object::didCollideWithTopOfWindow() {
	if (getYPos() <= 0) {
		return true;
	}
	
	return false;
}

bool Object::didCollideWithBottomOfWindow(int windowHeight) {
	if (getYPos() + getHeight() >= windowHeight) {
		return true;
	}
	
	return false;
}

bool Object::didCollideWithObject(Object *object) {
	if (getXPos() <= object->getXPos() + object->getWidth()) {
		return true;
	}
	
	return false;
}

int Object::getXPos() {
	return _rect.x;
}

int Object::getYPos() {
	return _rect.y;
}

int Object::getWidth() {
	return _rect.w;
}

int Object::getHeight() {
	return _rect.h;
}

void Object::renderObject(SDL_Renderer *objectRenderer) {
	SDL_SetRenderDrawColor(objectRenderer, _r, _g, _b, 0);
	SDL_RenderFillRect(objectRenderer, &_rect);
}