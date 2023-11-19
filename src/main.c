//----------------------------------------------------------------------------------
// Librerías
//----------------------------------------------------------------------------------
#include "raylib.h"
#include "./headers/player.h"
#include "./headers/grid.h"
#include "./headers/graphics.h"

//----------------------------------------------------------------------------------
// Variables Locales (al módulo)
//----------------------------------------------------------------------------------
#define TILE_SIZE 16
#define SCALE 5.0f
#define REL_TILE_SIZE (TILE_SIZE * SCALE)

//----------------------------------------------------------------------------------
// Funciones Locales
//----------------------------------------------------------------------------------

int main(void)
{
    int screenWidth = 800;
    int screenHeight = 800;
    bool debug = false;

    // Config
    //--------------------------------------------------------------------------------------
    Rectangle window = {0, 0, screenWidth, screenHeight};
    GraphicsData tileset;

    InitWindow(screenWidth, screenHeight, "juego");
    InitGraphics(&tileset);

    Player player = {.position = {REL_TILE_SIZE * 2, REL_TILE_SIZE * 2}, .color = BLUE, .controls = {KEY_W, KEY_S, KEY_A, KEY_D, KEY_SPACE}};

    Camera2D camera = {0};
    camera.target = (Vector2){player.position.x, player.position.y};
    camera.offset = (Vector2){(screenWidth / 2) - (TILE_SIZE / 2), (screenHeight / 2) - (TILE_SIZE / 2)};
    camera.zoom = 1.0f;

    RenderTexture screenCam = LoadRenderTexture(screenWidth, screenHeight);

    SetTargetFPS(120);
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())
    {
        // Update
        //----------------------------------------------------------------------------------
        if (IsKeyPressed(KEY_F1))
        {
            debug = !debug;
        }

        // Movimiento del jugador
        //-----------------------------------------
        actPlayer(&player);
        camera.target = (Vector2){player.position.x, player.position.y};

        // Draw
        //----------------------------------------------------------------------------------
        BeginTextureMode(screenCam);
        {
            ClearBackground(BLACK);

            BeginMode2D(camera);
            {
                DrawRoom(&tileset, (Vector2){0, 0}, SCALE);
                DrawRoom(&tileset, (Vector2){TILE_SIZE * 6, 0}, SCALE);
                DrawRoom(&tileset, (Vector2){TILE_SIZE * 12, 0}, SCALE);

                if (debug)
                {
                    PaintGrid((Grid){REL_TILE_SIZE, screenWidth * 2, screenHeight * 2, LIGHTGRAY});
                }

                DrawRectangleRec((Rectangle){player.position.x, player.position.y, REL_TILE_SIZE, REL_TILE_SIZE}, player.color);
            }
            EndMode2D();
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

    UnloadGraphics(&tileset);
    CloseWindow();
    //--------------------------------------------------------------------------------------

    return 0;
}