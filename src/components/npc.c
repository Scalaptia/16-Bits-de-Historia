#include "../headers/npc.h"

NPC enojado1;
NPC enojado2;
NPC enojado3;
NPC enojado4;

NPC tirado1;

NPC recargado1;
NPC recargado2;
NPC recargado3;
NPC recargado4;
NPC recargado5;

NPC saco1;
NPC saco2;
NPC saco3;
NPC saco4;
NPC saco5;
NPC saco6;
NPC saco7;
NPC saco8;
NPC saco9;
NPC saco10;

NPC mexicano1;
NPC mexicano2;
NPC mexicano3;
NPC mexicano4;
NPC mexicano5;
NPC mexicano6;

void InitNPCs()
{
    // *** Room 1 ***
    InitNPC(&enojado1, (Vector2){21, 4}, 1, "Adan", "Necesito un machete.", "Muchas gracias soldado =)", MACHETE);
    InitNPC(&enojado2, (Vector2){26, 4}, -1, "Fernando", "Necesito un machete.", "Muchas gracias soldado =)", MACHETE);
    InitNPC(&enojado3, (Vector2){7, 15}, -1, "Ricardo", "Necesito un machete.", "Muchas gracias soldado =)", MACHETE);
    InitNPC(&enojado4, (Vector2){13, 11}, -1, "Diego", "Necesito un machete.", "Muchas gracias soldado =)", MACHETE);

    InitNPC(&tirado1, (Vector2){7, 8}, 1, "Luis", "Necesito comida plis.", "Muchas gracias soldado", FOOD);

    InitNPC(&recargado1, (Vector2){1, 15}, 1, "Jorge", "Necesito una lanza.", "Muchas gracias soldado =)", LANZA);
    InitNPC(&recargado2, (Vector2){7, 19}, -1, "Brayan", "Necesito una lanza.", "Muchas gracias soldado =)", LANZA);
    InitNPC(&recargado3, (Vector2){19, 20}, 1, "Iván", "Necesito una lanza.", "Muchas gracias soldado =)", LANZA);
    InitNPC(&recargado4, (Vector2){27, 16}, -1, "Kevin", "Necesito una lanza.", "Muchas gracias soldado =)", LANZA);
    InitNPC(&recargado5, (Vector2){30, 20}, -1, "Diego", "Necesito una lanza.", "Muchas gracias soldado =)", LANZA);

    // *** Room 2 ***
    InitNPC(&saco1, (Vector2){3, 4 + 22}, 1, "", "", "", SACO);
    InitNPC(&saco2, (Vector2){4, 3 + 22}, 1, "", "", "", SACO);
    InitNPC(&saco3, (Vector2){7, 5 + 22}, 1, "", "", "", SACO);
    InitNPC(&saco4, (Vector2){8, 10 + 22}, 1, "", "", "", SACO);
    InitNPC(&saco5, (Vector2){4, 18 + 22}, 1, "", "", "", SACO);
    InitNPC(&saco6, (Vector2){5, 18 + 22}, 1, "", "", "", SACO);
    InitNPC(&saco7, (Vector2){27, 4 + 22}, 1, "", "", "", SACO);
    InitNPC(&saco8, (Vector2){24, 10 + 22}, 1, "", "", "", SACO);
    InitNPC(&saco9, (Vector2){27, 18 + 22}, 1, "", "", "", SACO);
    InitNPC(&saco10, (Vector2){28, 17 + 22}, 1, "", "", "", SACO);

    InitNPC(&mexicano1, (Vector2){6, 9 + 22}, 1, "", "", "", NONE);
    InitNPC(&mexicano2, (Vector2){13, 14 + 22}, -1, "", "", "", NONE);
    InitNPC(&mexicano3, (Vector2){21, 4 + 22}, 1, "", "", "", NONE);
    InitNPC(&mexicano4, (Vector2){23, 4 + 22}, -1, "", "", "", NONE);
    InitNPC(&mexicano5, (Vector2){28, 16 + 22}, -1, "", "", "", NONE);
    InitNPC(&mexicano6, (Vector2){3, 14 + 22}, 1, "", "", "", NONE);
}

void InitNPC(NPC *npc, Vector2 position, int direction, char *name, char *dialogue, char *happyDialogue, enum Item requiredItem)
{
    position.x *= REL_TILE_SIZE;
    position.y *= REL_TILE_SIZE;

    npc->position = position;
    npc->color = WHITE;
    npc->direction = direction;
    npc->name = name;
    npc->dialogue = dialogue;
    npc->happyDialogue = happyDialogue;
    npc->status = false;
    npc->requiredItem = requiredItem;
}

