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
#include "./headers/cine.h"
#include "./headers/enemy.h"

//----------------------------------------------------------------------------------
// Código
//----------------------------------------------------------------------------------

int main(void)
{
    //------------------------------------------------
    int screenWidth = 1366;
    int screenHeight = 768;
    float masterVolume = 1.0f;

    bool debug = false;
    bool pause = false;
    bool exitWindow = false;
    bool ToggleMusic = true; // Should be true
    bool finishedLevel = false;
    char path[100];

    bool cinema = false;
    bool cinema2 = false;
    bool cinema3 = false;

    bool showHint = true;
    char hintText[50];

    // Config -----------------------------------------

    Rectangle window = {0, 0, screenWidth, screenHeight};

    InitWindow(screenWidth, screenHeight, "16-Bits de Historia");
    SetWindowIcon(LoadImage(ASSETS_PATH "Icon/Logo.png"));

    InitItemTextures();
    InitSprites();
    InitPlayer(&charSprite, &charPickSprite, window);
    InitNPCs();
    InitEnemys();
    InitRoom1Objects();
    InitCinematica();

    // InitLoadingScreen();
    InitBackground();
    InitMenuButtons(window);
    InitRooms();

    InitAudioDevice();
    InitSounds();

    RenderTexture screenCam = LoadRenderTexture(screenWidth, screenHeight);

    //------------------------
    SetTargetFPS(60);

    currentScene = SCENE1;
    menu.state = MENU; // DEBERÍA SER LOADING
    // Main game loop
    while (!exitWindow)
    {
        SetMasterVolume(masterVolume);
        if (WindowShouldClose())
        {
            menu.prevState = menu.state;
            menu.state = MENU;
        }

        if (IsKeyPressed(KEY_F1))
        {
            InitRoom1Objects();
            player.position.x = REL_TILE_SIZE * 2;
            player.position.y = REL_TILE_SIZE * 4;
            player.heldItem = NONE;

            currentScene = SCENE1;
            menu.prevState = menu.state;
            menu.state = currentScene;
        }

        if (IsKeyPressed(KEY_F2))
        {
            InitRoom2Objects();
            player.position.x = REL_TILE_SIZE * 4;
            player.position.y = REL_TILE_SIZE * 27;
            player.heldItem = NONE;

            currentScene = SCENE2;
            menu.prevState = menu.state;
            menu.state = currentScene;
        }

        if (IsKeyPressed(KEY_F3))
        {
            InitRoom3Objects();
            player.position.x = REL_TILE_SIZE * 4;
            player.position.y = REL_TILE_SIZE * 49;
            player.heldItem = NONE;

            currentScene = SCENE3;
            menu.prevState = menu.state;
            menu.state = currentScene;
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
            // Cinematica-------------------------------------------------
            if (cinema == false)
            {
                cinema = RunCimeatica1(screenWidth, screenHeight, ToggleMusic);
            }

            // Nivel-------------------------------------------------------
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

                    finishedLevel = UpdateRoom1NPCs();

                    if (debug)
                    {
                        DebugRoom(camera, player, room1, (Vector2){0, 0});
                    }
                    else
                    {
                        DrawSpriteFrame(&player.sprite, player.position, SCALE, player.color, player.direction, player.isAnimated);
                        CheckRoom1NPCs(&player);
                        CheckRoom1Objects(&player);

                        if (finishedLevel)
                        {
                            DrawSpriteFrame(&npcMexicano3Sprite, (Vector2){REL_TILE_SIZE * 1, REL_TILE_SIZE * 4}, SCALE, WHITE, 1, true);
                            DrawSpriteFrame(&textoSalidaSprite, (Vector2){REL_TILE_SIZE * 2, REL_TILE_SIZE * 4}, SCALE, WHITE, 1, true);
                        }

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

                if (showHint)
                {
                    // Show hint at the middle-top of the screen
                    DrawRectangle(0, 0, screenWidth, screenHeight / 8, Fade(BLACK, 0.9f));

                    if (finishedLevel)
                    {
                        // Encuentra la salida
                        strcpy(hintText, "Encuentra la salida");
                    }
                    else
                    {
                        sprintf(hintText, "Entrega el armamento a los soldados (%d / %d)", room1.NPCcounter, room1.NPCCount);
                    }

                    DrawText(hintText, screenWidth / 2 - (MeasureText(hintText, 30) / 2), screenHeight / 16 - 15, 30, WHITE);
                }

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

            if (finishedLevel && !isInteracting)
                CheckTeleportTile(&player, 1, 4, 2, &menu, &currentScene);

            break;

        case SCENE2:
            // Cinematica
            if (cinema2 == false)
            {
                cinema2 = RunCimeatica2(screenWidth, screenHeight, ToggleMusic);
            }

            if (ToggleMusic)
                PlayMusic(lv2);
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
                    ClearBackground(BROWN);
                    DrawElement(&room2.tileset, (Vector2){0, TILE_SIZE * 22});

                    finishedLevel = UpdateRoom2NPCs();

                    if (debug)
                    {
                        DebugRoom(camera, player, room2, (Vector2){0, 22});
                    }
                    else
                    {
                        DrawSpriteFrame(&player.sprite, player.position, SCALE, player.color, player.direction, player.isAnimated);
                        CheckRoom2NPCs(&player);
                        CheckRoom2Objects(&player);

                        if (finishedLevel)
                        {
                            DrawSpriteFrame(&npcMexicano3Sprite, (Vector2){REL_TILE_SIZE * 16, REL_TILE_SIZE * (18 + 22)}, SCALE, WHITE, 1, true);
                            DrawSpriteFrame(&textoSalidaSprite, (Vector2){REL_TILE_SIZE * 17, REL_TILE_SIZE * (18 + 22)}, SCALE, WHITE, 1, true);
                        }

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

                if (showHint)
                {
                    // Show hint at the middle-top of the screen
                    DrawRectangle(0, 0, screenWidth, screenHeight / 8, Fade(BLACK, 0.9f));

                    if (finishedLevel)
                    {
                        strcpy(hintText, "Encuentra la salida");
                    }
                    else
                    {
                        sprintf(hintText, "Reúne armamento y colócalo en los sacos (%d / %d)", room2.NPCcounter, room2.NPCCount);
                    }

                    DrawText(hintText, screenWidth / 2 - (TextLength(hintText) * 6.5), screenHeight / 16 - 15, 30, WHITE);
                }

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

            if (finishedLevel && !isInteracting)
                CheckTeleportTile(&player, 16, 18 + 22, 3, &menu, &currentScene);

            break;

        case SCENE3:

            player.isDead = false;

            if (cinema3 == false)
            {
                cinema3 = RunCimeatica3(screenWidth, screenHeight, ToggleMusic);
            }
            if (ToggleMusic)
                PlayMusic(lv3);
            SetMusicVolume(lv3, 0.5f);
            //-----------------------------------------------------------

            if (!isInteracting)
            {
                Keybinds(&debug, &pause, &camera, &GameMusic, &fxButton);
                actPlayer(&player, &fxPasosGrava, room3);
            }

            camera.target = (Vector2){player.position.x, player.position.y};

            // Draw
            //----------------------------------------------------------------------------------
            UpdateSpritesFrame();
            BeginTextureMode(screenCam);
            {
                BeginMode2D(camera);
                {
                    ClearBackground(DARKBROWN);
                    DrawElement(&room3.tileset, (Vector2){0, TILE_SIZE * 44});

                    CheckRoom3Objects(&player);
                    UpdateEnemys();

                    if (debug)
                    {
                        DebugRoom(camera, player, room3, (Vector2){0, 44});
                    }
                    else
                    {
                        DrawSpriteFrame(&player.sprite, player.position, SCALE, player.color, player.direction, player.isAnimated);

                        DrawSpriteFrame(&huecoSalidaSprite, (Vector2){REL_TILE_SIZE * 50, REL_TILE_SIZE * (2 + 44)}, SCALE, WHITE, 1, true);
                        DrawSpriteFrame(&textoSalidaSprite, (Vector2){REL_TILE_SIZE * 51, REL_TILE_SIZE * (2 + 44)}, SCALE, WHITE, 1, true);

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

                if (showHint)
                {
                    // Show hint at the middle-top of the screen
                    DrawRectangle(0, 0, screenWidth, screenHeight / 8, Fade(BLACK, 0.9f));

                    strcpy(hintText, "Llega a la salida!");

                    // "Entrega el armamento a los soldados"
                    DrawText(hintText, screenWidth / 2 - (TextLength(hintText) * 6.5), screenHeight / 16 - 15, 30, WHITE);
                }

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

            if (player.isDead)
            {
                InitRoom3Objects();
                player.position.x = REL_TILE_SIZE * 4;
                player.position.y = REL_TILE_SIZE * 49;
                player.hitbox.x = player.position.x + (REL_TILE_SIZE / 4);
                player.hitbox.y = player.position.y;

                player.heldItem = NONE;

                currentScene = SCENE3;
                menu.prevState = menu.state;
                menu.state = currentScene;
            }

            CheckTeleportTile(&player, 50, 2 + 44, 4, &menu, &currentScene);

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