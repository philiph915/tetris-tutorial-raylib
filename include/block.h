#pragma once

#include <vector>
#include <map>
#include "position.h"
#include "colors.h"

class Block {
public:
    Block();
    void Draw(int offsetX, int offsetY);
    void Move(int rows, int columns);
    void Rotate();
    void UndoRotation();
    std::vector<Position> GetCellPositions();
    int id; // id defines the color of the block
    

    // Cells is a "map" in which a rotation state is a key associated with a vector of Position objects called cells
    // cells is indexed as if it is an array, i.e. each key is just an integer value that gets assigned in the blocks.cpp file
    std::map<int,std::vector<Position>> cells;
private:
    int cellSize;
    int rotationState;
    std::vector<Color> colors;
    int rowOffset;
    int columnOffset;
};