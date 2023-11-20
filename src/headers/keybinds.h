#ifndef KEYBINDS_H
#define KEYBINDS_H

#include "raylib.h"

typedef struct Controls
{
    KeyboardKey UP_KEY;
    KeyboardKey DOWN_KEY;
    KeyboardKey LEFT_KEY;
    KeyboardKey RIGHT_KEY;
    KeyboardKey ATTACK_KEY;
} Controls;

typedef struct Keys
{
    KeyboardKey DEBUG_KEY;
    KeyboardKey ZOOM_IN_KEY;
    KeyboardKey ZOOM_OUT_KEY;
    KeyboardKey SCREENSHOT_KEY;
} Keys;

void Keybinds(bool *debug, Camera2D *camera);

#endif