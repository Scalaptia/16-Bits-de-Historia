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
    GraphicsData tileset;
    Vector2 *walls;
    int wallsCount;
    Rectangle *objects;
    int objectsCount;
} LevelData;

/* PROTOTIPOS*/

void DrawElement(GraphicsData *tileset, Vector2 position);
void InitRoom1Collisions();
void InitRoom2Collisions();

void CreateCollisionWalls(Vector2 position, Vector2 size, int *wallsCount, Vector2 **walls);
void CreateCollisionObject(Vector2 position, Vector2 size, int *objectsCount, Rectangle **objects);

void UnloadGraphics(GraphicsData *tileset);
bool IsRectangleOnCamera(Rectangle rect, Camera2D camera);

void InitRoom1();
void InitRoom2();
void InitRooms();

void UnloadRoom(LevelData *room);

extern LevelData room1;
extern LevelData room2;

#endif