bool UpdateRoom1NPCs()
{
    int i = 0;

    // *** Enojados ***
    if (enojado1.status)
    {
        enojado1.sprite = npcEnojado2Sprite;
        i++;
    }
    else
        enojado1.sprite = npcEnojado1Sprite;

    if (enojado2.status)
    {
        enojado2.sprite = npcEnojado2Sprite;
        i++;
    }
    else
        enojado2.sprite = npcEnojado1Sprite;

    if (enojado3.status)
    {
        enojado3.sprite = npcEnojado2Sprite;
        i++;
    }
    else
        enojado3.sprite = npcEnojado1Sprite;

    if (enojado4.status)
    {
        enojado4.sprite = npcEnojado2Sprite;
        i++;
    }
    else
        enojado4.sprite = npcEnojado1Sprite;

    // *** Tirados ***
    if (tirado1.status)
    {
        tirado1.sprite = npcTirado2Sprite;
        i++;
    }
    else
        tirado1.sprite = npcTirado1Sprite;

    // *** Recargados ***
    if (recargado1.status)
    {
        recargado1.sprite = npcRecargado2Sprite;
        i++;
    }
    else
        recargado1.sprite = npcRecargado1Sprite;

    if (recargado2.status)
    {
        recargado2.sprite = npcRecargado2Sprite;
        i++;
    }
    else
        recargado2.sprite = npcRecargado1Sprite;

    if (recargado3.status)
    {
        recargado3.sprite = npcRecargado2Sprite;
        i++;
    }
    else
        recargado3.sprite = npcRecargado1Sprite;

    if (recargado4.status)
    {
        recargado4.sprite = npcRecargado2Sprite;
        i++;
    }
    else
        recargado4.sprite = npcRecargado1Sprite;

    if (recargado5.status)
    {
        recargado5.sprite = npcRecargado2Sprite;
        i++;
    }
    else
        recargado5.sprite = npcRecargado1Sprite;

    DrawSpriteFrame(&enojado1.sprite, enojado1.position, SCALE, enojado1.color, enojado1.direction, true);
    DrawSpriteFrame(&enojado2.sprite, enojado2.position, SCALE, enojado2.color, enojado2.direction, true);
    DrawSpriteFrame(&enojado3.sprite, enojado3.position, SCALE, enojado3.color, enojado3.direction, true);
    DrawSpriteFrame(&enojado4.sprite, enojado4.position, SCALE, enojado4.color, enojado4.direction, true);

    DrawSpriteFrame(&tirado1.sprite, tirado1.position, SCALE, tirado1.color, tirado1.direction, true);

    DrawSpriteFrame(&recargado1.sprite, recargado1.position, SCALE, recargado1.color, recargado1.direction, true);
    DrawSpriteFrame(&recargado2.sprite, recargado2.position, SCALE, recargado2.color, recargado2.direction, true);
    DrawSpriteFrame(&recargado3.sprite, recargado3.position, SCALE, recargado3.color, recargado3.direction, true);
    DrawSpriteFrame(&recargado4.sprite, recargado4.position, SCALE, recargado4.color, recargado4.direction, true);
    DrawSpriteFrame(&recargado5.sprite, recargado5.position, SCALE, recargado5.color, recargado5.direction, true);

    if (i >= room1.NPCCount)
    {
        return true;
    }

    return false;
}

void CheckRoom1NPCs(Player *player)
{
    CheckNPC(player, &enojado1);
    CheckNPC(player, &enojado2);
    CheckNPC(player, &enojado3);
    CheckNPC(player, &enojado4);

    CheckNPC(player, &tirado1);

    CheckNPC(player, &recargado1);
    CheckNPC(player, &recargado2);
    CheckNPC(player, &recargado3);
    CheckNPC(player, &recargado4);
    CheckNPC(player, &recargado5);
}

