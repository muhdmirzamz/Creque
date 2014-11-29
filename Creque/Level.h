//
//  Level.h
//  Creque
//
//  Created by Muhd Mirza on 22/11/14.
//  Copyright (c) 2014 Muhd Mirza. All rights reserved.
//

#ifndef __Creque__Level__
#define __Creque__Level__

#include <iostream>

#include "GameState.h"

using namespace std;

class Level: public GameState {
	public:
		Level();
	
		void initObjects();
		void setObjects();
	
		void run();
		void handleEvents();
		void loadEnemyBullet();
		void moveSprite();
		void checkCollision();
		void render();
		void update();
		void cleanup();
	
	private:
		Background _background;
		Background *_backgroundPointer;
	
		Player _player;
		Player *_playerPointer;
	
		Enemy _enemy;
		Enemy *_enemyPointer;
	
		bool _isPlayerShooting;
		int _randomNum;
		int _randomNum2;
	
		Font _bulletsRemainingWords;
		Font *_bulletsRemainingWordsPointer;
	
		Font _bulletsRemaining;
		Font *_bulletsRemainingPointer;
};

#endif /* defined(__Creque__Level__) */
