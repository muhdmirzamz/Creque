//
//  Level.cpp
//  Creque
//
//  Created by Muhd Mirza on 22/11/14.
//  Copyright (c) 2014 Muhd Mirza. All rights reserved.
//

#include "Level.h"

Level::Level() {
	setWindow();
	setRenderer();
	setRunning();
	initObjects();
	setObjects();
}

void Level::initObjects() {
	_backgroundPointer = &_background;
	_playerPointer = &_player;
	_bulletsRemainingWordsPointer = &_bulletsRemainingWords;
	_bulletsRemainingPointer = &_bulletsRemaining;
	
	_enemyPointer = &_enemy;
}

void Level::setObjects() {
	_backgroundPointer->setBackgroundColor(0, 0, 0);
	
	_playerPointer->setPlayerCoordinates(100, 100);
	_playerPointer->setPlayerSize(50, 50);
	_playerPointer->setPlayerColour(100, 255, 255);
	_playerPointer->setPlayerHealth();
	
	_playerPointer->setBullet();
	
	_bulletsRemainingWordsPointer->loadFont("fonts/Quicksand-Light.ttf", 10);
	_bulletsRemainingWordsPointer->setFontColor(255, 255, 255);
	_bulletsRemainingWordsPointer->setFontCoordinates(90, windowHeight - 100);
	_bulletsRemainingWordsPointer->setFontSize(150, 50);
	_bulletsRemainingWordsPointer->transferFontToTexture(renderer, "Bullets remaining: ");
	
	_bulletsRemainingPointer->loadFont("fonts/Quicksand-Light.ttf", 10);
	_bulletsRemainingPointer->setFontColor(255, 255, 255);
	_bulletsRemainingPointer->setFontCoordinates(250, windowHeight - 100);
	_bulletsRemainingPointer->setFontSize(50, 50);
	
	_enemyPointer->setEnemyCoordinates(windowWidth - 90, 50);
	_enemyPointer->setEnemySize(50, 50);
	_enemyPointer->setEnemyColour(200, 120, 100);
	_enemyPointer->setEnemyHealth();
	_enemyPointer->setSpeedY(5);
	
	_enemyPointer->setBullet();
	
	_isPlayerShooting = false;
	srand((int)time(0));
}

void Level::run() {
	while (running) {
		handleEvents();
		loadEnemyBullet();
		moveSprite();
		checkCollision();
		render();
		update();
	}
}

void Level::handleEvents() {
	while (SDL_PollEvent(&event) != 0) {
		if (event.type == SDL_QUIT) {
			running = false;
			
			cleanup();
			
			changeState(EXIT);
		}
		
		if (event.type == SDL_KEYDOWN) {
			if (event.key.keysym.sym == SDLK_j) {
				_isPlayerShooting = true;
				
				_playerPointer->loadBullet();
			}
			
			if (event.key.keysym.sym == SDLK_w) {
				_playerPointer->moveUp();
			}
			
			if (event.key.keysym.sym == SDLK_s) {
				_playerPointer->moveDown();
			}
			
			if (event.key.keysym.sym == SDLK_a) {
				_playerPointer->moveLeft();
			}
			
			if (event.key.keysym.sym == SDLK_d) {
				_playerPointer->moveRight();
			}
		}
	}
}

void Level::loadEnemyBullet() {
	_randomNum = rand() / 1000000;
	_randomNum2 = rand() / 1000000;
	
	if (_randomNum % 8 == 0 && _randomNum2 % 12  == 0) {
		_enemyPointer->loadBullet();
	}
}

void Level::moveSprite() {
	_playerPointer->moveBullet();

	if (_enemyPointer->getYPos() <= 0) {
		_enemyPointer->setSpeedY(5);
	}
	
	if (_enemyPointer->getYPos() + _enemyPointer->getHeight() >= windowHeight) {
		_enemyPointer->setSpeedY(-5);
	}
	
	_enemyPointer->moveVertically();
	_enemyPointer->moveBullet();
}

void Level::checkCollision() {
	if (_playerPointer->bulletDidCollideWithEnemy(_enemyPointer->getXPos(), _enemyPointer->getXPos() + _enemyPointer->getWidth(), _enemyPointer->getYPos(), _enemyPointer->getYPos() + _enemyPointer->getHeight())) {
		_enemyPointer->decreaseHealth(_playerPointer->getPlayerBulletDamage());
	}
	
	if (_enemyPointer->bulletDidCollideWithPlayer(_playerPointer->getXPos() + _playerPointer->getWidth(), _playerPointer->getXPos(), _playerPointer->getYPos(), _playerPointer->getXPos() + _playerPointer->getHeight())) {
		_playerPointer->decreaseHealth(_enemyPointer->getEnemyBulletDamage());
	}
}

void Level::render() {
	_backgroundPointer->renderBackground(renderer);
	
	if (_playerPointer->getPlayerHealth() >= 0) {
		_playerPointer->renderPlayer(renderer);
		
		// render bullet
		if (_isPlayerShooting) {
			_playerPointer->shoot(renderer);
		}
	}

	_bulletsRemainingWordsPointer->renderFont(renderer);
	_bulletsRemainingPointer->renderFont(renderer);
	_bulletsRemainingPointer->transferFontToTexture(renderer, _playerPointer->getNumberOfTimesPlayerHasShot());
	
	if (_enemyPointer->getEnemyHealth() >= 0) {
		_enemyPointer->renderEnemy(renderer);
		_enemyPointer->shoot(renderer);
	}
}

void Level::update() {
	SDL_RenderPresent(renderer);
}

void Level::cleanup() {
	_bulletsRemainingWordsPointer->closeFont();
	// TODO: find a way to close the _bulletsRemainingPointer font
	
	SDL_DestroyRenderer(renderer);
	renderer = NULL;
	SDL_DestroyWindow(window);
	window = NULL;
}