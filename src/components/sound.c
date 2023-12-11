#include "../headers/sound.h"

Sound IntroSound;
Music MenuMusic;
Sound fxButton;
Music fxPasosGrava;
//Lv1
Music GameMusic;
float timePlayed;

//Lv2
Music lv2;

//Lv2
Music lv3;

//Final
Music finalm;

//Cinematicas1
Music C1M_F;
Music C2M_F;
Music C3M_F;


void InitSounds()
{
    IntroSound = LoadSound(AUDIO_PATH "LoadingScreen/intro.mp3");
    GameMusic = LoadMusicStream(AUDIO_PATH "Music/N64.mp3");
    MenuMusic = LoadMusicStream(AUDIO_PATH "Music/gerudo.mp3");
    C1M_F = LoadMusicStream(AUDIO_PATH "Music/Arena.mp3");
    C2M_F = LoadMusicStream(AUDIO_PATH "Music/N642.mp3");
    C3M_F = LoadMusicStream(AUDIO_PATH "Music/Fortess.mp3");
    lv3 = LoadMusicStream(AUDIO_PATH "Music/paint.mp3");
    lv2 = LoadMusicStream(AUDIO_PATH "Music/tenso.mp3");
    finalm= LoadMusicStream (AUDIO_PATH "Music/flower.mp3");

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