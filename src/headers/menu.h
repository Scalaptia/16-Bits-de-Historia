#ifndef MENU_H
#define MENU_H

#include "raylib.h"
#include "../headers/animation.h"
#include <stdio.h>

enum GameState
{
    LOADING,
    MENU,
    CINE1,
    SCENE1,
    SCENE2,
    SCENE3,
    OPTIONS,
    EXIT
};

typedef struct MenuButton
{
    Rectangle rect;
    Color color;
    char *text;
} MenuButton;

typedef struct Menu
{
    enum GameState state;
    enum GameState prevState;
} Menu;

void InitLoadingScreen();

void InitBackground();
void InitMenuButtons(Rectangle screen);

void CheckMenuButtons(Sound fxButton, Music MenuMusic);
void CheckOptionsButtons(Sound fxButton, Music MenuMusic, float *volume, bool *ToggleMusic);

void UpdateBackground(Rectangle screen);
void DrawMenuUI();
void DrawOptionsUI();

void UnloadBackground();
void UnloadLoadingScreen();

extern Sprite loadingScreen;
extern Sprite menuBackground;

extern Color selectedColor;
extern Color rectangleColor;

extern MenuButton startButton;
extern MenuButton optionsButton;
extern MenuButton exitButton;

extern MenuButton fullscreenButton;
extern MenuButton volumeUpButton;
extern MenuButton volumeDownButton;
extern MenuButton backButton;

extern Menu menu;

extern enum GameState currentScene;

#endif