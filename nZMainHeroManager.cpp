#include "nZMainHeroManager.h"
#include "MainHero.h"
#include "GameMap.h"
#include "TilesMgr.h"

nZMainHeroMgr::nZMainHeroMgr()
 : gameWidth(0)
 , gameHeight(0)
 , newPositionX(0)
 , newPositionY(0)
 , jumpCounter(0)
 , state(STOP)
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
    if (state != STOP)
        return gameReaction::gr_ignore;

    int posX = g_obj->getPositionBeginX();
        //posY = g_obj->getPositionBeginY();

    MainHero* mh = dynamic_cast<MainHero*>(g_obj);

    if(keycode == SDLK_LEFT)
    {
        newPositionX = posX - hero_stepX;
        mh->setDirectionLeft();
        state = MOVE;
    }
    else if(keycode == SDLK_RIGHT)
    {
        newPositionX = posX + hero_stepX;
        mh->setDirectionRight();
        state = MOVE;
    }
    else if(keycode == SDLK_SPACE)
    {
        if (state != FOLLOW)
            state = JUMP;
    }

    return gameReaction::gr_ignore;
}


void nZMainHeroMgr::move(const GameMap* gameMap, const TilesMgr* tilesMgr)
{
    if (state == MOVE)
    {
        checkBoundaryPosition();

        g_obj->setPosition(newPositionX, newPositionY);
        state = STOP;
    }
    else if (state == STOP || state == FOLLOW)
    {
        int distance = gameMap->getDistanceFollow(g_obj->getGameObjectZone(), tilesMgr);
        processFollow(distance);
    }
    else if (state == JUMP)
    {
        processJump();
    }
}


void nZMainHeroMgr::processJump()
{
    if (jumpCounter++ < 5)
    {
        newPositionY = g_obj->getPositionBeginY();
        newPositionY -= hero_stepY;
        g_obj->setPosition(newPositionX, newPositionY);
    }
    else
    {
        jumpCounter = 0;
        state = STOP;
    }
}

void nZMainHeroMgr::checkBoundaryPosition()
{
    newPositionY = g_obj->getPositionBeginY();
    if (newPositionX < 0)
        newPositionX = 0;
    if (newPositionX + g_obj->getObjectWidth() > gameWidth)
        newPositionX -= hero_stepX;
    if (newPositionY < 0)
        newPositionY = 0;
    if (newPositionY + g_obj->getObjectHeight() > gameHeight)
        newPositionY -= hero_stepY;
}


void nZMainHeroMgr::processFollow(int distance)
{
    if (distance > 0)
    {
        newPositionY = g_obj->getPositionBeginY();

        if (distance >= hero_stepY)
            newPositionY += hero_stepY;
        else if (distance > 0)
            newPositionY += distance;

        state = FOLLOW;
        g_obj->setPosition(newPositionX, newPositionY);
    }
    else
    {
        state = STOP;
    }
}

gameReaction nZMainHeroMgr::process_keyboard_keyup(SDL_Keycode keycode)
{
    return gr_ignore;
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