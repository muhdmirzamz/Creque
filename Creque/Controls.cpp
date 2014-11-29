//
//  Controls.cpp
//  Creque
//
//  Created by Muhd Mirza on 23/11/14.
//  Copyright (c) 2014 Muhd Mirza. All rights reserved.
//

#include "Controls.h"

Controls::Controls() {
	setWindow();
	setRenderer();
	setRunning();
	initObjects();
	setObjects();
}

void Controls::initObjects() {
	_backgroundPointer = &_background;

	_moveLeftPointer = &_moveLeft;
	_moveRightPointer = &_moveRight;
	_moveUpPointer = &_moveUp;
	_moveDownPointer = &_moveDown;
	
	_shootPointer = &_shoot;
	
	_clickToContinuePointer = &_clickToContinue;
}

void Controls::setObjects() {
	_backgroundPointer->setBackgroundColor(0, 0, 0);

	_moveLeftPointer->loadFont("fonts/Quicksand-Light.ttf", 20);
	_moveLeftPointer->setFontCoordinates(50, 20);
	_moveLeftPointer->setFontSize(150, 50);
	_moveLeftPointer->setFontColor(255, 255, 255);
	_moveLeftPointer->transferFontToTexture(renderer, "Move left = a");
	
	_moveRightPointer->loadFont("fonts/Quicksand-Light.ttf", 20);
	_moveRightPointer->setFontCoordinates(380, 20);
	_moveRightPointer->setFontSize(150, 50);
	_moveRightPointer->setFontColor(255, 255, 255);
	_moveRightPointer->transferFontToTexture(renderer, "Move right = d");
	
	_moveUpPointer->loadFont("fonts/Quicksand-Light.ttf", 20);
	_moveUpPointer->setFontCoordinates(55, 200);
	_moveUpPointer->setFontSize(150, 50);
	_moveUpPointer->setFontColor(255, 255, 255);
	_moveUpPointer->transferFontToTexture(renderer, "Move up = w");
	
	_moveDownPointer->loadFont("fonts/Quicksand-Light.ttf", 20);
	_moveDownPointer->setFontCoordinates(380, 200);
	_moveDownPointer->setFontSize(150, 50);
	_moveDownPointer->setFontColor(255, 255, 255);
	_moveDownPointer->transferFontToTexture(renderer, "Move down = s");
	
	_shootPointer->loadFont("fonts/Quicksand-Light.ttf", 20);
	_shootPointer->setFontCoordinates(windowWidth / 3, 100);
	_shootPointer->setFontSize(150, 50);
	_shootPointer->setFontColor(255, 255, 255);
	_shootPointer->transferFontToTexture(renderer, "Shoot = j");
	
	_clickToContinuePointer->loadFont("fonts/Quicksand-Light.ttf", 20);
	_clickToContinuePointer->setFontCoordinates(windowWidth / 4, 400);
	_clickToContinuePointer->setFontSize(320, 50);
	_clickToContinuePointer->setFontColor(0, 255, 100);
	_clickToContinuePointer->transferFontToTexture(renderer, "Click Anywhere to continue");
}

void Controls::run() {
	while (running) {
		handleEvents();
		render();
		update();
	}
}

void Controls::handleEvents() {
	while (SDL_PollEvent(&event) != 0) {
		if (event.type == SDL_QUIT) {
			running = false;
			
			cleanup();
			
			changeState(EXIT);
		}
		
		if (event.type == SDL_MOUSEBUTTONDOWN) {
			running = false;
		
			cleanup();
			
			changeState(LEVEL);
		}
	}
}

void Controls::render() {
	_backgroundPointer->renderBackground(renderer);
	_moveLeftPointer->renderFont(renderer);
	_moveRightPointer->renderFont(renderer);
	_moveUpPointer->renderFont(renderer);
	_moveDownPointer->renderFont(renderer);
	
	_shootPointer->renderFont(renderer);
	
	_clickToContinuePointer->renderFont(renderer);
}

void Controls::update() {
	SDL_RenderPresent(renderer);
}

void Controls::cleanup() {
	_moveLeftPointer->closeFont();
	_moveRightPointer->closeFont();
	_moveUpPointer->closeFont();
	_moveDownPointer->closeFont();
	
	_shootPointer->closeFont();
	
	_clickToContinuePointer->closeFont();

	SDL_DestroyRenderer(renderer);
	renderer = NULL;
	SDL_DestroyWindow(window);
	window = NULL;
}