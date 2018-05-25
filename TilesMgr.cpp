#include "TilesMgr.h"


TilesMgr::TilesMgr()
{
}

TilesMgr::~TilesMgr()
{
    for (auto& item : m_tileMap)
        delete item.second;

    m_tileMap.clear();
}


void TilesMgr::init()
{
    // загрузить тайлы
}