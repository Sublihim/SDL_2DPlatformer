#ifndef SDL_GAME_H_INCLUDED
#define SDL_GAME_H_INCLUDED

#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_mouse.h>
#include <SDL2/SDL_keyboard.h>
#include <SDL2/SDL_ttf.h>
#include "SceneMgr.h"

const int FPS = 60;
const int frameDelay = 1000 / FPS;

class SDL_Game
{
private:
    SDL_Window *window = nullptr;
	SDL_Renderer *renderer = nullptr;
	SceneMgr *s_mgr = nullptr;
	std::string SDL_error_msg;
    Uint32 frameStart;
    int frameTime;
public:
    SDL_Game() noexcept;
    ~SDL_Game();
    std::string getErrorMsg();
    bool init(const char* title, int xpos, int ypos,
              int height, int width, int flags);
    int process_events();
    void render();
    void identFrameStart();
    void execFrameDelay();
};

#endif // SDL_GAME_H_INCLUDED
