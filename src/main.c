//----------------------------------------------------------------------------------
// Librerías
//----------------------------------------------------------------------------------
#include "raylib.h"
#include "./headers/player.h"
#include "./headers/grid.h"
#include "./headers/graphics.h"
#include "./headers/animation.h"
#include "./headers/keybinds.h"
#include "./headers/menu.h"
#include "./headers/sound.h"

//----------------------------------------------------------------------------------
// Variables Locales (al módulo)
//----------------------------------------------------------------------------------
#define TILE_SIZE 16
#define SCALE 5
#define REL_TILE_SIZE (TILE_SIZE * SCALE)

//----------------------------------------------------------------------------------
// Funciones Locales
//----------------------------------------------------------------------------------

int main(void)
{
    //------------------------------------------------
    int screenWidth = 1920;
    int screenHeight = 1080;

    bool debug = false;
    bool pause = false;
    bool exitWindow = false;

    // Config -----------------------------------------
    Rectangle window = {0, 0, screenWidth, screenHeight};

    GraphicsData tileset;

    InitWindow(screenWidth, screenHeight, "juego");

    InitPlayer(&charSprite, window, TILE_SIZE, REL_TILE_SIZE); // Inicializa sprite, player y cámara
    InitGraphics(&tileset);                                    // Inicializa tileset (mapa)

    InitBackground();
    InitMenuButtons(window);

    InitAudioDevice();
    InitSounds();

    RenderTexture screenCam = LoadRenderTexture(screenWidth, screenHeight);

    //------------------------
    SetTargetFPS(144);

    // Main game loop
    while (!exitWindow)
    {
        if (WindowShouldClose())
        {
            menu.prevState = menu.state;
            menu.state = MENU;
        }

        switch (menu.state)
        {
        case MENU:
            PlayMusic(MenuMusic);

            //-------------------------------------------------
            CheckMenuButtons(fxButton, MenuMusic);

            BeginDrawing();
            {
                ClearBackground(WHITE);
                UpdateBackground((Rectangle){0, 0, screenWidth, screenHeight});
                DrawMenuUI();
            }
            EndDrawing();

            break;

        case GAME:
            PlayMusic(GameMusic);
            //-----------------------------------------------------------

            Keybinds(&debug, &pause, &camera, &GameMusic, &fxButton);
            actPlayer(&player, &fxPasosGrava);

            camera.target = (Vector2){player.position.x, player.position.y};

            // Draw
            //----------------------------------------------------------------------------------
            BeginTextureMode(screenCam);
            {
                BeginMode2D(camera);
                {
                    ClearBackground(BLACK);
                    DrawRoom(&tileset, (Vector2){0, 0}, SCALE);
                    DrawRoom(&tileset, (Vector2){0, TILE_SIZE * 5}, SCALE);
                    DrawRoom(&tileset, (Vector2){TILE_SIZE * 6, 0}, SCALE);
                    DrawRoom(&tileset, (Vector2){TILE_SIZE * 6, TILE_SIZE * 5}, SCALE);

                    if (debug)
                    {
                        PaintGrid((Grid){REL_TILE_SIZE, screenWidth * 2, screenHeight * 2, LIGHTGRAY});
                    }

                    // DrawRectangle(player.position.x, player.position.y, REL_TILE_SIZE, REL_TILE_SIZE, player.color); // player collision
                    UpdateSprite(&charSprite, player.position, SCALE, player.color, player.direction);
                }
                EndMode2D();
            }
            EndTextureMode();
            //-----------------------------------------

            BeginDrawing();
            {
                // Pintar pantalla (textura)
                DrawTextureRec(screenCam.texture, (Rectangle){0, 0, screenWidth, -(screenHeight)}, (Vector2){0, 0}, WHITE);
                DrawFPS(GetScreenWidth() - 95, 10);
            }
            EndDrawing();

            break;

        case OPTIONS:
            PlayMusic(MenuMusic);
            menu.state = MENU;
            break;

        case EXIT:
            if (IsKeyPressed(KEY_Y))
            {
                exitWindow = true;
            }
            else if (IsKeyPressed(KEY_N))
            {
                menu.state = menu.prevState;
            }

            BeginDrawing();
            {
                ClearBackground(RAYWHITE);

                DrawRectangle(0, 100, screenWidth, 200, BLACK);
                DrawText("Are you sure you want to exit program? [Y/N]", 40, 180, 30, WHITE);
            }
            EndDrawing();

            break;
        }
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------

    UnloadSounds();
    CloseAudioDevice();

    UnloadRenderTexture(screenCam);
    UnloadBackground();
    UnloadSprite(&charSprite);
    UnloadGraphics(&tileset);

    CloseWindow();
    //--------------------------------------------------------------------------------------

    return 0;
}
