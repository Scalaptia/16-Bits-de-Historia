#include "../headers/level.h"

LevelData room1;

Vector2 ROOM1_POS = {TILE_SIZE * 3, TILE_SIZE * 3};

void InitGraphics(GraphicsData *tileset)
{
    tileset->image = LoadImage(ASSETS_PATH "character and tileset/Dungeon_Tileset.png");
    tileset->texture = LoadTextureFromImage(tileset->image);
    tileset->size = (Rectangle){0, 0, tileset->texture.width, tileset->texture.height};
}

void ScaleRec(Rectangle *rec)
{
    rec->x *= SCALE;
    rec->y *= SCALE;
    rec->width *= SCALE;
    rec->height *= SCALE;
}

void DrawElement(GraphicsData *tileset, char *element, Vector2 position)
{
    if (strcmp(element, "ROOM") == 0)
    {
        Rectangle room_src = {0, 0, TILE_SIZE * 6, TILE_SIZE * 5};
        Rectangle room_dst = {position.x, position.y, room_src.width, room_src.height};
        ScaleRec(&room_dst);
        DrawTexturePro(tileset->texture, room_src, room_dst, (Vector2){0, 0}, 0, WHITE);
    }
}

void DrawRoom(GraphicsData *tileset, Vector2 position)
{
    DrawElement(tileset, "ROOM", position);

    CreateCollisionWalls(position, (Vector2){12, 10}, &room1.wallsCount, &room1.walls);
    CreateCollisionObject((Vector2){position.x + 2, position.y + 7}, (Vector2){7, 1}, &room1.objectsCount, &room1.objects);
    CreateCollisionObject((Vector2){position.x + 9, position.y + 2}, (Vector2){1, 6}, &room1.objectsCount, &room1.objects);
    CreateCollisionObject((Vector2){position.x + 5, position.y + 3}, (Vector2){1, 1}, &room1.objectsCount, &room1.objects);
    CreateCollisionObject((Vector2){position.x + 4, position.y + 2}, (Vector2){1, 1}, &room1.objectsCount, &room1.objects);
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
    position.x *= REL_TILE_SIZE;
    position.y *= REL_TILE_SIZE;

    int newObjectsCount = (int)(size.x * size.y);
    Rectangle *newObjects = malloc(sizeof(Rectangle) * newObjectsCount);

    for (int i = 0; i < size.x; i++)
    {
        for (int j = 0; j < size.y; j++)
        {
            newObjects[i * (int)size.y + j] = (Rectangle){position.x + i * REL_TILE_SIZE + 2.5, position.y + j * REL_TILE_SIZE + 2.5, REL_TILE_SIZE - 5, REL_TILE_SIZE - 5};
        }
    }

    // Concatenar objetos nuevos con objetos viejos
    *objects = realloc(*objects, sizeof(Rectangle) * (*objectsCount + newObjectsCount));
    memcpy(*objects + *objectsCount, newObjects, sizeof(Rectangle) * newObjectsCount);
    *objectsCount += newObjectsCount;
    free(newObjects);
}

void UnloadGraphics(GraphicsData *tileset)
{
    UnloadTexture(tileset->texture);
    UnloadImage(tileset->image);
}