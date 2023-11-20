#ifndef PLAYER_H
#define PLAYER_H

#include "raylib.h"
#include "raymath.h"
#include "../headers/keybinds.h"

typedef struct Player
{
    Vector2 position;
    Color color;
    float speed;
    int direction;
} Player;

void actPlayer(Player *player, Music *sfx);
void movePlayer(Player *player, Music *sfx);
void playerAttack(Player *player);

#endif