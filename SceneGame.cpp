#include "MainConstants.h"
#include "SceneGame.h"
#include "LangMgr.h"
#include "Debug.h"
#include <iostream>


SceneGame::SceneGame()
{
    lives = 3; // Выставляем количество жизней
    lang_mgr = LangMgr::Init();
    hero = new MainHeroMgr();

    // Задаем параметры текста

    font_color = {0, 0, 255};

    font_game_info = ui::FontMgr::create();
    font_game_info->setFontName("assets/fonts/XoloniumBold.ttf");
    font_game_info->setFontSize(26);
    font_game_info->setFontColor(font_color);
    font_game_info->setLetterSizeInPX(20);
}

SceneGame::~SceneGame()
{
    delete hero;
    debug() << "SceneGame end" << std::endl;
}

void SceneGame::render(SDL_Renderer *renderer)
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

        static std::string lives_caption = lang_mgr->getPhrase("scene_lives") + ": " + std::to_string(lives);
        font_game_info->paintText(renderer, lives_caption, SCREEN_HEIGHT - 30, 30, ui::fontAlign::right);

        SDL_RenderPresent(renderer);
    }
}

void SceneGame::render_clean(SDL_Renderer *renderer)
{
    // Стираем текущие объекты сцены
}

gameReaction SceneGame::process_mouse_motion(Sint32 x, Sint32 y)
{
    if(!b_paused)
    {
    }

    return gameReaction::gr_ignore;
}

gameReaction SceneGame::process_mouse_button_event(SDL_MouseButtonEvent m_btn_event)
{
    return gameReaction::gr_ignore;
}

gameReaction SceneGame::process_keyboard_keydown(SDL_Keycode keycode)
{
    if(!b_paused)
    {
        hero->process_keyboard_keydown(keycode);
    }

    return gameReaction::gr_ignore;
}
