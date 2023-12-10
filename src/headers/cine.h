#ifndef CINE_H
#define CINE_H

#include "raylib.h"

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
};

typedef struct cinestruct
{
    Texture2D TexturaC;
    Vector2 Posicion;

}CINE;

//variables Externas
extern CINE M_F;
extern CINE M_B;
extern CINE M2_F;
extern CINE M3_F;
extern CINE M4_F;
extern CINE M5_F;

extern CINE C1_Per;
extern CINE C1_Fondo;

//Prototipos--------
void InitCinematica ();
bool RunCimeatica1(int p_limite_x,int p_limite_y);

#endif