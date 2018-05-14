#ifndef GAMESCENE_H_INCLUDED
#define GAMESCENE_H_INCLUDED

#include "DebugParams.h"
#include <string>
#include "Scene.h"
#include "MainHeroMgr.h"

class SceneGame: public Scene
{
private:
    int lives;
    MainHeroMgr *hero;
public:
    SceneGame() noexcept;
    ~SceneGame();
    void render(SDL_Renderer *renderer);
    void render_clean(SDL_Renderer *renderer);
    gameReaction process_mouse_motion(Sint32 x, Sint32 y);
    gameReaction process_mouse_button_event(SDL_MouseButtonEvent m_btn_event);
    gameReaction process_keyboard_keydown(SDL_Keycode keycode);
};


#endif // GAMESCENE_H_INCLUDED
