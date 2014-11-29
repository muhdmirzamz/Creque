//
//  Enemy.cpp
//  Creque
//
//  Created by Muhd Mirza on 22/11/14.
//  Copyright (c) 2014 Muhd Mirza. All rights reserved.
//

#include "Enemy.h"

static int numberOfTimesEnemyShot = 0;
static int enemyBulletDamage = 5;
static int bulletSpeed = -5;

Enemy::Enemy() {
	
}

void Enemy::setEnemyCoordinates(int x, int y) {
	_rect.x = x;
	_rect.y = y;
}

void Enemy::setEnemySize(int w, int h) {
	_rect.w = w;
	_rect.h = h;
}

void Enemy::setEnemyColour(int r, int g, int b) {
	_r = r;
	_g = g;
	_b = b;
}

void Enemy::setEnemyHealth() {
	_health = 50;
}

void Enemy::setBullet() {
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
	_bulletPointer1->setBulletDamage(enemyBulletDamage);
	
	_bulletPointer2->setBulletSize();
	_bulletPointer2->setBulletSpeed(bulletSpeed);
	_bulletPointer2->setBulletDamage(enemyBulletDamage);
	
	_bulletPointer3->setBulletSize();
	_bulletPointer3->setBulletSpeed(bulletSpeed);
	_bulletPointer3->setBulletDamage(enemyBulletDamage);
	
	_bulletPointer4->setBulletSize();
	_bulletPointer4->setBulletSpeed(bulletSpeed);
	_bulletPointer4->setBulletDamage(enemyBulletDamage);
	
	_bulletPointer5->setBulletSize();
	_bulletPointer5->setBulletSpeed(bulletSpeed);
	_bulletPointer5->setBulletDamage(enemyBulletDamage);
	
	_bulletPointer6->setBulletSize();
	_bulletPointer6->setBulletSpeed(bulletSpeed);
	_bulletPointer6->setBulletDamage(enemyBulletDamage);
	
	_bulletPointer7->setBulletSize();
	_bulletPointer7->setBulletSpeed(bulletSpeed);
	_bulletPointer7->setBulletDamage(enemyBulletDamage);
	
	_bulletPointer8->setBulletSize();
	_bulletPointer8->setBulletSpeed(bulletSpeed);
	_bulletPointer8->setBulletDamage(enemyBulletDamage);
	
	_bulletPointer9->setBulletSize();
	_bulletPointer9->setBulletSpeed(bulletSpeed);
	_bulletPointer9->setBulletDamage(enemyBulletDamage);
	
	_bulletPointer10->setBulletSize();
	_bulletPointer10->setBulletSpeed(bulletSpeed);
	_bulletPointer10->setBulletDamage(enemyBulletDamage);
}

void Enemy::loadBullet() {
	if (numberOfTimesEnemyShot <= 10) {
		numberOfTimesEnemyShot++;
		cout << "Enemy shot: " << numberOfTimesEnemyShot << endl;
	}
	
	if (numberOfTimesEnemyShot == 1) {
		_bulletPointer1->setBulletCoordinates(_rect.x + 1, _rect.y);
	}
	
	if (numberOfTimesEnemyShot == 2) {
		_bulletPointer2->setBulletCoordinates(_rect.x + 1, _rect.y);
	}
	
	if (numberOfTimesEnemyShot == 3) {
		_bulletPointer3->setBulletCoordinates(_rect.x + 1, _rect.y);
	}
	
	if (numberOfTimesEnemyShot == 4) {
		_bulletPointer4->setBulletCoordinates(_rect.x + 1, _rect.y);
	}
	
	if (numberOfTimesEnemyShot == 5) {
		_bulletPointer5->setBulletCoordinates(_rect.x + 1, _rect.y);
	}
	
	if (numberOfTimesEnemyShot == 6) {
		_bulletPointer6->setBulletCoordinates(_rect.x + 1, _rect.y);
	}
	
	if (numberOfTimesEnemyShot == 7) {
		_bulletPointer7->setBulletCoordinates(_rect.x + 1, _rect.y);
	}
	
	if (numberOfTimesEnemyShot == 8) {
		_bulletPointer8->setBulletCoordinates(_rect.x + 1, _rect.y);
	}
	
	if (numberOfTimesEnemyShot == 9) {
		_bulletPointer9->setBulletCoordinates(_rect.x + 1, _rect.y);
	}
	
	if (numberOfTimesEnemyShot == 10) {
		_bulletPointer10->setBulletCoordinates(_rect.x + 1, _rect.y);
	}
}

