#include "block.h"
#include "position.h"

Block::Block()
{
    cellSize = 30;
    rotationState = 0;
    colors = GetCellColors();
    rowOffset = 0;
    columnOffset = 0;
}

void Block::Draw()
{
    std::vector<Position> tiles = GetCellPositions();
    for (Position item: tiles) // loop across each item in the tiles vector and draw it
    {
        DrawRectangle(item.column * cellSize+1, item.row * cellSize+1, cellSize-1, cellSize-1, colors[id]);
    }
}

void Block::Move(int rows, int columns) 
{
    rowOffset += rows;
    columnOffset += columns;
}

void Block::Rotate()
{
    rotationState++;
    
    // wrap back to 0
    if (rotationState==cells.size())
    {
        rotationState=0;
    }
}

void Block::UndoRotation()
{
    rotationState--;
    if (rotationState==-1)
    {
        rotationState=cells.size()-1;
    }
}

std::vector<Position> Block::GetCellPositions()
{
    std::vector<Position> tiles = cells[rotationState];
    std::vector<Position> movedTiles;
    for (Position item: tiles )
    {
        Position newPos = Position(item.row + rowOffset, item.column + columnOffset);
        movedTiles.push_back(newPos); // appends the position newPos to the vector of positions in movedTiles
    }
    return movedTiles;
}