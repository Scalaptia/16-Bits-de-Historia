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

void actPlayer(Player *player, Sound *sound1, Sound *sound2, Sound *sound3, Sound *sound4);
void movePlayer(Player *player, Sound *sound1, Sound *sound2, Sound *sound3, Sound *sound4);
void playerAttack(Player *player);

#endif