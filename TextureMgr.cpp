#include "TextureMgr.h"
#include <SDL2/SDL_image.h>

bool TextureMgr::load(const std::string& fileName, const std::string& id, SDL_Renderer *renderer)
{
    SDL_Surface *tempSurface = IMG_Load(fileName.c_str());
    if(tempSurface == 0)
        return false;

    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, tempSurface);
    SDL_FreeSurface(tempSurface);
    if(tempSurface != 0)
    {
        m_textureMap[id] = texture;
        return true;
    }

    return false;
}

void TextureMgr::draw(const std::string& id, int x, int y, int w, int h, SDL_Renderer *renderer,
        SDL_RendererFlip flip)
{
    SDL_Rect srcRect, dstRect;

    srcRect.x = 0;
    srcRect.y = 0;
    srcRect.w = dstRect.w = w;
    srcRect.h = dstRect.h = h;
    dstRect.x = x;
    dstRect.y = y;

    SDL_RenderCopyEx(renderer, m_textureMap[id], &srcRect, &dstRect, 0, 0, flip);
}

void TextureMgr::drawFrame(const std::string& id, int x, int y, int w, int h, int curRow,
        int curFrame, SDL_Renderer *renderer, SDL_RendererFlip flip)
{
    SDL_Rect srcRect, dstRect;
    srcRect.x = w * curFrame;
    srcRect.y = h * (curRow - 1);
    srcRect.w = dstRect.w = w;
    srcRect.h = dstRect.h = h;
    dstRect.x = x;
    dstRect.y = y;

    SDL_RenderCopyEx(renderer, m_textureMap[id], &srcRect, &dstRect, 0, 0, flip);
}