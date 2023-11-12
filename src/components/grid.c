#include "../headers/grid.h"

void PaintGrid(Grid grid)
{
    for (int i = 0; i < grid.width / grid.cellSize + 1; i++)
    {
        DrawLineV((Vector2){(float)grid.cellSize * i, 0}, (Vector2){(float)grid.cellSize * i, (float)grid.height}, grid.color);
    }

    for (int i = 0; i < grid.height / grid.cellSize + 1; i++)
    {
        DrawLineV((Vector2){0, (float)grid.cellSize * i}, (Vector2){(float)grid.width, (float)grid.cellSize * i}, grid.color);
    }

    for (int i = 0; i < grid.width / grid.cellSize; i++)
    {
        for (int j = 0; j < grid.height / grid.cellSize; j++)
        {
            DrawText(TextFormat("[%i,%i]", i, j), 10 + grid.cellSize * i, 15 + grid.cellSize * j, 10, grid.color);
        }
    }
}