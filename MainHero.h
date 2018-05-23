#ifndef MAINHERO_H_INCLUDED
#define MAINHERO_H_INCLUDED

#include "GameObject.h"
#include <SDL2/SDL.h>
#include <iostream>

class TextureMgr;

class MainHero : public GameObject
{
private:
    std::string spriteFilePath;
    int curRow;
    int curFrame;
    TextureMgr *textureMgr;
    std::string textureName;
    void setTextureRowAndFrame(int row, int frame);
public:
    MainHero();
    ~MainHero();
    void setDirectionLeft();
    void setDirectionRight();
    void setNoDirection();
    void setDirectionUp();
    bool init(SDL_Renderer *renderer);
    void draw(SDL_Renderer *renderer);
    void draw(SDL_Renderer *renderer, const SDL_Rect& camera);
};

#endif // MAINHERO_H_INCLUDED