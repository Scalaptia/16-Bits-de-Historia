#include "../headers/animation.h"

Sprite charSprite;

void InitSprite(Sprite *sprite)
{
    char path[100];

    sprite->frameCount = 4;
    sprite->frameCurrent = 0;
    sprite->frameTime = ANIMATION_SPEED;

    sprite->frames = (Image *)malloc(sizeof(Image) * 4);
    sprite->textures = (Texture2D *)malloc(sizeof(Texture2D) * 4);

    for (int i = 0; i < 4; i++)
    {
        sprintf(path, ASSETS_PATH "Personaje/char%d.png", i + 1);
        sprite->frames[i] = LoadImage(path);
        sprite->textures[i] = LoadTextureFromImage(sprite->frames[i]);
    }
}

void UpdateSprite(Sprite *sprite, Vector2 position, float scale, Color color, int direction)
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

    float width = 16 * scale;
    float height = 16 * scale;
    Vector2 origin = {0, 0};

    float sourceWidth = direction < 0 ? -16.0f : 16.0f;

    DrawTexturePro(sprite->textures[sprite->frameCurrent], (Rectangle){0, 0, sourceWidth, 16}, (Rectangle){position.x, position.y, width, height}, origin, 0, color);
}

void UnloadSprite(Sprite *sprite)
{
    for (int i = 0; i < 4; i++)
    {
        UnloadImage(sprite->frames[i]);
        UnloadTexture(sprite->textures[i]);
    }

    free(sprite->frames);
    free(sprite->textures);
}
