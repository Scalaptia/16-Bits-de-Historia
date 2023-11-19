#include "../headers/graphics.h"

void InitGraphics(GraphicsData *tileset)
{
    tileset->image = LoadImage(ASSETS_PATH "character and tileset/Dungeon_Tileset.png");
    tileset->texture = LoadTextureFromImage(tileset->image);
    tileset->size = (Rectangle){0, 0, tileset->texture.width, tileset->texture.height};
}

void ScaleRec(Rectangle *rec, float scale)
{
    rec->x *= scale;
    rec->y *= scale;
    rec->width *= scale;
    rec->height *= scale;
}

void DrawElement(GraphicsData *tileset, char *element, Vector2 position, float scale)
{
    if (strcmp(element, "ROOM") == 0)
    {
        Rectangle room_src = {0, 0, TILE_SIZE * 6, TILE_SIZE * 5};
        Rectangle room_dst = {position.x, position.y, room_src.width, room_src.height};
        ScaleRec(&room_dst, scale);
        DrawTexturePro(tileset->texture, room_src, room_dst, (Vector2){0, 0}, 0, WHITE);
    }

    if (strcmp(element, "WALL_1") == 0)
    {
        Rectangle wall_src = {TILE_SIZE, 0, TILE_SIZE, TILE_SIZE};
        Rectangle wall_dst = {position.x, position.y, wall_src.width, wall_src.height};
        ScaleRec(&wall_dst, scale);
        DrawTexturePro(tileset->texture, wall_src, wall_dst, (Vector2){0, 0}, 0, WHITE);
    }

    if (strcmp(element, "FLOOR_1") == 0)
    {
        Rectangle floor_src = {TILE_SIZE * 7, TILE_SIZE, TILE_SIZE, TILE_SIZE};
        Rectangle floor_dst = {position.x, position.y, floor_src.width, floor_src.height};
        ScaleRec(&floor_dst, scale);
        DrawTexturePro(tileset->texture, floor_src, floor_dst, (Vector2){0, 0}, 0, WHITE);
    }

    if (strcmp(element, "DOOR_LEFT_OPEN") == 0)
    {
        DrawElement(tileset, "WALL_1", position, scale);
        DrawElement(tileset, "FLOOR_1", Vector2Add(position, DOWN), scale);
    }
}

void UnloadGraphics(GraphicsData *tileset)
{
    UnloadTexture(tileset->texture);
    UnloadImage(tileset->image);
}