void Enemy::setSpeedX(int speed) {
	_speedX = speed;
}

void Enemy::setSpeedY(int speed) {
	_speedY = speed;
}

void Enemy::moveHorizontally() {
	_rect.x += _speedX;
}

void Enemy::moveVertically() {
	_rect.y += _speedY;
}

void Enemy::decreaseHealth(int playerBulletDamage) {
	_health -= playerBulletDamage;
}

void Enemy::shoot(SDL_Renderer *enemyRenderer) {
	if (numberOfTimesEnemyShot == 1) {
		_bulletPointer1->renderBullet(enemyRenderer);
	}
	
	if (numberOfTimesEnemyShot == 2) {
		_bulletPointer1->renderBullet(enemyRenderer);
		_bulletPointer2->renderBullet(enemyRenderer);
	}
	
	if (numberOfTimesEnemyShot == 3) {
		_bulletPointer1->renderBullet(enemyRenderer);
		_bulletPointer2->renderBullet(enemyRenderer);
		_bulletPointer3->renderBullet(enemyRenderer);
	}
	
	if (numberOfTimesEnemyShot == 4) {
		_bulletPointer1->renderBullet(enemyRenderer);
		_bulletPointer2->renderBullet(enemyRenderer);
		_bulletPointer3->renderBullet(enemyRenderer);
		_bulletPointer4->renderBullet(enemyRenderer);
	}
	
	if (numberOfTimesEnemyShot == 5) {
		_bulletPointer1->renderBullet(enemyRenderer);
		_bulletPointer2->renderBullet(enemyRenderer);
		_bulletPointer3->renderBullet(enemyRenderer);
		_bulletPointer4->renderBullet(enemyRenderer);
		_bulletPointer5->renderBullet(enemyRenderer);
	}
	
	if (numberOfTimesEnemyShot == 6) {
		_bulletPointer1->renderBullet(enemyRenderer);
		_bulletPointer2->renderBullet(enemyRenderer);
		_bulletPointer3->renderBullet(enemyRenderer);
		_bulletPointer4->renderBullet(enemyRenderer);
		_bulletPointer5->renderBullet(enemyRenderer);
		_bulletPointer6->renderBullet(enemyRenderer);
	}
	
	if (numberOfTimesEnemyShot == 7) {
		_bulletPointer1->renderBullet(enemyRenderer);
		_bulletPointer2->renderBullet(enemyRenderer);
		_bulletPointer3->renderBullet(enemyRenderer);
		_bulletPointer4->renderBullet(enemyRenderer);
		_bulletPointer5->renderBullet(enemyRenderer);
		_bulletPointer6->renderBullet(enemyRenderer);
		_bulletPointer7->renderBullet(enemyRenderer);
	}
	
	if (numberOfTimesEnemyShot == 8) {
		_bulletPointer1->renderBullet(enemyRenderer);
		_bulletPointer2->renderBullet(enemyRenderer);
		_bulletPointer3->renderBullet(enemyRenderer);
		_bulletPointer4->renderBullet(enemyRenderer);
		_bulletPointer5->renderBullet(enemyRenderer);
		_bulletPointer6->renderBullet(enemyRenderer);
		_bulletPointer7->renderBullet(enemyRenderer);
		_bulletPointer8->renderBullet(enemyRenderer);
	}
	
	if (numberOfTimesEnemyShot == 9) {
		_bulletPointer1->renderBullet(enemyRenderer);
		_bulletPointer2->renderBullet(enemyRenderer);
		_bulletPointer3->renderBullet(enemyRenderer);
		_bulletPointer4->renderBullet(enemyRenderer);
		_bulletPointer5->renderBullet(enemyRenderer);
		_bulletPointer6->renderBullet(enemyRenderer);
		_bulletPointer7->renderBullet(enemyRenderer);
		_bulletPointer8->renderBullet(enemyRenderer);
		_bulletPointer9->renderBullet(enemyRenderer);
	}
	
	if (numberOfTimesEnemyShot == 10) {
		_bulletPointer1->renderBullet(enemyRenderer);
		_bulletPointer2->renderBullet(enemyRenderer);
		_bulletPointer3->renderBullet(enemyRenderer);
		_bulletPointer4->renderBullet(enemyRenderer);
		_bulletPointer5->renderBullet(enemyRenderer);
		_bulletPointer6->renderBullet(enemyRenderer);
		_bulletPointer7->renderBullet(enemyRenderer);
		_bulletPointer8->renderBullet(enemyRenderer);
		_bulletPointer9->renderBullet(enemyRenderer);
		_bulletPointer10->renderBullet(enemyRenderer);
	}
}

