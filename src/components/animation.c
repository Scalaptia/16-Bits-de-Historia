#include "../headers/animation.h"

Sprite charSprite;
Sprite charPickSprite;

// NPCs
Sprite npcEnojado1Sprite;
Sprite npcEnojado2Sprite;
Sprite npcTirado1Sprite;
Sprite npcTirado2Sprite;
Sprite npcRecargado1Sprite;
Sprite npcRecargado2Sprite;
Sprite npcSaco1Sprite;
Sprite npcSaco2Sprite;

// Enemys
Sprite bulletSprite;
Sprite enemy1Sprite;
Sprite enemy2Sprite;
Sprite enemy3Sprite;
Sprite enemy4Sprite;

void InitSprite(Sprite *sprite, int frameCount)
{
    char path[160];

    sprite->frameCount = frameCount;
    sprite->frameCurrent = 0;

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
    UpdateSpriteFrame(&npcEnojado1Sprite);
    UpdateSpriteFrame(&npcEnojado2Sprite);
    UpdateSpriteFrame(&npcTirado1Sprite);
    UpdateSpriteFrame(&npcTirado2Sprite);
    UpdateSpriteFrame(&npcRecargado1Sprite);
    UpdateSpriteFrame(&npcRecargado2Sprite);
    UpdateSpriteFrame(&npcSaco1Sprite);
    UpdateSpriteFrame(&npcSaco2Sprite);

    UpdateSpriteFrame(&bulletSprite);
    UpdateSpriteFrame(&enemy1Sprite);
    UpdateSpriteFrame(&enemy2Sprite);
    UpdateSpriteFrame(&enemy3Sprite);
    UpdateSpriteFrame(&enemy4Sprite);
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
    strcpy(npcEnojado1Sprite.path, "NPCs/Enojado/Triste/");
    strcpy(npcEnojado2Sprite.path, "NPCs/Enojado/Feliz/");
    strcpy(npcTirado1Sprite.path, "NPCs/Tirado/Triste/");
    strcpy(npcTirado2Sprite.path, "NPCs/Tirado/Feliz/");
    strcpy(npcRecargado1Sprite.path, "NPCs/Recargado/Triste/");
    strcpy(npcRecargado2Sprite.path, "NPCs/Recargado/Feliz/");
    strcpy(npcSaco1Sprite.path, "NPCs/Saco/Triste/");
    strcpy(npcSaco2Sprite.path, "NPCs/Saco/Feliz/");
    strcpy(bulletSprite.path, "Enemigos/Bala/");
    strcpy(enemy1Sprite.path, "Enemigos/E1/");
    strcpy(enemy2Sprite.path, "Enemigos/E2/");
    strcpy(enemy3Sprite.path, "Enemigos/E3/");
    strcpy(enemy4Sprite.path, "Enemigos/E4/");

    charSprite.frameTime = ANIMATION_SPEED;
    InitSprite(&charSprite, 4);

    charPickSprite.frameTime = ANIMATION_SPEED;
    InitSprite(&charPickSprite, 4);

    npcEnojado1Sprite.frameTime = ANIMATION_SPEED * 4;
    InitSprite(&npcEnojado1Sprite, 2);

    npcEnojado2Sprite.frameTime = ANIMATION_SPEED * 4;
    InitSprite(&npcEnojado2Sprite, 2);

    npcTirado1Sprite.frameTime = ANIMATION_SPEED * 4;
    InitSprite(&npcTirado1Sprite, 2);

    npcTirado2Sprite.frameTime = ANIMATION_SPEED * 4;
    InitSprite(&npcTirado2Sprite, 2);

    InitSprite(&npcRecargado1Sprite, 1);
    InitSprite(&npcRecargado2Sprite, 1);

    InitSprite(&npcSaco1Sprite, 1);
    InitSprite(&npcSaco2Sprite, 1);

    InitSprite(&bulletSprite, 1);

    enemy1Sprite.frameTime = ANIMATION_SPEED * 2;
    InitSprite(&enemy1Sprite, 2);

    enemy2Sprite.frameTime = ANIMATION_SPEED * 2;
    InitSprite(&enemy2Sprite, 2);

    enemy3Sprite.frameTime = ANIMATION_SPEED * 2;
    InitSprite(&enemy3Sprite, 2);

    enemy4Sprite.frameTime = ANIMATION_SPEED * 2;
    InitSprite(&enemy4Sprite, 2);
}

void UnloadSprites()
{
    UnloadSprite(&charSprite);
    UnloadSprite(&charPickSprite);
    UnloadSprite(&npcEnojado1Sprite);
    UnloadSprite(&npcEnojado2Sprite);
    UnloadSprite(&npcTirado1Sprite);
    UnloadSprite(&npcTirado2Sprite);
    UnloadSprite(&npcRecargado1Sprite);
    UnloadSprite(&npcRecargado2Sprite);
    UnloadSprite(&npcSaco1Sprite);
    UnloadSprite(&npcSaco2Sprite);
    UnloadSprite(&bulletSprite);
    UnloadSprite(&enemy1Sprite);
    UnloadSprite(&enemy2Sprite);
    UnloadSprite(&enemy3Sprite);
    UnloadSprite(&enemy4Sprite);
}