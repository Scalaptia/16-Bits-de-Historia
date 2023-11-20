#include "../headers/sound.h"

Music music;
float timePlayed;
Music MenuMusic;
float timePlayedMenu;
Sound fxButton;
Music fxPasosGrava;

void InitSound()
{
    music = LoadMusicStream(ASSETS_PATH "Music/meow.mp3");
    timePlayed = 0.0f; // Time played normalized [0.0f..1.0f]

    MenuMusic = LoadMusicStream(ASSETS_PATH "Music/gerudo.mp3");
    timePlayedMenu = 0.0f; // Time played normalized [0.0f..1.0f]

    fxButton = LoadSound(ASSETS_PATH "SoundEffects/Mine_button.mp3");

    fxPasosGrava = LoadMusicStream(ASSETS_PATH "SoundEffects/Pasos_Grava/MP1.mp3");
}