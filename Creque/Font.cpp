//
//  Font.cpp
//  Creque
//
//  Created by Muhd Mirza on 21/11/14.
//  Copyright (c) 2014 Muhd Mirza. All rights reserved.
//

#include "Font.h"

Font::Font() {

}

void Font::loadFont(const char *fontFile, int fontSize) {
	_font = TTF_OpenFont(fontFile, fontSize);
	if (!_font) {
		cout << "Font failed to initialise!\n";
	}
}

void Font::setFontColor(Uint8 r, Uint8 g, Uint8 b) {
	_color.r = r;
	_color.g = g;
	_color.b = b;
}

void Font::setFontCoordinates( int x, int y) {
	_rect.x = x;
	_rect.y = y;
}

void Font::setFontSize(int w, int h) {
	_rect.w = w;
	_rect.h = h;
}

void Font::transferFontToTexture(SDL_Renderer *fontRenderer, const char *fontText) {
	_surface = TTF_RenderText_Solid(_font, fontText, _color);
	
	if (!_surface) {
		cout << "Font surface failed to initialise!\n";
	}
	
	_texture = SDL_CreateTextureFromSurface(fontRenderer, _surface);
	
	SDL_FreeSurface(_surface);
}

int Font::getFontRectangleXPos() {
	return _rect.x;
}

int Font::getFontRectangleYPos() {
	return _rect.y;
}

int Font::getFontRectangleWidth() {
	return _rect.w;
}

int Font::getFontRectangleHeight() {
	return _rect.h;
}

void Font::renderFont(SDL_Renderer *fontRenderer) {
	SDL_RenderCopy(fontRenderer, _texture, NULL, &_rect);
}

void Font::closeFont() {
	TTF_CloseFont(_font);
}