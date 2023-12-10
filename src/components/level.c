#include "../headers/level.h"

LevelData room1;
LevelData room2;
LevelData room3;

void ScaleRec(Rectangle *rec)
{
    rec->x *= SCALE;
    rec->y *= SCALE;
    rec->width *= SCALE;
    rec->height *= SCALE;
}

void InitRoom1Collisions()
{
    Vector2 position = {0, 0};

    CreateCollisionWalls(position, (Vector2){32, 22}, &room1.wallsCount, &room1.walls);

    // *** Walls ***
    // 1, 1 - 6, 2
    CreateCollisionObject((Vector2){position.x + 1, position.y + 1}, (Vector2){6, 2}, &room1.objectsCount, &room1.objects);

    // 1, 8 - 6, 3
    CreateCollisionObject((Vector2){position.x + 1, position.y + 8}, (Vector2){6, 3}, &room1.objectsCount, &room1.objects);

    // 8, 14 - 2, 6
    CreateCollisionObject((Vector2){position.x + 8, position.y + 14}, (Vector2){2, 6}, &room1.objectsCount, &room1.objects);

    // 17, 17 - 1, 4
    CreateCollisionObject((Vector2){position.x + 17, position.y + 17}, (Vector2){1, 4}, &room1.objectsCount, &room1.objects);

    // 18, 17 - 5, 1
    CreateCollisionObject((Vector2){position.x + 18, position.y + 17}, (Vector2){5, 1}, &room1.objectsCount, &room1.objects);

    // 25, 17 - 4, 1
    CreateCollisionObject((Vector2){position.x + 25, position.y + 17}, (Vector2){4, 1}, &room1.objectsCount, &room1.objects);

    // 28, 12 - 1, 5
    CreateCollisionObject((Vector2){position.x + 28, position.y + 12}, (Vector2){1, 5}, &room1.objectsCount, &room1.objects);

    // 29, 12 - 2, 1
    CreateCollisionObject((Vector2){position.x + 29, position.y + 12}, (Vector2){2, 1}, &room1.objectsCount, &room1.objects);

    // 17, 1 - 1, 5
    CreateCollisionObject((Vector2){position.x + 17, position.y + 1}, (Vector2){1, 5}, &room1.objectsCount, &room1.objects);

    // 17, 8 - 1, 2
    CreateCollisionObject((Vector2){position.x + 17, position.y + 8}, (Vector2){1, 2}, &room1.objectsCount, &room1.objects);

    // 18, 9 - 10, 1
    CreateCollisionObject((Vector2){position.x + 18, position.y + 9}, (Vector2){10, 1}, &room1.objectsCount, &room1.objects);

    // 27, 7 - 1, 2
    CreateCollisionObject((Vector2){position.x + 27, position.y + 7}, (Vector2){1, 2}, &room1.objectsCount, &room1.objects);

    // 28, 7 - 3, 1
    CreateCollisionObject((Vector2){position.x + 28, position.y + 7}, (Vector2){3, 1}, &room1.objectsCount, &room1.objects);

    // *** Objects ***
    // 1, 7
    CreateCollisionObject((Vector2){position.x + 1, position.y + 7}, (Vector2){1, 1}, &room1.objectsCount, &room1.objects);

    // 1, 11
    CreateCollisionObject((Vector2){position.x + 1, position.y + 11}, (Vector2){1, 1}, &room1.objectsCount, &room1.objects);

    // 1, 19
    CreateCollisionObject((Vector2){position.x + 1, position.y + 19}, (Vector2){1, 1}, &room1.objectsCount, &room1.objects);

    // 2, 20
    CreateCollisionObject((Vector2){position.x + 2, position.y + 20}, (Vector2){1, 1}, &room1.objectsCount, &room1.objects);

    // 7, 1
    CreateCollisionObject((Vector2){position.x + 7, position.y + 1}, (Vector2){1, 1}, &room1.objectsCount, &room1.objects);

    // 8, 13 - 2, 1
    CreateCollisionObject((Vector2){position.x + 8, position.y + 13}, (Vector2){2, 1}, &room1.objectsCount, &room1.objects);

    // 16, 1
    CreateCollisionObject((Vector2){position.x + 16, position.y + 1}, (Vector2){1, 1}, &room1.objectsCount, &room1.objects);

    // 18, 1
    CreateCollisionObject((Vector2){position.x + 18, position.y + 1}, (Vector2){1, 1}, &room1.objectsCount, &room1.objects);

    // 18, 18 - 1, 3
    CreateCollisionObject((Vector2){position.x + 18, position.y + 18}, (Vector2){1, 3}, &room1.objectsCount, &room1.objects);

    // 28, 8 - 3, 1
    CreateCollisionObject((Vector2){position.x + 28, position.y + 8}, (Vector2){3, 1}, &room1.objectsCount, &room1.objects);

    // 30, 9
    CreateCollisionObject((Vector2){position.x + 30, position.y + 9}, (Vector2){1, 1}, &room1.objectsCount, &room1.objects);

    // 29, 1
    CreateCollisionObject((Vector2){position.x + 29, position.y + 1}, (Vector2){1, 1}, &room1.objectsCount, &room1.objects);

    // 30, 2
    CreateCollisionObject((Vector2){position.x + 30, position.y + 2}, (Vector2){1, 1}, &room1.objectsCount, &room1.objects);

    // 29, 13 - 2, 1
    CreateCollisionObject((Vector2){position.x + 29, position.y + 13}, (Vector2){2, 1}, &room1.objectsCount, &room1.objects);
}

