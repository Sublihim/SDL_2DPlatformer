ifeq ($(OS),Windows_NT)
WORKDIR = `echo %cd%`
else
WORKDIR = `pwd`
endif

EXEC_FILE_NAME = SDL_2DPlatformer

ifeq ($(OS),Windows_NT)
PATH_DELIM = \\

MINGW_BIN_PATH = C:\\MinGW\\MinGW\\bin

SDL2_INC_PARAM = -IC:\SDL\SDL2-2.0.8\i686-w64-mingw32\include -IC:\SDL\SDL2_ttf-2.0.14\i686-w64-mingw32\include -IC:\SDL\SDL2_mixer-2.0.2\i686-w64-mingw32\include -IC:\SDL\SDL2_image-2.0.3\i686-w64-mingw32\include
SDL2_LIB_PARAM = -LC:\SDL\SDL2-2.0.8\i686-w64-mingw32\lib -LC:\SDL\SDL2_ttf-2.0.14\i686-w64-mingw32\lib -LC:\SDL\SDL2_mixer-2.0.2\x86_64-w64-mingw32\lib -LC:\SDL\SDL2_image-2.0.3\i686-w64-mingw32\lib

CC = $(MINGW_BIN_PATH)\\gcc.exe
CXX = $(MINGW_BIN_PATH)\\g++.exe

AR = $(MINGW_BIN_PATH)\\ar.exe
LD = $(MINGW_BIN_PATH)\\g++.exe
WINDRES = $(MINGW_BIN_PATH)\\windres.exe
else
PATH_DELIM = /
CC = gcc
CXX = g++
AR = ar
LD = g++
WINDRES = windres
endif

INC =
CFLAGS = -Wall -fexceptions
RESINC =
LIBDIR =
LIB =
LDFLAGS =

ifeq ($(OS),Windows_NT)
INC_DEBUG = $(INC) $(SDL2_INC_PARAM)
else
INC_DEBUG = $(INC)
endif
CFLAGS_DEBUG = $(CFLAGS) -g
RESINC_DEBUG = $(RESINC)
RCFLAGS_DEBUG = $(RCFLAGS)
LIBDIR_DEBUG = $(LIBDIR)
LIB_DEBUG = $(LIB)
ifeq ($(OS),Windows_NT)
LDFLAGS_DEBUG = $(LDFLAGS) $(SDL2_LIB_PARAM) -lmingw32 -lSDL2main -lSDL2 -lSDL2_ttf -lSDL2_mixer -lSDL2_image
else
LDFLAGS_DEBUG = $(LDFLAGS) -lSDL2 -lSDL2_ttf -lSDL2_mixer -lSDL2_image
endif

ifeq ($(OS),Windows_NT)
OBJDIR_DEBUG = obj\\Debug
DEP_DEBUG =
OUT_DEBUG = bin\\Debug\\$(EXEC_FILE_NAME).exe
else
OBJDIR_DEBUG = obj/Debug
DEP_DEBUG =
OUT_DEBUG = bin/Debug/$(EXEC_FILE_NAME)
endif

ifeq ($(OS),Windows_NT)
INC_RELEASE = $(INC) $(SDL2_INC_PARAM)
else
INC_RELEASE = $(INC)
endif
CFLAGS_RELEASE = $(CFLAGS) -O2
RESINC_RELEASE = $(RESINC)
RCFLAGS_RELEASE = $(RCFLAGS)
LIBDIR_RELEASE = $(LIBDIR)
LIB_RELEASE = $(LIB)
ifeq ($(OS),Windows_NT)
LDFLAGS_RELEASE = $(LDFLAGS) $(SDL2_LIB_PARAM) -lmingw32 -lSDL2main -lSDL2 -lSDL2_ttf -lSDL2_mixer -lSDL2_image
else
LDFLAGS_RELEASE = $(LDFLAGS) -lSDL2 -lSDL2_ttf -lSDL2_mixer -lSDL2_image
endif

