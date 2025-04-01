#pragma once

#include "grid.h"
#include "blocks.hpp"

class Game
{
public:
    Game();
    Block GetRandomBlock();
    void Draw();

    std::vector<Block> GetAllBlocks();
    Block currentBlock;
    Block nextBlock;
    Grid grid;

private:
    std::vector<Block> blocks;
};