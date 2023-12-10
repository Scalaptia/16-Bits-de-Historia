#include "../headers/enemy.h"

Enemy enemy1;
Enemy enemy2;
Enemy enemy3;
Enemy enemy4;

void InitEnemy(Enemy *enemy, Vector2 position, int direction, Sprite *sprite, int attackSpeed)
{
    position.x *= REL_TILE_SIZE;
    position.y *= REL_TILE_SIZE;

    enemy->position = position;
    enemy->direction = direction;
    enemy->attackSpeed = attackSpeed;
    enemy->sprite = sprite;
}

void InitEnemys()
{
    InitEnemy(&enemy1, (Vector2){8, 4 + 44}, -1, &enemy1Sprite, 1);
    InitEnemy(&enemy2, (Vector2){8, 5 + 44}, -1, &enemy2Sprite, 1);
    InitEnemy(&enemy3, (Vector2){9, 4 + 44}, 1, &enemy3Sprite, 1);
    InitEnemy(&enemy4, (Vector2){9, 5 + 44}, 1, &enemy4Sprite, 1);
}

void UpdateEnemy(Enemy *enemy)
{
    DrawSpriteFrame(enemy->sprite, enemy->position, SCALE, WHITE, enemy->direction, true);
}

void UpdateEnemys()
{
    UpdateEnemy(&enemy1);
    UpdateEnemy(&enemy2);
    UpdateEnemy(&enemy3);
    UpdateEnemy(&enemy4);
}