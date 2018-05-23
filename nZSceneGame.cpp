#include "nZSceneGame.h"
#include "MainConstants.h"
#include "Debug.h"
#include "nZMainHeroManager.h"
#include "SimpleTextureMgr.h"
#include "LangMgr.h"

#include <iostream>

// количество жизней
static const int LIVES_COUNT = 3;

nZSceneGame::nZSceneGame()
    : lives(LIVES_COUNT)
    , hero(new nZMainHeroMgr())
    , bg(new SimpleTextureMgr())
{
    camera = {0, 0, SCREEN_WIDTH, SCREEN_HEIGHT};

    font_game_info = ui::FontMgr::create();
    font_game_info->setFontName("assets/fonts/XoloniumBold.ttf");
    font_game_info->setFontSize(26);
    font_game_info->setFontColor({0xa8, 0x2f, 0x14});
    font_game_info->setLetterSizeInPX(20);
}

nZSceneGame::~nZSceneGame()
{
    delete hero;
    delete bg;
    debug() << "nZSceneGame end" << std::endl;
}

void nZSceneGame::render(SDL_Renderer *renderer)
{
    if(!b_paused)
    {
        if(b_first_render)
        {
            setFirstRenderState(false);

            if(!hero->init(renderer))
                std::cout << "Error: " << hero->getErrorText() << std::endl;

            if(!bg->load(renderer, "assets/BG.png"))
                debug() << "Error load bg" << std::endl;

            hero->setGameBounds(bg->getWidth(), bg->getHeight());
        }

        SDL_Point pointHero = hero->getPoint();

        camera.x = pointHero.x;
        camera.y = pointHero.y;

        if( camera.x < 0 )
            camera.x = 0;
        else if( camera.x > bg->getWidth() - camera.w )
            camera.x = bg->getWidth() - camera.w;

        if( camera.y < 0 )
            camera.y = 0;
        else if( camera.y > bg->getHeight() - camera.h )
            camera.y = bg->getHeight() - camera.h;

        bg->render(renderer, 0, 0, &camera);
        hero->draw(renderer, camera);

        //TODO переделать со строками
        LangMgr* lang_mgr = LangMgr::Init();
        static std::string lives_caption = lang_mgr->getPhrase("scene_lives") + ": " + std::to_string(lives);
        font_game_info->paintText(renderer, lives_caption, SCREEN_HEIGHT - 30, 30, ui::fontAlign::right);

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
