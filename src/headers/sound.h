#ifndef SOUND_H
#define SOUND_H

#include "raylib.h"

void InitSounds();
void PlayMusic(Music music);
void UnloadSounds();

// Inicio
extern Music IntroMusic;

// Musica 1----------------
extern Music GameMusic;
extern float timePlayed;

// Musica 2-----------------
extern Music MenuMusic;
extern float timePlayedMenu;

// Button Sound-----------------
extern Sound fxButton;

// Pasos-----------------
extern Music fxPasosGrava;

#endif