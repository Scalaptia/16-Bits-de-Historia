#ifndef OBJECT_H
#define OBJECT_H

#include "raylib.h"
#include "raymath.h"
#include "../headers/player.h"
#include "../headers/animation.h"
#include "../headers/menu.h"

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

void InitRoom1Objects();
void InitRoom2Objects();
void InitRoom3Objects();
void InitObject(Object *object, Texture2D texture, Vector2 position, enum Item givenItem);
void CheckObject(Player *player, Object *object);

void CheckRoom1Objects(Player *player);
void CheckRoom2Objects(Player *player);
void CheckRoom3Objects(Player *player);
void InteractObject(Object *object, Player *player);

void CheckTeleportTile(Player *player, int x, int y, int roomNumber, Menu *menu, enum GameState *currentScene);

extern Object objComida1;

extern Object objRifle1;

extern Object objMachete1;
extern Object objMachete2;
extern Object objMachete3;
extern Object objMachete4;
extern Object objMachete5;
extern Object objMachete6;

extern Object objLanza1;
extern Object objLanza2;
extern Object objLanza3;
extern Object objLanza4;
extern Object objLanza5;
extern Object objLanza6;
extern Object objLanza7;
extern Object objLanza8;
extern Object objLanza9;
extern Object objLanza10;

#endif