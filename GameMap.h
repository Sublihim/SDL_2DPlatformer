#ifndef GAMEMAP_INCLUDE
#define GAMEMAP_INCLUDE

#include "TilesMgr.h"
#include "IGameMap.h"
#include <vector>

class TilesMgr;
// класс игровой карты
class GameMap : public IGameMap
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
    bool isCollisionBottom(const SDL_Rect& sdlRect, const TilesMgr* tilesMgr) const;
    int getDistanceFollow(const SDL_Rect& sdlRect, const TilesMgr* tilesMgr) const;
    int getCorrectY() const;
private:
    VMap map;
    int gameWidth;
    int gameHeight;
    mutable int correctY;
};

#endif // GAMEMAP_INCLUDE