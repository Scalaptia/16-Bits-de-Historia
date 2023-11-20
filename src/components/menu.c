#include "../headers/menu.h"

Sprite menuBackground;

Color selectedColor = {0, 0, 0, 255};
Color rectangleColor = {0, 0, 0, 128};

Vector2 mousePoint = {0.0f, 0.0f};
MenuButton startButton;
MenuButton optionsButton;
MenuButton exitButton;

Menu menu;

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

void InitMenuButtons(Rectangle screen)
{

    startButton.text = "Start Game";
    startButton.rect = (Rectangle){screen.width / 2 - 100, screen.height / 2 - 50, 200, 50};
    startButton.color = WHITE;

    optionsButton.text = "Options";
    optionsButton.rect = (Rectangle){screen.width / 2 - 100, screen.height / 2, 200, 50};
    optionsButton.color = WHITE;

    exitButton.text = "Exit";
    exitButton.rect = (Rectangle){screen.width / 2 - 100, screen.height / 2 + 50, 200, 50};
    exitButton.color = WHITE;

    menu.state = MENU;
    menu.prevState = MENU;
}

void CheckMenuButtons(Sound fxButton, Music MenuMusic)
{
    mousePoint = GetMousePosition();

    startButton.color = rectangleColor;
    optionsButton.color = rectangleColor;
    exitButton.color = rectangleColor;

    // Check mouse collision with buttons
    if (CheckCollisionPointRec(mousePoint, startButton.rect))
    {
        startButton.color = selectedColor;

        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        {
            PlaySound(fxButton);
            StopMusicStream(MenuMusic);
            menu.state = GAME;
        }
    }

    if (CheckCollisionPointRec(mousePoint, optionsButton.rect))
    {
        optionsButton.color = selectedColor;

        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        {
            PlaySound(fxButton);
            menu.state = OPTIONS;
        }
    }

    if (CheckCollisionPointRec(mousePoint, exitButton.rect))
    {
        exitButton.color = selectedColor;

        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        {
            PlaySound(fxButton);
            StopMusicStream(MenuMusic);
            menu.prevState = menu.state;
            menu.state = EXIT;
        }
    }
}

void DrawMenuUI()
{
    // Draw buttons
    DrawRectangleRec(startButton.rect, startButton.color);
    DrawRectangleRec(optionsButton.rect, optionsButton.color);
    DrawRectangleRec(exitButton.rect, exitButton.color);

    // Draw text
    DrawText(startButton.text, startButton.rect.x + 10, startButton.rect.y, 30, WHITE);
    DrawText(optionsButton.text, optionsButton.rect.x + 10, optionsButton.rect.y, 30, WHITE);
    DrawText(exitButton.text, exitButton.rect.x + 10, exitButton.rect.y + 10, 30, WHITE);
}

void UpdateBackground(Rectangle screen)
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

    DrawTexturePro(menuBackground.textures[menuBackground.frameCurrent], (Rectangle){0, 0, screen.width / 3, screen.height / 2.8}, screen, origin, 0, WHITE);
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