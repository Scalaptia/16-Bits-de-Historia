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
    bool status;
    enum Item requiredItem;
} NPC;

#define TILE_SIZE 16
#define SCALE 5
#define REL_TILE_SIZE (TILE_SIZE * SCALE)

void InitNPCs(Rectangle screen);
void InteractNPC(NPC *npc, Player *player);
void UpdateRoom1NPCs();

void CheckNPC(Player *player, NPC *npc);

void CheckRoom1NPCs(Player *player);
void CheckRoom2NPCs(Player *player);

extern NPC enojado1;
extern NPC enojado2;
extern NPC enojado3;
extern NPC enojado4;

extern NPC tirado1;

extern NPC recargado1;
extern NPC recargado2;
extern NPC recargado3;
extern NPC recargado4;
extern NPC recargado5;

#endif