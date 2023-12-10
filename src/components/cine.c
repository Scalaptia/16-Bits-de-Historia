#include "../headers/cine.h"

//Mexico----------------
CINE M_F;
CINE M_B;
CINE M2_F;

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

    Image M_BI = LoadImage(ASSETS_PATH "Cinematicas/Banderas/mexico.png");
    Image M_FI = LoadImage(ASSETS_PATH "Cinematicas/Bases/MFondo.png");
    
    Image M2_FI = LoadImage(ASSETS_PATH "Cinematicas/Bases/B3.png");
    
    C1_Per.TexturaC = LoadTextureFromImage(C1_PerI);
    C1_Fondo.TexturaC = LoadTextureFromImage(C1_FondoI);

    M_B.TexturaC = LoadTextureFromImage(M_BI);
    M_F.TexturaC = LoadTextureFromImage(M_FI);
    M2_F.TexturaC = LoadTextureFromImage(M2_FI);

    UnloadImage(M_FI);
    UnloadImage(M_BI);
    UnloadImage(M2_FI);

    UnloadImage(C1_PerI);
    UnloadImage(C1_FondoI);
}

bool RunCimeatica1(int p_limite_x,int p_limite_y)
{
    enum escenas Esc_run = INTRODUCCION;
    bool exitbucle = false;
    //Escena 1------------------------------
    {
        //Personaje------------
        C1_Per.Posicion.x = p_limite_x - 100;
        C1_Per.Posicion.y = p_limite_y / 2;

        //Fondo-----------------
        C1_Fondo.Posicion.x = 0;
        C1_Fondo.Posicion.y = 0;

        //Bandera E-Mexico
        M_B.Posicion.x=15;
        M_B.Posicion.y=15;

    }

    while(exitbucle == false)
    {
        BeginDrawing();
        {
            ClearBackground(BLACK);

            //----------------------------------PRE Escenario----------------------------------
            if(Esc_run==INTRODUCCION)
            {
                DrawText("LA BATALLA DE PUEBLA", (p_limite_x / 2) - 500 , (p_limite_y / 2)-50, 80 ,WHITE);
            }
            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && Esc_run==INTRODUCCION)
            {
                Esc_run=MEXICO;
                EndDrawing();
            }
            
            //---------------------------------Mexico Ip1-------------------------------------
            if(Esc_run==MEXICO)
            {
                //Fondo
                DrawTextureEx(M_F.TexturaC , M_F.Posicion , 0.0f , 1.2f , WHITE);
                
                //Bandera
                DrawTextureEx(M_B.TexturaC , M_B.Posicion , 0.0f , 5.0f , WHITE);

                //Rectangulo de texto
                Color bloque = Fade(BLACK, 0.5f);
                Rectangle TxtFondo = {160 ,p_limite_y - 500, 1050, 300};
                DrawRectangleRec(TxtFondo,bloque);

                //Texto
                DrawText("En la década de 1860, méxico debía dinero por prestaciones que hacía a españa\nReino unido y francia, debía 80 millones de pesos, pero en ese tiempo \nméxico estaba en tiempos dificiles economicamente debido a la independencia\nEn 1861 el presidente Benito Juárez\nDecretó la suspensión de pagos de la deuda externa del país.", 190 , p_limite_y - 450, 25 ,WHITE);

            }
            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && Esc_run==MEXICO)
            {
                Esc_run=MEXICO1;
                EndDrawing();
            }

            //---------------------------------Mexico1 Ip2-------------------------------------
            if(Esc_run==MEXICO1)
            {
                //fondo
                DrawTextureEx(M2_F.TexturaC , M2_F.Posicion , 0.0f , 0.73f , WHITE);

                //Rectangulo de texto
                Color bloque = Fade(WHITE, 0.8f);
                Rectangle TxtFondo = {160 ,p_limite_y - 500, 1050, 300};
                DrawRectangleRec(TxtFondo,bloque);
                
                //texto
                DrawText("Los demás países quedaron en ver como toman el dinero de vuelta\ndecidieronarmar un ejército cada país, españa con 5,789 soldados\nfrancia con 3,000 soldados y reino unido con\n700 marines británicos", 180 , p_limite_y - 450, 30 ,BLACK);

            }
            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && Esc_run==MEXICO1)
            {
                Esc_run=MEXICO2;
                EndDrawing();
            }

            //---------------------------------Mexico2 Ip3-------------------------------------
            if(Esc_run==MEXICO2)
            {

            }
            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && Esc_run==MEXICO2)
            {
                Esc_run=MEXICO3;
                EndDrawing();
            }

            //---------------------------------Mexico3 Ip4-------------------------------------
            if(Esc_run==MEXICO3)
            {

            }
            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && Esc_run==MEXICO3)
            {
                Esc_run=PRIMER_ESCENARIO;
                EndDrawing();
            }

            //----------------------------------Escenario 1 ----------------------------------
            if(Esc_run == PRIMER_ESCENARIO)
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
                DrawText("AAAAA", 200 , p_limite_y - 100, 30 ,BLACK);
            }
            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && Esc_run==PRIMER_ESCENARIO)
            {
                Esc_run = SEGUNDO_ESCENARIO;
                EndDrawing();
            }
            //----------------------------------Escenario 2 ----------------------------------
            if (Esc_run == SEGUNDO_ESCENARIO)
            {
                DrawTexture(C2_Per.TexturaC,0,0,WHITE);
                exitbucle = true;
                
            }
        }
        EndDrawing(); 
    }
    return true;
}
