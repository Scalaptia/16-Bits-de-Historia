#include "../headers/keybinds.h"

Keys keys = {.DEBUG_KEY = KEY_F1,
             .ZOOM_IN_KEY = KEY_PAGE_DOWN,
             .ZOOM_OUT_KEY = KEY_PAGE_UP,
             .SCREENSHOT_KEY = KEY_F12};

void Keybinds(bool *debug, Camera2D *camera)
{
    if (IsKeyPressed(keys.DEBUG_KEY))
    {
        *debug = !(*debug);
    }

    if (IsKeyPressed(keys.ZOOM_IN_KEY) && camera->zoom <= 1.8f)
    {
        camera->zoom += 0.05f;
    }

    if (IsKeyPressed(keys.ZOOM_OUT_KEY) && camera->zoom >= 0.4f)
    {
        camera->zoom -= 0.05f;
    }

    if (IsKeyPressed(keys.SCREENSHOT_KEY))
    {
        TakeScreenshot("screenshot.png");
    }
}