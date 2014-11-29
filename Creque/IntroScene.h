//
//  IntroScene.h
//  Creque
//
//  Created by Muhd Mirza on 21/11/14.
//  Copyright (c) 2014 Muhd Mirza. All rights reserved.
//

#ifndef __Creque__IntroScene__
#define __Creque__IntroScene__

#include <iostream>

#include "GameState.h"

using namespace std;

class IntroScene: public GameState {
	public:
		IntroScene();
	
		void initObjects();
		void setObjects();
	
		void run();
		void handleEvents();
		void moveSprite();
		void checkCollision();
		void render();
		void update();
		void cleanup();

	private:
		Background _background;
		Background *_backgroundPointer;
	
		Object _object;
		Object *_objectPointer;
	
		Object _anotherObject;
		Object *_anotherObjectPointer;
};

#endif /* defined(__Creque__IntroScene__) */
