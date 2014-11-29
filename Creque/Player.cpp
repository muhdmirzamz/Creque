//
//  Player.cpp
//  Creque
//
//  Created by Muhd Mirza on 21/11/14.
//  Copyright (c) 2014 Muhd Mirza. All rights reserved.
//

#include "Player.h"

static int numberOfTimesPlayerShot = 0;
static int playerBulletDamage = 25;
static int bulletSpeed = 5;

Player::Player() {

}

void Player::setPlayerCoordinates(int x, int y) {
	_rect.x = x;
	_rect.y = y;
}

void Player::setPlayerSize(int w, int h) {
	_rect.w = w;
	_rect.h = h;
}

void Player::setPlayerColour(int r, int g, int b) {
	_r = r;
	_g = g;
	_b = b;
}

void Player::setPlayerHealth() {
	_health = 60;
}

void Player::setBullet() {
	_bulletPointer1 = &_bullet1;
	_bulletPointer2 = &_bullet2;
	_bulletPointer3 = &_bullet3;
	_bulletPointer4 = &_bullet4;
	_bulletPointer5 = &_bullet5;
	_bulletPointer6 = &_bullet6;
	_bulletPointer7 = &_bullet7;
	_bulletPointer8 = &_bullet8;
	_bulletPointer9 = &_bullet9;
	_bulletPointer10 = &_bullet10;
	
	_bulletPointer1->setBulletSize();
	_bulletPointer1->setBulletSpeed(bulletSpeed);
	_bulletPointer1->setBulletDamage(25);
	
	_bulletPointer2->setBulletSize();
	_bulletPointer2->setBulletSpeed(bulletSpeed);
	_bulletPointer2->setBulletDamage(playerBulletDamage);
	
	_bulletPointer3->setBulletSize();
	_bulletPointer3->setBulletSpeed(bulletSpeed);
	_bulletPointer3->setBulletDamage(playerBulletDamage);
	
	_bulletPointer4->setBulletSize();
	_bulletPointer4->setBulletSpeed(bulletSpeed);
	_bulletPointer4->setBulletDamage(playerBulletDamage);
	
	_bulletPointer5->setBulletSize();
	_bulletPointer5->setBulletSpeed(bulletSpeed);
	_bulletPointer5->setBulletDamage(playerBulletDamage);
	
	_bulletPointer6->setBulletSize();
	_bulletPointer6->setBulletSpeed(bulletSpeed);
	_bulletPointer6->setBulletDamage(playerBulletDamage);
	
	_bulletPointer7->setBulletSize();
	_bulletPointer7->setBulletSpeed(bulletSpeed);
	_bulletPointer7->setBulletDamage(playerBulletDamage);
	
	_bulletPointer8->setBulletSize();
	_bulletPointer8->setBulletSpeed(bulletSpeed);
	_bulletPointer8->setBulletDamage(playerBulletDamage);
	
	_bulletPointer9->setBulletSize();
	_bulletPointer9->setBulletSpeed(bulletSpeed);
	_bulletPointer9->setBulletDamage(playerBulletDamage);
	
	_bulletPointer10->setBulletSize();
	_bulletPointer10->setBulletSpeed(bulletSpeed);
	_bulletPointer10->setBulletDamage(playerBulletDamage);
}

