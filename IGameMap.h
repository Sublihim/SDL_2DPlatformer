#ifndef IGAMEMAP_INCLUDE
#define IGAMEMAP_INCLUDE

class SDL_Rect;
class TilesMgr;

// Интерфейс общий для всех игровых карт
struct IGameMap
{
    virtual bool isCollisionBottom(const SDL_Rect& sdlRect, const SDL_Rect* camera, const TilesMgr* tilesMgr) const = 0;
    virtual ~IGameMap() {}
};


#endif // IGAMEMAP_INCLUDE