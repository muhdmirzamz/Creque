CXX=g++

SDL_FRAMEWORK=-F./ -framework SDL2
SDL_INCLUDES=-I./SDL2.framework/Versions/A/Headers

SDL_TTF_FRAMEWORK=-F./ -framework SDL2_ttf
SDL_TTF_INCLUDES=-I./SDL2_ttf.framework/Versions/A/Headers

CFLAGS=-Wall -c  $(SDL_INCLUDES) $(SDL_TTF_INCLUDES)
LFLAGS=-Wall $(SDL_FRAMEWORK) $(SDL_TTF_FRAMEWORK) -o 

VPATH=Creque

CrequeGame: main.o GameManager.o GameState.o Background.o Object.o Font.o Player.o Enemy.o Bullet.o IntroScene.o MainMenu.o Controls.o Level.o
	$(CXX) $(LFLAGS) $@ $^
	install_name_tool -change @rpath/SDL2.framework/Versions/A/SDL2 @loader_path/SDL2.framework/Versions/A/SDL2 CrequeGame
	install_name_tool -change @rpath/SDL2_ttf.framework/Versions/A/SDL2_ttf @loader_path/SDL2_ttf.framework/Versions/A/SDL2_ttf CrequeGame

Level.o: Level.cpp
	$(CXX) $(CFLAGS) $^

Controls.o: Controls.cpp
	$(CXX) $(CFLAGS) $^

MainMenu.o: MainMenu.cpp
	$(CXX) $(CFLAGS) $^

IntroScene.o: IntroScene.cpp
	$(CXX) $(CFLAGS) $^

Bullet.o: Bullet.cpp
	$(CXX) $(CFLAGS) $^

Enemy.o: Enemy.cpp
	$(CXX) $(CFLAGS) $^

Player.o: Player.cpp
	$(CXX) $(CFLAGS) $^

Font.o: Font.cpp
	$(CXX) $(CFLAGS) $^

Object.o: Object.cpp
	$(CXX) $(CFLAGS) $^

Background.o: Background.cpp
	$(CXX) $(CFLAGS) $^

GameState.o: GameState.cpp
	$(CXX) $(CFLAGS) $^

GameManager.o: GameManager.cpp
	$(CXX) $(CFLAGS) $^

main.o: main.cpp
	$(CXX) $(CFLAGS) $^

clean:
	rm -rf *.o
