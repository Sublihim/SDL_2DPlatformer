#include "nZSceneGame.h"
#include "MainConstants.h"
#include "Debug.h"
#include "MainHeroMgr.h"

#include <iostream>


nZSceneGame::nZSceneGame()
{
    lives = 3; // Выставляем количество жизней
    hero = new MainHeroMgr();
}

nZSceneGame::~nZSceneGame()
{
    delete hero;
    debug() << "nZSceneGame end" << std::endl;
}

void nZSceneGame::render(SDL_Renderer *renderer)
{
    if(!b_paused)
    {
        if(b_first_render)
        {
            setFirstRenderState(false);

            SDL_SetRenderDrawColor( renderer, 255, 255, 255, 255 );
            SDL_RenderClear( renderer );
            SDL_SetRenderDrawColor( renderer, 255, 255, 255, 255 );

            if(!hero->init(renderer))
                std::cout << "Error: " << hero->getErrorText() << std::endl;
        }

        hero->draw(renderer);

        SDL_RenderPresent(renderer);
    }
}

void nZSceneGame::render_clean(SDL_Renderer *renderer)
{
    // Стираем текущие объекты сцены
}

gameReaction nZSceneGame::process_mouse_motion(Sint32 x, Sint32 y)
{
    if(!b_paused)
    {
    }

    return gameReaction::gr_ignore;
}

gameReaction nZSceneGame::process_mouse_button_event(SDL_MouseButtonEvent m_btn_event)
{
    return gameReaction::gr_ignore;
}

gameReaction nZSceneGame::process_keyboard_keydown(SDL_Keycode keycode)
{
    if(!b_paused)
    {
        hero->process_keyboard_keydown(keycode);
    }

    return gameReaction::gr_ignore;
}
