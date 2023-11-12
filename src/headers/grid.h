#ifndef GRID_H
#define GRID_H

#include "raylib.h"

typedef struct Grid
{
    float cellSize;
    int width;
    int height;
    Color color;
} Grid;

void PaintGrid(Grid grid);

#endif