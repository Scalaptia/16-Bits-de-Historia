//----------------------------------------------------------------------------------
// Librerías
//----------------------------------------------------------------------------------
#include <raylib.h>
#include "./headers/player.h"
#include "./headers/debug.h"
#include "./headers/level.h"
#include "./headers/animation.h"
#include "./headers/keybinds.h"
#include "./headers/menu.h"
#include "./headers/sound.h"
#include "./headers/npc.h"
#include "./headers/object.h"

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
    bool ToggleMusic = false; // Should be true
    char path[100];

    // Config -----------------------------------------

    Rectangle window = {0, 0, screenWidth, screenHeight};

    InitWindow(screenWidth, screenHeight, "16-Bits de Historia");
    SetWindowIcon(LoadImage(ASSETS_PATH "Icon/Logo.png"));

    InitItemTextures();
    InitObjects();
    InitSprites();
    InitPlayer(&charSprite, &charPickSprite, window);
    InitNPCs(window);

    // InitLoadingScreen();
    InitBackground();
    InitMenuButtons(window);
    InitRooms();

    InitAudioDevice();
    InitSounds();

    RenderTexture screenCam = LoadRenderTexture(screenWidth, screenHeight);

    //------------------------
    // SetTargetFPS(60);

    menu.state = SCENE1; // DEBERÍA SER LOADING
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
            PlaySound(IntroSound);
            while (loadingScreen.frameCurrent < loadingScreen.frameCount)
            {
                BeginDrawing();
                {
                    ClearBackground(BLACK);

                    loadingScreen.currentTime += GetFrameTime();

                    if (loadingScreen.currentTime >= loadingScreen.frameTime)
                    {
                        loadingScreen.currentTime = 0.0f;
                        loadingScreen.frameCurrent++;
                    }

                    DrawTexturePro(loadingScreen.textures[loadingScreen.frameCurrent], (Rectangle){0, 0, 800, 450}, (Rectangle){0, 0, screenWidth, screenHeight}, (Vector2){0, 0}, 0, WHITE);
                }
                EndDrawing();
            }

            UnloadLoadingScreen();
            menu.state = MENU;
            menu.prevState = MENU;
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

        case SCENE1:
            if (ToggleMusic)
                PlayMusic(GameMusic);
            //-----------------------------------------------------------

            if (!isInteracting)
            {
                Keybinds(&debug, &pause, &camera, &GameMusic, &fxButton);
                actPlayer(&player, &fxPasosGrava, room1);
            }

            camera.target = (Vector2){player.position.x, player.position.y};

            // Draw
            //----------------------------------------------------------------------------------
            UpdateSpritesFrame();
            BeginTextureMode(screenCam);
            {
                BeginMode2D(camera);
                {
                    ClearBackground(BLACK);
                    DrawElement(&room1.tileset, (Vector2){0, 0});

                    UpdateRoom1NPCs();
                    CheckRoom1NPCs(&player);
                    CheckObjects(&player);

                    if (debug)
                    {
                        DebugRoom(camera, player, room1, (Vector2){0, 0});
                    }
                    else
                    {
                        DrawSpriteFrame(&player.sprite, player.position, SCALE, player.color, player.direction, player.isAnimated);

                        // Draw held item
                        if (player.heldItem != NONE)
                        {
                            if (player.direction == 1)
                            {
                                DrawTexturePro(player.heldTexture, (Rectangle){0, 0, 16, 16}, (Rectangle){player.position.x + (REL_TILE_SIZE / 2), player.position.y, REL_TILE_SIZE, REL_TILE_SIZE}, (Vector2){0, 0}, 0, WHITE);
                            }
                            else
                            {
                                DrawTexturePro(player.heldTexture, (Rectangle){0, 0, -16, 16}, (Rectangle){player.position.x - (REL_TILE_SIZE / 2), player.position.y, REL_TILE_SIZE, REL_TILE_SIZE}, (Vector2){0, 0}, 0, WHITE);
                            }
                        }
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

                if (isInteracting)
                {
                    DrawRectangle(0, 0, screenWidth, screenHeight, Fade(BLACK, 0.5f));
                    DrawRectangle(0, screenHeight - screenHeight / 4, screenWidth, screenHeight / 4, Fade(BLACK, 0.9f));
                    DrawText(currentName, 20, (screenHeight - screenHeight / 4) + 20, 30, WHITE);
                    DrawText(currentDialogue, 20, (screenHeight - screenHeight / 4) + 70, 25, WHITE);
                }

                DrawFPS(GetScreenWidth() - 95, 10);
            }
            EndDrawing();

            if (IsKeyPressed(KEY_F2))
            {
                player.position.x = REL_TILE_SIZE * 4;
                player.position.y = REL_TILE_SIZE * 27;

                menu.prevState = menu.state;
                menu.state = SCENE2;
            }

            break;

        case SCENE2:
            if (ToggleMusic)
                PlayMusic(GameMusic);
            //-----------------------------------------------------------

            if (!isInteracting)
            {
                Keybinds(&debug, &pause, &camera, &GameMusic, &fxButton);
                actPlayer(&player, &fxPasosGrava, room2);
            }

            camera.target = (Vector2){player.position.x, player.position.y};

            // Draw
            //----------------------------------------------------------------------------------
            UpdateSpritesFrame();
            BeginTextureMode(screenCam);
            {
                BeginMode2D(camera);
                {
                    ClearBackground(BLACK);
                    DrawElement(&room2.tileset, (Vector2){0, TILE_SIZE * 22});

                    // UpdateRoom2NPCs();
                    // CheckRoom2NPCs(&player);
                    CheckObjects(&player);

                    if (debug)
                    {
                        DebugRoom(camera, player, room2, (Vector2){0, 22});
                    }
                    else
                    {
                        DrawSpriteFrame(&player.sprite, player.position, SCALE, player.color, player.direction, player.isAnimated);

                        // Draw held item
                        if (player.heldItem != NONE)
                        {
                            if (player.direction == 1)
                            {
                                DrawTexturePro(player.heldTexture, (Rectangle){0, 0, 16, 16}, (Rectangle){player.position.x + (REL_TILE_SIZE / 2), player.position.y, REL_TILE_SIZE, REL_TILE_SIZE}, (Vector2){0, 0}, 0, WHITE);
                            }
                            else
                            {
                                DrawTexturePro(player.heldTexture, (Rectangle){0, 0, -16, 16}, (Rectangle){player.position.x - (REL_TILE_SIZE / 2), player.position.y, REL_TILE_SIZE, REL_TILE_SIZE}, (Vector2){0, 0}, 0, WHITE);
                            }
                        }
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

                if (isInteracting)
                {
                    DrawRectangle(0, 0, screenWidth, screenHeight, Fade(BLACK, 0.5f));
                    DrawRectangle(0, screenHeight - screenHeight / 4, screenWidth, screenHeight / 4, Fade(BLACK, 0.9f));
                    DrawText(currentName, 20, (screenHeight - screenHeight / 4) + 20, 30, WHITE);
                    DrawText(currentDialogue, 20, (screenHeight - screenHeight / 4) + 70, 25, WHITE);
                }

                DrawFPS(GetScreenWidth() - 95, 10);
            }
            EndDrawing();

            if (IsKeyPressed(KEY_F2))
            {
                player.position.x = REL_TILE_SIZE * 2;
                player.position.y = REL_TILE_SIZE * 4;

                menu.prevState = menu.state;
                menu.state = SCENE1;
            }
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

                DrawRectangle(0, screenHeight / 2 - 100, screenWidth, 200, BLACK);
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
    UnloadSprites();

    UnloadRoom(&room1);
    UnloadRoom(&room2);

    CloseWindow();
    //--------------------------------------------------------------------------------------

    return 0;
}
