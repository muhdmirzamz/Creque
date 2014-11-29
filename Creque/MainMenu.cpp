//
//  MainMenu.cpp
//  Creque
//
//  Created by Muhd Mirza on 21/11/14.
//  Copyright (c) 2014 Muhd Mirza. All rights reserved.
//

#include "MainMenu.h"

MainMenu::MainMenu() {
	setWindow();
	setRenderer();
	setRunning();
	initObjects();
	setObjects();
}

void MainMenu::initObjects() {
	_backgroundPointer = &_background;
	_gameTitlePointer = &_gameTitle;
	_gameBeginPointer = &_gameBegin;
	_gameBeginHoverPointer = &_gameBeginHover;
}

void MainMenu::setObjects() {
	_isGameBeginOnHovered = false;

	_backgroundPointer->setBackgroundColor(0, 200, 255);

	_gameTitlePointer->loadFont("fonts/Quicksand-Light.ttf", 20);
	_gameTitlePointer->setFontColor(0, 255, 0);
	_gameTitlePointer->setFontCoordinates(windowWidth / 4 + 50, windowHeight / 12);
	_gameTitlePointer->setFontSize(220, 220);
	_gameTitlePointer->transferFontToTexture(renderer, "Creque");
	
	_gameBeginPointer->loadFont("fonts/Quicksand-Light.ttf", 10);
	_gameBeginPointer->setFontColor(0, 255, 0);
	_gameBeginPointer->setFontCoordinates(windowWidth / 4 + 50, windowHeight / 10 + 200);
	_gameBeginPointer->setFontSize(220, 220);
	_gameBeginPointer->transferFontToTexture(renderer, "Begin");
	
	_gameBeginHoverPointer->loadFont("fonts/Quicksand-Light.ttf", 10);
	_gameBeginHoverPointer->setFontColor(0, 255, 0);
	_gameBeginHoverPointer->setFontCoordinates(windowWidth / 4 + 50, windowHeight / 10 + 200);
	_gameBeginHoverPointer->setFontSize(220, 220);
	_gameBeginHoverPointer->transferFontToTexture(renderer, "--Begin--");
}

void MainMenu::run() {
	while (running) {
		handleEvents();
		render();
		update();
	}
}

void MainMenu::handleEvents() {
	while (SDL_PollEvent(&event) != 0) {
		if (event.type == SDL_QUIT) {
			running = false;
			
			cleanup();
			
			changeState(EXIT);
		}
		
		if (event.type == SDL_MOUSEMOTION) {
			if (event.motion.x >= _gameBeginPointer->getFontRectangleXPos() && event.motion.x <= _gameBeginPointer->getFontRectangleXPos() + _gameBeginPointer->getFontRectangleWidth()) {
				if (event.motion.y >= _gameBeginPointer->getFontRectangleYPos() && event.motion.y <= _gameBeginPointer->getFontRectangleYPos() + _gameBeginPointer->getFontRectangleHeight()) {
					_isGameBeginOnHovered = true;
				}
			} else {
				_isGameBeginOnHovered = false;
			}
		}
		
		if (event.type == SDL_MOUSEBUTTONDOWN) {
			if (event.button.x >= _gameBeginHoverPointer->getFontRectangleXPos() && event.button.x <= _gameBeginHoverPointer->getFontRectangleXPos() + _gameBeginHoverPointer->getFontRectangleWidth()) {
				if (event.button.y >= _gameBeginHoverPointer->getFontRectangleYPos() && event.button.y <= _gameBeginHoverPointer->getFontRectangleYPos() + _gameBeginHoverPointer->getFontRectangleHeight()) {
					running = false;
					
					cleanup();
					
					changeState(CONTROLS);
				}
			}
		}
	}
}

void MainMenu::render() {
	_backgroundPointer->renderBackground(renderer);
	
	_gameTitlePointer->renderFont(renderer);
	
	if (!(_isGameBeginOnHovered)) {
		_gameBeginPointer->renderFont(renderer);
	} else {
		_gameBeginHoverPointer->renderFont(renderer);
	}
}

void MainMenu::update() {
	SDL_RenderPresent(renderer);
}

void MainMenu::cleanup() {
	_gameTitlePointer->closeFont();
	_gameBeginPointer->closeFont();
	_gameBeginHoverPointer->closeFont();
	
	SDL_DestroyRenderer(renderer);
	renderer = NULL;
	SDL_DestroyWindow(window);
	window = NULL;
}