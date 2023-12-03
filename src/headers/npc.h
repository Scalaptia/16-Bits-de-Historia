#ifndef NPC_H
#define NPC_H

#include "raylib.h"
#include "raymath.h"
#include "../headers/player.h"
#include "../headers/animation.h"

typedef struct NPC
{
    Sprite sprite;
    Vector2 position;
    Color color;
    int direction;
    char *name;
    char *dialogue;
} NPC;

#define TILE_SIZE 16
#define SCALE 5
#define REL_TILE_SIZE (TILE_SIZE * SCALE)

void InitNPCs(Sprite *sprite, Rectangle screen);
void InteractNPC(NPC npc);
void UpdateNPCs();

extern bool isInteracting;
extern char *currentDialogue;
extern char *currentName;

extern NPC skeleton1;
extern NPC skeleton2;

#endif