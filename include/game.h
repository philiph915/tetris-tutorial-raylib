#pragma once

#include "grid.h"
#include "blocks.hpp"
#include "assets.h"

class Game
{
public:
    // Functions
    Game();
    ~Game();
    void Draw();
    void HandleInput();
    void MoveBlockDown();
    bool TimerTriggered(double interval);
    
    // Properties
    bool gameOver;
    int score;
    // Music music;
    
    private:
    // Functions
    bool IsBlockOutside();
    void RotateBlock();
    void LockBlock();
    bool BlockFits();
    void Reset();
    Block GetRandomBlock();
    void MoveBlockLeft();
    void MoveBlockRight();
    void UpdateScore(int linesCleared, int moveDownPoints);
    std::vector<Block> GetAllBlocks();

    
    // Properties
    GameAssets gameSounds;
    Block currentBlock;
    Block nextBlock;
    double lastUpdateTime;
    Grid grid;
    std::vector<Block> blocks;
    Sound rotateSound;
    Sound clearSound;
};