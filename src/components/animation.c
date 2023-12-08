#include "../headers/animation.h"

Sprite charSprite;
Sprite charPickSprite;

// NPCs
Sprite npcE1Sprite;
Sprite npcE2Sprite;

void InitSprite(Sprite *sprite, int frameCount)
{
    char path[160];

    sprite->frameCount = frameCount;
    sprite->frameCurrent = 0;
    sprite->frameTime = ANIMATION_SPEED;

    sprite->textures = (Texture2D *)malloc(sizeof(Texture2D) * sprite->frameCount);

    for (int i = 0; i < sprite->frameCount; i++)
    {
        sprintf(path, ASSETS_PATH "%s%d.png", sprite->path, i + 1);

        Image frameImage = LoadImage(path);
        sprite->textures[i] = LoadTextureFromImage(frameImage);
        UnloadImage(frameImage);
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
    UpdateSpriteFrame(&charPickSprite);
    UpdateSpriteFrame(&npcE1Sprite);
    UpdateSpriteFrame(&npcE2Sprite);
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
    for (int i = 0; i < sprite->frameCount; i++)
    {
        UnloadTexture(sprite->textures[i]);
    }

    free(sprite->textures);
}

void InitSprites()
{
    strcpy(charSprite.path, "Personaje/char");
    strcpy(charPickSprite.path, "Personaje/charpick");
    strcpy(npcE1Sprite.path, "NPCs/Enojado/Triste/");
    strcpy(npcE2Sprite.path, "NPCs/Enojado/Feliz/");

    InitSprite(&charSprite, 4);
    InitSprite(&charPickSprite, 4);
    InitSprite(&npcE1Sprite, 2);
    InitSprite(&npcE2Sprite, 2);
}

void UnloadSprites()
{
    UnloadSprite(&charSprite);
    UnloadSprite(&charPickSprite);
    UnloadSprite(&npcE1Sprite);
    UnloadSprite(&npcE2Sprite);
}