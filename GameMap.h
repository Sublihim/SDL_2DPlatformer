#ifndef GAMEMAP_INCLUDE
#define GAMEMAP_INCLUDE

#include "TilesMgr.h"
#include <vector>

class TilesMgr;
// класс игровой карты
class GameMap
{
    struct MapObject
    {
        TypeTile tile;
        SDL_Point point;
    };

    typedef std::vector<MapObject> VMap;
public:
    GameMap();
    ~GameMap();
    void renderMap(SDL_Renderer* renderer, TilesMgr* tilesMgr, SDL_Rect* camera);
    void loadMap();
    void setGameBounds(int width, int height);
    int getDistanceFollow(const SDL_Rect& sdlRect, const TilesMgr* tilesMgr) const;
private:
    VMap map;
    int gameWidth;
    int gameHeight;
};

#endif // GAMEMAP_INCLUDE