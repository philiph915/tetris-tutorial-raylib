#include "game.h"
#include <random>

Game::Game()
{
    grid = Grid();
    blocks = GetAllBlocks();
    currentBlock = GetRandomBlock();
    nextBlock = GetRandomBlock();
}
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

void Game::Draw()
{
    grid.Draw();
    currentBlock.Draw();
}


// Function for detecting user input and moving the blocks accordingly
void Game::HandleInput()
{
    int keyPressed = GetKeyPressed();
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
    currentBlock.Move(1,0);
    // if moving the block down causes it to exit the screen or collide with another block, lock it in place
    if (IsBlockOutside() || BlockFits() == false)
    {
        currentBlock.Move(-1,0);
        LockBlock();
    }
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

// Function to move a block from currentBlock to the game grid
void Game::LockBlock()
{
    std::vector<Position> tiles = currentBlock.GetCellPositions();
    for (Position item: tiles)
    {
        // update the map object (grid) with the ID of each cell of the current block in its current location
        grid.grid[item.row][item.column] = currentBlock.id; 
    }
    // spawn a new block
    currentBlock = nextBlock;
    nextBlock = GetRandomBlock();
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
