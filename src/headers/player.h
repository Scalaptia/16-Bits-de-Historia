#ifndef PLAYER_H
#define PLAYER_H

#include "raylib.h"
#include "raymath.h"
#include "../headers/keybinds.h"
#include "../headers/animation.h"

typedef struct Player
{
    Vector2 position;
    Color color;
    float speed;
    int direction;
} Player;

void InitPlayer(Sprite *sprite, Rectangle screen, int TILE_SIZE, int REL_TILE_SIZE);
void actPlayer(Player *player, Music *sfx);
void movePlayer(Player *player, Music *sfx);
void playerAttack(Player *player);

extern Player player;
extern Camera2D camera;

#endif