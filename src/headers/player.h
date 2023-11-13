#ifndef PLAYER_H
#define PLAYER_H

#include "raylib.h"

typedef struct Controls
{
    int upKey;
    int downKey;
    int leftKey;
    int rightKey;
    int attackKey;
} Controls;

typedef struct Player
{
    Vector2 position;
    Color color;
    Controls controls;
} Player;

void actPlayer(Player *player);

void movePlayer(Player *player, int upKey, int downKey, int leftKey, int rightKey);
void playerAttack(Player *player, int attackKey);

#endif