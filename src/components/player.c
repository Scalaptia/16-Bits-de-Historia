#include "../headers/player.h"

void actPlayer(Player *player)
{
    movePlayer(player, player->controls.upKey, player->controls.downKey, player->controls.leftKey, player->controls.rightKey);
    playerAttack(player, player->controls.attackKey);
}

void movePlayer(Player *player, int upKey, int downKey, int leftKey, int rightKey)
{
    if (IsKeyDown(upKey))
        player->position.y -= 3.0f;

    if (IsKeyDown(downKey))
        player->position.y += 3.0f;

    if (IsKeyDown(leftKey))
        player->position.x -= 3.0f;

    if (IsKeyDown(rightKey))
        player->position.x += 3.0f;
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