#include "../headers/sound.h"

Sound IntroSound;
Music MenuMusic;
Sound fxButton;
Music fxPasosGrava;
// Lv1
Music GameMusic;
float timePlayed;

// Lv2
Music lv2;

// Lv2
Music lv3;

// Final
Music finalm;

// Cinematicas1
Music C1M_F;
Music C2M_F;
Music C3M_F;

void InitSounds()
{
    char strpath[512];

    strcpy(strpath, GetWorkingDirectory());
    strcat(strpath, "/audio/LoadingScreen/Intro.mp3");
    IntroSound = LoadSound(strpath);

    strcpy(strpath, GetWorkingDirectory());
    strcat(strpath, "/audio/Music/N64.mp3");
    GameMusic = LoadMusicStream(strpath);

    strcpy(strpath, GetWorkingDirectory());
    strcat(strpath, "/audio/Music/gerudo.mp3");
    MenuMusic = LoadMusicStream(strpath);

    strcpy(strpath, GetWorkingDirectory());
    strcat(strpath, "/audio/Music/Arena.mp3");
    C1M_F = LoadMusicStream(strpath);

    strcpy(strpath, GetWorkingDirectory());
    strcat(strpath, "/audio/Music/N642.mp3");
    C2M_F = LoadMusicStream(strpath);

    strcpy(strpath, GetWorkingDirectory());
    strcat(strpath, "/audio/Music/Fortess.mp3");
    C3M_F = LoadMusicStream(strpath);

    strcpy(strpath, GetWorkingDirectory());
    strcat(strpath, "/audio/Music/paint.mp3");
    lv3 = LoadMusicStream(strpath);

    strcpy(strpath, GetWorkingDirectory());
    strcat(strpath, "/audio/Music/tenso.mp3");
    lv2 = LoadMusicStream(strpath);

    strcpy(strpath, GetWorkingDirectory());
    strcat(strpath, "/audio/Music/flower.mp3");
    finalm = LoadMusicStream(strpath);

    strcpy(strpath, GetWorkingDirectory());
    strcat(strpath, "/audio/SoundEffects/Mine_button.mp3");
    fxButton = LoadSound(strpath);

    strcpy(strpath, GetWorkingDirectory());
    strcat(strpath, "/audio/SoundEffects/Pasos_Grava/MP1.mp3");
    fxPasosGrava = LoadMusicStream(strpath);
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