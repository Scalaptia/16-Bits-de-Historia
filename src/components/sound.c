#include "../headers/sound.h"

Sound IntroSound;
Music GameMusic;
float timePlayed;
Music MenuMusic;
Sound fxButton;
Music fxPasosGrava;

void InitSounds()
{
    IntroSound = LoadSound(AUDIO_PATH "LoadingScreen/intro.mp3");
    GameMusic = LoadMusicStream(AUDIO_PATH "Music/meow.mp3");
    MenuMusic = LoadMusicStream(AUDIO_PATH "Music/gerudo.mp3");

    fxButton = LoadSound(AUDIO_PATH "SoundEffects/Mine_button.mp3");
    fxPasosGrava = LoadMusicStream(AUDIO_PATH "SoundEffects/Pasos_Grava/MP1.mp3");
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
    UnloadSound(IntroSound);
    UnloadMusicStream(GameMusic);
    UnloadMusicStream(MenuMusic);
    UnloadSound(fxButton);
    UnloadMusicStream(fxPasosGrava);
}