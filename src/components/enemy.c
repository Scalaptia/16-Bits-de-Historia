#include "../headers/enemy.h"

Enemy enemy1;
Enemy enemy2;
Enemy enemy3;
Enemy enemy4;

void InitEnemy(Enemy *enemy, Vector2 position, int direction, Sprite *sprite, int attackSpeed, int bulletSpeed, enum ShootDirection shootDirection)
{
    position.x *= REL_TILE_SIZE;
    position.y *= REL_TILE_SIZE;

    enemy->position = position;
    enemy->direction = direction;
    enemy->attackSpeed = attackSpeed;
    enemy->shootDirection = shootDirection;
    enemy->sprite = sprite;
    enemy->bulletSpeed = bulletSpeed;
}

void InitEnemys()
{
    InitEnemy(&enemy1, (Vector2){8, 4 + 44}, -1, &enemy1Sprite, 20, 7, UP);
    InitEnemy(&enemy2, (Vector2){8, 5 + 44}, -1, &enemy2Sprite, 20, 7, DOWN);
    InitEnemy(&enemy3, (Vector2){9, 4 + 44}, 1, &enemy3Sprite, 20, 7, LEFT);
    InitEnemy(&enemy4, (Vector2){9, 5 + 44}, 1, &enemy4Sprite, 20, 7, RIGHT);
}

void UpdateEnemy(Enemy *enemy)
{
    DrawSpriteFrame(enemy->sprite, enemy->position, SCALE, WHITE, enemy->direction, true);

    if (rand() % 1000 < enemy->attackSpeed)
    {
        ShootBullet(enemy);
    }

    UpdateBullets(enemy);
    CheckPlayerHit(&player, enemy);
}

void UpdateEnemys()
{
    UpdateEnemy(&enemy1);
    UpdateEnemy(&enemy2);
    UpdateEnemy(&enemy3);
    UpdateEnemy(&enemy4);
}

void ShootBullet(Enemy *enemy)
{
    if (enemy->bulletCount >= 6)
    {
        enemy->bullets[0] = enemy->bullets[1];
        enemy->bullets[1] = enemy->bullets[2];
        enemy->bullets[2] = enemy->bullets[3];
        enemy->bullets[3] = enemy->bullets[4];
        enemy->bullets[4] = enemy->bullets[5];

        enemy->bulletCount = 5;
    }

    Bullet bullet = {
        RotateBullet(enemy->shootDirection),
        (Rectangle){enemy->position.x + (REL_TILE_SIZE / 4), enemy->position.y + (REL_TILE_SIZE / 4), REL_TILE_SIZE / 2, REL_TILE_SIZE / 2},
        enemy->position,
        enemy->shootDirection,
        enemy->bulletSpeed,
    };

    enemy->bullets[enemy->bulletCount++] = bullet;
}

void UpdateBullets(Enemy *enemy)
{
    int i;

    for (i = 0; i < enemy->bulletCount; i++)
    {
        Bullet *bullet = &enemy->bullets[i];

        switch (bullet->direction)
        {
        case UP:
            bullet->position.y -= bullet->speed;
            break;
        case DOWN:
            bullet->position.y += bullet->speed;
            break;
        case LEFT:
            bullet->position.x -= bullet->speed;
            break;
        case RIGHT:
            bullet->position.x += bullet->speed;
            break;
        }

        bullet->hitbox.x = bullet->position.x + (REL_TILE_SIZE / 4);
        bullet->hitbox.y = bullet->position.y + (REL_TILE_SIZE / 4);

        DrawTexturePro(bullet->sprite.textures[0], (Rectangle){0, 0, TILE_SIZE, TILE_SIZE}, (Rectangle){bullet->position.x, bullet->position.y, REL_TILE_SIZE, REL_TILE_SIZE}, (Vector2){0, 0}, 0, WHITE);
        // DrawRectangleLinesEx((Rectangle){bullet->hitbox.x, bullet->hitbox.y, bullet->hitbox.width, bullet->hitbox.height}, 1, RED);
    }
}

Sprite RotateBullet(enum ShootDirection direction)
{
    Sprite sprite;
    Image image = LoadImageFromTexture(bulletSprite.textures[0]);

    switch (direction)
    {
    case UP:
        ImageRotateCCW(&image);
        break;

    case DOWN:
        ImageRotateCW(&image);
        break;

    case LEFT:
        ImageRotateCW(&image);
        ImageRotateCW(&image);
        break;

    case RIGHT:
        break;
    }

    sprite.textures = malloc(sizeof(Texture2D));
    sprite.textures[0] = LoadTextureFromImage(image);

    UnloadImage(image);

    return sprite;
}

void CheckPlayerHit(Player *player, Enemy *enemy)
{
    int i;

    for (i = 0; i < enemy->bulletCount; i++)
    {
        Bullet *bullet = &enemy->bullets[i];
        if (CheckCollisionRecs(player->hitbox, bullet->hitbox))
        {
            printf("Player hit!\n");
            player->isDead = true;
            enemy1.bulletCount = 0;
            enemy2.bulletCount = 0;
            enemy3.bulletCount = 0;
            enemy4.bulletCount = 0;
        }
    }
}