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
}

void DrawRoom(GraphicsData *tileset, Vector2 position, float scale)
{
    DrawElement(tileset, "ROOM", position, scale);
}

void UnloadGraphics(GraphicsData *tileset)
{
    UnloadTexture(tileset->texture);
    UnloadImage(tileset->image);
}