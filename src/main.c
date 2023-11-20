//----------------------------------------------------------------------------------
// Librerías
//----------------------------------------------------------------------------------
#include "raylib.h"
#include "./headers/player.h"
#include "./headers/grid.h"
#include "./headers/graphics.h"
#include "./headers/animation.h"
#include "./headers/keybinds.h"

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
    int screenWidth = 800;
    int screenHeight = 800;
    float SCALE = 5.0f;
    bool debug = false;

    // Config
    //--------------------------------------------------------------------------------------
    Rectangle window = {0, 0, screenWidth, screenHeight};
    GraphicsData tileset;
    Sprite charSprite;

    InitWindow(screenWidth, screenHeight, "juego");
    InitSprite(&charSprite);
    InitGraphics(&tileset);

    Player player = {.position = {REL_TILE_SIZE * 2, REL_TILE_SIZE * 2}, .color = WHITE};

    Camera2D camera = {0};
    camera.target = (Vector2){player.position.x, player.position.y};
    camera.offset = (Vector2){(screenWidth / 2) - (TILE_SIZE * 2), (screenHeight / 2) - (TILE_SIZE * 2)};
    camera.zoom = 1.0f;

    RenderTexture screenCam = LoadRenderTexture(screenWidth, screenHeight);

    InitAudioDevice();              // Initialize audio device

    Music music = LoadMusicStream(ASSETS_PATH "Music/meow.mp3");

    PlayMusicStream(music);

    float timePlayed = 0.0f;        // Time played normalized [0.0f..1.0f]
    bool pause = false;             // Music playing paused

    SetTargetFPS(144);
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())
    {
        // Update
        //----------------------------------------------------------------------------------
        //Musica--
        UpdateMusicStream(music);

        if(IsKeyPressed(KEY_P))
        {
            pause=!pause;
            if(pause)
            {
                PauseMusicStream(music);
            }
            else
            {
                ResumeMusicStream(music);
            }
        }

        timePlayed = GetMusicTimePlayed(music)/GetMusicTimeLength(music);

        if (timePlayed > 1.0f) timePlayed = 1.0f;
        //----------------

        Keybinds(&debug, &camera);
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

                if (debug)
                {
                    PaintGrid((Grid){REL_TILE_SIZE, screenWidth * 2, screenHeight * 2, LIGHTGRAY});
                }

                UpdateSprite(&charSprite, player.position, SCALE, player.color);
            }
            EndMode2D();
        }
        EndTextureMode();
        //-----------------------------------------

        BeginDrawing();
        {
            ClearBackground(BLACK);

            // Pintar pantalla (textura)
            DrawTextureRec(screenCam.texture, (Rectangle){0, 0, screenWidth, -(screenHeight)}, (Vector2){0, 0}, WHITE);

            DrawFPS(GetScreenWidth() - 95, 10);
        }
        EndDrawing();
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    UnloadRenderTexture(screenCam);
    
    UnloadMusicStream(music);
    CloseAudioDevice();

    UnloadSprite(&charSprite);
    UnloadGraphics(&tileset);
    CloseWindow();
    //--------------------------------------------------------------------------------------

    return 0;
}