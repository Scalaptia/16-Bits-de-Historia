#include "../headers/cine.h"

//Escena 1----------------
CINE M_F;
CINE M_B;
CINE M2_F;
CINE M3_F;
CINE M4_F;
CINE M5_F;

CINE C1_Per;
CINE C1_Fondo;

//Escena 2----------------
CINE C2_F;


void InitCinematica ()
{
    //Escena 1----
        Image C1_PerI = LoadImage(ASSETS_PATH "Personaje/char1.png");
        Image C1_FondoI = LoadImage(ASSETS_PATH "Cinematicas/Fondo1.png");
        Image M_BI = LoadImage(ASSETS_PATH "Cinematicas/Banderas/mexico.png");
        Image M_FI = LoadImage(ASSETS_PATH "Cinematicas/Bases/MFondo.png");    
        Image M2_FI = LoadImage(ASSETS_PATH "Cinematicas/Bases/B3.png");
        Image M3_FI =LoadImage(ASSETS_PATH "Cinematicas/Bases/Hands.png");
        Image M4_FI = LoadImage(ASSETS_PATH "Cinematicas/Bases/Contra.png");
        Image M5_FI = LoadImage(ASSETS_PATH "Cinematicas/Bases/colonias.png");

        C1_Per.TexturaC = LoadTextureFromImage(C1_PerI);
        C1_Fondo.TexturaC = LoadTextureFromImage(C1_FondoI);
        M_B.TexturaC = LoadTextureFromImage(M_BI);
        M_F.TexturaC = LoadTextureFromImage(M_FI);
        M2_F.TexturaC = LoadTextureFromImage(M2_FI);
        M3_F.TexturaC = LoadTextureFromImage(M3_FI);
        M4_F.TexturaC = LoadTextureFromImage(M4_FI);
        M5_F.TexturaC = LoadTextureFromImage(M5_FI);
    
    //Escena 2----
        Image C2_FI = LoadImage(ASSETS_PATH "Cinematicas/C2/fortaleza.png");

        C2_F.TexturaC= LoadTextureFromImage(C2_FI);
    

    //Descarga de imagenes
    UnloadImage(C2_FI);

    UnloadImage(M_FI);
    UnloadImage(M_BI);
    UnloadImage(M2_FI);
    UnloadImage(M3_FI);
    UnloadImage(M4_FI);
    UnloadImage(M5_FI);
    UnloadImage(C1_PerI);
    UnloadImage(C1_FondoI);
}

