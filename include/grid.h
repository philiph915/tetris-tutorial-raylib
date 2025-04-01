# pragma once
#include "raylib.h" // should use "raylib.h" instead of <raylib.h> since the raylib headers are included locally in this project
#include <vector>

class Grid {
    public:
        // functions
        Grid(); // Constructor
        void Initialize();
        void Print();
        void Draw();

        // properties
        int grid[20][10];

    private: 
        // functions
        
        // properties
        int numRows;
        int numCols;
        int cellSize;
        std::vector<Color> colors;
};