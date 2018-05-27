#ifndef SIMPLETEXTUREMGR_INCLUDE
#define SIMPLETEXTUREMGR_INCLUDE

#include <string>
#include <SDL2/SDL_render.h>

class SDL_Rect;
class SDL_Point;
class SDL_Texture;

//Класс для загрузки простой текстуры
class SimpleTextureMgr
{
public:
    SimpleTextureMgr();
    ~SimpleTextureMgr();
    bool load(SDL_Renderer* renderer, const std::string& pathToTexture);
    void free();
    void render(SDL_Renderer* renderer, int x, int y,
                SDL_Rect* clip = NULL,
                double angle = 0.0,
                SDL_Point* center = NULL,
                SDL_RendererFlip flip = SDL_FLIP_NONE);
    int getWidth() const;
    int getHeight() const;

private:
    SDL_Texture* texture;
    int width;
    int height;
};

#endif // SIMPLETEXTUREMGR_INCLUDE