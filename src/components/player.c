#include "../headers/player.h"

Controls controls = {.UP_KEY = KEY_W,
                     .DOWN_KEY = KEY_S,
                     .LEFT_KEY = KEY_A,
                     .RIGHT_KEY = KEY_D,
                     .RUN_KEY = KEY_LEFT_SHIFT,
                     .GRAB_KEY = KEY_SPACE};

Player player;
Camera2D camera;

Texture2D itemFoodTexture;
Texture2D itemRifleTexture;

Texture2D itemMacheteTexture;
Texture2D itemMachete2Texture;
Texture2D itemHoldMacheteTexture;

Texture2D itemLanzaTexture;
Texture2D itemLanza2Texture;
Texture2D itemHoldLanzaTexture;

bool isInteracting = false;
char *currentDialogue = "Placeholder Text";
char *currentName = "Placeholder Name";

void InitPlayer(Sprite *sprite, Sprite *actSprite, Rectangle screen)
{
    player.position.x = REL_TILE_SIZE * 2;
    player.position.y = REL_TILE_SIZE * 4;
    player.color = WHITE;
    player.direction = 1;
    player.heldItem = NONE;
    player.hitbox = (Rectangle){player.position.x + (REL_TILE_SIZE / 4), player.position.y, REL_TILE_SIZE / 2, REL_TILE_SIZE};

    camera.target = (Vector2){player.position.x, player.position.y};
    camera.offset = (Vector2){(screen.width / 2) - (TILE_SIZE * 2), (screen.height / 2) - (TILE_SIZE * 2)};
    camera.zoom = 1.0f;
}

void actPlayer(Player *player, Music *sfx, LevelData room)
{
    movePlayer(player, sfx, room);

    // if (IsKeyPressed(KEY_ONE))
    // {
    //     player->heldItem = FOOD;
    // }

    // if (IsKeyPressed(KEY_TWO))
    // {
    //     player->heldItem = RIFLE;
    // }

    // if (IsKeyPressed(KEY_THREE))
    // {
    //     player->heldItem = MACHETE;
    // }

    // if (IsKeyPressed(KEY_FOUR))
    // {
    //     player->heldItem = LANZA;
    // }

    // if (IsKeyPressed(KEY_ZERO))
    // {
    //     player->heldItem = NONE;
    // }

    playerHold(player);
}

void movePlayer(Player *player, Music *sfx, LevelData room)
{
    float old_x = player->position.x;
    float old_y = player->position.y;

    Vector2 direction = {0.0f, 0.0f};

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

    if (IsKeyDown(controls.RUN_KEY))
    {
        player->speed += 100.0f;
    }

    if (Vector2Length(direction) > 0.0f)
    {
        direction = Vector2Normalize(direction);

        bool collision_x = false;
        bool collision_y = false;
        Vector2 new_position = {player->position.x + direction.x * player->speed * GetFrameTime(), player->position.y + direction.y * player->speed * GetFrameTime()};
        Rectangle new_hitbox = {new_position.x + (REL_TILE_SIZE / 4), new_position.y, REL_TILE_SIZE / 2, REL_TILE_SIZE};

        // Check for collisions in the x direction
        for (int i = 0; i < room.wallsCount; i++)
        {
            if (IsRectangleOnCamera((Rectangle){0, 0, room.walls[i].x, room.walls[i].y}, camera))
            {
                if (CheckCollisionRecs((Rectangle){new_hitbox.x, player->hitbox.y, player->hitbox.width, player->hitbox.height}, (Rectangle){room.walls[i].x, room.walls[i].y, REL_TILE_SIZE, REL_TILE_SIZE}))
                {
                    collision_x = true;
                }

                if (CheckCollisionRecs((Rectangle){player->hitbox.x, new_hitbox.y, player->hitbox.width, player->hitbox.height}, (Rectangle){room.walls[i].x, room.walls[i].y, REL_TILE_SIZE, REL_TILE_SIZE}))
                {
                    collision_y = true;
                }
            }
        }

        // Check if the player is colliding with an object
        for (int i = 0; i < room.objectsCount; i++)
        {
            if (IsRectangleOnCamera(room.objects[i], camera))
            {
                if (CheckCollisionRecs((Rectangle){new_hitbox.x, player->hitbox.y, player->hitbox.width, player->hitbox.height}, room.objects[i]))
                {
                    collision_x = true;
                }

                if (CheckCollisionRecs((Rectangle){player->hitbox.x, new_hitbox.y, player->hitbox.width, player->hitbox.height}, room.objects[i]))
                {
                    collision_y = true;
                }
            }
        }

        if (!collision_x)
        {
            player->position.x = new_position.x;
            player->hitbox.x = new_hitbox.x;
        }
        if (!collision_y)
        {
            player->position.y = new_position.y;
            player->hitbox.y = new_hitbox.y;
        }

        if (old_x != player->position.x || old_y != player->position.y)
        {
            player->isAnimated = true;
            UpdateMusicStream(*sfx);
            PlayMusicStream(*sfx);
        }
        else
        {
            player->isAnimated = false;
        }
    }
    else
    {
        player->isAnimated = false;
    }
}