ifeq ($(OS),Windows_NT)
OBJDIR_RELEASE = obj\\Release
DEP_RELEASE =
OUT_RELEASE = bin\\Release\\$(EXEC_FILE_NAME).exe
else
OBJDIR_RELEASE = obj/Release
DEP_RELEASE =
OUT_RELEASE = bin/Release/$(EXEC_FILE_NAME)
endif

OBJ_DEBUG = $(OBJDIR_DEBUG)$(PATH_DELIM)SDL_Game.o $(OBJDIR_DEBUG)$(PATH_DELIM)Scene.o $(OBJDIR_DEBUG)$(PATH_DELIM)nZSceneGame.o $(OBJDIR_DEBUG)$(PATH_DELIM)SceneGame.o $(OBJDIR_DEBUG)$(PATH_DELIM)SceneMenu.o $(OBJDIR_DEBUG)$(PATH_DELIM)SceneMenuPause.o $(OBJDIR_DEBUG)$(PATH_DELIM)SceneMgr.o $(OBJDIR_DEBUG)$(PATH_DELIM)main.o $(OBJDIR_DEBUG)$(PATH_DELIM)Button.o $(OBJDIR_DEBUG)$(PATH_DELIM)FontMgr.o $(OBJDIR_DEBUG)$(PATH_DELIM)GameObject.o $(OBJDIR_DEBUG)$(PATH_DELIM)GameObjectMgr.o $(OBJDIR_DEBUG)$(PATH_DELIM)MainHero.o $(OBJDIR_DEBUG)$(PATH_DELIM)MainHeroMgr.o $(OBJDIR_DEBUG)$(PATH_DELIM)TextureMgr.o $(OBJDIR_DEBUG)$(PATH_DELIM)GravityPowerMgr.o $(OBJDIR_DEBUG)$(PATH_DELIM)SimpleTextureMgr.o $(OBJDIR_DEBUG)$(PATH_DELIM)LangMgr.o $(OBJDIR_DEBUG)$(PATH_DELIM)nZMainHeroManager.o

OBJ_RELEASE = $(OBJDIR_RELEASE)$(PATH_DELIM)SDL_Game.o $(OBJDIR_RELEASE)$(PATH_DELIM)Scene.o $(OBJDIR_RELEASE)$(PATH_DELIM)nZSceneGame.o $(OBJDIR_RELEASE)$(PATH_DELIM)SceneGame.o $(OBJDIR_RELEASE)$(PATH_DELIM)SceneMenu.o $(OBJDIR_RELEASE)$(PATH_DELIM)SceneMenuPause.o $(OBJDIR_RELEASE)$(PATH_DELIM)SceneMgr.o $(OBJDIR_RELEASE)$(PATH_DELIM)main.o $(OBJDIR_RELEASE)$(PATH_DELIM)Button.o $(OBJDIR_RELEASE)$(PATH_DELIM)FontMgr.o $(OBJDIR_RELEASE)$(PATH_DELIM)GameObject.o $(OBJDIR_RELEASE)$(PATH_DELIM)GameObjectMgr.o $(OBJDIR_RELEASE)$(PATH_DELIM)MainHero.o $(OBJDIR_RELEASE)$(PATH_DELIM)MainHeroMgr.o $(OBJDIR_RELEASE)$(PATH_DELIM)TextureMgr.o $(OBJDIR_RELEASE)$(PATH_DELIM)GravityPowerMgr.o $(OBJDIR_RELEASE)$(PATH_DELIM)SimpleTextureMgr.o $(OBJDIR_RELEASE)$(PATH_DELIM)LangMgr.o $(OBJDIR_RELEASE)$(PATH_DELIM)nZMainHeroManager.o

all: debug release

clean: clean_debug clean_release

