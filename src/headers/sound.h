#ifndef SOUND_H
#define SOUND_H

#include "raylib.h"

void InitSound();

// Musica 1----------------
extern Music music;
extern float timePlayed;

// Musica 2-----------------
extern Music MenuMusic;
extern float timePlayedMenu;

// Button Sound-----------------
extern Sound fxButton;

// Pasos-----------------
extern Music fxPasosGrava;

#endif