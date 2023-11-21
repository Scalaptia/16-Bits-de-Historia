//----------------------------------------------------------------------------------
// Librerías
//----------------------------------------------------------------------------------
#include "raylib.h"
#include "./headers/player.h"
#include "./headers/grid.h"
#include "./headers/level.h"
#include "./headers/animation.h"
#include "./headers/keybinds.h"
#include "./headers/menu.h"
#include "./headers/sound.h"

//----------------------------------------------------------------------------------
// Código
//----------------------------------------------------------------------------------

int main(void)
{
    //------------------------------------------------
    int screenWidth = 1920;
    int screenHeight = 1080;
    float masterVolume = 0.5f;

    bool debug = false;
    bool pause = false;
    bool exitWindow = false;

    // Config -----------------------------------------
    Rectangle window = {0, 0, screenWidth, screenHeight};

    GraphicsData tileset;

    InitWindow(screenWidth, screenHeight, "juego");

    strcpy(charSprite.path, "Personaje/char");
    strcpy(npcSprite.path, "Character_animation/monsters_idle/skeleton1/v2/skeleton1_v2_");

    InitPlayer(&charSprite, window); // Inicializa sprite, player y cámara
    InitGraphics(&tileset);          // Inicializa tileset (mapa)
    InitSprite(&npcSprite);

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
        SetMasterVolume(masterVolume);
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
            actPlayer(&player, &fxPasosGrava, room1);

            camera.target = (Vector2){player.position.x, player.position.y};

            // Draw
            //----------------------------------------------------------------------------------
            UpdateSpritesFrame();
            BeginTextureMode(screenCam);
            {
                BeginMode2D(camera);
                {
                    ClearBackground(BLACK);
                    DrawRoom(&tileset, (Vector2){0, 0});

                    DrawSpriteFrame(&npcSprite, (Vector2){REL_TILE_SIZE, REL_TILE_SIZE}, SCALE, WHITE, 1);
                    DrawSpriteFrame(&npcSprite, (Vector2){REL_TILE_SIZE * 4, REL_TILE_SIZE * 3}, SCALE, WHITE, -1);

                    if (debug)
                    {
                        PaintGrid((Grid){REL_TILE_SIZE, REL_TILE_SIZE * 20, REL_TILE_SIZE * 10, LIGHTGRAY});
                        DrawRectangle(player.position.x, player.position.y, REL_TILE_SIZE, REL_TILE_SIZE, player.color); // player collision

                        // Draw debug walls
                        for (int i = 0; i < room1.wallsCount; i++)
                        {
                            DrawRectangleLinesEx((Rectangle){room1.walls[i].x, room1.walls[i].y, REL_TILE_SIZE, REL_TILE_SIZE}, 4, RED);
                        }
                    }
                    else
                    {
                        DrawSpriteFrame(&charSprite, player.position, SCALE, player.color, player.direction);
                    }
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

            CheckOptionsButtons(fxButton, MenuMusic, &masterVolume);

            BeginDrawing();
            {
                ClearBackground(WHITE);
                UpdateBackground((Rectangle){0, 0, screenWidth, screenHeight});
                DrawOptionsUI();
            }
            EndDrawing();

            break;

        case EXIT:
            if (IsKeyPressed(KEY_S))
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

                UpdateBackground((Rectangle){0, 0, screenWidth, screenHeight});
                DrawRectangle(0, 0, screenWidth, screenHeight, rectangleColor); // Fondo gris

                DrawRectangle(0, screenHeight / 2 - 100, screenWidth, 200, BLACK); //
                DrawText("¿Desea salir del juego? [S/N]", screenWidth / 2 - 230, screenHeight / 2 - 15, 30, WHITE);
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
