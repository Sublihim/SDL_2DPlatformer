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
    SDL_Texture *hero_texture;
    int curRow;
    int curFrame;
    TextureMgr *textureMgr;
    std::string textureName;
public:
    MainHero() noexcept;
    ~MainHero();
    bool init(SDL_Renderer *renderer);
    void setTextureRowAndFrame(int row, int frame);
    void draw(SDL_Renderer *renderer);
};

#endif // MAINHERO_H_INCLUDED