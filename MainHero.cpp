#include "MainHero.h"
#include <SDL2/SDL_image.h>
#include "TextureMgr.h"

MainHero::MainHero()
{
    // Задаем размеры главного героя
    //             x    y    w   h
    g_obj_zone = {100, 100, 56, 71};

    curRow = 1;
    curFrame = 0;

    textureName = "main_hero";

    // Указываем спрайтовый файл персонажа
    spriteFilePath = "assets/sprites/main_hero/Grue.png";

    textureMgr = new TextureMgr();
}

MainHero::~MainHero()
{
    delete textureMgr;
}

bool MainHero::init(SDL_Renderer *renderer)
{
    if(!textureMgr->load(spriteFilePath, textureName, renderer))
    {
        errorText = SDL_GetError();
        return false;
    }
    return true;
}

void MainHero::setTextureRowAndFrame(int row, int frame)
{
    curRow = row;
    curFrame = frame;
}

void MainHero::draw(SDL_Renderer *renderer)
{
    //textureMgr->draw(textureName, g_obj_zone.x, g_obj_zone.y, g_obj_zone.w, g_obj_zone.h, renderer);
    textureMgr->drawFrame(textureName, g_obj_zone.x, g_obj_zone.y, g_obj_zone.w, g_obj_zone.h, curRow, curFrame, renderer);
}

void MainHero::draw(SDL_Renderer *renderer, const SDL_Rect& camera)
{
    textureMgr->drawFrame(
        textureName,
        g_obj_zone.x - camera.x,
        g_obj_zone.y - camera.y,
        g_obj_zone.w,
        g_obj_zone.h,
        curRow,
        curFrame,
        renderer
    );
}