void InitRoom2Collisions()
{
    Vector2 position = {2, 24};
    CreateCollisionWalls(position, (Vector2){28, 18}, &room2.wallsCount, &room2.walls);

    // *** Objects ***
    // 4, 3
    CreateCollisionObject((Vector2){position.x + 2, position.y + 1}, (Vector2){1, 1}, &room2.objectsCount, &room2.objects);

    // 3, 4
    CreateCollisionObject((Vector2){position.x + 1, position.y + 2}, (Vector2){1, 1}, &room2.objectsCount, &room2.objects);

    // 6, 5
    CreateCollisionObject((Vector2){position.x + 4, position.y + 3}, (Vector2){1, 1}, &room2.objectsCount, &room2.objects);

    // 5, 5 - 3, 1
    CreateCollisionObject((Vector2){position.x + 3, position.y + 3}, (Vector2){3, 1}, &room2.objectsCount, &room2.objects);

    // 5, 6
    CreateCollisionObject((Vector2){position.x + 3, position.y + 4}, (Vector2){1, 1}, &room2.objectsCount, &room2.objects);

    // 9, 5
    CreateCollisionObject((Vector2){position.x + 7, position.y + 3}, (Vector2){1, 1}, &room2.objectsCount, &room2.objects);

    // 7, 2 - 2, 1
    CreateCollisionObject((Vector2){position.x + 5, position.y + 0}, (Vector2){2, 1}, &room2.objectsCount, &room2.objects);

    // 3, 17 - 1, 2
    CreateCollisionObject((Vector2){position.x + 1, position.y + 15}, (Vector2){1, 2}, &room2.objectsCount, &room2.objects);

    // 4, 18 - 2, 1
    CreateCollisionObject((Vector2){position.x + 2, position.y + 16}, (Vector2){2, 1}, &room2.objectsCount, &room2.objects);

    // 7, 10 - 2, 1
    CreateCollisionObject((Vector2){position.x + 5, position.y + 8}, (Vector2){2, 1}, &room2.objectsCount, &room2.objects);

    // 14, 14
    CreateCollisionObject((Vector2){position.x + 12, position.y + 12}, (Vector2){1, 1}, &room2.objectsCount, &room2.objects);

    // 19, 13 - 2, 1
    CreateCollisionObject((Vector2){position.x + 17, position.y + 11}, (Vector2){2, 1}, &room2.objectsCount, &room2.objects);

    // 23, 10 - 2, 1
    CreateCollisionObject((Vector2){position.x + 21, position.y + 8}, (Vector2){2, 1}, &room2.objectsCount, &room2.objects);

    // 27, 18 - 2, 1
    CreateCollisionObject((Vector2){position.x + 25, position.y + 16}, (Vector2){2, 1}, &room2.objectsCount, &room2.objects);

    // 28, 17
    CreateCollisionObject((Vector2){position.x + 26, position.y + 15}, (Vector2){1, 1}, &room2.objectsCount, &room2.objects);

    // 22, 3
    CreateCollisionObject((Vector2){position.x + 20, position.y + 1}, (Vector2){1, 1}, &room2.objectsCount, &room2.objects);

    // 27, 3 - 2, 2
    CreateCollisionObject((Vector2){position.x + 25, position.y + 1}, (Vector2){2, 2}, &room2.objectsCount, &room2.objects);
}

