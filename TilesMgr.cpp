#include "TilesMgr.h"
#include "Debug.h"
#include <experimental/filesystem>

namespace fs = std::experimental::filesystem;

const char* TILES_DIR = "assets/sprites/nZtiles";


static void fillMap(std::unordered_map<std::string, TypeTile>& map)
{
    map.emplace("Tile (1)", TILE_01);
    map.emplace("Tile (2)", TILE_02);
    map.emplace("Tile (3)", TILE_03);
    map.emplace("Tile (4)", TILE_04);
    map.emplace("Tile (5)", TILE_05);
    map.emplace("Tile (6)", TILE_06);
    map.emplace("Tile (7)", TILE_07);
    map.emplace("Tile (8)", TILE_08);
    map.emplace("Tile (9)", TILE_09);
    map.emplace("Tile (10)", TILE_10);
    map.emplace("Tile (11)", TILE_11);
    map.emplace("Tile (12)", TILE_12);
    map.emplace("Tile (13)", TILE_13);
    map.emplace("Tile (14)", TILE_14);
    map.emplace("Tile (15)", TILE_15);
}

static std::string extractFileName(const fs::path & path)
{
    std::string filename = path.filename();
    std::string extension = path.extension();
    return filename.replace(filename.size() - extension.size(), extension.size(), std::string());
}

TilesMgr::TilesMgr()
{

}

TilesMgr::~TilesMgr()
{
    for (auto& item : m_tileMap)
        delete item.second;

    m_tileMap.clear();
}

// Инициализация тайлового менеджера
void TilesMgr::init(SDL_Renderer* renderer)
{
    std::unordered_map<std::string, TypeTile> conformity_map;
    fillMap(conformity_map);

    auto di = fs::directory_iterator(TILES_DIR);
    for (auto& item : di)
    {
        const auto& path = item.path();
        debug() << path.c_str() << std::endl;

        SimpleTextureMgr* stm = new SimpleTextureMgr();
        stm->load(renderer, path.c_str());

        std::string filename = extractFileName(path);

        const auto& it = conformity_map.find(filename);
        if (it != conformity_map.end())
            m_tileMap.emplace(it->second, stm);
    }
}

SimpleTextureMgr* TilesMgr::getTextureByType(TypeTile typeTile)
{
    SimpleTextureMgr* res = nullptr;
    const auto& it = m_tileMap.find(typeTile);
    if (it != m_tileMap.end())
        res = it->second;

    return res;
}