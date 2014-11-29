//
//  GameManager.cpp
//  Creque
//
//  Created by Muhd Mirza on 21/11/14.
//  Copyright (c) 2014 Muhd Mirza. All rights reserved.
//

#include "GameManager.h"
#include "GameState.h"

#include "IntroScene.h"
#include "MainMenu.h"
#include "Controls.h"
#include "Level.h"

GameManager::GameManager() {
	
}

void GameManager::changeGameState(int state) {
	switch (state) {
		case INTRO_SCENE: {
			IntroScene introScene;
			GameState *introScenePointer = &introScene;
			introScenePointer->run();
			break;
		}
		
		case MAIN_MENU: {
			MainMenu mainMenu;
			GameState *mainMenuPointer = &mainMenu;
			mainMenuPointer->run();
			break;
		}
		
		case CONTROLS: {
			Controls controls;
			GameState *controlsPointer = &controls;
			controlsPointer->run();
			break;
		}
		
		case LEVEL: {
			Level level;
			GameState *levelPointer = &level;
			levelPointer->run();
			break;
		}
		
		case EXIT: {
			cout << "Exiting..";
			break;
		}
		
	  default:
			break;
	}
}