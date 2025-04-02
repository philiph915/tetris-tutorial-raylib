#pragma once

#include "grid.h"
#include "blocks.hpp"

class Game
{
public:
    Game();
    Block GetRandomBlock();
    void Draw();
    void HandleInput();
    void MoveBlockLeft();
    void MoveBlockRight();
    void MoveBlockDown();
    
    std::vector<Block> GetAllBlocks();
    Block currentBlock;
    Block nextBlock;
    Grid grid;
    
private:
    bool IsBlockOutside();
    void RotateBlock();
    void LockBlock();
    bool BlockFits();
    std::vector<Block> blocks;
};