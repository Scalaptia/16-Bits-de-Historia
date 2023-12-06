#include "../headers/npc.h"

NPC skeleton1;
NPC skeleton2;
bool isInteracting = false;
char *currentDialogue = "Placeholder Text";
char *currentName = "Placeholder Name";

void InitNPCs(Sprite *sprite, Rectangle screen)
{
    InitSprite(sprite);

    skeleton1.name = "Esqueleto 1";
    skeleton1.dialogue = "A ochoa lo mataron a balazos.";
    skeleton1.position.x = REL_TILE_SIZE * 1;
    skeleton1.position.y = REL_TILE_SIZE * 18;
    skeleton1.color = WHITE;
    skeleton1.direction = 1;

    skeleton2.name = "Esqueleto 2";
    skeleton2.dialogue = "El esqueleto 1 sabe cosas.";
    skeleton2.position.x = REL_TILE_SIZE * 4;
    skeleton2.position.y = REL_TILE_SIZE * 4;
    skeleton2.color = WHITE;
    skeleton2.direction = -1;
}

void UpdateNPCs()
{
    skeleton1.sprite = npcSprite;
    skeleton2.sprite = npcSprite;

    DrawSpriteFrame(&skeleton1.sprite, skeleton1.position, SCALE, skeleton1.color, skeleton1.direction, true);
    DrawSpriteFrame(&skeleton2.sprite, skeleton2.position, SCALE, skeleton2.color, skeleton2.direction, true);
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
