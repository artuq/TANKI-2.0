#include "asset_manager.h"

AssetManager &AssetManager::getInstance() { static AssetManager s; return s; }

bool AssetManager::loadTexture(const std::string &id, const std::string &path)
{
    // placeholder: in future return actual SDL texture handle
    m_textures[id] = 1;
    return true;
}
