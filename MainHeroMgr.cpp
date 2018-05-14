#include "MainHeroMgr.h"
#include "MainHero.h"

MainHeroMgr::MainHeroMgr() noexcept 
    : GameObjectMgr()
{
    g_obj = new MainHero();
    g_obj_cleaner = g_obj->getGameObjectZone();
    g_obj->setTextureRowAndFrame(1, 0);
    hero_step = 15;
}

MainHeroMgr::~MainHeroMgr()
{
    delete g_obj;
}

bool MainHeroMgr::init(SDL_Renderer *renderer)
{
    if(!g_obj->init(renderer))
    {
        errorText = g_obj->getErrorText();
        return false;
    }
    else
        return true;
}

void MainHeroMgr::setMoveStep(int step)
{
    if(step < 0)
        step = 0;
    hero_step = step;
}

void MainHeroMgr::draw(SDL_Renderer *renderer)
{
    SDL_RenderFillRect(renderer, &g_obj_cleaner);
    g_obj_cleaner = g_obj->getGameObjectZone();
    g_obj->draw(renderer);
}

bool MainHeroMgr::checkCollisionWithGameObject(GameObject *g_obj)
{
    return false;
}

gameReaction MainHeroMgr::process_mouse_motion(Sint32 x, Sint32 y)
{
    return gameReaction::gr_ignore;
}

gameReaction MainHeroMgr::process_mouse_button_event(SDL_MouseButtonEvent m_btn_event)
{
    return gameReaction::gr_ignore;
}

gameReaction MainHeroMgr::process_keyboard_keydown(SDL_Keycode keycode)
{
    if(keycode == SDLK_LEFT)
    {
        g_obj->setPosition(g_obj->getPositionBeginX() - hero_step, g_obj->getPositionBeginY());
        g_obj->setTextureRowAndFrame(2, 0);
    }
    else if(keycode == SDLK_RIGHT)
    {
        g_obj->setPosition(g_obj->getPositionBeginX() + hero_step, g_obj->getPositionBeginY());
        g_obj->setTextureRowAndFrame(1, 0);
    }

    return gameReaction::gr_ignore;
}