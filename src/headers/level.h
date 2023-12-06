#ifndef LEVEL_H
#define LEVEL_H

#include "raylib.h"
#include "raymath.h"
#include "string.h"
#include <stdlib.h>

#define TILE_SIZE 16
#define SCALE 5
#define REL_TILE_SIZE (TILE_SIZE * SCALE)

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
    Rectangle *objects;
    int objectsCount;
} LevelData;

/* PROTOTIPOS*/

void InitGraphics(GraphicsData *tileset);

/*
    #### LISTA DE ELEMENTOS
    - "ROOM"
*/
void DrawElement(GraphicsData *tileset, char *element, Vector2 position);
void InitRoom1Collisions(Vector2 position);
void CreateCollisionWalls(Vector2 position, Vector2 size, int *wallsCount, Vector2 **walls);
void CreateCollisionObject(Vector2 position, Vector2 size, int *objectsCount, Rectangle **objects);

void DrawRoom(GraphicsData *tileset, Vector2 position);
void UnloadGraphics(GraphicsData *tileset);
bool IsRectangleOnScreen(Rectangle rect, Camera2D camera);

extern LevelData room1;

#endif