void InitRoom3Collisions()
{
    Vector2 position = {0, 44};
    CreateCollisionWalls(position, (Vector2){52, 22}, &room3.wallsCount, &room3.walls);

    // *** WALLS ***
    // 1, 7 - 14, 8
    CreateCollisionObject((Vector2){position.x + 1, position.y + 7}, (Vector2){14, 2}, &room3.objectsCount, &room3.objects);

    // 18, 5 - 26, 8
    CreateCollisionObject((Vector2){position.x + 18, position.y + 5}, (Vector2){9, 4}, &room3.objectsCount, &room3.objects);

    // 26, 9 - 26, 14
    CreateCollisionObject((Vector2){position.x + 26, position.y + 9}, (Vector2){1, 6}, &room3.objectsCount, &room3.objects);

    // 1, 13 - 25, 14
    CreateCollisionObject((Vector2){position.x + 1, position.y + 13}, (Vector2){25, 2}, &room3.objectsCount, &room3.objects);

    // *** OBJECTS ***
    // 1, 1
    CreateCollisionObject((Vector2){position.x + 1, position.y + 1}, (Vector2){1, 1}, &room3.objectsCount, &room3.objects);

    // 4, 3
    CreateCollisionObject((Vector2){position.x + 4, position.y + 3}, (Vector2){1, 1}, &room3.objectsCount, &room3.objects);

    // 1, 6
    CreateCollisionObject((Vector2){position.x + 1, position.y + 6}, (Vector2){1, 1}, &room3.objectsCount, &room3.objects);

    // 11, 1
    CreateCollisionObject((Vector2){position.x + 11, position.y + 1}, (Vector2){1, 1}, &room3.objectsCount, &room3.objects);

    // 16, 3
    CreateCollisionObject((Vector2){position.x + 16, position.y + 3}, (Vector2){1, 1}, &room3.objectsCount, &room3.objects);

    // 26, 3
    CreateCollisionObject((Vector2){position.x + 26, position.y + 3}, (Vector2){1, 1}, &room3.objectsCount, &room3.objects);

    // 3, 9
    CreateCollisionObject((Vector2){position.x + 3, position.y + 9}, (Vector2){1, 1}, &room3.objectsCount, &room3.objects);

    // 2, 12
    CreateCollisionObject((Vector2){position.x + 2, position.y + 12}, (Vector2){1, 1}, &room3.objectsCount, &room3.objects);

    // 9, 10
    CreateCollisionObject((Vector2){position.x + 9, position.y + 10}, (Vector2){1, 1}, &room3.objectsCount, &room3.objects);

    // 14, 11
    CreateCollisionObject((Vector2){position.x + 14, position.y + 11}, (Vector2){1, 1}, &room3.objectsCount, &room3.objects);

    // 1, 15 - 3, 15
    CreateCollisionObject((Vector2){position.x + 1, position.y + 15}, (Vector2){3, 1}, &room3.objectsCount, &room3.objects);

    // 1, 16
    CreateCollisionObject((Vector2){position.x + 1, position.y + 16}, (Vector2){1, 1}, &room3.objectsCount, &room3.objects);

    // 1, 19 - 1, 20
    CreateCollisionObject((Vector2){position.x + 1, position.y + 19}, (Vector2){1, 2}, &room3.objectsCount, &room3.objects);

    // 2, 20
    CreateCollisionObject((Vector2){position.x + 2, position.y + 20}, (Vector2){1, 1}, &room3.objectsCount, &room3.objects);

    // 8, 20
    CreateCollisionObject((Vector2){position.x + 8, position.y + 20}, (Vector2){1, 1}, &room3.objectsCount, &room3.objects);

    // 17, 19
    CreateCollisionObject((Vector2){position.x + 17, position.y + 19}, (Vector2){1, 1}, &room3.objectsCount, &room3.objects);

    // 15, 17 - 29. 18
    CreateCollisionObject((Vector2){position.x + 15, position.y + 17}, (Vector2){15, 2}, &room3.objectsCount, &room3.objects);

    // 21, 11
    CreateCollisionObject((Vector2){position.x + 21, position.y + 11}, (Vector2){1, 1}, &room3.objectsCount, &room3.objects);

    // 25, 9 - 25, 10
    CreateCollisionObject((Vector2){position.x + 25, position.y + 9}, (Vector2){1, 2}, &room3.objectsCount, &room3.objects);

    // 31, 1 - 31, 2
    CreateCollisionObject((Vector2){position.x + 31, position.y + 1}, (Vector2){1, 2}, &room3.objectsCount, &room3.objects);

    // 32, 2 - 32, 6
    CreateCollisionObject((Vector2){position.x + 32, position.y + 2}, (Vector2){1, 5}, &room3.objectsCount, &room3.objects);

    // 31, 5 - 31, 15
    CreateCollisionObject((Vector2){position.x + 31, position.y + 5}, (Vector2){1, 9}, &room3.objectsCount, &room3.objects);

    // 30, 7 - 30, 8
    CreateCollisionObject((Vector2){position.x + 30, position.y + 7}, (Vector2){1, 2}, &room3.objectsCount, &room3.objects);

    // 30, 13 - 30, 17
    CreateCollisionObject((Vector2){position.x + 30, position.y + 13}, (Vector2){1, 5}, &room3.objectsCount, &room3.objects);

    // 31, 18
    CreateCollisionObject((Vector2){position.x + 31, position.y + 18}, (Vector2){1, 1}, &room3.objectsCount, &room3.objects);

    // 32, 8 - 40, 8
    CreateCollisionObject((Vector2){position.x + 32, position.y + 8}, (Vector2){9, 1}, &room3.objectsCount, &room3.objects);

    // 40, 4 - 40, 7
    CreateCollisionObject((Vector2){position.x + 40, position.y + 4}, (Vector2){1, 4}, &room3.objectsCount, &room3.objects);

    // 37, 4 - 39, 4
    CreateCollisionObject((Vector2){position.x + 37, position.y + 4}, (Vector2){3, 1}, &room3.objectsCount, &room3.objects);

    // 38, 1 - 38, 3
    CreateCollisionObject((Vector2){position.x + 38, position.y + 1}, (Vector2){1, 3}, &room3.objectsCount, &room3.objects);

    // 39, 3
    CreateCollisionObject((Vector2){position.x + 39, position.y + 3}, (Vector2){1, 1}, &room3.objectsCount, &room3.objects);

    // 34, 5
    CreateCollisionObject((Vector2){position.x + 34, position.y + 5}, (Vector2){1, 1}, &room3.objectsCount, &room3.objects);

    // 32, 13 - 38, 13
    CreateCollisionObject((Vector2){position.x + 32, position.y + 13}, (Vector2){7, 1}, &room3.objectsCount, &room3.objects);

    // 39, 13 - 43, 14
    CreateCollisionObject((Vector2){position.x + 39, position.y + 13}, (Vector2){5, 2}, &room3.objectsCount, &room3.objects);

    // 39, 16
    CreateCollisionObject((Vector2){position.x + 39, position.y + 16}, (Vector2){1, 1}, &room3.objectsCount, &room3.objects);

    // 39, 20
    CreateCollisionObject((Vector2){position.x + 39, position.y + 20}, (Vector2){1, 1}, &room3.objectsCount, &room3.objects);

    // 48, 17
    CreateCollisionObject((Vector2){position.x + 48, position.y + 17}, (Vector2){1, 1}, &room3.objectsCount, &room3.objects);

    // 47, 20
    CreateCollisionObject((Vector2){position.x + 47, position.y + 20}, (Vector2){1, 1}, &room3.objectsCount, &room3.objects);

    // 47, 13 - 50, 14
    CreateCollisionObject((Vector2){position.x + 47, position.y + 13}, (Vector2){4, 2}, &room3.objectsCount, &room3.objects);

    // 37, 9 - 37, 10
    CreateCollisionObject((Vector2){position.x + 37, position.y + 9}, (Vector2){1, 2}, &room3.objectsCount, &room3.objects);

    // 38, 11 - 39, 11
    CreateCollisionObject((Vector2){position.x + 38, position.y + 11}, (Vector2){2, 1}, &room3.objectsCount, &room3.objects);

    // 39, 12
    CreateCollisionObject((Vector2){position.x + 39, position.y + 12}, (Vector2){1, 1}, &room3.objectsCount, &room3.objects);

    // 40, 10
    CreateCollisionObject((Vector2){position.x + 40, position.y + 10}, (Vector2){1, 1}, &room3.objectsCount, &room3.objects);

    // 47, 9
    CreateCollisionObject((Vector2){position.x + 47, position.y + 9}, (Vector2){1, 1}, &room3.objectsCount, &room3.objects);

    // 48, 10
    CreateCollisionObject((Vector2){position.x + 48, position.y + 10}, (Vector2){1, 1}, &room3.objectsCount, &room3.objects);

    // 49, 11 - 49, 12
    CreateCollisionObject((Vector2){position.x + 49, position.y + 11}, (Vector2){1, 2}, &room3.objectsCount, &room3.objects);

    // 44, 5 - 50, 8
    CreateCollisionObject((Vector2){position.x + 44, position.y + 5}, (Vector2){7, 4}, &room3.objectsCount, &room3.objects);

    // 42, 1 - 43, 1
    CreateCollisionObject((Vector2){position.x + 42, position.y + 1}, (Vector2){2, 1}, &room3.objectsCount, &room3.objects);
}

