#ifndef GAMEOBJECT_H_INCLUDED
#define GAMEOBJECT_H_INCLUDED

#include <SDL2/SDL.h>
#include <iostream>

class GameObject
{
protected:
    SDL_Rect g_obj_zone;
    std::string errorText;
public:
    virtual ~GameObject() {};
    virtual std::string getErrorText();
    virtual SDL_Rect getGameObjectZone();
    virtual int getPositionBeginX() const;
    virtual int getPositionBeginY() const;
    virtual void setPosition(int x, int y);
    virtual void setGameObjectZone(int x, int y, int w, int h);
    virtual bool init(SDL_Renderer *renderer) = 0;
    virtual void setTextureRowAndFrame(int row, int frame) = 0;
    virtual void draw(SDL_Renderer *renderer) = 0;
};

#endif // GAMEOBJECT_H_INCLUDED