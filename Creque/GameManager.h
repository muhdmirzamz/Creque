//
//  GameManager.h
//  Creque
//
//  Created by Muhd Mirza on 21/11/14.
//  Copyright (c) 2014 Muhd Mirza. All rights reserved.
//

#ifndef __Creque__GameManager__
#define __Creque__GameManager__

#include <iostream>

enum states {
	INTRO_SCENE,
	MAIN_MENU,
	CONTROLS,
	LEVEL,
	EXIT
};

using namespace std;

class GameManager {
	public:
		GameManager();
	
		void changeGameState(int state);

	private:
};

#endif /* defined(__Creque__GameManager__) */
