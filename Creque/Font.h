//
//  Font.h
//  Creque
//
//  Created by Muhd Mirza on 21/11/14.
//  Copyright (c) 2014 Muhd Mirza. All rights reserved.
//

#ifndef __Creque__Font__
#define __Creque__Font__

#include <iostream>

#include "SDL_render.h"
#include "SDL_surface.h"
#include "SDL_video.h"

#include "SDL_ttf.h"

using namespace std;

class Font {
	public:
		Font();
	
		void loadFont(const char *fontFile, int fontSize);
		void setFontColor(Uint8 r, Uint8 g, Uint8 b);
		void setFontCoordinates( int x, int y);
		void setFontSize(int w, int h);
		void transferFontToTexture(SDL_Renderer *fontRenderer, const char *fontText);
	
		int getFontRectangleXPos();
		int getFontRectangleYPos();
		int getFontRectangleWidth();
		int getFontRectangleHeight();
	
		void renderFont(SDL_Renderer *fontRenderer);
		void closeFont();
	
	private:
		TTF_Font *_font;
		SDL_Color _color;
	
		SDL_Surface *_surface;
		SDL_Texture *_texture;
		SDL_Rect _rect;
};

#endif /* defined(__Creque__Font__) */