void Player::loadBullet() {
	if (numberOfTimesPlayerShot <= 10) {
		numberOfTimesPlayerShot++;
		cout << "Player shot: " << numberOfTimesPlayerShot << endl;
	}
	
	if (numberOfTimesPlayerShot == 1) {
		_bulletPointer1->setBulletCoordinates(_rect.x + 1, _rect.y);
	}
	
	if (numberOfTimesPlayerShot == 2) {
		_bulletPointer2->setBulletCoordinates(_rect.x + 1, _rect.y);
	}
	
	if (numberOfTimesPlayerShot == 3) {
		_bulletPointer3->setBulletCoordinates(_rect.x + 1, _rect.y);
	}
	
	if (numberOfTimesPlayerShot == 4) {
		_bulletPointer4->setBulletCoordinates(_rect.x + 1, _rect.y);
	}
	
	if (numberOfTimesPlayerShot == 5) {
		_bulletPointer5->setBulletCoordinates(_rect.x + 1, _rect.y);
	}
	
	if (numberOfTimesPlayerShot == 6) {
		_bulletPointer6->setBulletCoordinates(_rect.x + 1, _rect.y);
	}
	
	if (numberOfTimesPlayerShot == 7) {
		_bulletPointer7->setBulletCoordinates(_rect.x + 1, _rect.y);
	}
	
	if (numberOfTimesPlayerShot == 8) {
		_bulletPointer8->setBulletCoordinates(_rect.x + 1, _rect.y);
	}
	
	if (numberOfTimesPlayerShot == 9) {
		_bulletPointer9->setBulletCoordinates(_rect.x + 1, _rect.y);
	}
	
	if (numberOfTimesPlayerShot == 10) {
		_bulletPointer10->setBulletCoordinates(_rect.x + 1, _rect.y);
	}
}

void Player::moveLeft() {
	_speedX = -10;
	_rect.x += _speedX;
}

void Player::moveRight() {
	_speedX = 10;
	_rect.x += _speedX;
}

void Player::moveUp() {
	_speedY = -10;
	_rect.y += _speedY;
}

void Player::moveDown() {
	_speedY = 10;
	_rect.y += _speedY;
}

void Player::decreaseHealth(int enemyBulletDamage) {
	_health -= enemyBulletDamage;
}

void Player::shoot(SDL_Renderer *playerRenderer) {
	if (numberOfTimesPlayerShot == 1) {
		_bulletPointer1->renderBullet(playerRenderer);
	}
	
	if (numberOfTimesPlayerShot == 2) {
		_bulletPointer1->renderBullet(playerRenderer);
		_bulletPointer2->renderBullet(playerRenderer);
	}
	
	if (numberOfTimesPlayerShot == 3) {
		_bulletPointer1->renderBullet(playerRenderer);
		_bulletPointer2->renderBullet(playerRenderer);
		_bulletPointer3->renderBullet(playerRenderer);
	}
	
	if (numberOfTimesPlayerShot == 4) {
		_bulletPointer1->renderBullet(playerRenderer);
		_bulletPointer2->renderBullet(playerRenderer);
		_bulletPointer3->renderBullet(playerRenderer);
		_bulletPointer4->renderBullet(playerRenderer);
	}
	
	if (numberOfTimesPlayerShot == 5) {
		_bulletPointer1->renderBullet(playerRenderer);
		_bulletPointer2->renderBullet(playerRenderer);
		_bulletPointer3->renderBullet(playerRenderer);
		_bulletPointer4->renderBullet(playerRenderer);
		_bulletPointer5->renderBullet(playerRenderer);
	}
	
	if (numberOfTimesPlayerShot == 6) {
		_bulletPointer1->renderBullet(playerRenderer);
		_bulletPointer2->renderBullet(playerRenderer);
		_bulletPointer3->renderBullet(playerRenderer);
		_bulletPointer4->renderBullet(playerRenderer);
		_bulletPointer5->renderBullet(playerRenderer);
		_bulletPointer6->renderBullet(playerRenderer);
	}
	
	if (numberOfTimesPlayerShot == 7) {
		_bulletPointer1->renderBullet(playerRenderer);
		_bulletPointer2->renderBullet(playerRenderer);
		_bulletPointer3->renderBullet(playerRenderer);
		_bulletPointer4->renderBullet(playerRenderer);
		_bulletPointer5->renderBullet(playerRenderer);
		_bulletPointer6->renderBullet(playerRenderer);
		_bulletPointer7->renderBullet(playerRenderer);
	}
	
	if (numberOfTimesPlayerShot == 8) {
		_bulletPointer1->renderBullet(playerRenderer);
		_bulletPointer2->renderBullet(playerRenderer);
		_bulletPointer3->renderBullet(playerRenderer);
		_bulletPointer4->renderBullet(playerRenderer);
		_bulletPointer5->renderBullet(playerRenderer);
		_bulletPointer6->renderBullet(playerRenderer);
		_bulletPointer7->renderBullet(playerRenderer);
		_bulletPointer8->renderBullet(playerRenderer);
	}
	
	if (numberOfTimesPlayerShot == 9) {
		_bulletPointer1->renderBullet(playerRenderer);
		_bulletPointer2->renderBullet(playerRenderer);
		_bulletPointer3->renderBullet(playerRenderer);
		_bulletPointer4->renderBullet(playerRenderer);
		_bulletPointer5->renderBullet(playerRenderer);
		_bulletPointer6->renderBullet(playerRenderer);
		_bulletPointer7->renderBullet(playerRenderer);
		_bulletPointer8->renderBullet(playerRenderer);
		_bulletPointer9->renderBullet(playerRenderer);
	}
	
	if (numberOfTimesPlayerShot == 10) {
		_bulletPointer1->renderBullet(playerRenderer);
		_bulletPointer2->renderBullet(playerRenderer);
		_bulletPointer3->renderBullet(playerRenderer);
		_bulletPointer4->renderBullet(playerRenderer);
		_bulletPointer5->renderBullet(playerRenderer);
		_bulletPointer6->renderBullet(playerRenderer);
		_bulletPointer7->renderBullet(playerRenderer);
		_bulletPointer8->renderBullet(playerRenderer);
		_bulletPointer9->renderBullet(playerRenderer);
		_bulletPointer10->renderBullet(playerRenderer);
	}
}

