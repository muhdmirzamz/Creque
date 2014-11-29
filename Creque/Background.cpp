//
//  Background.cpp
//  Creque
//
//  Created by Muhd Mirza on 21/11/14.
//  Copyright (c) 2014 Muhd Mirza. All rights reserved.
//

#include "Background.h"

Background::Background() {
	
}

void Background::setBackgroundColor(int r, int g, int b) {
	_r = r;
	_g = g;
	_b = b;
}

void Background::renderBackground(SDL_Renderer *backgroundRenderer) {
	SDL_SetRenderDrawColor(backgroundRenderer, _r, _g, _b, 0);
	SDL_RenderClear(backgroundRenderer);
}