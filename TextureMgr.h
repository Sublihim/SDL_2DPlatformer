#ifndef TEXTUREMGR_H_INCLUDED
#define TEXTUREMGR_H_INCLUDED

#include <SDL2/SDL.h>
#include <iostream>
#include <map>

class TextureMgr
{
private:
    std::map<std::string,  SDL_Texture*> m_textureMap;
public:
    bool load(const std::string& fileName, const std::string& id, SDL_Renderer *renderer);
    void draw(const std::string& id, int x, int y, int w, int h, SDL_Renderer *renderer,
            SDL_RendererFlip flip = SDL_FLIP_NONE);
    void drawFrame(const std::string& id, int x, int y, int w, int h, int curRow,
            int curFrame, SDL_Renderer *renderer, SDL_RendererFlip flip = SDL_FLIP_NONE);
};

#endif // TEXTUREMGR_H_INCLUDED