before_debug:
ifeq ($(OS),Windows_NT)
	if not exist bin\\Debug\\*.* mkdir bin\\Debug
	if not exist $(OBJDIR_DEBUG)\\*.* mkdir $(OBJDIR_DEBUG)
else
	test -d bin/Debug || mkdir -p bin/Debug
	test -d $(OBJDIR_DEBUG) || mkdir -p $(OBJDIR_DEBUG)
endif

after_debug:
ifeq ($(OS),Windows_NT)
	xcopy /E /Y assets bin\\Debug\\assets\\
	xcopy /E /Y lang bin\\Debug\\lang\\
else
	cp -rf assets bin/Debug
	cp -rf lang bin/Debug
endif

debug: before_debug out_debug after_debug

out_debug: before_debug $(OBJ_DEBUG) $(DEP_DEBUG)
	$(LD) $(LIBDIR_DEBUG) -o $(OUT_DEBUG) $(OBJ_DEBUG)  $(LDFLAGS_DEBUG) $(LIB_DEBUG)

$(OBJDIR_DEBUG)$(PATH_DELIM)SDL_Game.o: SDL_Game.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c SDL_Game.cpp -o $(OBJDIR_DEBUG)$(PATH_DELIM)SDL_Game.o

$(OBJDIR_DEBUG)$(PATH_DELIM)Scene.o: Scene.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c Scene.cpp -o $(OBJDIR_DEBUG)$(PATH_DELIM)Scene.o

$(OBJDIR_DEBUG)$(PATH_DELIM)SceneGame.o: SceneGame.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c SceneGame.cpp -o $(OBJDIR_DEBUG)$(PATH_DELIM)SceneGame.o

$(OBJDIR_DEBUG)$(PATH_DELIM)SimpleTextureMgr.o: SimpleTextureMgr.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c SimpleTextureMgr.cpp -o $(OBJDIR_DEBUG)$(PATH_DELIM)SimpleTextureMgr.o

$(OBJDIR_DEBUG)$(PATH_DELIM)nZSceneGame.o: nZSceneGame.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c nZSceneGame.cpp -o $(OBJDIR_DEBUG)$(PATH_DELIM)nZSceneGame.o

$(OBJDIR_DEBUG)$(PATH_DELIM)nZMainHeroManager.o: nZMainHeroManager.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c nZMainHeroManager.cpp -o $(OBJDIR_DEBUG)$(PATH_DELIM)nZMainHeroManager.o

$(OBJDIR_DEBUG)$(PATH_DELIM)SceneMenu.o: SceneMenu.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c SceneMenu.cpp -o $(OBJDIR_DEBUG)$(PATH_DELIM)SceneMenu.o

$(OBJDIR_DEBUG)$(PATH_DELIM)SceneMenuPause.o: SceneMenuPause.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c SceneMenuPause.cpp -o $(OBJDIR_DEBUG)$(PATH_DELIM)SceneMenuPause.o

$(OBJDIR_DEBUG)$(PATH_DELIM)SceneMgr.o: SceneMgr.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c SceneMgr.cpp -o $(OBJDIR_DEBUG)$(PATH_DELIM)SceneMgr.o

$(OBJDIR_DEBUG)$(PATH_DELIM)main.o: main.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c main.cpp -o $(OBJDIR_DEBUG)$(PATH_DELIM)main.o

$(OBJDIR_DEBUG)$(PATH_DELIM)Button.o: ui/Button.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c ui/Button.cpp -o $(OBJDIR_DEBUG)$(PATH_DELIM)Button.o

$(OBJDIR_DEBUG)$(PATH_DELIM)FontMgr.o: ui/FontMgr.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c ui/FontMgr.cpp -o $(OBJDIR_DEBUG)$(PATH_DELIM)FontMgr.o

$(OBJDIR_DEBUG)$(PATH_DELIM)GameObject.o: GameObject.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c GameObject.cpp -o $(OBJDIR_DEBUG)$(PATH_DELIM)GameObject.o

