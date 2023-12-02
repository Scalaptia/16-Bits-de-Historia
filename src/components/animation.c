#include "../headers/animation.h"

Sprite charSprite;
Sprite npcSprite;

void InitSprite(Sprite *sprite)
{
    char path[150];

    sprite->frameCount = 4;
    sprite->frameCurrent = 0;
    sprite->frameTime = ANIMATION_SPEED;

    sprite->frames = (Image *)malloc(sizeof(Image) * sprite->frameCount);
    sprite->textures = (Texture2D *)malloc(sizeof(Texture2D) * sprite->frameCount);

    for (int i = 0; i < 4; i++)
    {
        sprintf(path, ASSETS_PATH "%s%d.png", sprite->path, i + 1);

        sprite->frames[i] = LoadImage(path);
        sprite->textures[i] = LoadTextureFromImage(sprite->frames[i]);
    }
}

void UpdateSpriteFrame(Sprite *sprite)
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
}

void UpdateSpritesFrame()
{
    UpdateSpriteFrame(&charSprite);
    UpdateSpriteFrame(&npcSprite);
}

void DrawSpriteFrame(Sprite *sprite, Vector2 position, float scale, Color color, int direction, bool isAnimated)
{
    float width = 16 * scale;
    float height = 16 * scale;
    Vector2 origin = {0, 0};

    float sourceWidth = direction < 0 ? -16.0f : 16.0f;

    if (isAnimated)
    {
        DrawTexturePro(sprite->textures[sprite->frameCurrent], (Rectangle){0, 0, sourceWidth, 16}, (Rectangle){position.x, position.y, width, height}, origin, 0, color);
    }
    else
    {
        DrawTexturePro(sprite->textures[0], (Rectangle){0, 0, sourceWidth, 16}, (Rectangle){position.x, position.y, width, height}, origin, 0, color);
    }
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
