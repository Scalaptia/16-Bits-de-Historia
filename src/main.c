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

    Color selectedColor = {0, 0, 0, 255};
    Color rectangleColor = {0, 0, 0, 128};

    MenuButton start = {.text = "Start Game", .rect = {screenWidth / 2 - 100, screenHeight / 2 - 50, 200, 50}, .color = WHITE};
    MenuButton options = {.text = "Options", .rect = {screenWidth / 2 - 100, screenHeight / 2, 200, 50}, .color = WHITE};
    MenuButton exit = {.text = "Exit", .rect = {screenWidth / 2 - 100, screenHeight / 2 + 50, 200, 50}, .color = WHITE};

    Menu menu = {.state = MENU, .prevState = MENU};

    //------------------------------------------------

    // Config
    //--------------------------------------------------------------------------------------
    Rectangle window = {0, 0, screenWidth, screenHeight};
    Vector2 mousePoint = {0.0f, 0.0f};

    GraphicsData tileset;
    Sprite charSprite;
    Sprite menuBackground;

    InitWindow(screenWidth, screenHeight, "juego");
    InitSprite(&charSprite);
    InitBackground(&menuBackground);

    // Calcular scale
    char path[100];
    sprintf(path, ASSETS_PATH "background/bg1.png");
    Image temp = LoadImage(path);
    UnloadImage(temp);

    InitGraphics(&tileset);

    Player player = {.position = {REL_TILE_SIZE * 2, REL_TILE_SIZE * 2}, .color = WHITE, .direction = 1};

    //------------------------------------------------
    Camera2D camera = {0};
    camera.target = (Vector2){player.position.x, player.position.y};
    camera.offset = (Vector2){(screenWidth / 2) - (TILE_SIZE * 2), (screenHeight / 2) - (TILE_SIZE * 2)};
    camera.zoom = 1.0f;

    RenderTexture screenCam = LoadRenderTexture(screenWidth, screenHeight);
    //SONIDO-----------------------------------------------------------------------------------------------------------------
    InitAudioDevice(); // Initialize audio device
    
    //Musica 1----------------
    Music music = LoadMusicStream(ASSETS_PATH "Music/meow.mp3");
    PlayMusicStream(music);

    float timePlayed = 0.0f; // Time played normalized [0.0f..1.0f]

    //Musica 2-----------------
    Music MenuMusic = LoadMusicStream(ASSETS_PATH "Music/gerudo.mp3");

    float timePlayedMenu = 0.0f; // Time played normalized [0.0f..1.0f]

    //Botton Sound------------
    Sound fxBotton = LoadSound(ASSETS_PATH "SoundEffects/Mine_botton.mp3");

    //----Pasos-----
    Sound paso1 = LoadSound(ASSETS_PATH "SoundEffects/Pasos_Grava/MP1.mp3");
    Sound paso2 = LoadSound(ASSETS_PATH "SoundEffects/Pasos_Grava/MP2.mp3");
    Sound paso3 = LoadSound(ASSETS_PATH "SoundEffects/Pasos_Grava/MP3.mp3");
    Sound paso4 = LoadSound(ASSETS_PATH "SoundEffects/Pasos_Grava/MP4.mp3");

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
            //Musica de menu ----------------------------------
            UpdateMusicStream(MenuMusic);

            PlayMusicStream(MenuMusic);

            timePlayedMenu = GetMusicTimePlayed(MenuMusic) / GetMusicTimeLength(MenuMusic);
            if (timePlayedMenu > 1.0f) timePlayedMenu = 1.0f;

            StopMusicStream(music);//Detiene la musica de la escena 1
            //-------------------------------------------------

            mousePoint = GetMousePosition();

            start.color = rectangleColor;
            options.color = rectangleColor;
            exit.color = rectangleColor;

            // Check mouse collision with buttons
            if (CheckCollisionPointRec(mousePoint, start.rect))
            {
                start.color = selectedColor;

                if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
                {
                    PlaySound(fxBotton);
                    StopMusicStream(MenuMusic);
                    menu.state = GAME;
                }
            }

            if (CheckCollisionPointRec(mousePoint, options.rect))
            {
                options.color = selectedColor;

                if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
                {
                    PlaySound(fxBotton);
                    StopMusicStream(MenuMusic);
                    menu.state = OPTIONS;
                }
            }

            if (CheckCollisionPointRec(mousePoint, exit.rect))
            {
                exit.color = selectedColor;

                if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
                {
                    PlaySound(fxBotton);
                    StopMusicStream(MenuMusic);
                    menu.prevState = menu.state;
                    menu.state = EXIT;
                }
            }

            BeginDrawing();
            {
                ClearBackground(WHITE);
                UpdateBackground(&menuBackground, (Vector2){screenWidth, screenHeight});

                // Draw buttons
                DrawRectangleRec(start.rect, start.color);
                DrawRectangleRec(options.rect, options.color);
                DrawRectangleRec(exit.rect, exit.color);

                // Draw text
                DrawText(start.text, start.rect.x + 10, start.rect.y, 30, WHITE);
                DrawText(options.text, options.rect.x + 10, options.rect.y, 30, WHITE);
                DrawText(exit.text, exit.rect.x + 10, exit.rect.y + 10, 30, WHITE);
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

            Keybinds(&debug, &pause, &camera, &music, &fxBotton);
            actPlayer(&player,&paso1,&paso2,&paso3,&paso4);
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
    UnloadBackground(&menuBackground);
    UnloadGraphics(&tileset);
    CloseWindow();
    //--------------------------------------------------------------------------------------

    return 0;
}
