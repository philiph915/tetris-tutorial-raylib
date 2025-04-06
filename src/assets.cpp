#include "assets.h"
#include <iostream>

// Function to load all assets (using the LoadAsset method)
// This function will progamatically add assets by their file name to 
// GameAssets(). As you add more assets to the game, add them here to make 
// sure they are loaded!

void GameAssets::LoadAssets() {
    // Example of loading assets dynamically
    LoadAsset("AmaticSC-Regular", "font");       // Load Amatic font
    LoadAsset("monogram","font");                // Load monogram font
    LoadAsset("Eurobeat_Remix","music");         // Load background music
    // LoadAsset("rotate","sound");
    // LoadAsset("clear","sound");

    // LoadAsset("player", "texture");    // Loads player texture
    // LoadAsset("background", "music"); // Loads background music
}

void GameAssets::LoadAsset(const std::string& key, const std::string& type) {
    if (type == "font") {
        // Load font
        fonts[key] = LoadFontEx((FONTS_PATH + key + ".ttf").c_str(), 64, 0, 0);
        if (fonts[key].texture.id == 0) {
            std::cerr << "Failed to load font: " << key << std::endl;
        }
    } else if (type == "texture") {
        // Load texture
        textures[key] = LoadTexture((ASSETS_PATH + key + ".png").c_str());
        if (textures[key].id == 0) {
            std::cerr << "Failed to load texture: " << key << std::endl;
        }
    } else if (type == "music") {
        // Load music
        music[key] = LoadMusicStream((SOUNDS_PATH + key + ".mp3").c_str());
        if (!IsMusicValid(music[key])) {  // Check if music stream is ready
            std::cerr << "Failed to load music: " << key << std::endl;
        }
    } else if (type == "sound") {
        // Load music
        sounds[key] = LoadSound((SOUNDS_PATH + key + ".mp3").c_str());
        if (!IsSoundValid(sounds[key])) {  // Check if music stream is ready
            std::cerr << "Failed to load sound: " << key << std::endl;
        }
    } else {
        std::cerr << "Unknown asset type: " << type << std::endl;
    }
}

