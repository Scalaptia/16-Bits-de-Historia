//----------------------------------------------------------------------------------
// Librerías
//----------------------------------------------------------------------------------

#include "raylib.h"

//----------------------------------------------------------------------------------
// Variables Locales (al módulo)
//----------------------------------------------------------------------------------

//----------------------------------------------------------------------------------
// Funciones Locales
//----------------------------------------------------------------------------------

int main()
{
    InitWindow(800, 600, "RPG Test");
    SetTargetFPS(60);

    Rectangle paddle1 = {20, GetScreenHeight() / 2 - 50, 20, 100};
    Rectangle paddle2 = {GetScreenWidth() - 40, GetScreenHeight() / 2 - 50, 20, 100};
    Vector2 ballPosition = {GetScreenWidth() / 2, GetScreenHeight() / 2};
    Vector2 ballSpeed = {5, 5};

    // Game loop
    while (!WindowShouldClose()) // Detecta "Cerrar Ventana" o Tecla Esc
    {
        // Fps Counter

        // Update
        if (IsKeyDown(KEY_W) && paddle1.y > 0)
            paddle1.y -= 5;
        if (IsKeyDown(KEY_S) && paddle1.y + paddle1.height < GetScreenHeight())
            paddle1.y += 5;
        if (IsKeyDown(KEY_UP) && paddle2.y > 0)
            paddle2.y -= 5;
        if (IsKeyDown(KEY_DOWN) && paddle2.y + paddle2.height < GetScreenHeight())
            paddle2.y += 5;

        ballPosition.x += ballSpeed.x;
        ballPosition.y += ballSpeed.y;

        if (CheckCollisionCircleRec(ballPosition, 10, paddle1) || CheckCollisionCircleRec(ballPosition, 10, paddle2))
            ballSpeed.x *= -1;

        if (ballPosition.y <= 0 || ballPosition.y >= GetScreenHeight())
            ballSpeed.y *= -1;

        // Draw
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawRectangleRec(paddle1, BLUE);
        DrawRectangleRec(paddle2, RED);
        DrawCircleV(ballPosition, 10, GREEN);
        EndDrawing();
    }
    CloseWindow();

    return 0;
}
