#ifndef MENU_H
#define MENU_H

#include "raylib.h"

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

#endif