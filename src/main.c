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
void writeSaveFile(bool ToggleMusic, float masterVolume);
void readSaveFile(bool *ToggleMusic, float *masterVolume);

int main(void)
{
    //------------------------------------------------
    int screenWidth = 1366;
    int screenHeight = 768;
    float masterVolume = 1.0f;

    bool debug = false;
    bool pause = false;
    bool exitWindow = false;
    bool ToggleMusic = true;
    bool finishedLevel = false;
    char path[100];

    bool cinema = false;
    bool cinema2 = false;
    bool cinema3 = false;
    bool finalband = false;
    bool resetBand = false;

    bool hasFadedIn = false;

    bool showHint = true;
    char hintText[50];

    // Config -----------------------------------------

    Rectangle window = {0, 0, screenWidth, screenHeight};

    InitWindow(screenWidth, screenHeight, "16-Bits de Historia");
    SetWindowIcon(LoadImage(ASSETS_PATH "Icon/Logo.png"));

    BeginDrawing();
    {
        ClearBackground(BLACK);

        DrawText("Cargando...", screenWidth / 2 - 100, screenHeight / 2 - 15, 30, WHITE);
    }
    EndDrawing();

    InitItemTextures();
    InitSprites();
    InitPlayer(&charSprite, &charPickSprite, window);
    InitNPCs();
    InitEnemys();
    InitRoom1Objects();
    InitCinematica();

    InitBackground();
    InitMenuButtons(window);
    InitRooms();

    InitAudioDevice();
    InitSounds();

    RenderTexture screenCam = LoadRenderTexture(screenWidth, screenHeight);

    //------------------------
    SetTargetFPS(60);
    readSaveFile(&ToggleMusic, &masterVolume);
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

        // if (IsKeyPressed(KEY_F1))
        // {
        //     InitRoom1Objects();
        //     player.position.x = REL_TILE_SIZE * 2;
        //     player.position.y = REL_TILE_SIZE * 4;
        //     player.heldItem = NONE;

        //     currentScene = SCENE1;
        //     menu.prevState = menu.state;
        //     menu.state = currentScene;

        //     writeSaveFile(ToggleMusic, masterVolume);
        // }

        // if (IsKeyPressed(KEY_F2))
        // {
        //     InitRoom2Objects();
        //     player.position.x = REL_TILE_SIZE * 4;
        //     player.position.y = REL_TILE_SIZE * 27;
        //     player.heldItem = NONE;

        //     currentScene = SCENE2;
        //     menu.prevState = menu.state;
        //     menu.state = currentScene;

        //     writeSaveFile(ToggleMusic, masterVolume);
        // }

        // if (IsKeyPressed(KEY_F3))
        // {
        //     InitRoom3Objects();
        //     player.position.x = REL_TILE_SIZE * 2;
        //     player.position.y = REL_TILE_SIZE * 55;
        //     player.heldItem = NONE;

        //     currentScene = SCENE3;
        //     menu.prevState = menu.state;
        //     menu.state = currentScene;

        //     writeSaveFile(ToggleMusic, masterVolume);
        // }

        switch (menu.state)
        {
        case MENU:
            if (ToggleMusic)
                PlayMusic(MenuMusic);

            if (resetBand)
            {
                InitRoom1Objects();
                player.position.x = REL_TILE_SIZE * 2;
                player.position.y = REL_TILE_SIZE * 4;
                player.heldItem = NONE;

                currentScene = SCENE1;
                menu.prevState = MENU;
                menu.state = MENU;

                cinema = false;
                cinema2 = false;
                cinema3 = false;
                resetBand = false;
            }

            //-------------------------------------------------
            CheckMenuButtons(fxButton, MenuMusic);

            BeginDrawing();
            {
                ClearBackground(WHITE);
                UpdateBackground((Rectangle){0, 0, screenWidth, screenHeight + 36});
                DrawMenuUI();
            }
            EndDrawing();

            break;

        case SCENE1:
            debug = false;
            // Cinematica-------------------------------------------------
            if (cinema == false)
            {
                cinema = RunCimeatica1(screenWidth, screenHeight, ToggleMusic);
                hasFadedIn = false;
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
            {
                CheckTeleportTile(&player, 1, 4, 2, &menu, &currentScene);
                writeSaveFile(ToggleMusic, masterVolume);
            }

            break;

        case SCENE2:
            debug = false;
            // Cinematica
            if (cinema2 == false)
            {
                cinema2 = RunCimeatica2(screenWidth, screenHeight, ToggleMusic);
                hasFadedIn = false;
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
            {
                CheckTeleportTile(&player, 16, 18 + 22, 3, &menu, &currentScene);
                writeSaveFile(ToggleMusic, masterVolume);
            }

            break;

        case SCENE3:
            debug = false;
            player.isDead = false;

            if (cinema3 == false)
            {
                cinema3 = RunCimeatica3(screenWidth, screenHeight, ToggleMusic);
                hasFadedIn = false;
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
                player.position.x = REL_TILE_SIZE * 2;
                player.position.y = REL_TILE_SIZE * 55;
                player.hitbox.x = player.position.x + (REL_TILE_SIZE / 4);
                player.hitbox.y = player.position.y;

                player.heldItem = NONE;

                currentScene = SCENE3;
                menu.prevState = menu.state;
                menu.state = currentScene;
            }

            if (CheckTeleportTile(&player, 50, 2 + 44, 4, &menu, &currentScene))
            {
                if (ToggleMusic)
                    PlayMusic(finalm);

                SetMusicVolume(lv2, 0.5f);
                cinema3 = finalCinematica(screenWidth, screenHeight, ToggleMusic);
                resetBand = true;
            }

            break;

        case OPTIONS:
            if (ToggleMusic)
                PlayMusic(MenuMusic);

            CheckOptionsButtons(fxButton, MenuMusic, &masterVolume, &ToggleMusic, &window, &screenWidth, &screenHeight);
            writeSaveFile(ToggleMusic, masterVolume);

            BeginDrawing();
            {
                ClearBackground(WHITE);
                UpdateBackground((Rectangle){0, 0, screenWidth, screenHeight + 36});
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

                UpdateBackground((Rectangle){0, 0, screenWidth, screenHeight + 36});
                // Draw title text (16-Bits de Historia)
                DrawText("16-Bits de Historia", GetScreenWidth() / 2 - MeasureText("16-Bits de Historia", 100) / 2, 54, 101, BLACK);
                DrawText("16-Bits de Historia", GetScreenWidth() / 2 - MeasureText("16-Bits de Historia", 100) / 2, 50, 100, WHITE);

                // Draw subtitle text (La batalla de Puebla)
                DrawText("La batalla de Puebla", GetScreenWidth() / 2 - MeasureText("La batalla de Puebla", 51) / 2, 164, 51, Fade(BLACK, 0.5f));
                DrawText("La batalla de Puebla", GetScreenWidth() / 2 - MeasureText("La batalla de Puebla", 50) / 2, 160, 50, RED);

                // Draw credits
                DrawText("@OnlyCodes", 6, GetScreenHeight() - 30, 20, Fade(WHITE, 0.8f));

                // Gray out the screen
                DrawRectangle(0, 0, screenWidth, screenHeight, rectangleColor);

                DrawRectangle(0, screenHeight / 2 - 100, screenWidth, 200, BLACK);
                DrawText("¿Desea salir del juego? [S/N]", screenWidth / 2 - 230, screenHeight / 2 - 15, 30, WHITE);
            }
            EndDrawing();

            writeSaveFile(ToggleMusic, masterVolume);
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

void writeSaveFile(bool ToggleMusic, float masterVolume)
{
    FILE *file = fopen("save.bin", "wb");
    fwrite(&currentScene, sizeof(currentScene), 1, file);
    fwrite(&ToggleMusic, sizeof(ToggleMusic), 1, file);
    fwrite(&masterVolume, sizeof(masterVolume), 1, file);

    fclose(file);
}

void readSaveFile(bool *ToggleMusic, float *masterVolume)
{
    FILE *file = fopen("save.bin", "rb");

    fread(&currentScene, sizeof(currentScene), 1, file);
    fread(ToggleMusic, sizeof(ToggleMusic), 1, file);
    fread(masterVolume, sizeof(masterVolume), 1, file);

    fclose(file);

    if (file != NULL)
    {
        fread(&currentScene, sizeof(currentScene), 1, file);
        fclose(file);

        switch (currentScene)
        {
        case SCENE1:
            InitRoom1Objects();
            player.position.x = REL_TILE_SIZE * 2;
            player.position.y = REL_TILE_SIZE * 4;
            break;

        case SCENE2:
            InitRoom2Objects();
            player.position.x = REL_TILE_SIZE * 4;
            player.position.y = REL_TILE_SIZE * 27;
            break;

        case SCENE3:
            InitRoom3Objects();
            player.position.x = REL_TILE_SIZE * 2;
            player.position.y = REL_TILE_SIZE * 55;
            break;
        }
    }
    else
    {
        currentScene = SCENE1;
        *ToggleMusic = true;
        *masterVolume = 1.0f;
    }

    player.heldItem = NONE;
}