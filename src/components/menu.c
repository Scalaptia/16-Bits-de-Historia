#include "../headers/menu.h"

void InitBackground(Sprite *sprite)
{
    char path[100];

    sprite->frameCount = 33;
    sprite->frameCurrent = 0;
    sprite->frameTime = ANIMATION_SPEED / 2;

    sprite->frames = (Image *)malloc(sizeof(Image) * 33);
    sprite->textures = (Texture2D *)malloc(sizeof(Texture2D) * 33);

    for (int i = 0; i < 33; i++)
    {
        sprintf(path, ASSETS_PATH "background/bg%d.png", i + 1);
        sprite->frames[i] = LoadImage(path);

        sprite->textures[i] = LoadTextureFromImage(sprite->frames[i]);
    }
}

void UpdateBackground(Sprite *sprite, Vector2 screen)
{
    sprite->currentTime += GetFrameTime();

    if (sprite->currentTime >= sprite->frameTime)
    {
        sprite->currentTime = 0.0f;
        sprite->frameCurrent++;

        if (sprite->frameCurrent >= sprite->frameCount)
        {
            sprite->frameCurrent = 0;
        }
    }

    Vector2 origin = {0, 0};

    DrawTexturePro(sprite->textures[sprite->frameCurrent], (Rectangle){0, 0, screen.x / 3, screen.y / 2.8}, (Rectangle){0, 0, screen.x, screen.y}, origin, 0, WHITE);
}

void UnloadBackground(Sprite *sprite)
{
    for (int i = 0; i < 33; i++)
    {
        UnloadImage(sprite->frames[i]);
        UnloadTexture(sprite->textures[i]);
    }

    free(sprite->frames);
    free(sprite->textures);
}