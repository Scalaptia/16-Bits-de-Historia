#ifndef MENU_H
#define MENU_H

#include "raylib.h"
#include "../headers/animation.h"
#include <stdio.h>

enum GameState
{
    MENU,
    GAME,
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

void InitBackground();
void InitMenuButtons(Rectangle screen);
void CheckMenuButtons(Sound fxButton, Music MenuMusic);
void UpdateBackground(Rectangle screen);
void DrawMenuUI();
void UnloadBackground();

extern Sprite menuBackground;

extern Color selectedColor;
extern Color rectangleColor;

extern MenuButton startButton;
extern MenuButton optionsButton;
extern MenuButton exitButton;

extern Menu menu;

#endif