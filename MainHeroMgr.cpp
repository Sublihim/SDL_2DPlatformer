#include "MainHeroMgr.h"
#include "MainHero.h"

MainHeroMgr::MainHeroMgr() noexcept 
    : GameObjectMgr(),
      gameWidth(0), 
      gameHeight(0)
{
    g_obj = new MainHero();
    g_obj->setTextureRowAndFrame(1, 0);

    hero_step = 15;
    b_jumping = false;

    gr_power_mgr = new GravityPowerMgr();
    gr_power_mgr->setBeginPoint(g_obj->getPositionBeginX(), g_obj->getPositionBeginY());
    gr_power_mgr->setSpeed(50);
    gr_power_mgr->setAngle(-58);
    gr_power_mgr->setTimeStep(0.25);
}

MainHeroMgr::~MainHeroMgr()
{
    delete gr_power_mgr;
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
    if(b_jumping)
    {
        SDL_Point p_next = gr_power_mgr->affectWithGravityPower();
        g_obj->setPosition(p_next.x, p_next.y);
        if(p_next.y >= SCREEN_HEIGHT)
            b_jumping = false;
    }

    g_obj->draw(renderer);
}

void MainHeroMgr::draw(SDL_Renderer *renderer, const SDL_Rect& camera)
{
    if(b_jumping)
    {
        SDL_Point p_next = gr_power_mgr->affectWithGravityPower();
        g_obj->setPosition(p_next.x, p_next.y);
        if(p_next.y >= SCREEN_HEIGHT)
            b_jumping = false;
    }
    //TODO по возможности отказаться от dc
    dynamic_cast<MainHero*>(g_obj)->draw(renderer, camera);
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
    if(!b_jumping)
    {
        int posX = g_obj->getPositionBeginX(),
            posY = g_obj->getPositionBeginY();

        if(keycode == SDLK_LEFT)
        {
            posX -= hero_step;
            gr_power_mgr->setAngle(-90-(90-58));
            g_obj->setTextureRowAndFrame(2, 0);
        }
        else if(keycode == SDLK_RIGHT)
        {
            posX += hero_step;
            gr_power_mgr->setAngle(-58);
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
            gr_power_mgr->setBeginPoint(g_obj->getPositionBeginX(), g_obj->getPositionBeginY());
            b_jumping = true;
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
    }

    return gameReaction::gr_ignore;
}

SDL_Point MainHeroMgr::getPoint() const
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


void MainHeroMgr::setGameBounds(int width, int height)
{
    gameWidth = width;
    gameHeight = height;
}