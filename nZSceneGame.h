#ifndef GAMESCENE_H_INCLUDED
#define GAMESCENE_H_INCLUDED

#include <string>
#include "Scene.h"
#include "ui/FontMgr.h"

class nZMainHeroMgr;
class SimpleTextureMgr;
class TilesMgr;

class nZSceneGame: public Scene
{
private:
    int lives;
    nZMainHeroMgr *hero;
    SimpleTextureMgr* bg;
    TilesMgr* tilesMgr;
    SDL_Rect camera;
    ui::FontMgrPtr font_game_info;
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
