#include "../headers/sound.h"

Music GameMusic;
float timePlayed;
Music MenuMusic;
Sound fxButton;
Music fxPasosGrava;

void InitSounds()
{
    GameMusic = LoadMusicStream(ASSETS_PATH "Music/meow.mp3");
    MenuMusic = LoadMusicStream(ASSETS_PATH "Music/gerudo.mp3");

    fxButton = LoadSound(ASSETS_PATH "SoundEffects/Mine_button.mp3");
    fxPasosGrava = LoadMusicStream(ASSETS_PATH "SoundEffects/Pasos_Grava/MP1.mp3");
}

void PlayMusic(Music music)
{
    PlayMusicStream(music);
    UpdateMusicStream(music);

    timePlayed = GetMusicTimePlayed(music) / GetMusicTimeLength(music);

    if (timePlayed > 1.0f)
        timePlayed = 1.0f;
}

void UnloadSounds()
{
    UnloadMusicStream(GameMusic);
    UnloadMusicStream(MenuMusic);
    UnloadSound(fxButton);
    UnloadMusicStream(fxPasosGrava);
}