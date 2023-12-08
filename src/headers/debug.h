#ifndef DEBUG_H
#define DEBUG_H

#include "raylib.h"
#include "player.h"
#include "level.h"

typedef struct Grid
{
    float cellSize;
    Vector2 position;
    int width;
    int height;
    Color color;
} Grid;

void PaintGrid(Grid grid);
void DebugRoom(Camera2D camera, Player player, LevelData room, Vector2 position);

#endif