#ifndef SCENEMENU_H_INCLUDED
#define SCENEMENU_H_INCLUDED

#include "Scene.h"
#include "ui/Button.h"

class SceneMenu : public Scene
{
private:
    ui::ButtonPtr btn_new_game {nullptr};
    ui::ButtonPtr btn_exit {nullptr};
public:
    SceneMenu() noexcept;
    ~SceneMenu();
    void render(SDL_Renderer *renderer);
    gameReaction process_mouse_motion(Sint32 x, Sint32 y);
    gameReaction process_mouse_button_event(SDL_MouseButtonEvent m_btn_event);
    gameReaction process_keyboard_keydown(SDL_Keycode keycode);
};

#endif // SCENEMENU_H_INCLUDED
