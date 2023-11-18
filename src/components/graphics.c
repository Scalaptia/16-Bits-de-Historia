#include "../headers/graphics.h"

void InitGraphics(GraphicsData *tileset)
{
    tileset->image = LoadImage(ASSETS_PATH "character and tileset/Dungeon_Tileset.png");
    tileset->texture = LoadTextureFromImage(tileset->image);
    tileset->size = (Rectangle){0, 0, tileset->texture.width, tileset->texture.height};
}

void UnloadGraphics(GraphicsData *tileset)
{
    UnloadTexture(tileset->texture);
    UnloadImage(tileset->image);
}