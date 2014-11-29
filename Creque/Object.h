//
//  Object.h
//  Creque
//
//  Created by Muhd Mirza on 22/11/14.
//  Copyright (c) 2014 Muhd Mirza. All rights reserved.
//

#ifndef __Creque__Object__
#define __Creque__Object__

#include <iostream>

#include "SDL_render.h"

using namespace std;

class Object {
	public:
		Object();
	
		void setObjectCoordinates(int x, int y);
		void setObjectSize(int w, int h);
		void setObjectColour(int r, int g, int b);
		void setSpeed(int speed);
	
		void move();
		
		bool didCollideWithRightOfWindow(int windowWidth);
		bool didCollideWithLeftOfWindow();
		bool didCollideWithTopOfWindow();
		bool didCollideWithBottomOfWindow(int windowHeight);
	
		bool didCollideWithObject(Object *object);
	
		int getXPos();
		int getYPos();
		int getWidth();
		int getHeight();
	
		void renderObject(SDL_Renderer *objectRenderer);
	
	private:
		SDL_Rect _rect;
		int _speed;
	
		int _r;
		int _g;
		int _b;
};


#endif /* defined(__Creque__Object__) */
