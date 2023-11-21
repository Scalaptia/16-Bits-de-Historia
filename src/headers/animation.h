#ifndef ANIMATION_H
#define ANIMATION_H

#include "raylib.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define ANIMATION_SPEED 0.2f
#define TILE_SIZE 16
#define SCALE 5
#define REL_TILE_SIZE (TILE_SIZE * SCALE)

enum Entities
{
    PLAYER,
    ENEMY
};

typedef struct Sprite
{
    char path[100];
    Image *frames;
    Texture2D *textures;
    float frameTime;
    float currentTime;
    int frameCurrent;
    int frameCount;
} Sprite;

void InitSprite(Sprite *sprite);
void UpdateSpriteFrame(Sprite *sprite);
void UpdateSpritesFrame();

void DrawSpriteFrame(Sprite *sprite, Vector2 position, float scale, Color color, int direction);
void UnloadSprite(Sprite *sprite);

extern Sprite charSprite;
extern Sprite npcSprite;

#endif