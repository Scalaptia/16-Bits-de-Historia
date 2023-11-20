#include "../headers/player.h"

Controls controls = {.UP_KEY = KEY_W,
                     .DOWN_KEY = KEY_S,
                     .LEFT_KEY = KEY_A,
                     .RIGHT_KEY = KEY_D,
                     .ATTACK_KEY = KEY_SPACE};

void actPlayer(Player *player, Sound *sound1, Sound *sound2, Sound *sound3, Sound *sound4)
{
    movePlayer(player, sound1, sound2, sound3, sound4);
    playerAttack(player);
}

void movePlayer(Player *player, Sound *sound1, Sound *sound2, Sound *sound3, Sound *sound4)
{
    Vector2 direction = {0.0f, 0.0f};
    player->speed = 300.0f;

    if (IsKeyDown(controls.UP_KEY))
    {
        PlaySound(*sound1);
        direction.y -= 1.0f;
    }
    if (IsKeyDown(controls.DOWN_KEY))
    {
        PlaySound(*sound2);
        direction.y += 1.0f;
    }
    if (IsKeyDown(controls.LEFT_KEY))
    {
        PlaySound(*sound3);
        direction.x -= 1.0f;
        player->direction = -1;
    }

    if (IsKeyDown(controls.RIGHT_KEY))
    {
        PlaySound(*sound4);
        direction.x += 1.0f;
        player->direction = 1;
    }

    if (Vector2Length(direction) > 0.0f)
    {
        direction = Vector2Normalize(direction);
        player->position.x += direction.x * player->speed * GetFrameTime();
        player->position.y += direction.y * player->speed * GetFrameTime();
    }
}

void playerAttack(Player *player)
{
    if (IsKeyDown(controls.ATTACK_KEY))
    {
        player->color = RED;
    }
    else
    {
        player->color = WHITE;
    }
}