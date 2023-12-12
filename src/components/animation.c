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
Sprite npcMexicano1Sprite;
Sprite npcMexicano2Sprite;
Sprite npcMexicano3Sprite;
Sprite npcMexicano4Sprite;

// Enemys
Sprite bulletSprite;
Sprite enemy1Sprite;
Sprite enemy2Sprite;
Sprite enemy3Sprite;
Sprite enemy4Sprite;

// Salidas
Sprite textoSalidaSprite;
Sprite huecoSalidaSprite;

void InitSprite(Sprite *sprite, int frameCount)
{
    char strpath[512];
    char path[512];

    sprite->frameCount = frameCount;
    sprite->frameCurrent = 0;

    sprite->textures = (Texture2D *)malloc(sizeof(Texture2D) * sprite->frameCount);

    for (int i = 0; i < sprite->frameCount; i++)
    {
        strcpy(strpath, GetWorkingDirectory());
        strcat(strpath, "/assets/");

        sprintf(path, "%s%d.png", sprite->path, i + 1);
        strcat(strpath, path);

        Image frameImage = LoadImage(strpath);
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
    UpdateSpriteFrame(&npcMexicano1Sprite);
    UpdateSpriteFrame(&npcMexicano2Sprite);
    UpdateSpriteFrame(&npcMexicano3Sprite);
    UpdateSpriteFrame(&npcMexicano4Sprite);

    UpdateSpriteFrame(&textoSalidaSprite);
    UpdateSpriteFrame(&huecoSalidaSprite);
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
    strcpy(npcMexicano1Sprite.path, "NPCs/Mexicano/M1/");
    strcpy(npcMexicano2Sprite.path, "NPCs/Mexicano/M2/");
    strcpy(npcMexicano3Sprite.path, "NPCs/Mexicano/M3/");
    strcpy(npcMexicano4Sprite.path, "NPCs/Mexicano/M4/");

    strcpy(textoSalidaSprite.path, "Salidas/Text/");
    strcpy(huecoSalidaSprite.path, "Salidas/Hueco/");

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

    InitSprite(&npcMexicano1Sprite, 1);
    InitSprite(&npcMexicano2Sprite, 1);
    InitSprite(&npcMexicano3Sprite, 1);
    InitSprite(&npcMexicano4Sprite, 1);

    InitSprite(&huecoSalidaSprite, 1);

    textoSalidaSprite.frameTime = ANIMATION_SPEED * 4;
    InitSprite(&textoSalidaSprite, 2);
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
    UnloadSprite(&npcMexicano1Sprite);
    UnloadSprite(&npcMexicano2Sprite);
    UnloadSprite(&npcMexicano3Sprite);
    UnloadSprite(&npcMexicano4Sprite);
    UnloadSprite(&textoSalidaSprite);
    UnloadSprite(&huecoSalidaSprite);
}