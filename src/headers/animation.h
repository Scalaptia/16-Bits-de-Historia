#ifndef ANIMATION_H
#define ANIMATION_H

#include "raylib.h"
#include <stdlib.h>

#define ANIMATION_SPEED 0.2f

typedef struct Sprite
{
    Image *frames;
    Texture2D *textures;
    float frameTime;
    float currentTime;
    int frameCurrent;
    int frameCount;
} Sprite;

void InitSprite(Sprite *sprite);
void UpdateSprite(Sprite *sprite, Vector2 position, float scale, Color color);
void UnloadSprite(Sprite *sprite);

#endif