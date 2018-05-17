#include <iostream>
#include "SDL_Game.h"

int main( int argc, char* args[] )
{
    SDL_Game *game = new SDL_Game();
    if(!game->init("SDL 2D Platformer by MIKRI and nZemekis (Press Esc for Exit)", SDL_WINDOWPOS_UNDEFINED,
                            SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT,
                            SDL_WINDOW_SHOWN))
    {
        std::cout << game->getErrorMsg() << std::endl;
        return 1;
    }

    std::cout << "Press Esc button to Exit!\n";

    bool game_playing = true;
    while(game_playing)
    {
        game->identFrameStart();
        game_playing = game->process_events();
        game->render();
        game->execFrameDelay();
    }

	delete game;

	return 0;
}
