//
//  GameState.cpp
//  Creque
//
//  Created by Muhd Mirza on 21/11/14.
//  Copyright (c) 2014 Muhd Mirza. All rights reserved.
//

#include "GameState.h"

GameState::GameState() {

}

GameState::~GameState() {
	
}

void GameState::printComponentErrorMessage(string comp) {
	cout << "ERROR: \n" << "Component: " << comp << endl;
}

void GameState::printStateErrorMessage(string state, string comp) {
	cout << "ERROR: \n" << "State: " << state << "\n" << "Component: " << comp << endl;
}

int GameState::getWindowWidth() {
	return windowWidth;
}

int GameState::getWindowHeight() {
	return windowHeight;
}

int GameState::getWindowXPos() {
	return windowXPos;
}

int GameState::getWindowYPos() {
	return windowYPos;
}

bool GameState::setWindow() {
	window = SDL_CreateWindow("Creque", windowXPos, windowYPos, windowWidth, windowHeight, SDL_WINDOW_SHOWN);
	if (!window) {
		printComponentErrorMessage("Window");
		return false;
	}
	
	return true;
}

bool GameState::setRenderer() {
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);
	
	if (!renderer) {
		printComponentErrorMessage("renderer");
		return false;
	}
	
	return true;
}

void GameState::setRunning() {
	running = true;
}

void GameState::initObjects() {
	
}

void GameState::setObjects() {
	
}

void GameState::run() {
	
}

void GameState::handleEvents() {
	
}

void GameState::moveSprite() {
	
}

void GameState::checkCollision() {
	
}

void GameState::changeState(int state) {
	_gameManager->changeGameState(state);
}

void GameState::render() {
	
}

void GameState::update() {
	
}

void GameState::cleanup() {
	
}