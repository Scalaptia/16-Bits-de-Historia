#include "../headers/menu.h"

Sprite menuBackground;

Color selectedColor = {0, 0, 0, 255};
Color rectangleColor = {0, 0, 0, 128};

Vector2 mousePoint = {0.0f, 0.0f};

/* Main Menu */
MenuButton startButton;
MenuButton optionsButton;
MenuButton exitButton;

/* Options Menu*/
MenuButton fullscreenButton;
MenuButton toggleMusicButton;
MenuButton volumeUpButton;
MenuButton volumeDownButton;
MenuButton backButton;

Menu menu;

enum GameState currentScene;

void InitBackground()
{
    char path[100];

    menuBackground.frameCount = 33;
    menuBackground.frameCurrent = 0;
    menuBackground.frameTime = ANIMATION_SPEED / 2;

    menuBackground.textures = (Texture2D *)malloc(sizeof(Texture2D) * menuBackground.frameCount);

    for (int i = 0; i < menuBackground.frameCount; i++)
    {
        sprintf(path, ASSETS_PATH "Background/bg%d.png", i + 1);
        Image frameImage = LoadImage(path);
        menuBackground.textures[i] = LoadTextureFromImage(frameImage);
        UnloadImage(frameImage);
    }
}

void InitMenuButtons(Rectangle screen)
{
    startButton.text = "Jugar";
    startButton.rect = (Rectangle){screen.width / 2 - 150, screen.height / 2 - 50, 300, 50};
    startButton.color = WHITE;

    optionsButton.text = "Opciones";
    optionsButton.rect = (Rectangle){screen.width / 2 - 150, screen.height / 2, 300, 50};
    optionsButton.color = WHITE;

    exitButton.text = "Salir";
    exitButton.rect = (Rectangle){screen.width / 2 - 150, screen.height / 2 + 100, 300, 50};
    exitButton.color = WHITE;

    fullscreenButton.text = "Pantalla Completa";
    fullscreenButton.rect = (Rectangle){screen.width / 2 - 150, screen.height / 2 - 50, 300, 50};
    fullscreenButton.color = WHITE;

    toggleMusicButton.text = "Apagar Música";
    toggleMusicButton.rect = (Rectangle){screen.width / 2 - 150, screen.height / 2 + 0, 300, 50};
    toggleMusicButton.color = WHITE;

    volumeUpButton.text = "Subir Volumen";
    volumeUpButton.rect = (Rectangle){screen.width / 2 - 150, screen.height / 2 + 50, 300, 50};
    volumeUpButton.color = WHITE;

    volumeDownButton.text = "Bajar Volumen";
    volumeDownButton.rect = (Rectangle){screen.width / 2 - 150, screen.height / 2 + 100, 300, 50};
    volumeDownButton.color = WHITE;

    backButton.text = "Atrás";
    backButton.rect = (Rectangle){screen.width / 2 - 150, screen.height / 2 + 200, 300, 50};
    backButton.color = WHITE;

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
            menu.state = currentScene;
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

void CheckOptionsButtons(Sound fxButton, Music MenuMusic, float *volume, bool *ToggleMusic)
{
    mousePoint = GetMousePosition();

    fullscreenButton.color = rectangleColor;
    toggleMusicButton.color = rectangleColor;
    if (*ToggleMusic)
    {
        toggleMusicButton.text = "Apagar Música";
    }
    else
    {
        toggleMusicButton.text = "Encender Música";
    }

    volumeUpButton.color = rectangleColor;
    volumeDownButton.color = rectangleColor;
    backButton.color = rectangleColor;

    // Check mouse collision with buttons
    if (CheckCollisionPointRec(mousePoint, fullscreenButton.rect))
    {
        fullscreenButton.color = selectedColor;

        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        {
            PlaySound(fxButton);
            ToggleFullscreen();
        }
    }

    if (CheckCollisionPointRec(mousePoint, toggleMusicButton.rect))
    {
        toggleMusicButton.color = selectedColor;

        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        {
            (*ToggleMusic) = !(*ToggleMusic);
        }
    }

    if (CheckCollisionPointRec(mousePoint, volumeUpButton.rect))
    {
        volumeUpButton.color = selectedColor;

        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        {
            PlaySound(fxButton);
            if (*volume < 1.0f)
                (*volume) += 0.1f;
        }
    }

    if (CheckCollisionPointRec(mousePoint, volumeDownButton.rect))
    {
        volumeDownButton.color = selectedColor;

        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        {
            PlaySound(fxButton);
            if (*volume > 0.0f)
                (*volume) -= 0.1f;
        }
    }

    if (CheckCollisionPointRec(mousePoint, backButton.rect))
    {
        backButton.color = selectedColor;

        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        {
            PlaySound(fxButton);
            menu.state = MENU;
        }
    }
}

void DrawMenuUI()
{
    // Draw title text (16-Bits de Historia)
    DrawText("16-Bits de Historia", GetScreenWidth() / 2 - MeasureText("16-Bits de Historia", 100) / 2, 54, 101, BLACK);
    DrawText("16-Bits de Historia", GetScreenWidth() / 2 - MeasureText("16-Bits de Historia", 100) / 2, 50, 100, WHITE);

    // Draw subtitle text (La batalla de Puebla)
    DrawText("La batalla de Puebla", GetScreenWidth() / 2 - MeasureText("La batalla de Puebla", 51) / 2, 164, 51, Fade(BLACK, 0.5f));
    DrawText("La batalla de Puebla", GetScreenWidth() / 2 - MeasureText("La batalla de Puebla", 50) / 2, 160, 50, RED);

    // Draw buttons
    DrawRectangleRec(startButton.rect, startButton.color);
    DrawRectangleRec(optionsButton.rect, optionsButton.color);
    DrawRectangleRec(exitButton.rect, exitButton.color);

    // Draw centered text
    DrawText(startButton.text, GetScreenWidth() / 2 - MeasureText(startButton.text, 30) / 2, startButton.rect.y + 10, 30, WHITE);
    DrawText(optionsButton.text, GetScreenWidth() / 2 - MeasureText(optionsButton.text, 30) / 2, optionsButton.rect.y + 10, 30, WHITE);
    DrawText(exitButton.text, GetScreenWidth() / 2 - MeasureText(exitButton.text, 30) / 2, exitButton.rect.y + 10, 30, WHITE);

    // Draw credits
    DrawText("@OnlyCodes", 6, GetScreenHeight() - 30, 20, Fade(WHITE, 0.8f));
}

void DrawOptionsUI()
{
    // Draw title text (16-Bits de Historia)
    DrawText("16-Bits de Historia", GetScreenWidth() / 2 - MeasureText("16-Bits de Historia", 100) / 2, 54, 101, BLACK);
    DrawText("16-Bits de Historia", GetScreenWidth() / 2 - MeasureText("16-Bits de Historia", 100) / 2, 50, 100, WHITE);

    // Draw subtitle text (La batalla de Puebla)
    DrawText("La batalla de Puebla", GetScreenWidth() / 2 - MeasureText("La batalla de Puebla", 51) / 2, 164, 51, Fade(BLACK, 0.5f));
    DrawText("La batalla de Puebla", GetScreenWidth() / 2 - MeasureText("La batalla de Puebla", 50) / 2, 160, 50, RED);

    // Draw buttons
    DrawRectangleRec(fullscreenButton.rect, fullscreenButton.color);
    DrawRectangleRec(toggleMusicButton.rect, toggleMusicButton.color);
    DrawRectangleRec(volumeUpButton.rect, volumeUpButton.color);
    DrawRectangleRec(volumeDownButton.rect, volumeDownButton.color);
    DrawRectangleRec(backButton.rect, backButton.color);

    // Draw centered text
    DrawText(fullscreenButton.text, GetScreenWidth() / 2 - MeasureText(fullscreenButton.text, 30) / 2, fullscreenButton.rect.y + 10, 30, WHITE);
    DrawText(toggleMusicButton.text, GetScreenWidth() / 2 - MeasureText(toggleMusicButton.text, 30) / 2, toggleMusicButton.rect.y + 10, 30, WHITE);
    DrawText(volumeUpButton.text, GetScreenWidth() / 2 - MeasureText(volumeUpButton.text, 30) / 2, volumeUpButton.rect.y + 10, 30, WHITE);
    DrawText(volumeDownButton.text, GetScreenWidth() / 2 - MeasureText(volumeDownButton.text, 30) / 2, volumeDownButton.rect.y + 10, 30, WHITE);
    DrawText(backButton.text, GetScreenWidth() / 2 - MeasureText(backButton.text, 30) / 2, backButton.rect.y + 10, 30, WHITE);

    // Draw credits
    DrawText("@OnlyCodes", 6, GetScreenHeight() - 30, 20, Fade(WHITE, 0.8f));
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

    DrawTexturePro(menuBackground.textures[menuBackground.frameCurrent], (Rectangle){0, 0, 640, 400}, screen, origin, 0, WHITE);
}

void UnloadBackground()
{
    for (int i = 0; i < 33; i++)
    {
        UnloadTexture(menuBackground.textures[i]);
    }

    free(menuBackground.textures);
}
