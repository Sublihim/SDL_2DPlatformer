#ifndef MAINHEROMGR_H_INCLUDED
#define MAINHEROMGR_H_INCLUDED

#include "GameObjectMgr.h"
#include "GravityPowerMgr.h"

class MainHero;

class MainHeroMgr : public GameObjectMgr
{
private:
    int hero_step;
    bool b_jumping;
    GravityPowerMgr *gr_power_mgr;
public:
    MainHeroMgr();
    ~MainHeroMgr();
    bool init(SDL_Renderer *renderer);
    void setMoveStep(int step);
    void draw(SDL_Renderer *renderer);
    void setPosition(int x, int y);
    bool checkCollisionWithGameObject(GameObject *g_obj);
    gameReaction process_mouse_motion(Sint32 x, Sint32 y);
    gameReaction process_mouse_button_event(SDL_MouseButtonEvent m_btn_event);
    gameReaction process_keyboard_keydown(SDL_Keycode keycode);
};

#endif // MAINHEROMGR_H_INCLUDED