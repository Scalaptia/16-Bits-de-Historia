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
void UpdateBackground(Vector2 screen);
void UnloadBackground();

extern Sprite menuBackground;

#endif