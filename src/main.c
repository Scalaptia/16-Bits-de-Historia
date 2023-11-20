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
#define REL_TILE_SIZE (TILE_SIZE * SCALE)

//----------------------------------------------------------------------------------
// Funciones Locales
//----------------------------------------------------------------------------------

int main(void)
{
    //------------------------------------------------
    int screenWidth = 1920;
    int screenHeight = 1080;
    float SCALE = 5.0f;

    //------------------------------------------------
    bool debug = false;
    bool pause = false;
    bool exitWindow = false;

    //------------------------------------------------

    // Config
    //--------------------------------------------------------------------------------------
    Rectangle window = {0, 0, screenWidth, screenHeight};

    GraphicsData tileset;

    InitWindow(screenWidth, screenHeight, "juego");

    InitSprite(&charSprite);
    InitGraphics(&tileset);
    InitBackground();
    InitMenuButtons((Rectangle){0, 0, screenWidth, screenHeight});

    InitAudioDevice();
    InitSound();

    Player player = {.position = {REL_TILE_SIZE * 2, REL_TILE_SIZE * 2}, .color = WHITE, .direction = 1};

    //------------------------------------------------
    Camera2D camera = {0};
    camera.target = (Vector2){player.position.x, player.position.y};
    camera.offset = (Vector2){(screenWidth / 2) - (TILE_SIZE * 2), (screenHeight / 2) - (TILE_SIZE * 2)};
    camera.zoom = 1.0f;

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
            // Musica de menu ----------------------------------
            UpdateMusicStream(MenuMusic);

            PlayMusicStream(MenuMusic);

            timePlayedMenu = GetMusicTimePlayed(MenuMusic) / GetMusicTimeLength(MenuMusic);
            if (timePlayedMenu > 1.0f)
                timePlayedMenu = 1.0f;

            StopMusicStream(music); // Detiene la musica de la escena 1

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
            // Musica
            //-------------------------------------------------------------
            UpdateMusicStream(music);
            PlayMusicStream(music);

            timePlayed = GetMusicTimePlayed(music) / GetMusicTimeLength(music);

            if (timePlayed > 1.0f)
                timePlayed = 1.0f;
            //-----------------------------------------------------------

            Keybinds(&debug, &pause, &camera, &music, &fxButton);
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
                    DrawRoom(&tileset, (Vector2){TILE_SIZE * 6, 0}, SCALE);

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
    UnloadRenderTexture(screenCam);

    UnloadMusicStream(music);
    UnloadMusicStream(MenuMusic);
    CloseAudioDevice();

    UnloadSprite(&charSprite);
    UnloadBackground();
    UnloadGraphics(&tileset);
    CloseWindow();
    //--------------------------------------------------------------------------------------

    return 0;
}
