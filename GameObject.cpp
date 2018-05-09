#include "GameObject.h"

std::string GameObject::getErrorText()
{
    return errorText;
}

SDL_Rect GameObject::getGameObjectZone()
{
    return g_obj_zone;
}

int GameObject::getPositionBeginX()
{
    return g_obj_zone.x;
}

int GameObject::getPositionBeginY()
{
    return g_obj_zone.y;
}

void GameObject::setPosition(int x, int y)
{
    g_obj_zone.x = x;
    g_obj_zone.y = y;
}

void GameObject::setGameObjectZone(int x, int y, int w, int h)
{
    g_obj_zone.x = x;
    g_obj_zone.y = y;
    g_obj_zone.w = w;
    g_obj_zone.h = h;
}