//
//  Enemy.h
//  Creque
//
//  Created by Muhd Mirza on 22/11/14.
//  Copyright (c) 2014 Muhd Mirza. All rights reserved.
//

#ifndef __Creque__Enemy__
#define __Creque__Enemy__

#include <iostream>

#include "SDL_render.h"

#include "Bullet.h"

using namespace std;

class Enemy {
	public:
		Enemy();
	
		void setEnemyCoordinates(int x, int y);
		void setEnemySize(int w, int h);
		void setEnemyColour(int r, int g, int b);
		void setEnemyHealth();
		void setBullet();
		void loadBullet();
	
		void setSpeedX(int speed);
		void setSpeedY(int speed);
		void moveHorizontally();
		void moveVertically();
	
		void decreaseHealth(int playerBulletDamage);
	
		void shoot(SDL_Renderer *enemyRenderer);
		void moveBullet();
	
		bool bulletDidCollideWithPlayer(int rightOfPlayer, int leftOfPlayer, int topOfPlayer, int bottomOfPlayer);
		
		const char* getNumberOfTimesPlayerHasShot();
		int getXPos();
		int getYPos();
		int getWidth();
		int getHeight();
	
		int getEnemyHealth();
		int getEnemyBulletDamage();
		
		void renderEnemy(SDL_Renderer *enemyRenderer);
	
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

#endif /* defined(__Creque__Enemy__) */
