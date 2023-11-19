#include "../headers/animation.h"

static int frame = 0;
static int counter = 0;

AnimationData charAnim;

void InitCharacter()
{
    charAnim.frames = (Image *)malloc(sizeof(Image) * 4);
    charAnim.textures = (Texture2D *)malloc(sizeof(Texture2D) * 4);

    charAnim.frames[0] = LoadImage(ASSETS_PATH "Character_animation/priests_idle/priest3/v2/priest3_v2_1.png");
    charAnim.frames[1] = LoadImage(ASSETS_PATH "Character_animation/priests_idle/priest3/v2/priest3_v2_2.png");
    charAnim.frames[2] = LoadImage(ASSETS_PATH "Character_animation/priests_idle/priest3/v2/priest3_v2_3.png");
    charAnim.frames[3] = LoadImage(ASSETS_PATH "Character_animation/priests_idle/priest3/v2/priest3_v2_4.png");

    charAnim.textures[0] = LoadTextureFromImage(charAnim.frames[0]);
    charAnim.textures[1] = LoadTextureFromImage(charAnim.frames[1]);
    charAnim.textures[2] = LoadTextureFromImage(charAnim.frames[2]);
    charAnim.textures[3] = LoadTextureFromImage(charAnim.frames[3]);
}

void UpdateFrame()
{
    counter++;

    if (counter >= ANIMATION_SPEED)
    {
        frame++;
        counter = 0;
    }

    if (frame > 3)
    {
        frame = 0;
    }
}

void DrawCharacter(Rectangle position, Color color)
{
    UpdateFrame();
    DrawTexturePro(charAnim.textures[frame], (Rectangle){0, 0, 16, 16}, position, (Vector2){0, 0}, 0, color);
}

void UnloadCharacter()
{
    for (int i = 0; i < 4; i++)
    {
        UnloadImage(charAnim.frames[i]);
        UnloadTexture(charAnim.textures[i]);
    }
}
