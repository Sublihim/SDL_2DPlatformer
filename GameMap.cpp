﻿#include "GameMap.h"
#include "TilesMgr.h"
#include "algorithm"

GameMap::GameMap()
    : gameWidth(0)
    , gameHeight(0)
    , correctY(0)
{
}

GameMap::~GameMap()
{
}

// загрузка карты из файла
void GameMap::loadMap()
{
    // пока не продумали формат генерируем руками
    map.push_back({TILE_02, {128 * 0,  128}});
    map.push_back({TILE_02, {128 * 1,  128}});
    map.push_back({TILE_02, {128 * 2,  128}});
    map.push_back({TILE_02, {128 * 3,  128}});
    map.push_back({TILE_02, {128 * 4,  128}});
    map.push_back({TILE_02, {128 * 5,  128}});
    map.push_back({TILE_02, {128 * 6,  128}});
    map.push_back({TILE_02, {128 * 7,  128}});
    map.push_back({TILE_02, {128 * 8,  128}});
    map.push_back({TILE_02, {128 * 9,  128}});
    map.push_back({TILE_02, {128 * 10, 128}});
    map.push_back({TILE_02, {128 * 11, 128}});
    map.push_back({TILE_02, {128 * 12, 128}});
    map.push_back({TILE_02, {128 * 13, 128}});
    map.push_back({TILE_02, {128 * 14, 128}});
    map.push_back({TILE_02, {128 * 15, 128}});
}

void GameMap::renderMap(SDL_Renderer* renderer, TilesMgr* tilesMgr, SDL_Rect* camera)
{
    for(const auto& item : map)
    {
        auto texture = tilesMgr->getTextureByType(item.tile);
        const auto& point = item.point;

        int x = point.x - camera->x;
        // коррекция y на gameHeight нужна, для отображения координат,
        // т.к. "карта задана" для координат с ТО внизу слева
        int y = gameHeight - point.y - camera->y;

        texture->render(renderer, x, y);
    }
}

void GameMap::setGameBounds(int width, int height)
{
    gameWidth = width;
    gameHeight = height;
}


bool GameMap::isCollisionBottom(const SDL_Rect& sdlRect, const TilesMgr* tilesMgr) const
{
    bool res = false;
    for(const auto& item : map)
    {
        auto texture = tilesMgr->getTextureByType(item.tile);
        const auto& point = item.point;
        SDL_Rect rectMapObj = {
            point.x,
            gameHeight - point.y, //переходим к y координате
            texture->getWidth(),
            texture->getHeight()
        };

        auto result = SDL_HasIntersection(&sdlRect, &rectMapObj);
        if (result == SDL_TRUE)
        {
            res = true;
            correctY = (rectMapObj.y) - (sdlRect.y + sdlRect.h);
            break;
        }
    }
    return res;
}

int GameMap::getDistanceFollow(const SDL_Rect& sdlRect, const TilesMgr* tilesMgr) const
{
    int distance = -1;
    for(const auto& item : map)
    {
        auto texture = tilesMgr->getTextureByType(item.tile);
        const auto& point = item.point;
        int tileRight = point.x + texture->getWidth();
        int objRight = sdlRect.x + sdlRect.y;
        bool inIntersect = !((sdlRect.x < point.x && objRight < point.x) ||
                            (sdlRect.x > tileRight && objRight > tileRight));
        if (inIntersect)
        {
            int newDistance = (gameHeight - point.y - (sdlRect.y + sdlRect.h));
            distance = (distance < 0) ? newDistance : std::min(distance, newDistance);
        }
    }
    return distance;
}

int GameMap::getCorrectY() const
{
    int res = correctY;
    correctY = 0;
    return res;
}