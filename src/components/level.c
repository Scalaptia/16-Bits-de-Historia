#include "../headers/level.h"

LevelData room1;
Vector2 ROOM1_POS = {TILE_SIZE * 3, TILE_SIZE * 3};

void InitGraphics(GraphicsData *tileset)
{
    tileset->image = LoadImage(ASSETS_PATH "character and tileset/Dungeon_Tileset.png");
    tileset->texture = LoadTextureFromImage(tileset->image);
    tileset->size = (Rectangle){0, 0, tileset->texture.width, tileset->texture.height};
}

void ScaleRec(Rectangle *rec)
{
    rec->x *= SCALE;
    rec->y *= SCALE;
    rec->width *= SCALE;
    rec->height *= SCALE;
}

void DrawElement(GraphicsData *tileset, char *element, Vector2 position)
{
    if (strcmp(element, "ROOM") == 0)
    {
        Rectangle room_src = {0, 0, TILE_SIZE * 6, TILE_SIZE * 5};
        Rectangle room_dst = {position.x, position.y, room_src.width, room_src.height};
        ScaleRec(&room_dst);
        DrawTexturePro(tileset->texture, room_src, room_dst, (Vector2){0, 0}, 0, WHITE);
    }
}

void DrawRoom(GraphicsData *tileset, Vector2 position)
{
    // Create collision walls
    room1.wallsCount = 24;
    room1.walls = malloc(sizeof(Vector2) * room1.wallsCount);

    // Top and bottom walls
    for (int i = 0; i < 6; i++)
    {
        room1.walls[i] = (Vector2){position.x + (i * REL_TILE_SIZE), position.y};
        room1.walls[i + 6] = (Vector2){position.x + (i * REL_TILE_SIZE), position.y + (REL_TILE_SIZE * 4)};
    }

    // Left and right walls
    for (int i = 0; i < 5; i++)
    {
        room1.walls[i + 12] = (Vector2){position.x, position.y + (i * REL_TILE_SIZE)};
        room1.walls[i + 17] = (Vector2){position.x + (REL_TILE_SIZE * 5), position.y + (i * REL_TILE_SIZE)};
    }

    DrawElement(tileset, "ROOM", position);
}

void UnloadGraphics(GraphicsData *tileset)
{
    UnloadTexture(tileset->texture);
    UnloadImage(tileset->image);
}