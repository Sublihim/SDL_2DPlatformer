#include "SceneMenu.h"
#include "Debug.h"

SceneMenu::SceneMenu() noexcept
{
    int menuPosition_x = 120;
    int menuPosition_y = 100;

    int btn_w = 400;
    int btn_h = 70;

    // Задаем параметры кнопок
    btn_new_game = ui::Button::create();
    btn_new_game->setCaption("NEW GAME");
    btn_new_game->setPosition(menuPosition_x, menuPosition_y);
    btn_new_game->setSize(btn_w, btn_h);

    btn_exit = ui::Button::create();
    btn_exit->setCaption("EXIT");
    btn_exit->setPosition(menuPosition_x, menuPosition_y + btn_h + 30);
    btn_exit->setSize(btn_w, btn_h);
}

SceneMenu::~SceneMenu()
{
    debug() << "SceneMenu end" << std::endl;
}

void SceneMenu::render(SDL_Renderer *renderer)
{
    if(b_first_render)
    {
        setFirstRenderState(false);

        SDL_SetRenderDrawColor( renderer, 255, 255, 255, 255 );
        SDL_RenderClear( renderer );
        SDL_SetRenderDrawColor( renderer, 255, 0, 0, 255 );
    }

    btn_new_game->draw(renderer);
    btn_exit->draw(renderer);

    SDL_RenderPresent(renderer);
}

gameReaction SceneMenu::process_mouse_motion(Sint32 x, Sint32 y)
{
    return gameReaction::gr_ignore;
}

gameReaction SceneMenu::process_mouse_button_event(SDL_MouseButtonEvent m_btn_event)
{
    // Клик левой кнопкой мышки
    if(m_btn_event.button == SDL_BUTTON_LEFT)
    {
        // Один клик
        if(m_btn_event.clicks == 1)
        {
            if(btn_exit->checkHover(m_btn_event.x, m_btn_event.y))
            {
                // Выходим из игры
                return gameReaction::gr_exit;
            }

            if(btn_new_game->checkHover(m_btn_event.x, m_btn_event.y))
            {
                // Начинаем новую игру
                return gameReaction::gr_start_new;
            }
        }
    }

    return gameReaction::gr_ignore;
}

gameReaction SceneMenu::process_keyboard_keydown(SDL_Keycode keycode)
{
    return gameReaction::gr_ignore;
}
