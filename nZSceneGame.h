#ifndef GAMESCENE_H_INCLUDED
#define GAMESCENE_H_INCLUDED

#include <string>
#include "Scene.h"
#include "ui/FontMgr.h"

class nZMainHeroMgr;
class SimpleTextureMgr;
class TilesMgr;
class GameMap;

class nZSceneGame: public Scene
{
private:
    int lives;
    nZMainHeroMgr *hero;
    SimpleTextureMgr* bg;
    TilesMgr* tilesMgr;
    GameMap* gameMap;
    SDL_Rect camera;
    ui::FontMgrPtr font_game_info;

    inline void initFont();
    inline void firstRender(SDL_Renderer *renderer);
    inline void moveCamera();
    inline void outScore(SDL_Renderer *renderer);
    void move(); // двигаем объекты
public:
    nZSceneGame();
    ~nZSceneGame();
    void render(SDL_Renderer *renderer);
    void render_clean(SDL_Renderer *renderer);
    gameReaction process_mouse_motion(Sint32 x, Sint32 y);
    gameReaction process_mouse_button_event(SDL_MouseButtonEvent m_btn_event);
    gameReaction process_keyboard_keydown(SDL_Keycode keycode);
};


#endif // GAMESCENE_H_INCLUDED
