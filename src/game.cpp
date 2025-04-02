#include "game.h"
#include <random>
#include "raylib.h"

// Constructor method
Game::Game()
{
    grid = Grid();
    blocks = GetAllBlocks();
    currentBlock = GetRandomBlock();
    nextBlock = GetRandomBlock();
    gameOver = false;
    lastUpdateTime = 0;
}

// Function to return a random Block object from the list of available blocks, and remove that block from the list
Block Game::GetRandomBlock()
{
    if (blocks.empty())
    {
        blocks = GetAllBlocks();
    }
    int randomIndex = rand() % blocks.size(); // get a random integer from 0 to 6 in order to draw a block from the list
    Block block = blocks[randomIndex];
    blocks.erase(blocks.begin() + randomIndex); // remove the chosen block from the list of available blocks
    return block;
}

// Function to get a list of all possible blocks in the game
std::vector<Block> Game::GetAllBlocks()
{
    return {IBlock(), JBlock(), LBlock(), OBlock(), SBlock(), TBlock(), ZBlock()};
}

// Function to test if a block is outside the game grid
bool Game::IsBlockOutside()
{
    std::vector<Position> tiles = currentBlock.GetCellPositions();
    for (Position item: tiles)
    {
        if (grid.IsCellOutside(item.row,item.column))
        {
            return true;
        }
    }
    return false;
}

// Function to draw the current block on the grid
void Game::Draw()
{
    grid.Draw();
    currentBlock.Draw();
}

// Function for detecting user input and moving the blocks accordingly
void Game::HandleInput()
{
    // Get all keys that are pressed (returns 0 for no keys pressed)
    int keyPressed = GetKeyPressed();

    // Allow the user to move the current block if the game is not over
    if (gameOver == false)
    {
        switch (keyPressed)
        {
            case KEY_LEFT:
            MoveBlockLeft();
            break;
            
            case KEY_RIGHT:
            MoveBlockRight();
            break;
            
            case KEY_UP:
            RotateBlock();
            break;
            
            case KEY_DOWN:
            MoveBlockDown();
            break;
        }
    }
    // If the game is over and a key is pressed, reset the game
    else if (gameOver && keyPressed != 0)
    {
        Reset();
    }
}

void Game::MoveBlockLeft()
{
    currentBlock.Move(0,-1);
    // don't allow the block to move off the screen or sideways through another block
    if (IsBlockOutside() || BlockFits() == false)
    {
        currentBlock.Move(0,1);
    }
}

void Game::MoveBlockRight()
{
    currentBlock.Move(0,1);
    // don't allow the block to move off the screen or sideways through another block
    if (IsBlockOutside() || BlockFits() == false)
    {
        currentBlock.Move(0,-1);
    }
}

void Game::MoveBlockDown()
{
    // Do not make blocks fall if the game is over
    if (gameOver == false)
        {
        currentBlock.Move(1,0);
        // if moving the block down causes it to exit the screen or collide with another block, lock it in place
        if (IsBlockOutside() || BlockFits() == false)
        {
            currentBlock.Move(-1,0);
            LockBlock();
        }
    }
}

// this timer resets every time it returns true
bool Game::TimerTriggered(double interval)
{
    double currentTime = GetTime();
    if (currentTime - lastUpdateTime >= interval)
    {
        lastUpdateTime = currentTime;
        return true;
    }
    return false;
}

// Function to clear the grid, reset the list of blocks, and draw the current and next block
void Game::Reset()
{
    grid.Initialize();
    gameOver = false;
    lastUpdateTime = GetTime(); // reset the block dropping timer
    blocks = GetAllBlocks();
    currentBlock = GetRandomBlock();
    nextBlock = GetRandomBlock();
}

void Game::RotateBlock()
{
    currentBlock.Rotate();
    // don't allow the block to rotate off the screen or sideways through another block
    if (IsBlockOutside() || BlockFits() == false)
    {
        currentBlock.UndoRotation();
    }
}

// Function to move a block from currentBlock to the game grid and clear full rows
void Game::LockBlock()
{
    // update the grid with the current block to be locked
    std::vector<Position> tiles = currentBlock.GetCellPositions();
    for (Position item: tiles)
    {
        // update the map object (grid) with the ID of each cell of the current block in its current location
        grid.grid[item.row][item.column] = currentBlock.id; 
    }
    
    // spawn a new block
    currentBlock = nextBlock;

    // if the newly spawned block does not fit in the grid, the game ends
    if (BlockFits() == false)
    {
        gameOver = true;
    }

    // draw the next block
    nextBlock = GetRandomBlock();

    // remove rows that have been filled by the placement of this block
    grid.ClearFullRows(); 
}


// Function to test if all the cells a block occupies are unoccupied by other blocks
bool Game::BlockFits()
{
    std::vector<Position> tiles = currentBlock.GetCellPositions();
    for (Position item: tiles)
    {
        if (grid.IsCellEmpty(item.row,item.column) == false)
        {
            return false;
        }
    }
    return true;
}
