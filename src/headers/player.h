#ifndef PLAYER_H
#define PLAYER_H

#include "raylib.h"
#include "raymath.h"
#include "../headers/keybinds.h"
#include "../headers/animation.h"
#include "../headers/level.h"

typedef struct Player
{
    Vector2 position;
    Color color;
    float speed;
    int direction;
} Player;

#define TILE_SIZE 16
#define SCALE 5
#define REL_TILE_SIZE (TILE_SIZE * SCALE)

void InitPlayer(Sprite *sprite, Rectangle screen);
void actPlayer(Player *player, Music *sfx, LevelData room);
void movePlayer(Player *player, Music *sfx, LevelData room);
void playerAttack(Player *player);

extern Player player;
extern Camera2D camera;

#endif