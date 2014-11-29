//
//  Bullet.cpp
//  Creque
//
//  Created by Muhd Mirza on 22/11/14.
//  Copyright (c) 2014 Muhd Mirza. All rights reserved.
//

#include "Bullet.h"

Bullet::Bullet() {
	
}

void Bullet::setBulletCoordinates(int x, int y) {
	_rect.x = x;
	_rect.y = y;
}

void Bullet::setBulletSize() {
	_rect.w = 10;
	_rect.h = 5;
}

void Bullet::setBulletSpeed(int speed) {
	_speedX = speed;
}

void Bullet::setBulletDamage(int bulletDamage) {
	_damage = bulletDamage;
}

void Bullet::moveRight() {
	_rect.x += _speedX;
}

void Bullet::moveLeft() {
	_rect.x += _speedX;
}

int Bullet::getXPos() {
	return _rect.x;
}

int Bullet::getYPos() {
	return _rect.y;
}

int Bullet::getWidth() {
	return _rect.w;
}

int Bullet::getHeight() {
	return _rect.h;
}

bool Bullet::didCollideWithEnemy(int leftOfEnemy, int rightOfEnemy, int topOfEnemy, int bottomOfEnemy) {
	if (_rect.x + _rect.w >= leftOfEnemy && _rect.x <= rightOfEnemy) {
		if (_rect.y + _rect.h >= topOfEnemy && _rect.y <= bottomOfEnemy) {
			return true;
		}
	}
	
	return false;
}

bool Bullet::didCollideWithPlayer(int rightOfPlayer, int leftOfPlayer, int topOfPlayer, int bottomOfPlayer) {
	if (_rect.x <= rightOfPlayer && _rect.x + _rect.w <= leftOfPlayer) {
		if (_rect.y + _rect.h >= topOfPlayer && _rect.y <= bottomOfPlayer) {
			return true;
		}
	}
	
	return false;
}

void Bullet::renderBullet(SDL_Renderer *bulletRenderer) {
	SDL_SetRenderDrawColor(bulletRenderer, 200, 0, 0, 0);
	SDL_RenderFillRect(bulletRenderer, &_rect);
}