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
    Texture2D *textures;
    float frameTime;
    float currentTime;
    int frameCurrent;
    int frameCount;
} Sprite;

void InitSprite(Sprite *sprite, int frameCount);
void UpdateSpriteFrame(Sprite *sprite);
void UpdateSpritesFrame();

void DrawSpriteFrame(Sprite *sprite, Vector2 position, float scale, Color color, int direction, bool isAnimated);
void UnloadSprite(Sprite *sprite);

void InitSprites();
void UnloadSprites();

extern Sprite charSprite;
extern Sprite charPickSprite;

extern Sprite npcE1Sprite;
extern Sprite npcE2Sprite;

#endif