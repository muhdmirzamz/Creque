//
//  Player.h
//  Creque
//
//  Created by Muhd Mirza on 21/11/14.
//  Copyright (c) 2014 Muhd Mirza. All rights reserved.
//

#ifndef __Creque__Player__
#define __Creque__Player__

#include <iostream>

#include "SDL_render.h"

#include "Bullet.h"

using namespace std;

class Player {
	public:
		Player();
	
		void setPlayerCoordinates(int x, int y);
		void setPlayerSize(int w, int h);
		void setPlayerColour(int r, int g, int b);
		void setPlayerHealth();
		void setBullet();
		void loadBullet();
	
		void moveLeft();
		void moveRight();
		void moveUp();
		void moveDown();
	
		void decreaseHealth(int enemyBulletDamage);
	
		void shoot(SDL_Renderer *playerRenderer);
		void moveBullet();
	
		bool bulletDidCollideWithEnemy(int leftOfEnemy, int rightOfEnemy, int topOfEnemy, int bottomOfEnemy);
	
		const char* getNumberOfTimesPlayerHasShot();
		int getXPos();
		int getYPos();
		int getWidth();
		int getHeight();
	
		int getPlayerHealth();
		int getPlayerBulletDamage();
	
		void renderPlayer(SDL_Renderer *playerRenderer);
	
	private:
		SDL_Rect _rect;
	
		int _health;
	
		int _r;
		int _g;
		int _b;
	
		int _speedX;
		int _speedY;
	
		Bullet _bullet1;
		Bullet *_bulletPointer1;
		
		Bullet _bullet2;
		Bullet *_bulletPointer2;
	
		Bullet _bullet3;
		Bullet *_bulletPointer3;
	
		Bullet _bullet4;
		Bullet *_bulletPointer4;
	
		Bullet _bullet5;
		Bullet *_bulletPointer5;
	
		Bullet _bullet6;
		Bullet *_bulletPointer6;
	
		Bullet _bullet7;
		Bullet *_bulletPointer7;
	
		Bullet _bullet8;
		Bullet *_bulletPointer8;
	
		Bullet _bullet9;
		Bullet *_bulletPointer9;
	
		Bullet _bullet10;
		Bullet *_bulletPointer10;
};

#endif /* defined(__Creque__Player__) */