$(OBJDIR_DEBUG)$(PATH_DELIM)GameObjectMgr.o: GameObjectMgr.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c GameObjectMgr.cpp -o $(OBJDIR_DEBUG)$(PATH_DELIM)GameObjectMgr.o

$(OBJDIR_DEBUG)$(PATH_DELIM)MainHero.o: MainHero.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c MainHero.cpp -o $(OBJDIR_DEBUG)$(PATH_DELIM)MainHero.o

$(OBJDIR_DEBUG)$(PATH_DELIM)MainHeroMgr.o: MainHeroMgr.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c MainHeroMgr.cpp -o $(OBJDIR_DEBUG)$(PATH_DELIM)MainHeroMgr.o

$(OBJDIR_DEBUG)$(PATH_DELIM)TextureMgr.o: TextureMgr.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c TextureMgr.cpp -o $(OBJDIR_DEBUG)$(PATH_DELIM)TextureMgr.o

$(OBJDIR_DEBUG)$(PATH_DELIM)GravityPowerMgr.o: GravityPowerMgr.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c GravityPowerMgr.cpp -o $(OBJDIR_DEBUG)$(PATH_DELIM)GravityPowerMgr.o

$(OBJDIR_DEBUG)$(PATH_DELIM)LangMgr.o: LangMgr.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c LangMgr.cpp -o $(OBJDIR_DEBUG)$(PATH_DELIM)LangMgr.o


clean_debug:
ifeq ($(OS),Windows_NT)
	del /Q /F $(OBJ_DEBUG) $(OUT_DEBUG)
	rmdir /S /Q bin\\Debug
	rmdir /S /Q $(OBJDIR_DEBUG)
else
	rm -f $(OBJ_DEBUG) $(OUT_DEBUG)
	rm -rf bin/Debug
	rm -rf $(OBJDIR_DEBUG)
endif

before_release:
ifeq ($(OS),Windows_NT)
	if not exist bin\\Release\\*.* mkdir bin\\Release
	if not exist $(OBJDIR_RELEASE)\\*.* mkdir $(OBJDIR_RELEASE)
else
	test -d bin/Release || mkdir -p bin/Release
	test -d $(OBJDIR_RELEASE) || mkdir -p $(OBJDIR_RELEASE)
endif

after_release:
ifeq ($(OS),Windows_NT)
	xcopy /E /Y assets bin\\Release\\assets\\
	xcopy /E /Y lang bin\\Release\\lang\\
else
	cp -rf assets bin/Release
	cp -rf lang bin/Release
endif

release: before_release out_release after_release

out_release: before_release $(OBJ_RELEASE) $(DEP_RELEASE)
	$(LD) $(LIBDIR_RELEASE) -o $(OUT_RELEASE) $(OBJ_RELEASE)  $(LDFLAGS_RELEASE) $(LIB_RELEASE)

$(OBJDIR_RELEASE)$(PATH_DELIM)SDL_Game.o: SDL_Game.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c SDL_Game.cpp -o $(OBJDIR_RELEASE)$(PATH_DELIM)SDL_Game.o

$(OBJDIR_RELEASE)$(PATH_DELIM)Scene.o: Scene.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c Scene.cpp -o $(OBJDIR_RELEASE)$(PATH_DELIM)Scene.o

$(OBJDIR_RELEASE)$(PATH_DELIM)SceneGame.o: SceneGame.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c SceneGame.cpp -o $(OBJDIR_RELEASE)$(PATH_DELIM)SceneGame.o

$(OBJDIR_RELEASE)$(PATH_DELIM)SimpleTextureMgr.o: SimpleTextureMgr.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c SimpleTextureMgr.cpp -o $(OBJDIR_RELEASE)$(PATH_DELIM)SimpleTextureMgr.o

$(OBJDIR_RELEASE)$(PATH_DELIM)nZSceneGame.o: nZSceneGame.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c nZSceneGame.cpp -o $(OBJDIR_RELEASE)$(PATH_DELIM)nZSceneGame.o

