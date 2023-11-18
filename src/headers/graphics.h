#ifndef GRAPHICS_H
#define GRAPHICS_H

#include "raylib.h"

typedef struct GraphicsData
{
    Image image;
    Texture2D texture;
    Rectangle size;
} GraphicsData;

void InitGraphics(GraphicsData *tileset);
void UnloadGraphics(GraphicsData *tileset);

#endif