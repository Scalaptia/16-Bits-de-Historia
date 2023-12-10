#include "../headers/cine.h"

//Escena 1---------------
CINE C1_Per;
CINE C1_Fondo;

//Escena 2---------------
CINE C2_Per;

//Escena 3---------------
CINE CINEMATICA3;

void InitCinematica ()
{
    Image C1_PerI = LoadImage(ASSETS_PATH "NPCs/Enojado/Feliz/1.png");
    Image C1_FondoI = LoadImage(ASSETS_PATH "Cinematicas/Fondo1.png");
    
    C1_Per.TexturaC = LoadTextureFromImage(C1_PerI);
    C1_Fondo.TexturaC = LoadTextureFromImage(C1_FondoI);

    UnloadImage(C1_PerI);
    UnloadImage(C1_FondoI);
}

void RunCimeatica1(int p_limite_x,int p_limite_y)
{
    enum escenas currentEscenario = PRIMER_ESCENARIO;
    bool exitbucle = false;
    //Escena 1------------------------------
    {
        //Personaje------------
        C1_Per.Posicion.x = p_limite_x - 100;
        C1_Per.Posicion.y = p_limite_y / 2;

        //Fondo-----------------
        C1_Fondo.Posicion.x = 0;
        C1_Fondo.Posicion.y = 0;

    }

    while(exitbucle == false || !WindowShouldClose())
    {
        BeginDrawing();
        {
            ClearBackground(RAYWHITE);
            
            //----------------------------------Escenario 1 ----------------------------------
            if(currentEscenario == PRIMER_ESCENARIO)
            {
                //Fondo
                DrawTextureEx(C1_Fondo.TexturaC , C1_Fondo.Posicion , 0.0f , 5.0f , WHITE);

                //Personaje
                DrawTextureEx(C1_Per.TexturaC , C1_Per.Posicion , 0.0f , 30.0f , WHITE);

                if(C1_Per.Posicion.x > ((p_limite_x / 2) - (C1_Per.TexturaC.width/2) - 300 ))
                {
                    C1_Per.Posicion.x -= 1;
                }

                //Rectangulo de texto
                Rectangle TxtFondo = {180 ,p_limite_y - 100, 1050, 100};
                DrawRectangleRec(TxtFondo,WHITE);

                //Texto
                DrawText("", 200 , p_limite_y - 100, 30 ,BLACK);


            }

            //-------------------------CAMBIO a Escenario 2 ----------------------------------
            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && currentEscenario==PRIMER_ESCENARIO)
            {
                currentEscenario = SEGUNDO_ESCENARIO;
            }
            if (currentEscenario == SEGUNDO_ESCENARIO)
            {
                DrawTexture(C2_Per.TexturaC,0,0,WHITE);
            }
        }
        EndDrawing(); 
    }
}
