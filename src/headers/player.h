#ifndef PLAYER_H
#define PLAYER_H

#include "raylib.h"
#include "raymath.h"
#include "../headers/keybinds.h"
#include "../headers/animation.h"
#include "../headers/level.h"

enum Item
{
    NONE,
    FOOD,
    RIFLE,
    MACHETE,
    SACO,
    LANZA
};

typedef struct Player
{
    Sprite sprite;
    Sprite actSprite;
    Vector2 position;
    Color color;
    float speed;
    int direction;
    bool isAnimated;
    enum Item heldItem;
    Texture2D heldTexture;
    bool isDead;
    Rectangle hitbox;
} Player;

#define TILE_SIZE 16
#define SCALE 5
#define REL_TILE_SIZE (TILE_SIZE * SCALE)

void InitPlayer(Sprite *sprite, Sprite *actSprite, Rectangle screen);
void actPlayer(Player *player, Music *sfx, LevelData room);
void movePlayer(Player *player, Music *sfx, LevelData room);
void playerHold(Player *player);

void InitItemTextures();

extern bool isInteracting;
extern char *currentDialogue;
extern char *currentName;

extern Player player;
extern Camera2D camera;

extern Texture2D itemFoodTexture;

extern Texture2D itemRifleTexture;

extern Texture2D itemMacheteTexture;
extern Texture2D itemMachete2Texture;

extern Texture2D itemLanzaTexture;
extern Texture2D itemLanza2Texture;

#endif