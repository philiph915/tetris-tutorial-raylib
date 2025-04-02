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

bool Grid::IsCellOutside(int row, int column)
{
    if (row >= 0 && row < numRows && column >= 0 && column < numCols)
    {
        return false;
    }
    return true;
}

// function to check if a specific cell is empty (has ID == 0)
bool Grid::IsCellEmpty(int row, int column)
{
    if (grid[row][column] == 0)
    {
        return true;
    }
    return false;
}

int Grid::ClearFullRows()
{
    int completed = 0;
    for (int row = numRows-1; row >= 0; row--)
    {
        if (IsRowFull(row))
        {
            ClearRow(row);
            completed++;
        }
        else if (completed > 0)
        {
            MoveRowDown(row, completed);
        }
    }
    return completed;
}

// Function to check if a specific row does not contain any 0's 
bool Grid::IsRowFull(int row)
{
    for (int column = 0; column < numCols; column++)
    {
        if (grid[row][column] == 0)
        {
            return false;
        }
    }
    return true;
}

// Function to set all cells in a given row to 0
void Grid::ClearRow(int row)
{
    for (int column = 0; column < numCols; column++)
    {
        grid[row][column] = 0;
    }
}

// Function to move a row down by a number of rows
void Grid::MoveRowDown(int row, int nRows)
{
    for (int column = 0; column < numCols; column++)
    {
        // copy the values from the current row to a new row nRows down, then clear the original row
        grid[row+nRows][column] = grid[row][column];
        grid[row][column] = 0;
    }
}