bool UpdateRoom2NPCs()
{
    int i = 0;

    if (saco1.status)
    {
        saco1.sprite = npcSaco2Sprite;
        i++;
    }
    else
        saco1.sprite = npcSaco1Sprite;

    if (saco2.status)
    {
        saco2.sprite = npcSaco2Sprite;
        i++;
    }
    else
        saco2.sprite = npcSaco1Sprite;

    if (saco3.status)
    {
        saco3.sprite = npcSaco2Sprite;
        i++;
    }
    else
        saco3.sprite = npcSaco1Sprite;

    if (saco4.status)
    {
        saco4.sprite = npcSaco2Sprite;
        i++;
    }
    else
        saco4.sprite = npcSaco1Sprite;

    if (saco5.status)
    {
        saco5.sprite = npcSaco2Sprite;
        i++;
    }
    else
        saco5.sprite = npcSaco1Sprite;

    if (saco6.status)
    {
        saco6.sprite = npcSaco2Sprite;
        i++;
    }
    else
        saco6.sprite = npcSaco1Sprite;

    if (saco7.status)
    {
        saco7.sprite = npcSaco2Sprite;
        i++;
    }
    else
        saco7.sprite = npcSaco1Sprite;

    if (saco8.status)
    {
        saco8.sprite = npcSaco2Sprite;
        i++;
    }
    else
        saco8.sprite = npcSaco1Sprite;

    if (saco9.status)
    {
        saco9.sprite = npcSaco2Sprite;
        i++;
    }
    else
        saco9.sprite = npcSaco1Sprite;

    if (saco10.status)
    {
        saco10.sprite = npcSaco2Sprite;
        i++;
    }
    else
        saco10.sprite = npcSaco1Sprite;

    mexicano1.sprite = npcMexicano1Sprite;
    mexicano2.sprite = npcMexicano2Sprite;
    mexicano3.sprite = npcMexicano3Sprite;
    mexicano4.sprite = npcMexicano4Sprite;
    mexicano5.sprite = npcMexicano1Sprite;
    mexicano6.sprite = npcMexicano2Sprite;

    DrawSpriteFrame(&saco1.sprite, saco1.position, SCALE, saco1.color, saco1.direction, true);
    DrawSpriteFrame(&saco2.sprite, saco2.position, SCALE, saco2.color, saco2.direction, true);
    DrawSpriteFrame(&saco3.sprite, saco3.position, SCALE, saco3.color, saco3.direction, true);
    DrawSpriteFrame(&saco4.sprite, saco4.position, SCALE, saco4.color, saco4.direction, true);
    DrawSpriteFrame(&saco5.sprite, saco5.position, SCALE, saco5.color, saco5.direction, true);
    DrawSpriteFrame(&saco6.sprite, saco6.position, SCALE, saco6.color, saco6.direction, true);
    DrawSpriteFrame(&saco7.sprite, saco7.position, SCALE, saco7.color, saco7.direction, true);
    DrawSpriteFrame(&saco8.sprite, saco8.position, SCALE, saco8.color, saco8.direction, true);
    DrawSpriteFrame(&saco9.sprite, saco9.position, SCALE, saco9.color, saco9.direction, true);
    DrawSpriteFrame(&saco10.sprite, saco10.position, SCALE, saco10.color, saco10.direction, true);

    DrawSpriteFrame(&mexicano1.sprite, mexicano1.position, SCALE, mexicano1.color, mexicano1.direction, true);
    DrawSpriteFrame(&mexicano2.sprite, mexicano2.position, SCALE, mexicano2.color, mexicano2.direction, true);
    DrawSpriteFrame(&mexicano3.sprite, mexicano3.position, SCALE, mexicano3.color, mexicano3.direction, true);
    DrawSpriteFrame(&mexicano4.sprite, mexicano4.position, SCALE, mexicano4.color, mexicano4.direction, true);
    DrawSpriteFrame(&mexicano5.sprite, mexicano5.position, SCALE, mexicano5.color, mexicano5.direction, true);
    DrawSpriteFrame(&mexicano6.sprite, mexicano6.position, SCALE, mexicano6.color, mexicano6.direction, true);

    if (i >= room2.NPCCount)
    {
        return true;
    }

    return false;
}

void CheckRoom2NPCs(Player *player)
{
    CheckNPC(player, &saco1);
    CheckNPC(player, &saco2);
    CheckNPC(player, &saco3);
    CheckNPC(player, &saco4);
    CheckNPC(player, &saco5);
    CheckNPC(player, &saco6);
    CheckNPC(player, &saco7);
    CheckNPC(player, &saco8);
    CheckNPC(player, &saco9);
    CheckNPC(player, &saco10);
}

void CheckNPC(Player *player, NPC *npc)
{
    if (npc->requiredItem == SACO && npc->status == true)
    {
        return;
    }

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

void InteractNPC(NPC *npc, Player *player)
{
    char *necesidad;

    if (IsKeyPressed(KEY_E) && isInteracting)
    {
        isInteracting = false;
        return;
    }

    isInteracting = true;

    if (npc->requiredItem == SACO)
    {
        if (player->heldItem == MACHETE || player->heldItem == LANZA)
        {
            player->heldItem = NONE;
            npc->status = true;
        }

        isInteracting = false;
        return;
    }

    if (npc->status == false)
    {
        if (player->heldItem == npc->requiredItem)
        {
            player->heldItem = NONE;
            npc->status = true;
            npc->dialogue = npc->happyDialogue;
        }
    }

    isInteracting = true;
    currentDialogue = npc->dialogue;
    currentName = npc->name;
}
