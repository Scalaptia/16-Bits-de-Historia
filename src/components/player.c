#include "../headers/player.h"

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