#ifndef TILESMGR_H_INCLUDED
#define TILESMGR_H_INCLUDED

#include <unordered_map>

#include "SimpleTextureMgr.h"

class SDL_Renderer;


enum TypeTile {
        TILE_01 = 0, TILE_02, TILE_03, TILE_04, TILE_05, TILE_06, TILE_07, TILE_08, TILE_09, TILE_10, TILE_11, TILE_12, TILE_13, TILE_14, TILE_15,
        BONE_01, BONE_02, BONE_03, BONE_04
    };

class TilesMgr
{
    typedef std::unordered_map<TypeTile, SimpleTextureMgr*> TileMap;
public:
    TilesMgr();
    ~TilesMgr();

    void init(SDL_Renderer* renderer);
    SimpleTextureMgr* getTextureByType(TypeTile typeTile) const;
private:
    TileMap m_tileMap;


};

#endif //TILESMGR_H_INCLUDED