void playerHold(Player *player)
{
    if (player->heldItem != NONE)
    {
        player->sprite = charPickSprite;

        switch (player->heldItem)
        {
        case FOOD:
            player->heldTexture = itemFoodTexture;
            break;
        case RIFLE:
            player->heldTexture = itemRifleTexture;
            break;
        case MACHETE:
            player->heldTexture = itemHoldMacheteTexture;
            break;
        case LANZA:
            player->heldTexture = itemHoldLanzaTexture;
            break;
        }

        player->speed = 250.0f;
    }
    else
    {
        player->sprite = charSprite;
        player->speed = 300.0f;
    }
}

void InitItemTextures()
{
    char strpath[512];

    // Load images
    strcpy(strpath, GetWorkingDirectory());
    strcat(strpath, "/assets/Items/Plato.png");
    Image itemFoodImage = LoadImage(strpath);

    strcpy(strpath, GetWorkingDirectory());
    strcat(strpath, "/assets/Items/Rifle.png");
    Image itemRifleImage = LoadImage(strpath);

    strcpy(strpath, GetWorkingDirectory());
    strcat(strpath, "/assets/Items/Machete.png");
    Image itemMacheteImage = LoadImage(strpath);

    strcpy(strpath, GetWorkingDirectory());
    strcat(strpath, "/assets/Items/Machete2.png");
    Image itemMachete2Image = LoadImage(strpath);

    strcpy(strpath, GetWorkingDirectory());
    strcat(strpath, "/assets/Items/smachete.png");
    Image itemHoldMacheteImage = LoadImage(strpath);

    strcpy(strpath, GetWorkingDirectory());
    strcat(strpath, "/assets/Items/Lanza.png");
    Image itemLanzaImage = LoadImage(strpath);

    strcpy(strpath, GetWorkingDirectory());
    strcat(strpath, "/assets/Items/Lanza2.png");
    Image itemLanza2Image = LoadImage(strpath);

    strcpy(strpath, GetWorkingDirectory());
    strcat(strpath, "/assets/Items/Slanza.png");
    Image itemHoldLanzaImage = LoadImage(strpath);

    // Load textures
    itemFoodTexture = LoadTextureFromImage(itemFoodImage);
    itemRifleTexture = LoadTextureFromImage(itemRifleImage);
    itemMacheteTexture = LoadTextureFromImage(itemMacheteImage);
    itemMachete2Texture = LoadTextureFromImage(itemMachete2Image);
    itemHoldMacheteTexture = LoadTextureFromImage(itemHoldMacheteImage);
    itemLanzaTexture = LoadTextureFromImage(itemLanzaImage);
    itemLanza2Texture = LoadTextureFromImage(itemLanza2Image);
    itemHoldLanzaTexture = LoadTextureFromImage(itemHoldLanzaImage);

    // Unload images
    UnloadImage(itemFoodImage);
    UnloadImage(itemRifleImage);
    UnloadImage(itemMacheteImage);
    UnloadImage(itemMachete2Image);
    UnloadImage(itemHoldLanzaImage);
    UnloadImage(itemHoldMacheteImage);
    UnloadImage(itemLanzaImage);
    UnloadImage(itemLanza2Image);
}