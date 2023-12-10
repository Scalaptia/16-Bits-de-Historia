#include "../headers/object.h"

Object objComida1;

Object objRifle1;

Object objMachete1;
Object objMachete2;
Object objMachete3;
Object objMachete4;
Object objMachete5;
Object objMachete6;

Object objLanza1;
Object objLanza2;
Object objLanza3;
Object objLanza4;
Object objLanza5;
Object objLanza6;
Object objLanza7;
Object objLanza8;
Object objLanza9;
Object objLanza10;

void InitRoom1Objects()
{
    InitObject(&objComida1, itemFoodTexture, (Vector2){7, 1}, FOOD);
    InitObject(&objMachete1, itemMacheteTexture, (Vector2){2, 20}, MACHETE);
    InitObject(&objMachete2, itemMacheteTexture, (Vector2){18, 1}, MACHETE);
    InitObject(&objMachete3, itemMachete2Texture, (Vector2){9, 13}, MACHETE);
    InitObject(&objMachete4, itemMachete2Texture, (Vector2){30, 2}, MACHETE);
    InitObject(&objLanza1, itemLanzaTexture, (Vector2){1, 11}, LANZA);
    InitObject(&objLanza2, itemLanzaTexture, (Vector2){1, 19}, LANZA);
    InitObject(&objLanza3, itemLanza2Texture, (Vector2){28, 9}, LANZA);
    InitObject(&objLanza4, itemLanzaTexture, (Vector2){30, 11}, LANZA);
    InitObject(&objLanza5, itemLanzaTexture, (Vector2){30, 13}, LANZA);
}

void InitRoom2Objects()
{
    // *** Machetes ***
    InitObject(&objMachete1, itemMacheteTexture, (Vector2){3, 3 + 22}, MACHETE);
    InitObject(&objMachete2, itemMacheteTexture, (Vector2){8, 5 + 22}, MACHETE);
    InitObject(&objMachete3, itemMacheteTexture, (Vector2){26, 6 + 22}, MACHETE);
    InitObject(&objMachete4, itemMachete2Texture, (Vector2){26, 9 + 22}, MACHETE);
    InitObject(&objMachete5, itemMachete2Texture, (Vector2){18, 10 + 22}, MACHETE);
    InitObject(&objMachete6, itemMacheteTexture, (Vector2){14, 14 + 22}, MACHETE);

    // *** Lanzas ***
    InitObject(&objLanza1, itemLanza2Texture, (Vector2){13, 5 + 22}, LANZA);
    InitObject(&objLanza2, itemLanzaTexture, (Vector2){21, 3 + 22}, LANZA);
    InitObject(&objLanza3, itemLanzaTexture, (Vector2){25, 3 + 22}, LANZA);
    InitObject(&objLanza4, itemLanza2Texture, (Vector2){26, 7 + 22}, LANZA);
    InitObject(&objLanza5, itemLanzaTexture, (Vector2){26, 8 + 22}, LANZA);
    InitObject(&objLanza6, itemLanzaTexture, (Vector2){20, 10 + 22}, LANZA);
    InitObject(&objLanza7, itemLanza2Texture, (Vector2){22, 18 + 22}, LANZA);
    InitObject(&objLanza8, itemLanzaTexture, (Vector2){6, 10 + 22}, LANZA);
    InitObject(&objLanza9, itemLanza2Texture, (Vector2){5, 12 + 22}, LANZA);
    InitObject(&objLanza10, itemLanzaTexture, (Vector2){3, 16 + 22}, LANZA);
}

void InitRoom3Objects()
{
}

void InitObject(Object *object, Texture2D texture, Vector2 position, enum Item givenItem)
{
    position.x *= REL_TILE_SIZE;
    position.y *= REL_TILE_SIZE;

    object->texture = texture;
    object->position = position;
    object->givenItem = givenItem;
    object->isTaken = false;
}

void CheckObject(Player *player, Object *object)
{
    if (!object->isTaken)
    {
        DrawTextureEx(object->texture, object->position, 0, SCALE, WHITE);

        if (player->heldItem == NONE)
        {
            if (Vector2Distance(player->position, object->position) < 128)
            {
                DrawRectangle(object->position.x - 17 + (REL_TILE_SIZE / 2), object->position.y - 50, 32, 38, Fade(BLACK, 0.6f));
                DrawText("E", object->position.x - 10 + (REL_TILE_SIZE / 2), object->position.y - 45, 30, Fade(WHITE, 0.8f));

                if (IsKeyPressed(KEY_E) || isInteracting)
                {
                    InteractObject(object, player);

                    object->isTaken = true;
                }
            }
        }
    }
}

void CheckRoom1Objects(Player *player)
{
    CheckObject(player, &objComida1);

    CheckObject(player, &objRifle1);

    CheckObject(player, &objMachete1);
    CheckObject(player, &objMachete2);
    CheckObject(player, &objMachete3);
    CheckObject(player, &objMachete4);

    CheckObject(player, &objLanza1);
    CheckObject(player, &objLanza2);
    CheckObject(player, &objLanza3);
    CheckObject(player, &objLanza4);
    CheckObject(player, &objLanza5);
}

void CheckRoom2Objects(Player *player)
{
    CheckObject(player, &objMachete1);
    CheckObject(player, &objMachete2);
    CheckObject(player, &objMachete3);
    CheckObject(player, &objMachete4);
    CheckObject(player, &objMachete5);
    CheckObject(player, &objMachete6);

    CheckObject(player, &objLanza1);
    CheckObject(player, &objLanza2);
    CheckObject(player, &objLanza3);
    CheckObject(player, &objLanza4);
    CheckObject(player, &objLanza5);
    CheckObject(player, &objLanza6);
    CheckObject(player, &objLanza7);
    CheckObject(player, &objLanza8);
    CheckObject(player, &objLanza9);
    CheckObject(player, &objLanza10);
}

void CheckRoom3Objects(Player *player)
{
}

void InteractObject(Object *object, Player *player)
{
    player->heldItem = object->givenItem;
}