void Player::moveBullet() {
	if (numberOfTimesPlayerShot == 1)
		_bulletPointer1->moveRight();
	
	if (numberOfTimesPlayerShot == 2) {
		_bulletPointer1->moveRight();
		_bulletPointer2->moveRight();
	}
	
	if (numberOfTimesPlayerShot == 3) {
		_bulletPointer1->moveRight();
		_bulletPointer2->moveRight();
		_bulletPointer3->moveRight();
	}
	
	if (numberOfTimesPlayerShot == 4) {
		_bulletPointer1->moveRight();
		_bulletPointer2->moveRight();
		_bulletPointer3->moveRight();
		_bulletPointer4->moveRight();
	}
	
	if (numberOfTimesPlayerShot == 5) {
		_bulletPointer1->moveRight();
		_bulletPointer2->moveRight();
		_bulletPointer3->moveRight();
		_bulletPointer4->moveRight();
		_bulletPointer5->moveRight();
	}
	
	if (numberOfTimesPlayerShot == 6) {
		_bulletPointer1->moveRight();
		_bulletPointer2->moveRight();
		_bulletPointer3->moveRight();
		_bulletPointer4->moveRight();
		_bulletPointer5->moveRight();
		_bulletPointer6->moveRight();
	}
	
	if (numberOfTimesPlayerShot == 7) {
		_bulletPointer1->moveRight();
		_bulletPointer2->moveRight();
		_bulletPointer3->moveRight();
		_bulletPointer4->moveRight();
		_bulletPointer5->moveRight();
		_bulletPointer6->moveRight();
		_bulletPointer7->moveRight();
	}
	
	if (numberOfTimesPlayerShot == 8) {
		_bulletPointer1->moveRight();
		_bulletPointer2->moveRight();
		_bulletPointer3->moveRight();
		_bulletPointer4->moveRight();
		_bulletPointer5->moveRight();
		_bulletPointer6->moveRight();
		_bulletPointer7->moveRight();
		_bulletPointer8->moveRight();
	}
	
	if (numberOfTimesPlayerShot == 9) {
		_bulletPointer1->moveRight();
		_bulletPointer2->moveRight();
		_bulletPointer3->moveRight();
		_bulletPointer4->moveRight();
		_bulletPointer5->moveRight();
		_bulletPointer6->moveRight();
		_bulletPointer7->moveRight();
		_bulletPointer8->moveRight();
		_bulletPointer9->moveRight();
	}
	
	if (numberOfTimesPlayerShot == 10) {
		_bulletPointer1->moveRight();
		_bulletPointer2->moveRight();
		_bulletPointer3->moveRight();
		_bulletPointer4->moveRight();
		_bulletPointer5->moveRight();
		_bulletPointer6->moveRight();
		_bulletPointer7->moveRight();
		_bulletPointer8->moveRight();
		_bulletPointer9->moveRight();
		_bulletPointer10->moveRight();
	}
}

