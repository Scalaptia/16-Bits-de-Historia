#ifndef ENEMY_H
#define ENEMY_H

#include "raylib.h"
#include "raymath.h"
#include "../headers/player.h"
#include "../headers/animation.h"

enum ShootDirection
{
    UP,
    DOWN,
    LEFT,
    RIGHT
};

typedef struct Bullet
{
    Sprite sprite;
    Rectangle hitbox;
    Vector2 position;
    int direction;
    int speed;
} Bullet;

typedef struct Enemy
{
    Sprite *sprite;
    Vector2 position;
    int direction;
    enum ShootDirection shootDirection;
    int attackSpeed;
    int bulletSpeed;
    int bulletCount;
    Bullet bullets[6];
} Enemy;

#define TILE_SIZE 16
#define SCALE 5
#define REL_TILE_SIZE (TILE_SIZE * SCALE)

void InitEnemy(Enemy *enemy, Vector2 position, int direction, Sprite *sprite, int attackSpeed, int bulletSpeed, enum ShootDirection shootDirection);
void InitEnemys();

void UpdateEnemy(Enemy *enemy);
void UpdateEnemys();

void ShootBullet(Enemy *enemy);
void UpdateBullets(Enemy *enemy);
Sprite RotateBullet(enum ShootDirection direction);
void CheckPlayerHit(Player *player, Enemy *enemy);

extern Enemy enemy1;
extern Enemy enemy2;
extern Enemy enemy3;
extern Enemy enemy4;

#endif