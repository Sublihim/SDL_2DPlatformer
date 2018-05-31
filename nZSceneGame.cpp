#include "nZSceneGame.h"
#include "MainConstants.h"
#include "Debug.h"
#include "nZMainHeroManager.h"
#include "SimpleTextureMgr.h"
#include "LangMgr.h"
#include "TilesMgr.h"
#include "GameMap.h"

#include <iostream>

// количество жизней
static const int LIVES_COUNT = 3;

nZSceneGame::nZSceneGame()
    : lives(LIVES_COUNT)
    , hero(new nZMainHeroMgr())
    , bg(new SimpleTextureMgr())
    , tilesMgr(new TilesMgr())
    , gameMap(new GameMap())
{
    camera = {0, 0, SCREEN_WIDTH, SCREEN_HEIGHT};
    initFont();
}


nZSceneGame::~nZSceneGame()
{
    delete hero;
    delete bg;
    delete tilesMgr;
    delete gameMap;
    debug() << "nZSceneGame end" << std::endl;
}


inline void nZSceneGame::initFont()
{
    font_game_info = ui::FontMgr::create();
    font_game_info->setFontName("assets/fonts/XoloniumBold.ttf");
    font_game_info->setFontSize(26);
    font_game_info->setFontColor({0xa8, 0x2f, 0x14});
    font_game_info->setLetterSizeInPX(20);
}


inline void nZSceneGame::firstRender(SDL_Renderer *renderer)
{
    setFirstRenderState(false);

    if(!hero->init(renderer))
        std::cout << "Error: " << hero->getErrorText() << std::endl;

    if(!bg->load(renderer, "assets/BG.png"))
        debug() << "Error load bg" << std::endl;

    int bgWidth = bg->getWidth();
    int bgHeight = bg->getHeight();

    hero->setGameBounds(bgWidth, bgHeight);
    tilesMgr->init(renderer);
    gameMap->loadMap();
    gameMap->setGameBounds(bgWidth, bgHeight);
}


inline void nZSceneGame::moveCamera()
{
    SDL_Point pointHero = hero->getPoint();

    debug() << "pointH: x= " << pointHero.x << " y= " << pointHero.y << std::endl;

    camera.x = pointHero.x;
    camera.y = pointHero.y;

    int bgWidth = bg->getWidth();
    int bgHeight = bg->getHeight();

    if( camera.x < 0 )
        camera.x = 0;
    else if( camera.x > bgWidth - camera.w )
        camera.x = bgWidth - camera.w;

    if( camera.y < 0 )
        camera.y = 0;
    else if( camera.y > bgHeight - camera.h )
        camera.y = bgHeight - camera.h;

    debug() << "camera: x= " << camera.x << " y= " << camera.y << std::endl;
}


inline void nZSceneGame::outScore(SDL_Renderer *renderer)
{
    static std::string scenePhrase = LangMgr::Init()->getPhrase("scene_lives");
    std::string lives_caption = scenePhrase + ": " + std::to_string(lives);
    font_game_info->paintText(renderer, lives_caption, SCREEN_HEIGHT - 30, 30, ui::fontAlign::right);
}


void nZSceneGame::render(SDL_Renderer *renderer)
{
    if(!b_paused)
    {
        if(b_first_render)
            firstRender(renderer);

        move();
        moveCamera();

        bg->render(renderer, 0, 0, &camera);
        gameMap->renderMap(renderer, tilesMgr, &camera);
        hero->draw(renderer, camera);

        //TODO переделать со строками
        outScore(renderer);

        SDL_RenderPresent(renderer);
    }
}

void nZSceneGame::move()
{
    hero->move(gameMap, tilesMgr);
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
