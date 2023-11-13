#include "../headers/player.h"

void actPlayer(Player *player)
{
    movePlayer(player, player->controls.upKey, player->controls.downKey, player->controls.leftKey, player->controls.rightKey);
    playerAttack(player, player->controls.attackKey);
}

void movePlayer(Player *player, int upKey, int downKey, int leftKey, int rightKey)
{
    Vector2 direction = {0.0f, 0.0f};

    if (IsKeyDown(upKey))
        direction.y -= 1.0f;

    if (IsKeyDown(downKey))
        direction.y += 1.0f;

    if (IsKeyDown(leftKey))
        direction.x -= 1.0f;

    if (IsKeyDown(rightKey))
        direction.x += 1.0f;

    if (Vector2Length(direction) > 0.0f)
    {
        direction = Vector2Normalize(direction);
        player->position.x += direction.x * 3.0f;
        player->position.y += direction.y * 3.0f;
    }
}

void playerAttack(Player *player, int attackKey)
{
    if (IsKeyDown(attackKey))
    {
        player->color = RED;
    }
    else
    {
        player->color = BLUE;
    }
}