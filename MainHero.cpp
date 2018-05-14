#include "MainHero.h"
#include <SDL2/SDL_image.h>
#include "TextureMgr.h"

MainHero::MainHero() noexcept
    : hero_texture(nullptr)
{
    // Задаем размеры главного героя
    g_obj_zone.x = 100;
    g_obj_zone.y = 100;
    g_obj_zone.w = 56;
    g_obj_zone.h = 71;

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
    if(textureMgr->load(spriteFilePath, textureName, renderer))
        return true;
    else
    {
        errorText = SDL_GetError();
        return false;
    }
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