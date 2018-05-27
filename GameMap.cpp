
#include "GameMap.h"

GameMap::GameMap()
    : gameWidth(0)
    , gameHeight(0)
{
}

GameMap::~GameMap()
{
}

// загрузка карты из файла
void GameMap::loadMap()
{
    // пока не продумали формат генерируем руками
    map.push_back({TILE_02, {128 * 0,128}});
    map.push_back({TILE_02, {128 * 1,128}});
    map.push_back({TILE_02, {128 * 2,128}});
    map.push_back({TILE_02, {128 * 3,128}});
    map.push_back({TILE_02, {128 * 4,128}});
    map.push_back({TILE_02, {128 * 5,128}});
    map.push_back({TILE_02, {128 * 6,128}});
    map.push_back({TILE_02, {128 * 7,128}});
    map.push_back({TILE_02, {128 * 8,128}});
    map.push_back({TILE_02, {128 * 9,128}});
    map.push_back({TILE_02, {128 * 10,128}});
    map.push_back({TILE_02, {128 * 11,128}});
    map.push_back({TILE_02, {128 * 12,128}});
    map.push_back({TILE_02, {128 * 13,128}});
    map.push_back({TILE_02, {128 * 14,128}});
    map.push_back({TILE_02, {128 * 15,128}});
}

void GameMap::renderMap(SDL_Renderer* renderer, TilesMgr* tilesMgr, SDL_Rect* camera)
{
    for(const auto& item : map)
    {
        auto texture = tilesMgr->getTextureByType(item.tile);
        const auto& point = item.point;
        int x = point.x - camera->x;
        int y = gameHeight - point.y - camera->y;
        texture->render(renderer, x, y);
    }
}

void GameMap::setGameBounds(int width, int height)
{
    gameWidth = width;
    gameHeight = height;
}