void Enemy::moveBullet() {
	if (numberOfTimesEnemyShot == 1)
		_bulletPointer1->moveLeft();
	
	if (numberOfTimesEnemyShot == 2) {
		_bulletPointer1->moveLeft();
		_bulletPointer2->moveLeft();
	}
	
	if (numberOfTimesEnemyShot == 3) {
		_bulletPointer1->moveLeft();
		_bulletPointer2->moveLeft();
		_bulletPointer3->moveLeft();
	}
	
	if (numberOfTimesEnemyShot == 4) {
		_bulletPointer1->moveLeft();
		_bulletPointer2->moveLeft();
		_bulletPointer3->moveLeft();
		_bulletPointer4->moveLeft();
	}
	
	if (numberOfTimesEnemyShot == 5) {
		_bulletPointer1->moveLeft();
		_bulletPointer2->moveLeft();
		_bulletPointer3->moveLeft();
		_bulletPointer4->moveLeft();
		_bulletPointer5->moveLeft();
	}
	
	if (numberOfTimesEnemyShot == 6) {
		_bulletPointer1->moveLeft();
		_bulletPointer2->moveLeft();
		_bulletPointer3->moveLeft();
		_bulletPointer4->moveLeft();
		_bulletPointer5->moveLeft();
		_bulletPointer6->moveLeft();
	}
	
	if (numberOfTimesEnemyShot == 7) {
		_bulletPointer1->moveLeft();
		_bulletPointer2->moveLeft();
		_bulletPointer3->moveLeft();
		_bulletPointer4->moveLeft();
		_bulletPointer5->moveLeft();
		_bulletPointer6->moveLeft();
		_bulletPointer7->moveLeft();
	}
	
	if (numberOfTimesEnemyShot == 8) {
		_bulletPointer1->moveLeft();
		_bulletPointer2->moveLeft();
		_bulletPointer3->moveLeft();
		_bulletPointer4->moveLeft();
		_bulletPointer5->moveLeft();
		_bulletPointer6->moveLeft();
		_bulletPointer7->moveLeft();
		_bulletPointer8->moveLeft();
	}
	
	if (numberOfTimesEnemyShot == 9) {
		_bulletPointer1->moveLeft();
		_bulletPointer2->moveLeft();
		_bulletPointer3->moveLeft();
		_bulletPointer4->moveLeft();
		_bulletPointer5->moveLeft();
		_bulletPointer6->moveLeft();
		_bulletPointer7->moveLeft();
		_bulletPointer8->moveLeft();
		_bulletPointer9->moveLeft();
	}
	
	if (numberOfTimesEnemyShot == 10) {
		_bulletPointer1->moveLeft();
		_bulletPointer2->moveLeft();
		_bulletPointer3->moveLeft();
		_bulletPointer4->moveLeft();
		_bulletPointer5->moveLeft();
		_bulletPointer6->moveLeft();
		_bulletPointer7->moveLeft();
		_bulletPointer8->moveLeft();
		_bulletPointer9->moveLeft();
		_bulletPointer10->moveLeft();
	}
}

