//
//  Controls.h
//  Creque
//
//  Created by Muhd Mirza on 23/11/14.
//  Copyright (c) 2014 Muhd Mirza. All rights reserved.
//

#ifndef __Creque__Controls__
#define __Creque__Controls__

#include <iostream>

#include "SDL_render.h"

#include "GameState.h"

using namespace std;

class Controls: public GameState {
	public:
		Controls();
	
		void initObjects();
		void setObjects();
		
		void run();
		void handleEvents();
		void render();
		void update();
		void cleanup();
	
	private:
		Background _background;
		Background *_backgroundPointer;
	
		Font _moveLeft;
		Font *_moveLeftPointer;
	
		Font _moveRight;
		Font *_moveRightPointer;
		
		Font _moveUp;
		Font *_moveUpPointer;
		
		Font _moveDown;
		Font *_moveDownPointer;
	
		Font _shoot;
		Font *_shootPointer;
	
		Font _clickToContinue;
		Font *_clickToContinuePointer;
};

#endif /* defined(__Creque__Controls__) */
