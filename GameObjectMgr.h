#ifndef GAMEOBJECTMGR_H_INCLUDED
#define GAMEOBJECTMGR_H_INCLUDED

#include "DebugParams.h"
#include "MainConstants.h"
#include <SDL2/SDL.h>
#include <iostream>

class GameObject;

class GameObjectMgr
{
protected:
    GameObject *g_obj;
    SDL_Rect g_obj_cleaner;
    std::string errorText;
public:
    GameObjectMgr() noexcept : g_obj(nullptr) {}
    virtual ~GameObjectMgr() {};
    virtual std::string getErrorText();
    virtual bool init(SDL_Renderer *renderer) = 0;
    virtual void draw(SDL_Renderer *renderer) = 0;
    virtual bool checkCollisionWithGameObject(GameObject *g_obj) = 0;
    virtual gameReaction process_mouse_motion(Sint32 x, Sint32 y) = 0;
    virtual gameReaction process_mouse_button_event(SDL_MouseButtonEvent m_btn_event) = 0;
    virtual gameReaction process_keyboard_keydown(SDL_Keycode keycode) = 0;
};

#endif // GAMEOBJECTMGR_H_INCLUDED