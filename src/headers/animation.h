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

extern Sprite npcEnojado1Sprite;
extern Sprite npcEnojado2Sprite;

extern Sprite npcTirado1Sprite;
extern Sprite npcTirado2Sprite;

extern Sprite npcRecargado1Sprite;
extern Sprite npcRecargado2Sprite;

extern Sprite npcSaco1Sprite;
extern Sprite npcSaco2Sprite;

extern Sprite bulletSprite;
extern Sprite enemy1Sprite;
extern Sprite enemy2Sprite;
extern Sprite enemy3Sprite;
extern Sprite enemy4Sprite;

extern Sprite npcMexicano1Sprite;
extern Sprite npcMexicano2Sprite;
extern Sprite npcMexicano3Sprite;
extern Sprite npcMexicano4Sprite;

extern Sprite textoSalidaSprite;
extern Sprite huecoSalidaSprite;

#endif