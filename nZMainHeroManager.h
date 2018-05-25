#ifndef MAINHEROMGR_H_INCLUDED
#define MAINHEROMGR_H_INCLUDED

#include "GameObjectMgr.h"

class MainHero;

class nZMainHeroMgr : public GameObjectMgr
{
private:
    int hero_stepX;
    int hero_stepY;
    int gameWidth;
    int gameHeight;
public:
    nZMainHeroMgr();
    ~nZMainHeroMgr();
    bool init(SDL_Renderer *renderer);
    void draw(SDL_Renderer *renderer);
    void draw(SDL_Renderer *renderer, const SDL_Rect& camera);
    bool checkCollisionWithGameObject(GameObject *g_obj);
    SDL_Point getPoint() const;
    void setGameBounds(int width, int height);
    gameReaction process_mouse_motion(Sint32 x, Sint32 y);
    gameReaction process_mouse_button_event(SDL_MouseButtonEvent m_btn_event);
    gameReaction process_keyboard_keydown(SDL_Keycode keycode);
    gameReaction process_keyboard_keyup(SDL_Keycode keycode);
};

#endif // MAINHEROMGR_H_INCLUDED