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

void InitRoomCollisions(LevelData *room, Vector2 position, Vector2 size, char *fileName)
{
    int i, objectsCount = 0;
    int x, y, width, height;

    CreateCollisionWalls(position, size, &room->wallsCount, &room->walls);

    FILE *file = fopen(fileName, "r");
    if (file == NULL)
    {
        printf("Error opening file!\n");
        exit(1);
    }

    fscanf(file, "%d", &objectsCount);

    for (i = 0; i < objectsCount; i++)
    {
        fscanf(file, "%d %d %d %d", &x, &y, &width, &height);
        CreateCollisionObject((Vector2){x, y}, (Vector2){width, height}, &room->objectsCount, &room->objects);
    }

    fclose(file);
}

void InitRoom(LevelData *room, int roomNumber)
{
    char *path;

    switch (roomNumber)
    {
    case 1:
        room1.NPCCount = 10;
        path = ASSETS_PATH "Escenarios/Escena1.png";
        InitRoomCollisions(&room1, (Vector2){0, 0}, (Vector2){32, 22}, ASSETS_PATH "Collisions/col_room1.txt");
        break;
    case 2:
        room2.NPCCount = 10;
        path = ASSETS_PATH "Escenarios/Escena2.png";
        InitRoomCollisions(&room2, (Vector2){2, 24}, (Vector2){28, 18}, ASSETS_PATH "Collisions/col_room2.txt");
        break;
    case 3:
        path = ASSETS_PATH "Escenarios/Escena3.png";
        InitRoomCollisions(&room3, (Vector2){0, 44}, (Vector2){52, 22}, ASSETS_PATH "Collisions/col_room3.txt");
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
}

// Check if a rectangle is 2 TILES away from the center of the camera
bool IsRectangleOnCamera(Rectangle rect, Camera2D camera)
{
    return CheckCollisionRecs(rect, (Rectangle){camera.target.x - REL_TILE_SIZE * 2, camera.target.y - REL_TILE_SIZE * 2, REL_TILE_SIZE * 4, REL_TILE_SIZE * 4});
}