void InitRoom(LevelData *room, int roomNumber)
{
    char *path;

    switch (roomNumber)
    {
    case 1:
        path = ASSETS_PATH "Escenarios/Escena1.png";
        InitRoom1Collisions();
        break;
    case 2:
        path = ASSETS_PATH "Escenarios/Escena2.png";
        InitRoom2Collisions();
        break;
    case 3:
        path = ASSETS_PATH "Escenarios/Escena3.png";
        InitRoom3Collisions();
        break;
    }

    room->tileset.image = LoadImage(path);
    room->tileset.texture = LoadTextureFromImage(room->tileset.image);
    room->tileset.size = (Rectangle){0, 0, room->tileset.texture.width, room->tileset.texture.height};
    UnloadImage(room->tileset.image);
}

void InitRooms()
{
    printf("Initializing rooms...\n");
    InitRoom(&room1, 1);
    InitRoom(&room2, 2);
    InitRoom(&room3, 3);
}

void DrawElement(GraphicsData *tileset, Vector2 position)
{
    Rectangle room_src = {0, 0, tileset->image.width, tileset->image.height};
    Rectangle room_dst = {position.x + TILE_SIZE, position.y + TILE_SIZE, room_src.width, room_src.height};
    ScaleRec(&room_dst);
    DrawTexturePro(tileset->texture, room_src, room_dst, (Vector2){0, 0}, 0, WHITE);
}