bool Player::bulletDidCollideWithEnemy(int leftOfEnemy, int rightOfEnemy, int topOfEnemy, int bottomOfEnemy) {
	if (_bulletPointer1->didCollideWithEnemy(leftOfEnemy, rightOfEnemy, topOfEnemy, bottomOfEnemy)) {
		return true;
	}
	
	if (_bulletPointer2->didCollideWithEnemy(leftOfEnemy, rightOfEnemy, topOfEnemy, bottomOfEnemy)) {
		return true;
	}
	
	if (_bulletPointer3->didCollideWithEnemy(leftOfEnemy, rightOfEnemy, topOfEnemy, bottomOfEnemy)) {
		return true;
	}
	
	if (_bulletPointer4->didCollideWithEnemy(leftOfEnemy, rightOfEnemy, topOfEnemy, bottomOfEnemy)) {
		return true;
	}
	
	if (_bulletPointer5->didCollideWithEnemy(leftOfEnemy, rightOfEnemy, topOfEnemy, bottomOfEnemy)) {
		return true;
	}
	
	if (_bulletPointer6->didCollideWithEnemy(leftOfEnemy, rightOfEnemy, topOfEnemy, bottomOfEnemy)) {
		return true;
	}

	if (_bulletPointer7->didCollideWithEnemy(leftOfEnemy, rightOfEnemy, topOfEnemy, bottomOfEnemy)) {
		return true;
	}
	
	if (_bulletPointer8->didCollideWithEnemy(leftOfEnemy, rightOfEnemy, topOfEnemy, bottomOfEnemy)) {
		return true;
	}
	
	if (_bulletPointer9->didCollideWithEnemy(leftOfEnemy, rightOfEnemy, topOfEnemy, bottomOfEnemy)) {
		return true;
	}
	
	if (_bulletPointer10->didCollideWithEnemy(leftOfEnemy, rightOfEnemy, topOfEnemy, bottomOfEnemy)) {
		return true;
	}
	
	return false;
}

const char* Player::getNumberOfTimesPlayerHasShot() {
	if (numberOfTimesPlayerShot == 0) {
		return "10";
	}

	if (numberOfTimesPlayerShot == 1) {
		return "9";
	}
	
	if (numberOfTimesPlayerShot == 2) {
		return "8";
	}
	
	if (numberOfTimesPlayerShot == 3) {
		return "7";
	}
	
	if (numberOfTimesPlayerShot == 4) {
		return "6";
	}
	
	if (numberOfTimesPlayerShot == 5) {
		return "5";
	}
	
	if (numberOfTimesPlayerShot == 6) {
		return "4";
	}
	
	if (numberOfTimesPlayerShot == 7) {
		return "3";
	}
	
	if (numberOfTimesPlayerShot == 8) {
		return "2";
	}
	
	if (numberOfTimesPlayerShot == 9) {
		return "1";
	}
	
	return "0";
}

int Player::getXPos() {
	return _rect.x;
}

int Player::getYPos() {
	return _rect.y;
}

int Player::getWidth() {
	return _rect.w;
}

int Player::getHeight() {
	return _rect.h;
}

int Player::getPlayerHealth() {
	cout << "Player health: " << _health << endl;
	return _health;
}

int Player::getPlayerBulletDamage() {
	return playerBulletDamage;
}

void Player::renderPlayer(SDL_Renderer *playerRenderer) {
	SDL_SetRenderDrawColor(playerRenderer, _r, _g, _b, 0);
	SDL_RenderFillRect(playerRenderer, &_rect);
}