
#include "SimpleTextureMgr.h"

#include <SDL2/SDL_image.h>

#include "Debug.h"

SimpleTextureMgr::SimpleTextureMgr()
    : texture(nullptr), width(0), height(0)
{
}


SimpleTextureMgr::~SimpleTextureMgr()
{
    free();
}


bool SimpleTextureMgr::load(SDL_Renderer* renderer, const std::string& pathToTexture)
{
    free();
    SDL_Texture* newTexture = nullptr;
    SDL_Surface* loadedSurface = IMG_Load(pathToTexture.c_str());
    if (loadedSurface == nullptr)
    {
        debug() << "error load surface" << std::endl;
    }
    else
    {
        SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB( loadedSurface->format, 0, 0xFF, 0xFF ));
        newTexture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
        if (newTexture == nullptr)
        {
            debug() << "unable to create texture" << std::endl;
        }
        else
        {
            width = loadedSurface->w;
            height = loadedSurface->h;
        }

        SDL_FreeSurface(loadedSurface);
    }
    texture = newTexture;
    return newTexture != nullptr;
}


void SimpleTextureMgr::free()
{
    if (texture != nullptr)
    {
        SDL_DestroyTexture(texture);
        texture = nullptr;
        width = 0;
        height = 0;
    }
}


void SimpleTextureMgr::render(SDL_Renderer* renderer, int x, int y, SDL_Rect* clip, double angle,
                              SDL_Point* center, SDL_RendererFlip flip)
{
    SDL_Rect renderQuad = {x, y, width, height};

    if (clip != nullptr)
    {
        renderQuad.w = clip->w;
        renderQuad.h = clip->h;
    }

    SDL_RenderCopyEx(renderer, texture, clip, &renderQuad, angle, center, flip);
}


int SimpleTextureMgr::getWidth() const
{
    return width;
}


int SimpleTextureMgr::getHeight() const
{
    return height;
}