void CreateCollisionWalls(Vector2 position, Vector2 size, int *wallsCount, Vector2 **walls)
{
    // Make position relative to the tileset
    position.x *= REL_TILE_SIZE;
    position.y *= REL_TILE_SIZE;

    int count = 0;
    Vector2 *wallsArray = malloc(sizeof(Vector2) * (int)(size.x * 2 + size.y * 2));

    for (int i = 0; i < size.x; i++)
    {
        wallsArray[count] = (Vector2){position.x + i * REL_TILE_SIZE, position.y};
        count++;
        wallsArray[count] = (Vector2){position.x + i * REL_TILE_SIZE, position.y + (size.y - 1) * REL_TILE_SIZE};
        count++;
    }

    for (int i = 0; i < size.y; i++)
    {
        wallsArray[count] = (Vector2){position.x, position.y + i * REL_TILE_SIZE};
        count++;

        wallsArray[count] = (Vector2){position.x + (size.x - 1) * REL_TILE_SIZE, position.y + i * REL_TILE_SIZE};
        count++;
    }

    *wallsCount = count;
    *walls = wallsArray;
}

void CreateCollisionObject(Vector2 position, Vector2 size, int *objectsCount, Rectangle **objects)
{
    int i, j;

    // Write collision data to file
    FILE *file = fopen("collisionroom1_col.txt", "a");

    fprintf(file, "%d %d %d %d\n", (int)position.x, (int)position.y, (int)size.x, (int)size.y);

    fclose(file);

    position.x *= REL_TILE_SIZE;
    position.y *= REL_TILE_SIZE;

    int newObjectsCount = (int)(size.x * size.y);

    // Directly allocate newObjects to *objects
    *objects = realloc(*objects, sizeof(Rectangle) * (*objectsCount + newObjectsCount));

    int offset = *objectsCount;
    for (i = 0; i < size.x; i++)
    {
        for (j = 0; j < size.y; j++)
        {
            (*objects)[offset++] = (Rectangle){position.x + i * REL_TILE_SIZE + 5, position.y + j * REL_TILE_SIZE + 5, REL_TILE_SIZE - 10, REL_TILE_SIZE - 10};
        }
    }

    *objectsCount += newObjectsCount;
}

void UnloadRoom(LevelData *room)
{
    UnloadGraphics(&room->tileset);
    free(room->walls);
    free(room->objects);
}

void UnloadGraphics(GraphicsData *tileset)
{
    UnloadTexture(tileset->texture);
    UnloadImage(tileset->image);
}

// Check if a rectangle is 2 TILES away from the center of the camera
bool IsRectangleOnCamera(Rectangle rect, Camera2D camera)
{
    return CheckCollisionRecs(rect, (Rectangle){camera.target.x - REL_TILE_SIZE * 2, camera.target.y - REL_TILE_SIZE * 2, REL_TILE_SIZE * 4, REL_TILE_SIZE * 4});
}
