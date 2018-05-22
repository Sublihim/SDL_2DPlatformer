#ifndef GAMESCENE_H_INCLUDED
#define GAMESCENE_H_INCLUDED

#include <string>
#include "ui/FontMgr.h"
#include "Scene.h"
#include "MainHeroMgr.h"

class LangMgr;

class SceneGame: public Scene
{
private:
    int lives;
    MainHeroMgr *hero;
    ui::FontMgrPtr font_game_info;
    SDL_Color font_color;
    LangMgr *lang_mgr;
public:
    SceneGame();
    ~SceneGame();
    void render(SDL_Renderer *renderer);
    void render_clean(SDL_Renderer *renderer);
    gameReaction process_mouse_motion(Sint32 x, Sint32 y);
    gameReaction process_mouse_button_event(SDL_MouseButtonEvent m_btn_event);
    gameReaction process_keyboard_keydown(SDL_Keycode keycode);
};


#endif // GAMESCENE_H_INCLUDED
