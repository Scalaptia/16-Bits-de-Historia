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

    InitWindow(screenWidth, screenHeight, "split screen");

    Player player1 = {.position = {(screenWidth / 4) - 100, screenHeight / 2}, .color = RED};
    Player player2 = {.position = {(screenWidth / 4) + 100, screenHeight / 2}, .color = BLUE};

    Camera2D camera1 = {0};
    camera1.target = (Vector2){player1.position.x, player1.position.y};
    camera1.offset = (Vector2){200.0f, 200.0f};
    camera1.zoom = 1.0f;

    Camera2D camera2 = {0};
    camera2.target = (Vector2){player2.position.x, player2.position.y};
    camera2.offset = (Vector2){200.0f, 200.0f};
    camera2.zoom = 1.0f;

    // Crea dos texturas para dibujar la escena en split screen
    RenderTexture screenCamera1 = LoadRenderTexture(screenWidth / 2, screenHeight);
    RenderTexture screenCamera2 = LoadRenderTexture(screenWidth / 2, screenHeight);

    // Rectangulo tamaño mitad de la pantalla para dibujar las texturas de las camaras
    Rectangle splitScreenRect = {0.0f, 0.0f, (float)screenCamera1.texture.width, (float)-screenCamera1.texture.height};

    SetTargetFPS(60);
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())
    {
        // Update
        //----------------------------------------------------------------------------------

        // Movimiento del jugador
        movePlayer(&player1, KEY_W, KEY_S, KEY_A, KEY_D);
        movePlayer(&player2, KEY_UP, KEY_DOWN, KEY_LEFT, KEY_RIGHT);

        camera1.target = (Vector2){player1.position.x, player1.position.y};
        camera2.target = (Vector2){player2.position.x, player2.position.y};
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        // Escena Camara 1
        //-----------------------------------------
        BeginTextureMode(screenCamera1);
        {
            ClearBackground(RAYWHITE);

            BeginMode2D(camera1);
            {
                PaintGrid((Grid){PLAYER_SIZE, screenWidth, screenHeight, LIGHTGRAY});

                DrawRectangleRec((Rectangle){player1.position.x, player1.position.y, PLAYER_SIZE, PLAYER_SIZE}, player1.color);
                DrawRectangleRec((Rectangle){player2.position.x, player2.position.y, PLAYER_SIZE, PLAYER_SIZE}, player2.color);
            }
            EndMode2D();

            // UI drawing
            DrawRectangle(0, 0, GetScreenWidth() / 2, 30, Fade(RAYWHITE, 0.6f));
            DrawText("PLAYER1: W/S/A/D", 10, 10, 10, MAROON);
        }
        EndTextureMode();
        //-----------------------------------------

        // Escena Camara 2
        //-----------------------------------------
        BeginTextureMode(screenCamera2);
        {
            ClearBackground(RAYWHITE);

            BeginMode2D(camera2);
            {
                PaintGrid((Grid){PLAYER_SIZE, screenWidth, screenHeight, GRAY});

                DrawRectangleRec((Rectangle){player1.position.x, player1.position.y, PLAYER_SIZE, PLAYER_SIZE}, player1.color);
                DrawRectangleRec((Rectangle){player2.position.x, player2.position.y, PLAYER_SIZE, PLAYER_SIZE}, player2.color);
            }
            EndMode2D();

            // UI drawing
            DrawRectangle(0, 0, GetScreenWidth() / 2, 30, Fade(RAYWHITE, 0.6f));
            DrawText("PLAYER2: UP/DOWN/LEFT/RIGHT", 10, 10, 10, DARKBLUE);
        }
        EndTextureMode();
        //-----------------------------------------

        // Pinta ambas vistas para renderizar lado a lado
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(BLACK);

        DrawTextureRec(screenCamera1.texture, splitScreenRect, (Vector2){0, 0}, WHITE);
        DrawTextureRec(screenCamera2.texture, splitScreenRect, (Vector2){screenWidth / 2.0f, 0}, WHITE);

        DrawRectangle(GetScreenWidth() / 2 - 2, 0, 4, GetScreenHeight(), LIGHTGRAY);

        DrawFPS(GetScreenWidth() - 95, 10);
        EndDrawing();
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    UnloadRenderTexture(screenCamera1);
    UnloadRenderTexture(screenCamera2);

    CloseWindow();
    //--------------------------------------------------------------------------------------

    return 0;
}