$(OBJDIR_RELEASE)$(PATH_DELIM)nZMainHeroManager.o: nZMainHeroManager.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c nZMainHeroManager.cpp -o $(OBJDIR_RELEASE)$(PATH_DELIM)nZMainHeroManager.o

$(OBJDIR_RELEASE)$(PATH_DELIM)SceneMenu.o: SceneMenu.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c SceneMenu.cpp -o $(OBJDIR_RELEASE)$(PATH_DELIM)SceneMenu.o

$(OBJDIR_RELEASE)$(PATH_DELIM)SceneMenuPause.o: SceneMenuPause.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c SceneMenuPause.cpp -o $(OBJDIR_RELEASE)$(PATH_DELIM)SceneMenuPause.o

$(OBJDIR_RELEASE)$(PATH_DELIM)SceneMgr.o: SceneMgr.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c SceneMgr.cpp -o $(OBJDIR_RELEASE)$(PATH_DELIM)SceneMgr.o

$(OBJDIR_RELEASE)$(PATH_DELIM)main.o: main.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c main.cpp -o $(OBJDIR_RELEASE)$(PATH_DELIM)main.o

$(OBJDIR_RELEASE)$(PATH_DELIM)Button.o: ui/Button.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c ui/Button.cpp -o $(OBJDIR_RELEASE)$(PATH_DELIM)Button.o

$(OBJDIR_RELEASE)$(PATH_DELIM)FontMgr.o: ui/FontMgr.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c ui/FontMgr.cpp -o $(OBJDIR_RELEASE)$(PATH_DELIM)FontMgr.o

$(OBJDIR_RELEASE)$(PATH_DELIM)GameObject.o: GameObject.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c GameObject.cpp -o $(OBJDIR_RELEASE)$(PATH_DELIM)GameObject.o

$(OBJDIR_RELEASE)$(PATH_DELIM)GameObjectMgr.o: GameObjectMgr.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c GameObjectMgr.cpp -o $(OBJDIR_RELEASE)$(PATH_DELIM)GameObjectMgr.o

$(OBJDIR_RELEASE)$(PATH_DELIM)MainHero.o: MainHero.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c MainHero.cpp -o $(OBJDIR_RELEASE)$(PATH_DELIM)MainHero.o

$(OBJDIR_RELEASE)$(PATH_DELIM)MainHeroMgr.o: MainHeroMgr.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c MainHeroMgr.cpp -o $(OBJDIR_RELEASE)$(PATH_DELIM)MainHeroMgr.o

$(OBJDIR_RELEASE)$(PATH_DELIM)TextureMgr.o: TextureMgr.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_RELEASE) -c TextureMgr.cpp -o $(OBJDIR_RELEASE)$(PATH_DELIM)TextureMgr.o

$(OBJDIR_RELEASE)$(PATH_DELIM)GravityPowerMgr.o: GravityPowerMgr.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_RELEASE) -c GravityPowerMgr.cpp -o $(OBJDIR_RELEASE)$(PATH_DELIM)GravityPowerMgr.o

$(OBJDIR_RELEASE)$(PATH_DELIM)LangMgr.o: LangMgr.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_RELEASE) -c LangMgr.cpp -o $(OBJDIR_RELEASE)$(PATH_DELIM)LangMgr.o

clean_release:
ifeq ($(OS),Windows_NT)
	del /Q /F $(OBJDIR_RELEASE) $(OBJDIR_RELEASE)
	rmdir /S /Q bin\\Release
	rmdir /S /Q $(OBJDIR_RELEASE)
else
	rm -f $(OBJ_RELEASE) $(OUT_RELEASE)
	rm -rf bin/Release
	rm -rf $(OBJDIR_RELEASE)
endif

.PHONY: before_debug after_debug clean_debug before_release after_release clean_release

