#include "../headers/debug.h"

void PaintGrid(Grid grid)
{
    for (int i = 0; i < grid.width / grid.cellSize + 1; i++)
    {
        DrawLineV((Vector2){(float)grid.cellSize * i + grid.position.x, grid.position.y}, (Vector2){(float)grid.cellSize * i + grid.position.x, (float)grid.height + grid.position.y}, grid.color);
    }

    for (int i = 0; i < grid.height / grid.cellSize + 1; i++)
    {
        DrawLineV((Vector2){grid.position.x, (float)grid.cellSize * i + grid.position.y}, (Vector2){(float)grid.width + grid.position.x, (float)grid.cellSize * i + grid.position.y}, grid.color);
    }

    for (int i = 0; i < grid.width / grid.cellSize; i++)
    {
        for (int j = 0; j < grid.height / grid.cellSize; j++)
        {
            DrawText(TextFormat("[%i,%i]", i, j), 10 + grid.cellSize * i + grid.position.x, 15 + grid.cellSize * j + grid.position.y, 10, grid.color);
        }
    }
}

void DebugRoom(Camera2D camera, Player player, LevelData room, Vector2 position)
{
    // Paint grid considering sizeof room
    PaintGrid((Grid){REL_TILE_SIZE, (Vector2){position.x * REL_TILE_SIZE, position.y * REL_TILE_SIZE}, REL_TILE_SIZE * ((room.tileset.size.width / TILE_SIZE) + 2), REL_TILE_SIZE * ((room.tileset.size.height / TILE_SIZE) + 2), LIGHTGRAY});

    DrawRectangle(player.position.x, player.position.y, REL_TILE_SIZE, REL_TILE_SIZE, player.color); // player collision
    DrawRectangleLinesEx(player.hitbox, 4, BLACK);

    // Draw debug walls
    for (int i = 0; i < room.wallsCount; i++)
    {
        Rectangle wallRect = {room.walls[i].x, room.walls[i].y, REL_TILE_SIZE, REL_TILE_SIZE};
        if (IsRectangleOnCamera(wallRect, camera))
        {
            DrawRectangleLinesEx(wallRect, 4, RED);
        }
    }

    // Draw debug objects
    for (int i = 0; i < room.objectsCount; i++)
    {
        if (IsRectangleOnCamera(room.objects[i], camera))
        {
            DrawRectangleLinesEx(room.objects[i], 4, MAROON);
        }
    }
}
