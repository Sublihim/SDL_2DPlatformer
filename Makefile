WORKDIR = `pwd`

CC = gcc
CXX = g++
AR = ar
LD = g++
WINDRES = windres

INC = 
CFLAGS = -Wall -fexceptions
RESINC = 
LIBDIR = 
LIB = 
LDFLAGS = 

INC_DEBUG = $(INC)
CFLAGS_DEBUG = $(CFLAGS) -g
RESINC_DEBUG = $(RESINC)
RCFLAGS_DEBUG = $(RCFLAGS)
LIBDIR_DEBUG = $(LIBDIR)
LIB_DEBUG = $(LIB)
LDFLAGS_DEBUG = $(LDFLAGS) -lSDL2 -lSDL2_ttf -lSDL2_mixer
OBJDIR_DEBUG = obj/Debug
DEP_DEBUG = 
OUT_DEBUG = bin/Debug/SDL_2DPlatformer

INC_RELEASE = $(INC)
CFLAGS_RELEASE = $(CFLAGS) -O2
RESINC_RELEASE = $(RESINC)
RCFLAGS_RELEASE = $(RCFLAGS)
LIBDIR_RELEASE = $(LIBDIR)
LIB_RELEASE = $(LIB)
LDFLAGS_RELEASE = $(LDFLAGS) -lSDL2 -lSDL2_ttf -lSDL2_mixer
OBJDIR_RELEASE = obj/Release
DEP_RELEASE = 
OUT_RELEASE = bin/Release/SDL_2DPlatformer

OBJ_DEBUG = $(OBJDIR_DEBUG)/SDL_Game.o $(OBJDIR_DEBUG)/Scene.o $(OBJDIR_DEBUG)/SceneGame.o $(OBJDIR_DEBUG)/SceneMenu.o $(OBJDIR_DEBUG)/SceneMenuPause.o $(OBJDIR_DEBUG)/SceneMgr.o $(OBJDIR_DEBUG)/main.o $(OBJDIR_DEBUG)/Button.o $(OBJDIR_DEBUG)/FontMgr.o

OBJ_RELEASE = $(OBJDIR_RELEASE)/SDL_Game.o $(OBJDIR_RELEASE)/Scene.o $(OBJDIR_RELEASE)/SceneGame.o $(OBJDIR_RELEASE)/SceneMenu.o $(OBJDIR_RELEASE)/SceneMenuPause.o $(OBJDIR_RELEASE)/SceneMgr.o $(OBJDIR_RELEASE)/main.o $(OBJDIR_RELEASE)/Button.o $(OBJDIR_RELEASE)/FontMgr.o

all: debug release

clean: clean_debug clean_release

before_debug: 
	test -d bin/Debug || mkdir -p bin/Debug
	test -d $(OBJDIR_DEBUG) || mkdir -p $(OBJDIR_DEBUG)

after_debug: 

debug: before_debug out_debug after_debug

out_debug: before_debug $(OBJ_DEBUG) $(DEP_DEBUG)
	$(LD) $(LIBDIR_DEBUG) -o $(OUT_DEBUG) $(OBJ_DEBUG)  $(LDFLAGS_DEBUG) $(LIB_DEBUG)

$(OBJDIR_DEBUG)/SDL_Game.o: SDL_Game.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c SDL_Game.cpp -o $(OBJDIR_DEBUG)/SDL_Game.o

$(OBJDIR_DEBUG)/Scene.o: Scene.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c Scene.cpp -o $(OBJDIR_DEBUG)/Scene.o

$(OBJDIR_DEBUG)/SceneGame.o: SceneGame.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c SceneGame.cpp -o $(OBJDIR_DEBUG)/SceneGame.o

$(OBJDIR_DEBUG)/SceneMenu.o: SceneMenu.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c SceneMenu.cpp -o $(OBJDIR_DEBUG)/SceneMenu.o

$(OBJDIR_DEBUG)/SceneMenuPause.o: SceneMenuPause.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c SceneMenuPause.cpp -o $(OBJDIR_DEBUG)/SceneMenuPause.o

$(OBJDIR_DEBUG)/SceneMgr.o: SceneMgr.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c SceneMgr.cpp -o $(OBJDIR_DEBUG)/SceneMgr.o

$(OBJDIR_DEBUG)/main.o: main.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c main.cpp -o $(OBJDIR_DEBUG)/main.o

$(OBJDIR_DEBUG)/Button.o: Button.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c Button.cpp -o $(OBJDIR_DEBUG)/Button.o

$(OBJDIR_DEBUG)/FontMgr.o: FontMgr.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c FontMgr.cpp -o $(OBJDIR_DEBUG)/FontMgr.o

clean_debug: 
	rm -f $(OBJ_DEBUG) $(OUT_DEBUG)
	rm -rf bin/Debug
	rm -rf $(OBJDIR_DEBUG)

before_release: 
	test -d bin/Release || mkdir -p bin/Release
	test -d $(OBJDIR_RELEASE) || mkdir -p $(OBJDIR_RELEASE)

after_release: 

release: before_release out_release after_release

out_release: before_release $(OBJ_RELEASE) $(DEP_RELEASE)
	$(LD) $(LIBDIR_RELEASE) -o $(OUT_RELEASE) $(OBJ_RELEASE)  $(LDFLAGS_RELEASE) $(LIB_RELEASE)

$(OBJDIR_RELEASE)/SDL_Game.o: SDL_Game.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c SDL_Game.cpp -o $(OBJDIR_RELEASE)/SDL_Game.o

$(OBJDIR_RELEASE)/Scene.o: Scene.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c Scene.cpp -o $(OBJDIR_RELEASE)/Scene.o

$(OBJDIR_RELEASE)/SceneGame.o: SceneGame.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c SceneGame.cpp -o $(OBJDIR_RELEASE)/SceneGame.o

$(OBJDIR_RELEASE)/SceneMenu.o: SceneMenu.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c SceneMenu.cpp -o $(OBJDIR_RELEASE)/SceneMenu.o

$(OBJDIR_RELEASE)/SceneMenuPause.o: SceneMenuPause.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c SceneMenuPause.cpp -o $(OBJDIR_RELEASE)/SceneMenuPause.o

$(OBJDIR_RELEASE)/SceneMgr.o: SceneMgr.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c SceneMgr.cpp -o $(OBJDIR_RELEASE)/SceneMgr.o

$(OBJDIR_RELEASE)/main.o: main.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c main.cpp -o $(OBJDIR_RELEASE)/main.o

$(OBJDIR_RELEASE)/Button.o: Button.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c Button.cpp -o $(OBJDIR_RELEASE)/Button.o

$(OBJDIR_RELEASE)/FontMgr.o: FontMgr.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c FontMgr.cpp -o $(OBJDIR_RELEASE)/FontMgr.o

clean_release: 
	rm -f $(OBJ_RELEASE) $(OUT_RELEASE)
	rm -rf bin/Release
	rm -rf $(OBJDIR_RELEASE)

.PHONY: before_debug after_debug clean_debug before_release after_release clean_release

