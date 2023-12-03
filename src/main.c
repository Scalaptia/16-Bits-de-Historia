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
    int screenWidth = 1280;
    int screenHeight = 720;
    float masterVolume = 0.5f;

    bool debug = false;
    bool pause = false;
    bool exitWindow = false;
    bool ToggleMusic = true;
    char path[100];

    // Config -----------------------------------------

    Rectangle window = {0, 0, screenWidth, screenHeight};

    GraphicsData tileset;

    InitWindow(screenWidth, screenHeight, "16-Bits de Historia");
    SetWindowIcon(LoadImage(ASSETS_PATH "Icon/Logo.png"));

    strcpy(charSprite.path, "Personaje/char");
    strcpy(charPickSprite.path, "Personaje/charpick");
    strcpy(npcSprite.path, "Character_animation/monsters_idle/skeleton1/v2/skeleton1_v2_");

    InitPlayer(&charSprite, &charPickSprite, window); // Inicializa sprite, player y cámara
    InitGraphics(&tileset);                           // Inicializa tileset (mapa)
    InitSprite(&npcSprite);                           // Inicializa sprite del NPC

    InitLoadingScreen();
    InitBackground();
    InitMenuButtons(window);

    InitAudioDevice();
    InitSounds();

    RenderTexture screenCam = LoadRenderTexture(screenWidth, screenHeight);

    //------------------------
    SetTargetFPS(144);

    menu.state = GAME; // DEBERÍA SER LOADING
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
        case LOADING:
            while (loadingScreen.frameCurrent < loadingScreen.frameCount)
            {
                PlayMusic(IntroMusic);
                BeginDrawing();
                {
                    ClearBackground(RAYWHITE);

                    loadingScreen.currentTime += GetFrameTime();

                    if (loadingScreen.currentTime >= loadingScreen.frameTime)
                    {
                        loadingScreen.currentTime = 0.0f;
                        loadingScreen.frameCurrent++;

                        sprintf(path, ASSETS_PATH "LoadingScreen/frame%04d.png", loadingScreen.frameCurrent + 1);
                        loadingScreen.frames[0] = LoadImage(path);
                        loadingScreen.textures[0] = LoadTextureFromImage(loadingScreen.frames[0]);
                    }

                    DrawTexturePro(loadingScreen.textures[0], (Rectangle){0, 0, 1280, 720}, (Rectangle){0, 0, screenWidth, screenHeight}, (Vector2){0, 0}, 0, WHITE);

                    if (loadingScreen.frameCurrent == loadingScreen.frameCount - 1)
                    {
                        menu.state = MENU;
                        menu.prevState = MENU;
                        EndDrawing();
                        break;
                    }
                }
                EndDrawing();
            }

            break;

        case MENU:
            if (ToggleMusic)
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
            if (ToggleMusic)
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

                    DrawSpriteFrame(&npcSprite, (Vector2){REL_TILE_SIZE, REL_TILE_SIZE}, SCALE, WHITE, 1, true);
                    DrawSpriteFrame(&npcSprite, (Vector2){REL_TILE_SIZE * 4, REL_TILE_SIZE * 3}, SCALE, WHITE, -1, true);

                    if (debug)
                    {
                        PaintGrid((Grid){REL_TILE_SIZE, REL_TILE_SIZE * 6, REL_TILE_SIZE * 5, LIGHTGRAY});
                        DrawRectangle(player.position.x, player.position.y, REL_TILE_SIZE, REL_TILE_SIZE, player.color); // player collision

                        // Draw debug walls
                        for (int i = 0; i < room1.wallsCount; i++)
                        {
                            DrawRectangleLinesEx((Rectangle){room1.walls[i].x, room1.walls[i].y, REL_TILE_SIZE, REL_TILE_SIZE}, 4, RED);
                        }
                    }
                    else
                    {
                        DrawSpriteFrame(&player.sprite, player.position, SCALE, player.color, player.direction, player.isAnimated);
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
            if (ToggleMusic)
                PlayMusic(MenuMusic);

            CheckOptionsButtons(fxButton, MenuMusic, &masterVolume, &ToggleMusic);

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
    UnloadSprite(&charPickSprite);
    UnloadSprite(&npcSprite);
    UnloadGraphics(&tileset);

    CloseWindow();
    //--------------------------------------------------------------------------------------

    return 0;
}
