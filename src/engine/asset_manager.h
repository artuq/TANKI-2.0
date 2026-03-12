#ifndef ENGINE_ASSET_MANAGER_H
#define ENGINE_ASSET_MANAGER_H

#include <string>
#include <unordered_map>

class AssetManager {
public:
    static AssetManager &getInstance();
    bool loadTexture(const std::string &id, const std::string &path);
private:
    AssetManager() = default;
    std::unordered_map<std::string, int> m_textures; // placeholder for texture handles
};

#endif // ENGINE_ASSET_MANAGER_H

#ifndef ENGINE_ASSET_MANAGER_H
#define ENGINE_ASSET_MANAGER_H

#include <string>
#include <unordered_map>

class AssetManager {
public:
    static AssetManager &getInstance();
    bool loadTexture(const std::string &id, const std::string &path);
private:
    AssetManager() = default;
    std::unordered_map<std::string, int> m_textures; // placeholder for texture handles
};

#endif // ENGINE_ASSET_MANAGER_H
