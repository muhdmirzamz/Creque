//
//  Background.h
//  Creque
//
//  Created by Muhd Mirza on 21/11/14.
//  Copyright (c) 2014 Muhd Mirza. All rights reserved.
//

#ifndef __Creque__Background__
#define __Creque__Background__

#include <iostream>

#include "SDL_render.h"

using namespace std;

class Background {
	public:
		Background();
	
		void setBackgroundColor(int r, int g, int b);
		void renderBackground(SDL_Renderer *backgroundRenderer);
	
	private:
		int _r;
		int _g;
		int _b;
};

#endif /* defined(__Creque__Background__) */
