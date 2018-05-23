#include "nZMainHeroManager.h"
#include "MainHero.h"

nZMainHeroMgr::nZMainHeroMgr()
 : gameWidth(0)
 , gameHeight(0)
{
    g_obj = new MainHero();
    dynamic_cast<MainHero*>(g_obj)->setDirectionRight();
    hero_stepX = 15;
    hero_stepY = 15;
}


nZMainHeroMgr::~nZMainHeroMgr()
{
    delete g_obj;
}


bool nZMainHeroMgr::init(SDL_Renderer *renderer)
{
    bool res = true;
    if(!g_obj->init(renderer))
    {
        errorText = g_obj->getErrorText();
        res = false;
    }
    return res;
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

    MainHero* mh = dynamic_cast<MainHero*>(g_obj);

    if(keycode == SDLK_LEFT)
    {
        if (hero_stepX > 0)
            hero_stepX = ~hero_stepX + 1;
        mh->setDirectionLeft();
    }
    else if(keycode == SDLK_RIGHT)
    {
        if (hero_stepX < 0)
            hero_stepX = ~hero_stepX + 1;
        mh->setDirectionRight();
    }
    else if(keycode == SDLK_UP)
    {
        if (hero_stepY > 0)
            hero_stepY = ~hero_stepY + 1;
    }
    else if (keycode == SDLK_DOWN)
    {
        if (hero_stepY < 0)
            hero_stepY = ~hero_stepY + 1;
    }
    else if(keycode == SDLK_SPACE)
    {
    }

    posX += hero_stepX;
    posY += hero_stepY;

    if (posX < 0)
        posX = 0;
    if (posX + g_obj->getObjectWidth() > gameWidth)
        posX -= hero_stepX;
    if (posY < 0)
        posY = 0;
    if (posY + g_obj->getObjectHeight() > gameHeight)
        posY -= hero_stepY;

    g_obj->setPosition(posX, posY);

    return gameReaction::gr_ignore;
}


SDL_Point nZMainHeroMgr::getPoint() const
{
    SDL_Point res;
    SDL_Rect gameZone = g_obj->getGameObjectZone();

    res.x = (gameZone.x + gameZone.w / 2) - SCREEN_WIDTH / 2;
    res.y = (gameZone.y + gameZone.h / 2) - SCREEN_HEIGHT / 2;

    return res;
}


void nZMainHeroMgr::setGameBounds(int width, int height)
{
    gameWidth = width;
    gameHeight = height;
}