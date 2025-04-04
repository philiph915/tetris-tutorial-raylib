#ifndef ASSETS_H
#define ASSETS_H

#include "paths.h"
#include "raylib.h"
#include <string>
#include <map>

class GameAssets {
public:
    // Maps for different asset types
    std::map<std::string, Font> fonts;
    std::map<std::string, Texture2D> textures;
    std::map<std::string, Music> music;

    // Function to load a specific asset by type and key
    void LoadAsset(const std::string& key, const std::string& type);

    // Function to load all assets at once
    void LoadAssets();
};

#endif // ASSETS_H
