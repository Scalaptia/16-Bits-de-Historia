#include "../headers/player.h"

Controls controls = {.UP_KEY = KEY_W,
                     .DOWN_KEY = KEY_S,
                     .LEFT_KEY = KEY_A,
                     .RIGHT_KEY = KEY_D,
                     .ATTACK_KEY = KEY_SPACE};

Player player;
Camera2D camera;

void InitPlayer(Sprite *sprite, Rectangle screen, int tileSize, int relTileSize)
{
    InitSprite(sprite);

    player.position.x = relTileSize * 2;
    player.position.y = relTileSize * 2;
    player.color = WHITE;
    player.direction = 1;

    camera.target = (Vector2){player.position.x, player.position.y};
    camera.offset = (Vector2){(screen.width / 2) - (tileSize * 2), (screen.height / 2) - (tileSize * 2)};
    camera.zoom = 1.0f;
}

void actPlayer(Player *player, Music *sfx)
{
    movePlayer(player, sfx);
    playerAttack(player);
}

void movePlayer(Player *player, Music *sfx)
{
    Vector2 direction = {0.0f, 0.0f};
    player->speed = 300.0f;

    if (IsKeyDown(controls.UP_KEY))
    {
        direction.y -= 1.0f;
    }
    if (IsKeyDown(controls.DOWN_KEY))
    {
        direction.y += 1.0f;
    }
    if (IsKeyDown(controls.LEFT_KEY))
    {
        direction.x -= 1.0f;
        player->direction = -1;
    }

    if (IsKeyDown(controls.RIGHT_KEY))
    {
        direction.x += 1.0f;
        player->direction = 1;
    }

    if (Vector2Length(direction) > 0.0f)
    {
        UpdateMusicStream(*sfx);
        PlayMusicStream(*sfx);

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