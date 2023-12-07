#include "../headers/npc.h"

NPC enojado1;
NPC enojado2;

bool isInteracting = false;
char *currentDialogue = "Placeholder Text";
char *currentName = "Placeholder Name";

void InitNPCs(Rectangle screen)
{
    enojado1.name = "Juan";
    enojado1.dialogue = "Necesito municiones.";
    enojado1.position.x = REL_TILE_SIZE * 1;
    enojado1.position.y = REL_TILE_SIZE * 18;
    enojado1.color = WHITE;
    enojado1.direction = 1;

    enojado2.name = "Pepe";
    enojado2.dialogue = "Muchas gracias!.";
    enojado2.position.x = REL_TILE_SIZE * 4;
    enojado2.position.y = REL_TILE_SIZE * 4;
    enojado2.color = WHITE;
    enojado2.direction = -1;
}

void UpdateNPCs()
{
    enojado1.sprite = npcE1Sprite;
    enojado2.sprite = npcE2Sprite;

    DrawSpriteFrame(&enojado1.sprite, enojado1.position, SCALE, enojado1.color, enojado1.direction, true);
    DrawSpriteFrame(&enojado2.sprite, enojado2.position, SCALE, enojado2.color, enojado2.direction, true);
}

void InteractNPC(NPC npc)
{
    if (IsKeyPressed(KEY_E) && isInteracting)
    {
        isInteracting = false;
        return;
    }

    isInteracting = true;
    currentDialogue = npc.dialogue;
    currentName = npc.name;
}