bool RunCimeatica1(int p_limite_x,int p_limite_y,bool togle)
{
    //Reducir texto en escenas, osea dar 2 clicks para seguir el texto
    enum escenas Esc_run = INTRODUCCION;
    bool exitbucle = false;
    bool finish = false;
    //Escena 1------------------------------
    {
        //Personaje------------
        C1_Per.Posicion.x = -100;
        C1_Per.Posicion.y = 250 ;

        //Fondo-----------------
        C1_Fondo.Posicion.x = 0;
        C1_Fondo.Posicion.y = 0;

        //Bandera E-Mexico
        M_B.Posicion.x=15;
        M_B.Posicion.y=15;

    }

    while(exitbucle == false)
    {
        if(togle)
            SetMusicVolume(C1M_F, 0.5f);
            PlayMusic(C1M_F);
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
                PlaySound(fxButton);
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
                PlaySound(fxButton);
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
                PlaySound(fxButton);
                Esc_run=MEXICO2;
                EndDrawing();
            }

            //---------------------------------Mexico2 Ip3-------------------------------------
            if(Esc_run==MEXICO2)
            {
                //fondo
                DrawTextureEx(M3_F.TexturaC , M3_F.Posicion , 0.0f , 2.5f , WHITE);

                //Rectangulo de texto
                Color bloque = Fade(WHITE, 0.8f);
                Rectangle TxtFondo = {160 ,p_limite_y - 500, 1050, 300};
                DrawRectangleRec(TxtFondo,bloque);

                //Fondo
                DrawText("Sin embargo, gracias a la diplomacia mexicana, méxico consiguió\nconvencer a españa y reino unido de que les pagaría después\ny estos 2 se retiraron, Además de que francian\nno solo quería su dinero de vuelta\nsi no que también quería hacer de México su protectorado",180,p_limite_y -450, 30, BLACK);
            }
            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && Esc_run==MEXICO2)
            {
                PlaySound(fxButton);
                Esc_run=MEXICO3;
                EndDrawing();
            }

            //---------------------------------Mexico3 Ip4-------------------------------------
            if(Esc_run==MEXICO3)
            {
                //Fondo
                DrawTextureEx(M4_F.TexturaC , M4_F.Posicion , 0.0f , 0.8f , WHITE);
                
                //Rectangulo de texto
                Color bloque = Fade(WHITE, 0.8f);
                Rectangle TxtFondo = {160 ,p_limite_y - 500, 1050, 300};
                DrawRectangleRec(TxtFondo,bloque);

                //Fondo
                DrawText("Imponiendo una monarquía en el país, dejando de lado\na sus compañeros creyó que conseguiría por sí solo la victoria\nya que llevaban una racha de 50 años sin perder una batalla\nAl final Francia terminó con 6m soldados y méxico\nse preparó con 6m hombres,la cual francia contaba\ncon fuerzas de elite (zuavos) y méxico.",180,p_limite_y -480, 30, BLACK);

            }
            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && Esc_run==MEXICO3)
            {
                PlaySound(fxButton);
                Esc_run=MEXICO4;
                EndDrawing();
            }

            //---------------------------------Mexico4 Ip5-------------------------------------
            if(Esc_run==MEXICO4)
            {
                //Fondo
                DrawTextureEx(M5_F.TexturaC , M5_F.Posicion , 0.0f , 1.0f , WHITE);
                
                //Rectangulo de texto
                Color bloque = Fade(WHITE, 0.8f);
                Rectangle TxtFondo = {230 ,p_limite_y - 450, 900, 200};
                DrawRectangleRec(TxtFondo,bloque);

                //Fondo
                DrawText("México reclutó en su mayoría personas forzadas\nEs decir sin experiencia en el campo de batalla\ny no muy bien tratados, lo único sobresaliente de méxico\neran sus oficiales jóvenes bien experimentados\n",250, p_limite_y -440, 30, BLACK);

            }
            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && Esc_run==MEXICO4)
            {
                PlaySound(fxButton);
                Esc_run=PRIMER_ESCENARIO;
                EndDrawing();
            }


            //----------------------------------Escenario 1 ----------------------------------
            if(Esc_run == PRIMER_ESCENARIO)
            {
                //Fondo
                DrawTextureEx(C1_Fondo.TexturaC , C1_Fondo.Posicion , 0.0f , 5.0f , WHITE);

                //Personaje
                DrawTextureEx(C1_Per.TexturaC , C1_Per.Posicion , 0.0f , 40.0f , WHITE);

                if(C1_Per.Posicion.x < p_limite_x/2 -360 )
                {
                    C1_Per.Posicion.x += 4;
                }
                if(C1_Per.Posicion.x >= p_limite_x/2 -360 )
                {
                    finish = true;
                }

                //Rectangulo de texto
                Color bloque = Fade(WHITE, 0.8f);
                Rectangle TxtFondo = {500 ,p_limite_y - 100, 300, 80};
                DrawRectangleRec(TxtFondo,bloque);

                //Texto
                DrawText("Entre ellos\nIgnacio zaragoza", 520 , p_limite_y - 100, 30 ,BLACK);
            }
            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && finish == true)
            {
                PlaySound(fxButton);
                EndDrawing();
                exitbucle = true;
            }
        }
        EndDrawing(); 
    }
    return true;
}

bool RunCimeatica2(int p_limite_x,int p_limite_y,bool togle)
{
    enum escenas run_esc = C2_e1;
    bool exitbucle = false;
    //Colores
    
        Color b_colorgray = Fade (GRAY, 0.7f);
        Color b_colorwhite = Fade (WHITE,0.7f);
        Color b_colorblack = Fade (BLACK,0.7f);
    
    

    while(!exitbucle)
    {
        BeginDrawing();
        {
            ClearBackground(BLACK);
            //---------------------------Escena 1---------------------------
            if(run_esc == C2_e1)
            {
                // Fondo
                DrawTextureEx(C2_F.TexturaC,C2_F.Posicion,0.0f,10.0f,WHITE);
                
                // Ignacio
                C1_Per.Posicion.x=250;
                C1_Per.Posicion.y=(p_limite_y / 2) - 250 ; 
                DrawTextureEx(C1_Per.TexturaC,C1_Per.Posicion,0.0f,15.0f,WHITE);

                //rectangulo
                Rectangle block = {250, (p_limite_y/2) - 80 , 900 , 200};
                DrawRectangleRec(block,b_colorgray);

                //Texto
                DrawText("La defensa organizada por el general Zaragoza\nen Pueblaconsistió en fortificar la ciudad ante el\ninminente ataque francés\n", 300 , (p_limite_y/2) - 50 , 30 , BLACK);
            }
            if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && run_esc == C2_e1)
            {
                PlaySound(fxButton);
                run_esc = C2_e2;
                EndDrawing();
            }
            //---------------------------Escena 2---------------------------
            if(run_esc == C2_e2)
            {

            }
        }

        EndDrawing();
    }

    return true;
}