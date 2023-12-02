#include "../headers/player.h"

Controls controls = {.UP_KEY = KEY_W,
                     .DOWN_KEY = KEY_S,
                     .LEFT_KEY = KEY_A,
                     .RIGHT_KEY = KEY_D,
                     .ATTACK_KEY = KEY_SPACE};

Player player;
Camera2D camera;

void InitPlayer(Sprite *sprite, Rectangle screen)
{
    InitSprite(sprite);

    player.position.x = REL_TILE_SIZE * 2;
    player.position.y = REL_TILE_SIZE * 2;
    player.color = WHITE;
    player.direction = 1;

    camera.target = (Vector2){player.position.x, player.position.y};
    camera.offset = (Vector2){(screen.width / 2) - (TILE_SIZE * 2), (screen.height / 2) - (TILE_SIZE * 2)};
    camera.zoom = 1.0f;
}

void actPlayer(Player *player, Music *sfx, LevelData room)
{
    movePlayer(player, sfx, room);
    playerAttack(player);
}

void movePlayer(Player *player, Music *sfx, LevelData room)
{
    float old_x = player->position.x;
    float old_y = player->position.y;

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
        player->isAnimated = true;

        direction = Vector2Normalize(direction);

        Vector2 new_position;
        new_position.x = player->position.x + direction.x * player->speed * GetFrameTime();
        new_position.y = player->position.y + direction.y * player->speed * GetFrameTime();

        // Check for collisions in the x direction
        bool collision_x = false;
        for (int i = 0; i < room.wallsCount; i++)
        {
            if (CheckCollisionRecs((Rectangle){new_position.x, player->position.y, REL_TILE_SIZE, REL_TILE_SIZE}, (Rectangle){room.walls[i].x, room.walls[i].y, REL_TILE_SIZE, REL_TILE_SIZE}))
            {
                collision_x = true;
                break;
            }
        }

        // Check for collisions in the y direction
        bool collision_y = false;
        for (int i = 0; i < room.wallsCount; i++)
        {
            if (CheckCollisionRecs((Rectangle){player->position.x, new_position.y, REL_TILE_SIZE, REL_TILE_SIZE}, (Rectangle){room.walls[i].x, room.walls[i].y, REL_TILE_SIZE, REL_TILE_SIZE}))
            {
                collision_y = true;
                break;
            }
        }

        if (!collision_x)
        {
            player->position.x = new_position.x;
        }
        if (!collision_y)
        {
            player->position.y = new_position.y;
        }

        if (old_x != player->position.x || old_y != player->position.y)
        {
            UpdateMusicStream(*sfx);
            PlayMusicStream(*sfx);
        }
    }
    else
    {
        player->isAnimated = false;
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