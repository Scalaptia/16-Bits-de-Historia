#ifndef SOUND_H
#define SOUND_H

#include "raylib.h"

void InitSounds();
void PlayMusic(Music music);
void UnloadSounds();

// Inicio
extern Sound IntroSound;

// Musica 1----------------
extern Music GameMusic;
extern float timePlayed;

// Musica 2-----------------
extern Music MenuMusic;
extern float timePlayedMenu;

//Musca 3-------------------
extern Music lv2;
extern float timeplayedpaint;

//Musca 3-------------------
extern Music lv3;
extern float timeplayedtense;

//final
extern Music finalm;
extern float timeplayedtense;

//Musica escena 1 - 2 - 3 ---
extern Music C1M_F;
extern Music C2M_F;
extern Music C3M_F;
// Button Sound-----------------
extern Sound fxButton;

// Pasos-----------------
extern Music fxPasosGrava;

#endif