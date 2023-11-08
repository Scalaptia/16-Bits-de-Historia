#include "raylib.h"

int main(void)
{
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "raylib [audio] example - sound loading and playing");
    InitAudioDevice();

    Sound fxWav = LoadSound("resources/voz.wav"); // Load WAV audio file
    Sound fxOgg = LoadSound("resources/voz.ogg"); // Load OGG audio file

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        // Update
        //----------------------------------------------------------------------------------
        if (IsKeyPressed(KEY_SPACE))
            PlaySound(fxWav); // Play WAV sound
        if (IsKeyPressed(KEY_ENTER))
            PlaySound(fxOgg); // Play OGG sound
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawText("Press SPACE to PLAY the WAV sound!", 200, 180, 20, LIGHTGRAY);
        DrawText("Press ENTER to PLAY the OGG sound!", 200, 220, 20, LIGHTGRAY);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    UnloadSound(fxWav); // Unload sound data
    UnloadSound(fxOgg); // Unload sound data

    CloseAudioDevice(); // Close audio device

    CloseWindow(); // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}