bool Enemy::bulletDidCollideWithPlayer(int rightOfPlayer, int leftOfPlayer, int topOfPlayer, int bottomOfPlayer) {
	if (_bulletPointer1->didCollideWithPlayer(rightOfPlayer, leftOfPlayer, topOfPlayer, bottomOfPlayer)) {
		return true;
	}

	if (_bulletPointer2->didCollideWithPlayer(rightOfPlayer, leftOfPlayer, topOfPlayer, bottomOfPlayer)) {
		return true;
	}
	
	if (_bulletPointer3->didCollideWithPlayer(rightOfPlayer, leftOfPlayer, topOfPlayer, bottomOfPlayer)) {
		return true;
	}
	
	if (_bulletPointer4->didCollideWithPlayer(rightOfPlayer, leftOfPlayer, topOfPlayer, bottomOfPlayer)) {
		return true;
	}
	
	if (_bulletPointer5->didCollideWithPlayer(rightOfPlayer, leftOfPlayer, topOfPlayer, bottomOfPlayer)) {
		return true;
	}
	
	if (_bulletPointer6->didCollideWithPlayer(rightOfPlayer, leftOfPlayer, topOfPlayer, bottomOfPlayer)) {
		return true;
	}
	
	if (_bulletPointer7->didCollideWithPlayer(rightOfPlayer, leftOfPlayer, topOfPlayer, bottomOfPlayer)) {
		return true;
	}
	
	if (_bulletPointer8->didCollideWithPlayer(rightOfPlayer, leftOfPlayer, topOfPlayer, bottomOfPlayer)) {
		return true;
	}
	
	if (_bulletPointer9->didCollideWithPlayer(rightOfPlayer, leftOfPlayer, topOfPlayer, bottomOfPlayer)) {
		return true;
	}
	
	if (_bulletPointer10->didCollideWithPlayer(rightOfPlayer, leftOfPlayer, topOfPlayer, bottomOfPlayer)) {
		return true;
	}
	
	return false;
}

const char* Enemy::getNumberOfTimesPlayerHasShot() {
	if (numberOfTimesEnemyShot == 0) {
		return "10";
	}
	
	if (numberOfTimesEnemyShot == 1) {
		return "9";
	}
	
	if (numberOfTimesEnemyShot == 2) {
		return "8";
	}
	
	if (numberOfTimesEnemyShot == 3) {
		return "7";
	}
	
	if (numberOfTimesEnemyShot == 4) {
		return "6";
	}
	
	if (numberOfTimesEnemyShot == 5) {
		return "5";
	}
	
	if (numberOfTimesEnemyShot == 6) {
		return "4";
	}
	
	if (numberOfTimesEnemyShot == 7) {
		return "3";
	}
	
	if (numberOfTimesEnemyShot == 8) {
		return "2";
	}
	
	if (numberOfTimesEnemyShot == 9) {
		return "1";
	}
	
	return "0";
}

int Enemy::getXPos() {
	return _rect.x;
}

int Enemy::getYPos() {
	return _rect.y;
}

int Enemy::getWidth() {
	return _rect.w;
}

int Enemy::getHeight() {
	return _rect.h;
}

int Enemy::getEnemyHealth() {
	cout << "Enemy health: " << _health << endl;
	return _health;
}

int Enemy::getEnemyBulletDamage() {
	return enemyBulletDamage;
}

void Enemy::renderEnemy(SDL_Renderer *enemyRenderer) {
	SDL_SetRenderDrawColor(enemyRenderer, _r, _g, _b, 0);
	SDL_RenderFillRect(enemyRenderer, &_rect);
}