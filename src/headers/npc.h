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
    char *happyDialogue;
    bool status;
    enum Item requiredItem;
} NPC;

#define TILE_SIZE 16
#define SCALE 5
#define REL_TILE_SIZE (TILE_SIZE * SCALE)

void InitNPC(NPC *npc, Vector2 position, int direction, char *name, char *dialogue, char *happyDialogue, enum Item requiredItem);
void InitNPCs();
void InteractNPC(NPC *npc, Player *player);
bool UpdateRoom1NPCs();
bool UpdateRoom2NPCs();

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

extern NPC saco1;
extern NPC saco2;
extern NPC saco3;
extern NPC saco4;
extern NPC saco5;
extern NPC saco6;
extern NPC saco7;
extern NPC saco8;
extern NPC saco9;
extern NPC saco10;

extern NPC mexicano1;
extern NPC mexicano2;
extern NPC mexicano3;
extern NPC mexicano4;
extern NPC mexicano5;
extern NPC mexicano6;

#endif