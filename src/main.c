//----------------------------------------------------------------------------------
// Librerías
//----------------------------------------------------------------------------------
#include "raylib.h"
#include "./headers/player.h"
#include "./headers/grid.h"

//----------------------------------------------------------------------------------
// Variables Locales (al módulo)
//----------------------------------------------------------------------------------
#define PLAYER_SIZE 40

//----------------------------------------------------------------------------------
// Funciones Locales
//----------------------------------------------------------------------------------

int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 440;

    InitWindow(screenWidth, screenHeight, "juego");
    InitAudioDevice();

    Player player = {.position = {(screenWidth / 2), screenHeight / 2}, .color = BLUE, .controls = {KEY_W, KEY_S, KEY_A, KEY_D, KEY_SPACE}};

    Camera2D camera = {0};
    camera.target = (Vector2){player.position.x, player.position.y};
    camera.offset = (Vector2){(screenWidth / 2) - (PLAYER_SIZE / 2), (screenHeight / 2) - (PLAYER_SIZE / 2)};
    camera.zoom = 1.0f;

    Sound fxHurt = LoadSound("resources/hurt.wav");

    // Textura para camara
    RenderTexture screenCam = LoadRenderTexture(screenWidth, screenHeight);

    SetTargetFPS(60);
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())
    {
        // Update
        //----------------------------------------------------------------------------------

        // Movimiento del jugador
        //-----------------------------------------
        actPlayer(&player);
        camera.target = (Vector2){player.position.x, player.position.y};

        // Draw
        //----------------------------------------------------------------------------------
        BeginTextureMode(screenCam);
        {
            ClearBackground(RAYWHITE);

            BeginMode2D(camera);
            {
                PaintGrid((Grid){PLAYER_SIZE, screenWidth, screenHeight, LIGHTGRAY});

                DrawRectangleRec((Rectangle){player.position.x, player.position.y, PLAYER_SIZE, PLAYER_SIZE}, player.color);
            }
            EndMode2D();

            // UI drawing
            DrawRectangle(0, 0, screenWidth, 30, Fade(RAYWHITE, 0.6f));
            DrawText("MOVE: W/A/S/D", 10, 10, 10, MAROON);
        }
        EndTextureMode();
        //-----------------------------------------

        // Renderizar camara
        BeginDrawing();

        ClearBackground(BLACK);

        DrawTextureRec(screenCam.texture, (Rectangle){0, 0, screenWidth, -(screenHeight)}, (Vector2){0, 0}, WHITE);

        DrawFPS(GetScreenWidth() - 95, 10);
        EndDrawing();
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    UnloadRenderTexture(screenCam);

    CloseAudioDevice();
    CloseWindow();
    //--------------------------------------------------------------------------------------

    return 0;
}
