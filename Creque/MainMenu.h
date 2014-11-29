//
//  MainMenu.h
//  Creque
//
//  Created by Muhd Mirza on 21/11/14.
//  Copyright (c) 2014 Muhd Mirza. All rights reserved.
//

#ifndef __Creque__MainMenu__
#define __Creque__MainMenu__

#include <iostream>

#include "GameState.h"

using namespace std;

class MainMenu: public GameState {
	public:
		MainMenu();
	
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
	
		Font _gameTitle;
		Font *_gameTitlePointer;
	
		Font _gameBegin;
		Font *_gameBeginPointer;
	
		Font _gameBeginHover;
		Font *_gameBeginHoverPointer;
	
		bool _isGameBeginOnHovered;
};

#endif /* defined(__Creque__MainMenu__) */
