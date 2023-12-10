#ifndef CINE_H
#define CINE_H

#include "raylib.h"

enum escenas
{
    INTRODUCCION,
    MEXICO,
    PRIMER_ESCENARIO,
    SEGUNDO_ESCENARIO,
    TERCER_ESCENARIO
};

typedef struct cinestruct
{
    Texture2D TexturaC;
    Vector2 Posicion;

}CINE;

//variables Externas
extern CINE M_F;
extern CINE M_B;

extern CINE C1_Per;
extern CINE C1_Fondo;

extern CINE C2_Per;

extern CINE C3_Per;

//Prototipos--------
void InitCinematica ();
bool RunCimeatica1(int p_limite_x,int p_limite_y);

#endif