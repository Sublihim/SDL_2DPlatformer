#include "nZMainHeroManager.h"
#include "MainHero.h"

nZMainHeroMgr::nZMainHeroMgr()
 : gameWidth(0), gameHeight(0)
{
    g_obj = new MainHero();
    g_obj->setTextureRowAndFrame(1, 0);

    hero_step = 15;
}


nZMainHeroMgr::~nZMainHeroMgr()
{
    delete g_obj;
}


bool nZMainHeroMgr::init(SDL_Renderer *renderer)
{
    if(!g_obj->init(renderer))
    {
        errorText = g_obj->getErrorText();
        return false;
    }
    else
        return true;
}


void nZMainHeroMgr::setMoveStep(int step)
{
    if(step < 0)
        step = 0;
    hero_step = step;
}


void nZMainHeroMgr::draw(SDL_Renderer *renderer)
{
    g_obj->draw(renderer);
}


void nZMainHeroMgr::draw(SDL_Renderer *renderer, const SDL_Rect& camera)
{
    //TODO по возможности отказаться от dc
    dynamic_cast<MainHero*>(g_obj)->draw(renderer, camera);
}


bool nZMainHeroMgr::checkCollisionWithGameObject(GameObject *g_obj)
{
    return false;
}

gameReaction nZMainHeroMgr::process_mouse_motion(Sint32 x, Sint32 y)
{
    return gameReaction::gr_ignore;
}

gameReaction nZMainHeroMgr::process_mouse_button_event(SDL_MouseButtonEvent m_btn_event)
{
    return gameReaction::gr_ignore;
}

gameReaction nZMainHeroMgr::process_keyboard_keydown(SDL_Keycode keycode)
{
    int posX = g_obj->getPositionBeginX(),
        posY = g_obj->getPositionBeginY();

    if(keycode == SDLK_LEFT)
    {
        posX -= hero_step;
        g_obj->setTextureRowAndFrame(2, 0);
    }
    else if(keycode == SDLK_RIGHT)
    {
        posX += hero_step;
        g_obj->setTextureRowAndFrame(1, 0);
    }
    else if(keycode == SDLK_UP)
    {
        posY -= hero_step;
    }
    else if (keycode == SDLK_DOWN)
    {
        posY += hero_step;
    }
    else if(keycode == SDLK_SPACE)
    {
    }

    if (posX < 0)
        posX = 0;
    if (posX + g_obj->getObjectWidth() > gameWidth)
        posX -= hero_step;
    if (posY < 0)
        posY = 0;
    if (posY + g_obj->getObjectHeight() > gameHeight)
        posY -= hero_step;

    g_obj->setPosition(posX, posY);

    return gameReaction::gr_ignore;
}

SDL_Point nZMainHeroMgr::getPoint() const
{
    SDL_Point res;
    int x = g_obj->getPositionBeginX();
    int y = g_obj->getPositionBeginY();
    int w = g_obj->getObjectWidth();
    int h = g_obj->getObjectHeight();

    res.x = (x + w / 2) - SCREEN_WIDTH / 2;
    res.y = (y + h / 2) - SCREEN_HEIGHT / 2;

    return res;
}


void nZMainHeroMgr::setGameBounds(int width, int height)
{
    gameWidth = width;
    gameHeight = height;
}