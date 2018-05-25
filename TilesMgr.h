#include <unordered_map>

#include "SimpleTextureMgr.h"


class TilesMgr
{
    typedef std::unordered_map<std::string, SimpleTextureMgr*> TileMap;
public:
    TilesMgr();
    ~TilesMgr();

private:
    TileMap m_tileMap;

    void init();
};
