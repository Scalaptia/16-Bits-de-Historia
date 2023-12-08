#include "../headers/object.h"

Object objComida1;

Object objRifle1;

Object objMachete1;
Object objMachete2;
Object objMachete3;
Object objMachete4;

Object objLanza1;
Object objLanza2;
Object objLanza3;
Object objLanza4;
Object objLanza5;

void InitObjects()
{
    objComida1.position.x = REL_TILE_SIZE * 7;
    objComida1.position.y = REL_TILE_SIZE * 1;
    objComida1.givenItem = FOOD;

    objMachete1.position.x = REL_TILE_SIZE * 9;
    objMachete1.position.y = REL_TILE_SIZE * 13;
    objMachete1.givenItem = MACHETE;

    objMachete2.position.x = REL_TILE_SIZE * 2;
    objMachete2.position.y = REL_TILE_SIZE * 20;
    objMachete2.givenItem = MACHETE;

    objMachete3.position.x = REL_TILE_SIZE * 18;
    objMachete3.position.y = REL_TILE_SIZE * 1;
    objMachete3.givenItem = MACHETE;

    objMachete4.position.x = REL_TILE_SIZE * 30;
    objMachete4.position.y = REL_TILE_SIZE * 2;
    objMachete4.givenItem = MACHETE;

    objLanza1.position.x = REL_TILE_SIZE * 1;
    objLanza1.position.y = REL_TILE_SIZE * 11;
    objLanza1.givenItem = LANZA;

    objLanza2.position.x = REL_TILE_SIZE * 1;
    objLanza2.position.y = REL_TILE_SIZE * 19;
    objLanza2.givenItem = LANZA;

    objLanza3.position.x = REL_TILE_SIZE * 28;
    objLanza3.position.y = REL_TILE_SIZE * 9;
    objLanza3.givenItem = LANZA;

    objLanza4.position.x = REL_TILE_SIZE * 30;
    objLanza4.position.y = REL_TILE_SIZE * 11;
    objLanza4.givenItem = LANZA;

    objLanza5.position.x = REL_TILE_SIZE * 30;
    objLanza5.position.y = REL_TILE_SIZE * 13;
    objLanza5.givenItem = LANZA;
}

void CheckObject(Player *player, Object *object)
{
    if (Vector2Distance(player->position, object->position) < 128)
    {
        DrawRectangle(object->position.x - 17 + (REL_TILE_SIZE / 2), object->position.y - 50, 32, 38, Fade(BLACK, 0.6f));
        DrawText("E", object->position.x - 10 + (REL_TILE_SIZE / 2), object->position.y - 45, 30, Fade(WHITE, 0.8f));

        if (IsKeyPressed(KEY_E) || isInteracting)
        {
            InteractObject(object, player);
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

void InteractObject(Object *object, Player *player)
{
    player->heldItem = object->givenItem;
}
