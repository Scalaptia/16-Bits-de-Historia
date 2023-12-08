#include "../headers/npc.h"

NPC enojado1;
NPC enojado2;
NPC tirado1;
NPC tirado2;
NPC recargado1;
NPC recargado2;

void InitNPCs(Rectangle screen)
{
    enojado1.name = "Juan";
    enojado1.position.x = REL_TILE_SIZE * 8;
    enojado1.position.y = REL_TILE_SIZE * 4;
    enojado1.color = WHITE;
    enojado1.direction = 1;
    enojado1.requiredItem = MACHETE;
    enojado1.status = false;

    enojado2.name = "Pepe";
    enojado2.position.x = REL_TILE_SIZE * 4;
    enojado2.position.y = REL_TILE_SIZE * 4;
    enojado2.color = WHITE;
    enojado2.direction = -1;
    enojado2.requiredItem = MACHETE;
    enojado2.status = false;

    tirado1.name = "Eduardo";
    tirado1.position.x = REL_TILE_SIZE * 7;
    tirado1.position.y = REL_TILE_SIZE * 8;
    tirado1.color = WHITE;
    tirado1.direction = 1;
    tirado1.requiredItem = FOOD;
    tirado1.status = false;

    tirado2.name = "Ricardo";
    tirado2.position.x = REL_TILE_SIZE * 7;
    tirado2.position.y = REL_TILE_SIZE * 15;
    tirado2.color = WHITE;
    tirado2.direction = -1;
    tirado2.requiredItem = FOOD;
    tirado2.status = false;

    recargado1.name = "Jorge";
    recargado1.position.x = REL_TILE_SIZE * 10;
    recargado1.position.y = REL_TILE_SIZE * 18;
    recargado1.color = WHITE;
    recargado1.direction = 1;
    recargado1.requiredItem = LANZA;
    recargado1.status = false;

    recargado2.name = "Luis";
    recargado2.position.x = REL_TILE_SIZE * 1;
    recargado2.position.y = REL_TILE_SIZE * 15;
    recargado2.color = WHITE;
    recargado2.direction = 1;
    recargado2.requiredItem = LANZA;
    recargado2.status = false;
}

void UpdateNPCs()
{
    if (enojado1.status)
        enojado1.sprite = npcEnojado2Sprite;
    else
        enojado1.sprite = npcEnojado1Sprite;

    if (enojado2.status)
        enojado2.sprite = npcEnojado2Sprite;
    else
        enojado2.sprite = npcEnojado1Sprite;

    if (tirado1.status)
        tirado1.sprite = npcTirado2Sprite;
    else
        tirado1.sprite = npcTirado1Sprite;

    if (tirado2.status)
        tirado2.sprite = npcTirado2Sprite;
    else
        tirado2.sprite = npcTirado1Sprite;

    if (recargado1.status)
        recargado1.sprite = npcRecargado2Sprite;
    else
        recargado1.sprite = npcRecargado1Sprite;

    if (recargado2.status)
        recargado2.sprite = npcRecargado2Sprite;
    else
        recargado2.sprite = npcRecargado1Sprite;

    DrawSpriteFrame(&enojado1.sprite, enojado1.position, SCALE, enojado1.color, enojado1.direction, true);
    DrawSpriteFrame(&enojado2.sprite, enojado2.position, SCALE, enojado2.color, enojado2.direction, true);
    DrawSpriteFrame(&tirado1.sprite, tirado1.position, SCALE, tirado1.color, tirado1.direction, true);
    DrawSpriteFrame(&tirado2.sprite, tirado2.position, SCALE, tirado2.color, tirado2.direction, true);
    DrawSpriteFrame(&recargado1.sprite, recargado1.position, SCALE, recargado1.color, recargado1.direction, true);
    DrawSpriteFrame(&recargado2.sprite, recargado2.position, SCALE, recargado2.color, recargado2.direction, true);
}

void CheckNPC(Player *player, NPC *npc)
{
    if (Vector2Distance(player->position, npc->position) < 128)
    {
        DrawRectangle(npc->position.x - 17 + (REL_TILE_SIZE / 2), npc->position.y - 50, 32, 38, Fade(BLACK, 0.6f));
        DrawText("E", npc->position.x - 10 + (REL_TILE_SIZE / 2), npc->position.y - 45, 30, Fade(WHITE, 0.8f));

        if (IsKeyPressed(KEY_E) || isInteracting)
        {
            InteractNPC(npc, player);
        }
    }
}

void CheckNPCs(Player *player)
{
    CheckNPC(player, &enojado1);
    CheckNPC(player, &enojado2);
    CheckNPC(player, &tirado1);
    CheckNPC(player, &tirado2);
    CheckNPC(player, &recargado1);
    CheckNPC(player, &recargado2);
}

void InteractNPC(NPC *npc, Player *player)
{
    char *necesidad;

    if (IsKeyPressed(KEY_E) && isInteracting)
    {
        isInteracting = false;
        return;
    }

    isInteracting = true;

    if (npc->status == false)
    {
        // Cambiar el texto dependiendo del item que se necesite
        switch (npc->requiredItem)
        {
        case FOOD:
            necesidad = "comida";
            break;
        case RIFLE:
            necesidad = "un rifle";
            break;
        case MACHETE:
            necesidad = "un machete";
            break;
        case LANZA:
            necesidad = "una lanza";
            break;
        default:
            necesidad = "nada";
            break;
        }

        npc->dialogue = TextFormat("Necesito %s.", necesidad);

        if (player->heldItem == npc->requiredItem)
        {
            isInteracting = true;

            player->heldItem = NONE;
            npc->status = true;
            npc->dialogue = "Muchas gracias soldado =)";
        }
    }

    currentDialogue = npc->dialogue;
    currentName = npc->name;
}
