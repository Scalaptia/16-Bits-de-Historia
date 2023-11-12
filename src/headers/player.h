#ifndef PLAYER_H
#define PLAYER_H

#include "raylib.h"

typedef struct Player
{
    Vector2 position;
    Color color;
} Player;

void movePlayer(Player *player, int upKey, int downKey, int leftKey, int rightKey);

#endif