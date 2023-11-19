#ifndef ANIMATION_H
#define ANIMATION_H

#include "raylib.h"
#include <stdlib.h>

#define ANIMATION_SPEED 20

typedef struct AnimationData
{
    Image *frames;
    Texture2D *textures;
} AnimationData;

void UpdateFrame();
void DrawCharacter(Rectangle position, Color color);
void InitCharacter();
void UnloadCharacter();

#endif