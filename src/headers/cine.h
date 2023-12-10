#ifndef CINE_H
#define CINE_H

#include "raylib.h"
#include "../headers/sound.h"

enum escenas
{
    INTRODUCCION,
    MEXICO,
    MEXICO1,
    MEXICO2,
    MEXICO3,
    MEXICO4,
    PRIMER_ESCENARIO,
    SEGUNDO_ESCENARIO,
    
    C2_e1,
    C2_e2,
    C2_e3,
    C2_e4
};

typedef struct cinestruct
{
    Texture2D TexturaC;
    Vector2 Posicion;

}CINE;

//variables Externas-------------------------
/*
    Funciona sin necesidad de las vairables externas
*/
extern CINE vineta;

//Escena 1
extern CINE M_F;
extern CINE M_B;
extern CINE M2_F;
extern CINE M3_F;
extern CINE M4_F;
extern CINE M5_F;

extern CINE C1_Per;
extern CINE C1_Fondo;

//Escena 2


//Escena 3

//Prototipos---------------------------------
void InitCinematica ();
bool RunCimeatica1(int p_limite_x,int p_limite_y,bool togle);
bool RunCimeatica2(int p_limite_x,int p_limite_y,bool togle);

#endif