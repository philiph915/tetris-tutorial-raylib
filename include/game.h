#pragma once

#include "grid.h"
#include "blocks.hpp"

class Game
{
public:
    // Functions
    Game();
    Block GetRandomBlock();
    void Draw();
    void HandleInput();
    void MoveBlockLeft();
    void MoveBlockRight();
    void MoveBlockDown();
    bool TimerTriggered(double interval);
    std::vector<Block> GetAllBlocks();

    // Properties
    Block currentBlock;
    Block nextBlock;
    Grid grid;
    bool gameOver;
    double lastUpdateTime;
    
private:
    // Functions
    bool IsBlockOutside();
    void RotateBlock();
    void LockBlock();
    bool BlockFits();
    void Reset();
    
    // Properties
    std::vector<Block> blocks;
};