#ifndef MAINHEROMGR_H_INCLUDED
#define MAINHEROMGR_H_INCLUDED

#include "GameObjectMgr.h"

class MainHero;
class GameMap;
class TilesMgr;

class nZMainHeroMgr : public GameObjectMgr
{
private:
    enum StateHero {STOP, MOVE, FOLLOW, JUMP};
    int hero_stepX;
    int hero_stepY;
    int gameWidth;
    int gameHeight;
    int newPositionX;
    int newPositionY;
    int jumpCounter;
    StateHero state;

    void processFollow(int distance);
    void checkBoundaryPosition();
public:
    nZMainHeroMgr();
    ~nZMainHeroMgr();
    bool init(SDL_Renderer *renderer);
    void draw(SDL_Renderer *renderer);
    void draw(SDL_Renderer *renderer, const SDL_Rect& camera);
    bool checkCollisionWithGameObject(GameObject *g_obj);
    SDL_Point getPoint() const;
    void setGameBounds(int width, int height);
    void move(const GameMap* gameMap, const TilesMgr* tilesMgr);
    gameReaction process_mouse_motion(Sint32 x, Sint32 y);
    gameReaction process_mouse_button_event(SDL_MouseButtonEvent m_btn_event);
    gameReaction process_keyboard_keydown(SDL_Keycode keycode);
    gameReaction process_keyboard_keyup(SDL_Keycode keycode);
};

#endif // MAINHEROMGR_H_INCLUDED