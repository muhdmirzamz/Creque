//
//  GameState.h
//  Creque
//
//  Created by Muhd Mirza on 21/11/14.
//  Copyright (c) 2014 Muhd Mirza. All rights reserved.
//

#ifndef __Creque__GameState__
#define __Creque__GameState__

#include <iostream>

#include "SDL_video.h"
#include "SDL_render.h"
#include "SDL_surface.h"
#include "SDL_events.h"

#include "SDL_ttf.h"

#include "GameManager.h"
#include "Background.h"
#include "Player.h"
#include "Enemy.h"
#include "Object.h"
#include "Font.h"

const int windowWidth = 640;
const int windowHeight = 480;
const int windowXPos = (windowWidth / 2);
const int windowYPos = (windowHeight / 2) - 50;

using namespace std;

class GameState {
	public:
		GameState();
		virtual ~GameState();
	
		void printComponentErrorMessage(string comp);
		void printStateErrorMessage(string state, string comp);
	
		int getWindowWidth();
		int getWindowHeight();
		int getWindowXPos();
		int getWindowYPos();
	
		virtual bool setWindow();
		virtual bool setRenderer();
		virtual void setRunning();

		void changeState(int state);
	
		// functions to be implemented
		virtual void initObjects();
		virtual void setObjects();
	
		virtual void run();
		virtual void handleEvents();
		virtual void moveSprite();
		virtual void checkCollision();
		virtual void render();
		virtual void update();
		virtual void cleanup();
	
	protected:
		SDL_Window *window;
		SDL_Renderer *renderer;
		SDL_Event event;
	
		bool running;
	
	private:
		GameManager *_gameManager;
};

#endif /* defined(__Creque__GameState__) */
