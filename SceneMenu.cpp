#include "SceneMenu.h"
#include "Debug.h"
#include "LangMgr.h"

SceneMenu::SceneMenu()
{
    int btn_w = 500;
    int btn_h = 70;

    int menuPosition_x = (SCREEN_WIDTH - btn_w) / 2;
    int menuPosition_y = 100;    

    // Задаем параметры кнопок
    LangMgr *lang_mgr;
    lang_mgr = LangMgr::Init();

    btn_new_game = ui::Button::create();
    btn_new_game->setCaption(lang_mgr->getPhrase("menu_new_game"));
    btn_new_game->setPosition(menuPosition_x, menuPosition_y);
    btn_new_game->setSize(btn_w, btn_h);

    btn_exit = ui::Button::create();
    btn_exit->setCaption(lang_mgr->getPhrase("menu_exit"));
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
