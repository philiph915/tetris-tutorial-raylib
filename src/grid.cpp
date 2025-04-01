#include "grid.h"
#include <iostream>
#include "colors.h"

Grid::Grid()
{
    numRows = 20;
    numCols = 10;
    cellSize = 30;
    Initialize(); // call the initialize function upon creation of the object
    colors = GetCellColors();
}

void Grid::Initialize()
{
    // Loop across rows and columns in the grid, initialize all cells as 0's
    for (int row = 0; row < numRows; row++)
    {
        for (int column = 0; column<numCols; column++)
        {
            grid[row][column] = 0;
        }
    }
}

// Function to print the current status of the grid to the console
void Grid::Print()
{
    for (int row = 0; row < numRows; row++)
    {
        for (int column = 0; column<numCols; column++)
        {
            std::cout << grid[row][column] << " ";
        }
        std::cout << std::endl;
    }
}

// Function to draw every cell in the grid
void Grid::Draw()
{
    for (int row = 0; row < numRows; row++)
    {
        for (int column = 0; column<numCols; column++)
        {
            int cellValue = grid[row][column];
            DrawRectangle(column * cellSize+1, row * cellSize+1, cellSize-1, cellSize-1, colors[cellValue]);
        }
    }
}
