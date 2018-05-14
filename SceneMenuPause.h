#ifndef SCENEMENUPAUSE_H_INCLUDED
#define SCENEMENUPAUSE_H_INCLUDED

#include "DebugParams.h"
#include "Scene.h"
#include "ui/Button.h"

class SceneMenuPause : public Scene
{
private:
    SDL_Rect rect_backgrnd;
    ui::ButtonPtr btn_continue {nullptr};
    ui::ButtonPtr btn_main_menu {nullptr};
    ui::ButtonPtr btn_exit {nullptr};
public:
    SceneMenuPause() noexcept;
    ~SceneMenuPause();
    void render(SDL_Renderer *renderer);
    gameReaction process_mouse_motion(Sint32 x, Sint32 y);
    gameReaction process_mouse_button_event(SDL_MouseButtonEvent m_btn_event);
    gameReaction process_keyboard_keydown(SDL_Keycode keycode);
};

#endif // SCENEMENUPAUSE_H_INCLUDED
