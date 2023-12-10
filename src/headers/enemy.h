#ifndef ENEMY_H
#define ENEMY_H

#include "raylib.h"
#include "raymath.h"
#include "../headers/player.h"
#include "../headers/animation.h"

typedef struct Enemy
{
    Sprite *sprite;
    Vector2 position;
    int direction;
    int attackSpeed;
} Enemy;

#define TILE_SIZE 16
#define SCALE 5
#define REL_TILE_SIZE (TILE_SIZE * SCALE)

void InitEnemy(Enemy *enemy, Vector2 position, int direction, Sprite *sprite, int attackSpeed);
void InitEnemys();

void UpdateEnemy(Enemy *enemy);
void UpdateEnemys();

extern Enemy enemys[4];

#endif