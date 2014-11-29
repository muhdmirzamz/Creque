//
//  IntroScene.cpp
//  Creque
//
//  Created by Muhd Mirza on 21/11/14.
//  Copyright (c) 2014 Muhd Mirza. All rights reserved.
//

#include "IntroScene.h"

IntroScene::IntroScene() {
	setWindow();
	setRenderer();
	setRunning();
	initObjects();
	setObjects();
}

void IntroScene::initObjects() {
	_backgroundPointer = &_background;
	_objectPointer = &_object;
	_anotherObjectPointer = &_anotherObject;
}

void IntroScene::setObjects() {
	_backgroundPointer->setBackgroundColor(0, 0, 0);

	_objectPointer->setObjectCoordinates(50, 50);
	_objectPointer->setObjectSize(100, 100);
	_objectPointer->setObjectColour(0, 0, 0);
	
	_anotherObjectPointer->setObjectCoordinates(160, 80);
	_anotherObjectPointer->setObjectSize(50, 50);
	_anotherObjectPointer->setObjectColour(0, 0, 0);
	_anotherObjectPointer->setSpeed(5);
}

void IntroScene::run() {
	while (running) {
		handleEvents();
		moveSprite();
		checkCollision();
		render();
		update();
	}
}

void IntroScene::handleEvents() {
	while (SDL_PollEvent(&event) != 0) {
		if (event.type == SDL_QUIT) {
			running = false;
			
			cleanup();
			
			changeState(EXIT);
		}
	}
}

void IntroScene::moveSprite() {
	_anotherObjectPointer->move();
}

void IntroScene::checkCollision() {
	if (_anotherObjectPointer->didCollideWithRightOfWindow(windowWidth)) {
		_anotherObjectPointer->setSpeed(-5);
	}
	
	if (_anotherObjectPointer->didCollideWithObject(_objectPointer)) {
		running = false;
		
		cleanup();
		
		changeState(MAIN_MENU);
	}
}

void IntroScene::render() {
	_backgroundPointer->renderBackground(renderer);
	_objectPointer->renderObject(renderer);
	_anotherObjectPointer->renderObject(renderer);
}

void IntroScene::update() {
	SDL_RenderPresent(renderer);
}

void IntroScene::cleanup() {	
	SDL_DestroyRenderer(renderer);
	renderer = NULL;
	SDL_DestroyWindow(window);
	window = NULL;
}