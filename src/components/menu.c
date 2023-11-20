#include "../headers/menu.h"

Sprite menuBackground;

void InitBackground()
{
    char path[100];

    menuBackground.frameCount = 33;
    menuBackground.frameCurrent = 0;
    menuBackground.frameTime = ANIMATION_SPEED / 2;

    menuBackground.frames = (Image *)malloc(sizeof(Image) * 33);
    menuBackground.textures = (Texture2D *)malloc(sizeof(Texture2D) * 33);

    for (int i = 0; i < 33; i++)
    {
        sprintf(path, ASSETS_PATH "background/bg%d.png", i + 1);
        menuBackground.frames[i] = LoadImage(path);

        menuBackground.textures[i] = LoadTextureFromImage(menuBackground.frames[i]);
    }
}

void UpdateBackground(Vector2 screen)
{
    menuBackground.currentTime += GetFrameTime();

    if (menuBackground.currentTime >= menuBackground.frameTime)
    {
        menuBackground.currentTime = 0.0f;
        menuBackground.frameCurrent++;

        if (menuBackground.frameCurrent >= menuBackground.frameCount)
        {
            menuBackground.frameCurrent = 0;
        }
    }

    Vector2 origin = {0, 0};

    DrawTexturePro(menuBackground.textures[menuBackground.frameCurrent], (Rectangle){0, 0, screen.x / 3, screen.y / 2.8}, (Rectangle){0, 0, screen.x, screen.y}, origin, 0, WHITE);
}

void UnloadBackground()
{
    for (int i = 0; i < 33; i++)
    {
        UnloadImage(menuBackground.frames[i]);
        UnloadTexture(menuBackground.textures[i]);
    }

    free(menuBackground.frames);
    free(menuBackground.textures);
}