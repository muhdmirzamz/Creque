//
//  Bullet.h
//  Creque
//
//  Created by Muhd Mirza on 22/11/14.
//  Copyright (c) 2014 Muhd Mirza. All rights reserved.
//

#ifndef __Creque__Bullet__
#define __Creque__Bullet__

#include <iostream>

#include "SDL_render.h"

using namespace std;

class Bullet {
	public:
		Bullet();
	
		void setBulletCoordinates(int x, int y);
		void setBulletSize();
		void setBulletSpeed(int speed);
		void setBulletDamage(int bulletDamage);
	
		void moveRight();
		void moveLeft();
	
		int getXPos();
		int getYPos();
		int getWidth();
		int getHeight();
	
		bool didCollideWithEnemy(int leftOfEnemy, int rightOfEnemy, int topOfEnemy, int bottomOfEnemy);
		bool didCollideWithPlayer(int rightOfPlayer, int leftOfPlayer, int topOfPlayer, int bottomOfPlayer);
	
		void renderBullet(SDL_Renderer *bulletRenderer);
	
	private:
		SDL_Rect _rect;
	
		int _speedX;
		int _damage;
};

#endif /* defined(__Creque__Bullet__) */
