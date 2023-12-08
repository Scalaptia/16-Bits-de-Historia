#include "../headers/npc.h"

NPC enojado1;
NPC enojado2;

bool isInteracting = false;
char *currentDialogue = "Placeholder Text";
char *currentName = "Placeholder Name";

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
    enojado2.requiredItem = RIFLE;
    enojado2.status = false;
}

void UpdateNPCs()
{
    if (enojado1.status)
        enojado1.sprite = npcE2Sprite;
    else
        enojado1.sprite = npcE1Sprite;

    if (enojado2.status)
        enojado2.sprite = npcE2Sprite;
    else
        enojado2.sprite = npcE1Sprite;

    DrawSpriteFrame(&enojado1.sprite, enojado1.position, SCALE, enojado1.color, enojado1.direction, true);
    DrawSpriteFrame(&enojado2.sprite, enojado2.position, SCALE, enojado2.color, enojado2.direction, true);
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
            npc->dialogue = "Muchas gracias.";
        }
    }

    currentDialogue = npc->dialogue;
    currentName = npc->name;
}
