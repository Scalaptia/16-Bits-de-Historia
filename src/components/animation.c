#include "../headers/animation.h"

Sprite charSprite;

void InitSprite(Sprite *sprite)
{
    sprite->frameCount = 4;
    sprite->frameCurrent = 0;
    sprite->frameTime = ANIMATION_SPEED;

    sprite->frames = (Image *)malloc(sizeof(Image) * 4);
    sprite->textures = (Texture2D *)malloc(sizeof(Texture2D) * 4);

    sprite->frames[0] = LoadImage(ASSETS_PATH "Character_animation/priests_idle/priest3/v2/priest3_v2_1.png");
    sprite->frames[1] = LoadImage(ASSETS_PATH "Character_animation/priests_idle/priest3/v2/priest3_v2_2.png");
    sprite->frames[2] = LoadImage(ASSETS_PATH "Character_animation/priests_idle/priest3/v2/priest3_v2_3.png");
    sprite->frames[3] = LoadImage(ASSETS_PATH "Character_animation/priests_idle/priest3/v2/priest3_v2_4.png");

    sprite->textures[0] = LoadTextureFromImage(sprite->frames[0]);
    sprite->textures[1] = LoadTextureFromImage(sprite->frames[1]);
    sprite->textures[2] = LoadTextureFromImage(sprite->frames[2]);
    sprite->textures[3] = LoadTextureFromImage(sprite->frames[3]);
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
