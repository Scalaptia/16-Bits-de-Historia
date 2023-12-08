#ifndef OBJECT_H
#define OBJECT_H

#include "raylib.h"
#include "raymath.h"
#include "../headers/player.h"
#include "../headers/animation.h"

typedef struct Object
{
    Texture2D texture;
    Vector2 position;
    enum Item givenItem;
    bool isTaken;
} Object;

#define TILE_SIZE 16
#define SCALE 5
#define REL_TILE_SIZE (TILE_SIZE * SCALE)

void InitObjects();
void CheckObject(Player *player, Object *object);

void CheckRoom1Objects(Player *player);
void InteractObject(Object *object, Player *player);

extern Object objComida1;

extern Object objRifle1;

extern Object objMachete1;
extern Object objMachete2;
extern Object objMachete3;
extern Object objMachete4;

extern Object objLanza1;
extern Object objLanza2;
extern Object objLanza3;
extern Object objLanza4;
extern Object objLanza5;

#endif