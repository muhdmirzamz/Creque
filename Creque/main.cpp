//
//  main.cpp
//  Creque
//
//  Created by Muhd Mirza on 20/11/14.
//  Copyright (c) 2014 Muhd Mirza. All rights reserved.
//

#include <iostream>

#include "SDL.h"
#include "SDL_ttf.h"

#include "GameManager.h"

using namespace std;

bool initSDL() {
	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
		return false;
	}
	
	return true;
}

bool initSDLTTF() {
	if (TTF_Init() == -1) {
		return false;
	}
	
	return true;
}

int main(int argc, const char * argv[]) {
	// TODO: Optimise the game
	//       Fix bullets
	// so far, playable
	if (!initSDL()) {
		cout << "SDL could not initialise!\n";
	}
	
	if (!initSDLTTF()) {
		cout << "SDL TTF could not initialise!\n";
	}
	
	GameManager *gameManager = new GameManager();
	gameManager->changeGameState(INTRO_SCENE);
	delete gameManager;
	gameManager = NULL;
	
	TTF_Quit();
	SDL_Quit();
	
    return 0;
}
