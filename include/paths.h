#include <string>
#include "raylib.h"

// Store paths important to the game (assets, save files, build directory, etc.)
const std::string EXECUTABLE_PATH = GetApplicationDirectory(); 
const std::string FONTS_PATH = EXECUTABLE_PATH + "../Fonts/"; 
const std::string ASSETS_PATH = EXECUTABLE_PATH + "../Assets/";