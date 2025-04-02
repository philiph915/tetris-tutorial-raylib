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
    bool IsCellOutside(int row, int column);
    bool IsCellEmpty(int row, int column);
    int ClearFullRows();

    
    // properties
    int grid[20][10];
    
private: 
    // functions
    bool IsRowFull(int row);
    void ClearRow(int row);
    void MoveRowDown(int row, int numRows);
    
    // properties
    int numRows;
    int numCols;
    int cellSize;
    std::vector<Color> colors;
};