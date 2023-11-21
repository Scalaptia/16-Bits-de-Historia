#ifndef LEVEL_H
#define LEVEL_H

#include "raylib.h"
#include "raymath.h"
#include "string.h"
#include <stdlib.h>

#define TILE_SIZE 16

typedef struct GraphicsData
{
    Image image;
    Texture2D texture;
    Rectangle size;
} GraphicsData;

typedef struct LevelData
{
    Vector2 *walls;
    int wallsCount;
} LevelData;

/* PROTOTIPOS*/

// Inicializa los datos de la textura
void InitGraphics(GraphicsData *tileset);

/*
    #### LISTA DE ELEMENTOS
    - "ROOM"
*/
void DrawElement(GraphicsData *tileset, char *element, Vector2 position, float scale);
void DrawRoom(GraphicsData *tileset, Vector2 position, float scale);

// Libera los datos de la textura
void UnloadGraphics(GraphicsData *tileset);

#endif