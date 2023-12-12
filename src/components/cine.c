#include "../headers/cine.h"

CINE vineta;
CINE negro;

// Personajes
CINE Por;
CINE Por2;
CINE Ign;
CINE Ign2;

// Escena 1----------------
CINE M_F;
CINE M_B;
CINE M2_F;
CINE M3_F;
CINE M4_F;
CINE M5_F;

CINE C1_Per;
CINE C1_Fondo;

// Escena 2----------------
CINE C2_F1;
CINE C2_F2;
CINE C2_F3;
CINE C2_F4;
CINE C2_F5;

// Escena 3----------------
CINE C3_F1;
CINE C3_F2;

// final
CINE C4_F1;
CINE C4_F2;

void InitCinematica()
{
    char strpath[512];

    strcpy(strpath, GetWorkingDirectory());
    strcat(strpath, "/assets/Cinematicas/vineta.png");
    Image vinetai = LoadImage(strpath);
    vineta.TexturaC = LoadTextureFromImage(vinetai);

    strcpy(strpath, GetWorkingDirectory());
    strcat(strpath, "/assets/capi/Porfirio1.png");
    Image PorI = LoadImage(strpath);

    strcpy(strpath, GetWorkingDirectory());
    strcat(strpath, "/assets/capi/Porfirio2.png");
    Image PorI2 = LoadImage(strpath);

    strcpy(strpath, GetWorkingDirectory());
    strcat(strpath, "/assets/capi/ignacio.png");
    Image IgnI = LoadImage(strpath);

    strcpy(strpath, GetWorkingDirectory());
    strcat(strpath, "/assets/capi/ignacio2.png");
    Image IgnI2 = LoadImage(strpath);

    Por.TexturaC = LoadTextureFromImage(PorI);
    Por2.TexturaC = LoadTextureFromImage(PorI2);
    Ign.TexturaC = LoadTextureFromImage(IgnI);
    Ign2.TexturaC = LoadTextureFromImage(IgnI2);

    // Escena 1----
    strcpy(strpath, GetWorkingDirectory());
    strcat(strpath, "/assets/Personaje/char1.png");
    Image C1_PerI = LoadImage(strpath);

    strcpy(strpath, GetWorkingDirectory());
    strcat(strpath, "/assets/Cinematicas/Fondo1.png");
    Image C1_FondoI = LoadImage(strpath);

    strcpy(strpath, GetWorkingDirectory());
    strcat(strpath, "/assets/Cinematicas/Banderas/mexico.png");
    Image M_BI = LoadImage(strpath);

    strcpy(strpath, GetWorkingDirectory());
    strcat(strpath, "/assets/Cinematicas/Bases/MFondo.png");
    Image M_FI = LoadImage(strpath);

    strcpy(strpath, GetWorkingDirectory());
    strcat(strpath, "/assets/Cinematicas/Bases/B3.png");
    Image M2_FI = LoadImage(strpath);

    strcpy(strpath, GetWorkingDirectory());
    strcat(strpath, "/assets/Cinematicas/Bases/Hands.png");
    Image M3_FI = LoadImage(strpath);

    strcpy(strpath, GetWorkingDirectory());
    strcat(strpath, "/assets/Cinematicas/Bases/Contra.png");
    Image M4_FI = LoadImage(strpath);

    strcpy(strpath, GetWorkingDirectory());
    strcat(strpath, "/assets/Cinematicas/Bases/colonias.png");
    Image M5_FI = LoadImage(strpath);

    C1_Per.TexturaC = LoadTextureFromImage(C1_PerI);
    C1_Fondo.TexturaC = LoadTextureFromImage(C1_FondoI);
    M_B.TexturaC = LoadTextureFromImage(M_BI);
    M_F.TexturaC = LoadTextureFromImage(M_FI);
    M2_F.TexturaC = LoadTextureFromImage(M2_FI);
    M3_F.TexturaC = LoadTextureFromImage(M3_FI);
    M4_F.TexturaC = LoadTextureFromImage(M4_FI);
    M5_F.TexturaC = LoadTextureFromImage(M5_FI);

    // Escena 2----

    strcpy(strpath, GetWorkingDirectory());
    strcat(strpath, "/assets/Cinematicas/C2/fortaleza.png");
    Image C2_F1I = LoadImage(strpath);

    strcpy(strpath, GetWorkingDirectory());
    strcat(strpath, "/assets/Cinematicas/C2/fuerzas.png");
    Image C2_F2I = LoadImage(strpath);

    strcpy(strpath, GetWorkingDirectory());
    strcat(strpath, "/assets/Cinematicas/C2/guadalupe.png");
    Image C2_F3I = LoadImage(strpath);

    strcpy(strpath, GetWorkingDirectory());
    strcat(strpath, "/assets/Cinematicas/C2/defensa.png");
    Image C2_F4I = LoadImage(strpath);

    strcpy(strpath, GetWorkingDirectory());
    strcat(strpath, "/assets/Cinematicas/C2/run.png");
    Image C2_F5I = LoadImage(strpath);

    C2_F1.TexturaC = LoadTextureFromImage(C2_F1I);
    C2_F2.TexturaC = LoadTextureFromImage(C2_F2I);
    C2_F3.TexturaC = LoadTextureFromImage(C2_F3I);
    C2_F4.TexturaC = LoadTextureFromImage(C2_F4I);
    C2_F5.TexturaC = LoadTextureFromImage(C2_F5I);

    // Escena 3----
    strcpy(strpath, GetWorkingDirectory());
    strcat(strpath, "/assets/Cinematicas/C3/preparados.png");
    Image C3_F1I = LoadImage(strpath);

    strcpy(strpath, GetWorkingDirectory());
    strcat(strpath, "/assets/Cinematicas/C3/ataquen.png");
    Image C3_F2I = LoadImage(strpath);

    C3_F1.TexturaC = LoadTextureFromImage(C3_F1I);
    C3_F2.TexturaC = LoadTextureFromImage(C3_F2I);

    // Final
    strcpy(strpath, GetWorkingDirectory());
    strcat(strpath, "/assets/Cinematicas/C4/retirada.png");
    Image C4_F1I = LoadImage(strpath);

    strcpy(strpath, GetWorkingDirectory());
    strcat(strpath, "/assets/Cinematicas/C4/final.png");
    Image C4_F2I = LoadImage(strpath);

    C4_F1.TexturaC = LoadTextureFromImage(C4_F1I);
    C4_F2.TexturaC = LoadTextureFromImage(C4_F2I);

    // Descarga de imagenes
    UnloadImage(C4_F1I);
    UnloadImage(C4_F2I);

    UnloadImage(C3_F1I);
    UnloadImage(C3_F2I);

    UnloadImage(C2_F1I);
    UnloadImage(C2_F2I);
    UnloadImage(C2_F3I);
    UnloadImage(C2_F4I);
    UnloadImage(C2_F5I);

    UnloadImage(M_FI);
    UnloadImage(M_BI);
    UnloadImage(M2_FI);
    UnloadImage(M3_FI);
    UnloadImage(M4_FI);
    UnloadImage(M5_FI);
    UnloadImage(C1_PerI);
    UnloadImage(C1_FondoI);

    UnloadImage(vinetai);
    UnloadImage(PorI);
    UnloadImage(PorI2);
    UnloadImage(IgnI);
    UnloadImage(IgnI2);
}

bool RunCimeatica1(int p_limite_x, int p_limite_y, bool togle)
{
    // Reducir texto en escenas, osea dar 2 clicks para seguir el texto
    enum escenas Esc_run = INTRODUCCION;
    bool exitbucle = false;
    bool finish = false;
    // Escena 1------------------------------
    {
        // Personaje------------
        Ign.Posicion.x = -100;
        Ign.Posicion.y = 250;

        // Fondo-----------------
        C1_Fondo.Posicion.x = 0;
        C1_Fondo.Posicion.y = -200;

        // Bandera E-Mexico
        M_B.Posicion.x = 15;
        M_B.Posicion.y = 15;
    }

    while (exitbucle == false)
    {
        if (togle)
            SetMusicVolume(C1M_F, 0.5f);
        PlayMusic(C1M_F);
        BeginDrawing();
        {
            ClearBackground(BLACK);

            //----------------------------------PRE Escenario----------------------------------
            if (Esc_run == INTRODUCCION)
            {
                DrawText("LA BATALLA DE PUEBLA", (p_limite_x / 2) - 500, (p_limite_y / 2) - 50, 80, WHITE);
            }
            if ((IsMouseButtonPressed(MOUSE_BUTTON_LEFT) || IsKeyPressed(KEY_E)) && Esc_run == INTRODUCCION)
            {
                PlaySound(fxButton);
                Esc_run = MEXICO;
                EndDrawing();
            }

            //---------------------------------Mexico Ip1-------------------------------------
            if (Esc_run == MEXICO)
            {
                // Fondo
                DrawTextureEx(M_F.TexturaC, M_F.Posicion, 0.0f, 1.2f, WHITE);

                // Bandera
                DrawTextureEx(M_B.TexturaC, M_B.Posicion, 0.0f, 5.0f, WHITE);

                // Rectangulo de texto
                Color bloque = Fade(BLACK, 0.5f);
                Rectangle TxtFondo = {160, p_limite_y - 500, 1050, 300};
                DrawRectangleRec(TxtFondo, bloque);

                // Texto
                DrawText("En la década de 1860, méxico debía dinero por prestaciones que hacía a españa\n\n\nReino unido y francia, debía 80 millones de pesos, pero en ese tiempo \n\n\nméxico estaba en tiempos dificiles economicamente debido a la independencia\n\n\nEn 1861 el presidente Benito Juárez\n\n\nDecretó la suspensión de pagos de la deuda externa del país.", 190, p_limite_y - 450, 25, WHITE);
            }
            if ((IsMouseButtonPressed(MOUSE_BUTTON_LEFT) || IsKeyPressed(KEY_E)) && Esc_run == MEXICO)
            {
                PlaySound(fxButton);
                Esc_run = MEXICO1;
                EndDrawing();
            }

            //---------------------------------Mexico1 Ip2-------------------------------------
            if (Esc_run == MEXICO1)
            {
                // fondo
                DrawTextureEx(M2_F.TexturaC, M2_F.Posicion, 0.0f, 0.73f, WHITE);

                // Rectangulo de texto
                Color bloque = Fade(WHITE, 0.8f);
                Rectangle TxtFondo = {160, p_limite_y - 500, 1050, 300};
                DrawRectangleRec(TxtFondo, bloque);

                // texto
                DrawText("Los demás países quedaron en ver como toman el dinero de vuelta\n\n\ndecidieronarmar un ejército cada país, españa con 5,789 soldados\n\n\nfrancia con 3,000 soldados y reino unido con\n\n\n700 marines británicos", 180, p_limite_y - 450, 30, BLACK);
            }
            if ((IsMouseButtonPressed(MOUSE_BUTTON_LEFT) || IsKeyPressed(KEY_E)) && Esc_run == MEXICO1)
            {
                PlaySound(fxButton);
                Esc_run = MEXICO2;
                EndDrawing();
            }

            //---------------------------------Mexico2 Ip3-------------------------------------
            if (Esc_run == MEXICO2)
            {
                // fondo
                DrawTextureEx(M3_F.TexturaC, M3_F.Posicion, 0.0f, 2.5f, WHITE);

                // Rectangulo de texto
                Color bloque = Fade(WHITE, 0.8f);
                Rectangle TxtFondo = {160, p_limite_y - 500, 1050, 300};
                DrawRectangleRec(TxtFondo, bloque);

                // Fondo
                DrawText("Sin embargo, gracias a la diplomacia mexicana, méxico consiguió\n\n\nconvencer a españa y reino unido de que les pagaría después\n\n\ny estos 2 se retiraron, Además de que francian\n\n\nno solo quería su dinero de vuelta\n\n\nsi no que también quería hacer de México su protectorado", 180, p_limite_y - 450, 30, BLACK);
            }
            if ((IsMouseButtonPressed(MOUSE_BUTTON_LEFT) || IsKeyPressed(KEY_E)) && Esc_run == MEXICO2)
            {
                PlaySound(fxButton);
                Esc_run = MEXICO3;
                EndDrawing();
            }

            //---------------------------------Mexico3 Ip4-------------------------------------
            if (Esc_run == MEXICO3)
            {
                // Fondo
                DrawTextureEx(M4_F.TexturaC, M4_F.Posicion, 0.0f, 0.8f, WHITE);

                // Rectangulo de texto
                Color bloque = Fade(WHITE, 0.8f);
                Rectangle TxtFondo = {160, p_limite_y - 500, 1050, 300};
                DrawRectangleRec(TxtFondo, bloque);

                // Fondo
                DrawText("Imponiendo una monarquía en el país, dejando de lado\n\n\na sus compañeros creyó que conseguiría por sí solo la victoria\n\n\nya que llevaban una racha de 50 años sin perder una batalla\n\n\nAl final Francia terminó con 6m soldados y méxico\n\n\nse preparó con 6m hombres,la cual francia contaba\n\n\ncon fuerzas de elite (zuavos) y méxico.", 180, p_limite_y - 480, 30, BLACK);
            }
            if ((IsMouseButtonPressed(MOUSE_BUTTON_LEFT) || IsKeyPressed(KEY_E)) && Esc_run == MEXICO3)
            {
                PlaySound(fxButton);
                Esc_run = MEXICO4;
                EndDrawing();
            }

            //---------------------------------Mexico4 Ip5-------------------------------------
            if (Esc_run == MEXICO4)
            {
                // Fondo
                DrawTextureEx(M5_F.TexturaC, M5_F.Posicion, 0.0f, 1.0f, WHITE);

                // Rectangulo de texto
                Color bloque = Fade(WHITE, 0.8f);
                Rectangle TxtFondo = {230, p_limite_y - 450, 900, 200};
                DrawRectangleRec(TxtFondo, bloque);

                // Fondo
                DrawText("México reclutó en su mayoría personas forzadas\n\n\nEs decir sin experiencia en el campo de batalla\n\n\ny no muy bien tratados, lo único sobresaliente de méxico\n\n\neran sus oficiales jóvenes bien experimentados\n\n\n", 250, p_limite_y - 440, 30, BLACK);
            }
            if ((IsMouseButtonPressed(MOUSE_BUTTON_LEFT) || IsKeyPressed(KEY_E)) && Esc_run == MEXICO4)
            {
                PlaySound(fxButton);
                Esc_run = PRIMER_ESCENARIO;
                EndDrawing();
            }

            //----------------------------------Escenario 1 ----------------------------------
            if (Esc_run == PRIMER_ESCENARIO)
            {
                // Fondo
                DrawTextureEx(C1_Fondo.TexturaC, C1_Fondo.Posicion, 0.0f, 5.0f, WHITE);

                // Personaje
                DrawTextureEx(Ign.TexturaC, Ign.Posicion, 0.0f, 40.0f, WHITE);

                if (Ign.Posicion.x < p_limite_x / 2 - 360)
                {
                    Ign.Posicion.x += 4;
                }
                if (Ign.Posicion.x >= p_limite_x / 2 - 360)
                {
                    finish = true;
                }

                // Rectangulo de texto
                Color bloque = Fade(WHITE, 0.8f);
                Rectangle TxtFondo = {500, p_limite_y - 100, 300, 80};
                DrawRectangleRec(TxtFondo, bloque);

                // Texto
                DrawText("Entre ellos\n\n\nIgnacio zaragoza", 520, p_limite_y - 100, 30, BLACK);
            }
            if ((IsMouseButtonPressed(MOUSE_BUTTON_LEFT) || IsKeyPressed(KEY_E)) && finish == true)
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

bool RunCimeatica2(int p_limite_x, int p_limite_y, bool togle)
{
    enum escenas run_esc = C2_e1;
    bool exitbucle = false;
    // Colores
    Color b_colorgray = Fade(GRAY, 0.7f);
    Color b_colorwhite = Fade(WHITE, 0.7f);
    Color b_colorblack = Fade(BLACK, 0.7f);

    while (!exitbucle)
    {
        if (togle)
            SetMusicVolume(C1M_F, 0.5f);
        PlayMusic(C2M_F);
        BeginDrawing();
        {
            ClearBackground(BLACK);
            //---------------------------Escena 1---------------------------
            if (run_esc == C2_e1)
            {
                // Fondo
                DrawTextureEx(C2_F1.TexturaC, C2_F1.Posicion, 0.0f, 8.0f, WHITE);
                DrawTextureEx(vineta.TexturaC, vineta.Posicion, 0.0f, 0.9f, WHITE);

                // Ignacio
                C1_Per.Posicion.x = 250;
                C1_Per.Posicion.y = (p_limite_y / 2) - 250;
                DrawTextureEx(C1_Per.TexturaC, C1_Per.Posicion, 0.0f, 15.0f, WHITE);

                // rectangulo
                Rectangle block = {250, (p_limite_y / 2) - 80, 900, 200};
                DrawRectangleRec(block, b_colorgray);

                // Texto
                DrawText("La defensa organizada por el general Zaragoza\n\n\nen Puebla consistió en fortificar la ciudad ante el\n\n\ninminente ataque francés\n\n\n", 300, (p_limite_y / 2) - 50, 30, WHITE);
            }
            if ((IsMouseButtonPressed(MOUSE_BUTTON_LEFT) || IsKeyPressed(KEY_E)) && run_esc == C2_e1)
            {
                PlaySound(fxButton);
                run_esc = C2_e2;
                EndDrawing();
            }
            //---------------------------Escena 2---------------------------
            if (run_esc == C2_e2)
            {
                // Fondo
                DrawTextureEx(C2_F2.TexturaC, C2_F2.Posicion, 0.0f, 8.0f, WHITE);
                DrawTextureEx(vineta.TexturaC, vineta.Posicion, 0.0f, 0.9f, WHITE);

                // Ingacio
                C1_Per.Posicion.x = -150;
                C1_Per.Posicion.y = (p_limite_y / 2) - 100;
                DrawTextureEx(C1_Per.TexturaC, C1_Per.Posicion, 0.0f, 40.0f, WHITE);

                // Rectangulo
                Rectangle block2 = {450, (p_limite_y / 2) - 80, 900, 300};
                DrawRectangleRec(block2, b_colorgray);

                // texto
                DrawText("Se instaló un cuartel a unos metros\n\n\ndel frente de batalla y las tropas mexicanas\n\n\n(que recibieron el nombre de Ejército de Oriente)\n\n\nSe prepararon para repeler a los invasores\n\n\nantes de que alcanzaran el área urbana.", 500, (p_limite_y / 2) - 50, 30, WHITE);
            }
            if ((IsMouseButtonPressed(MOUSE_BUTTON_LEFT) || IsKeyPressed(KEY_E)) && run_esc == C2_e2)
            {
                PlaySound(fxButton);
                run_esc = C2_e3;
                EndDrawing();
            }
            //---------------------------Escena 3---------------------------
            if (run_esc == C2_e3)
            {
                // Fondo
                DrawTextureEx(C2_F3.TexturaC, C2_F3.Posicion, 0.0f, 8.0f, WHITE);

                // Tropas------------------------------------------------------------------------------------PENDIENTE

                // Rectangulo
                Rectangle block3 = {50, (p_limite_y / 2) - 70, 600, 400};
                DrawRectangleRec(block3, b_colorwhite);

                // Texto
                DrawText("Dos baterías de artillería\n\n\nY 1200 hombres defendían\n\n\nLos fuertes Guadalupe\n\n\nY Loreto ubicados\n\n\nEn sendos cerros al\n\n\nnorte de la ciudad", 70, (p_limite_y / 2) - 50, 40, BLACK);
            }
            if ((IsMouseButtonPressed(MOUSE_BUTTON_LEFT) || IsKeyPressed(KEY_E)) && run_esc == C2_e3)
            {
                PlaySound(fxButton);
                run_esc = C2_e4;
                EndDrawing();
            }
            //---------------------------Escena 4---------------------------
            if (run_esc == C2_e4)
            {
                // Fondo
                DrawTextureEx(C2_F4.TexturaC, C2_F4.Posicion, 0.0f, 8.0f, WHITE);

                // Porfirio ----------------------------------------------------------------------------------CREAR IMAGEN
                Por.Posicion.x = 200;
                Por.Posicion.y = (p_limite_y / 2) + 200;
                DrawTextureEx(Por.TexturaC, Por.Posicion, 0.0f, 15.0f, WHITE);

                // Tropas------------------------------------------------------------------------------------PENDIENTE

                // Rectangulo
                Rectangle block3 = {50, (p_limite_y / 2) - 220, 600, 400};
                DrawRectangleRec(block3, b_colorgray);

                // Texto
                DrawText("Mientras que 3500 soldados\n\n\nDe infantería y una brigada\n\n\nDe caballería se distribuyeron\n\n\nEn distintas posiciones \n\n\ndefensivas\n\n\nUna de ellas la comandaba\n\n\nPorfirio Díaz", 70, (p_limite_y / 2) - 200, 35, BLACK);
            }
            if ((IsMouseButtonPressed(MOUSE_BUTTON_LEFT) || IsKeyPressed(KEY_E)) && run_esc == C2_e4)
            {
                PlaySound(fxButton);
                run_esc = C2_e5;
                EndDrawing();
            }
            //---------------------------Escena 5---------------------------
            if (run_esc == C2_e5)
            {
                // Fondo
                DrawTextureEx(C2_F5.TexturaC, C2_F5.Posicion, 0.0f, 8.0f, WHITE);

                // Porifirio
                Por.Posicion.x = 200;
                Por.Posicion.y = (p_limite_y / 2) + 100;
                DrawTextureEx(Por.TexturaC, Por.Posicion, 0.0f, 20.0f, WHITE);

                // Rectangulo
                Rectangle block3 = {70, 50, 1200, 200};
                DrawRectangleRec(block3, b_colorgray);

                // Texto
                DrawText("Los franceses salieron de Amozoc hacia Puebla y dividieron sus tropas\n\n\nuna primera columna de alrededor de 4000 hombres protegida por la \n\n\nartillería avanzó sobre los fuertes, en los que el ejército mexicano era\n\n\nmás fuerte, la columna restante permaneció en la reserva", 90, 70, 30, WHITE);
            }
            if ((IsMouseButtonPressed(MOUSE_BUTTON_LEFT) || IsKeyPressed(KEY_E)) && run_esc == C2_e5)
            {
                PlaySound(fxButton);
                exitbucle = true;
                EndDrawing();
            }
        }
        EndDrawing();
    }
    return true;
}

bool RunCimeatica3(int p_limite_x, int p_limite_y, bool togle)
{
    bool exitbucle = false;
    enum escenas current_esc = C3_e1;
    // Colores
    Color b_colorgray = Fade(GRAY, 0.7f);
    Color b_colorwhite = Fade(WHITE, 0.7f);
    Color b_colorblack = Fade(BLACK, 0.7f);

    while (!exitbucle)
    {
        if (togle)
            SetMusicVolume(C3M_F, 1.0f);
        PlayMusic(C3M_F);
        BeginDrawing();
        {
            //----------------------------------------------Escena 1-----------------------------------------------
            if (current_esc == C3_e1)
            {
                // fondo
                DrawTextureEx(C3_F1.TexturaC, C3_F1.Posicion, 0.0f, 8.0f, WHITE);

                // Rectangulo
                Rectangle block5 = {p_limite_x - 520, 180, 500, 270};
                DrawRectangleRec(block5, b_colorblack);

                // texto
                DrawText("Una vez todas\n\n\nlas tropas armadas en posición\n\n\nEstaban todos listos para\n\n\nLa batalla", p_limite_x - 500, 200, 30, WHITE);
            }
            if ((IsMouseButtonPressed(MOUSE_BUTTON_LEFT) || IsKeyPressed(KEY_E)) && current_esc == C3_e1)
            {
                PlaySound(fxButton);
                current_esc = C3_e2;
                EndDrawing();
            }
            //----------------------------------------------Escena 2-----------------------------------------------
            if (current_esc == C3_e2)
            {
                // fondo
                ClearBackground(BLACK);

                // texto
                DrawText("La batalla comenzó a las", (p_limite_x / 2) - 500, (p_limite_y / 2) - 150, 80, WHITE);
                DrawText("11:15 AM", (p_limite_x / 2) - 120, (p_limite_y / 2) - 70, 80, RED);
                DrawText("5 de mayo", (p_limite_x / 2) - 180, (p_limite_y / 2), 80, RED);
            }
            if ((IsMouseButtonPressed(MOUSE_BUTTON_LEFT) || IsKeyPressed(KEY_E)) && current_esc == C3_e2)
            {
                PlaySound(fxButton);
                exitbucle = true;
                EndDrawing();
            }
        }
        EndDrawing();
    }
    return true;
}

bool finalCinematica(int p_limite_x, int p_limite_y, bool togle)
{
    bool exitbucle = false;
    enum escenas current_esc = C4_e1;

    float mitady = p_limite_y / 2;
    float mitadx = p_limite_x / 2;

    // Colores
    Color b_colorgray = Fade(GRAY, 0.7f);
    Color b_colorwhite = Fade(WHITE, 0.7f);
    Color b_colorblack = Fade(BLACK, 0.7f);

    while (!exitbucle)
    {
        BeginDrawing();
        {
            ClearBackground(BLACK);
            // Escena 1----------------------------
            if (current_esc == C4_e1)
            {
                DrawTextureEx(C4_F1.TexturaC, C4_F1.Posicion, 0.0f, 1.5f, WHITE);

                Rectangle block = {100, 100, 480, 500};
                DrawRectangleRec(block, b_colorgray);

                DrawText("El ataque de las tropas\n\n\nde Lorencez fue repelido\n\n\npor la infantería la\n\n\nartillería y la caballería\n\n\nmexicanas, los franceses\n\n\nno lograron avanzar\n\n\nretrocedieron a los Álamos\n\n\ndesde donde se\n\n\nretiraron hacia Amozoc", 120, 120, 30, WHITE);
            }
            if ((IsMouseButtonPressed(MOUSE_BUTTON_LEFT) || IsKeyPressed(KEY_E)) && current_esc == C4_e1)
            {
                current_esc = C4_e2;
                EndDrawing();
            }

            // Escena 2-----------------------------
            if (current_esc == C4_e2)
            {
                DrawText("La batalla terminó a las 5:49PM", mitadx - 230, mitady - 70, 30, WHITE);
                DrawText("Con la victoria de mexico", mitadx - 300, mitady, 50, GREEN);
            }
            if ((IsMouseButtonPressed(MOUSE_BUTTON_LEFT) || IsKeyPressed(KEY_E)) && current_esc == C4_e2)
            {
                current_esc = C4_e3;
                EndDrawing();
            }

            // Escena 3----------------------
            if (current_esc == C4_e3)
            {
                DrawTextureEx(C4_F2.TexturaC, C4_F2.Posicion, 0.0f, 1.3f, WHITE);

                DrawText("MUCHAS GRACIAS POR JUGAR", 200, 120, 50, WHITE);
                DrawText("Programadores\n\n\nFernando Haro Calvo\n\n\nAdan Gonzalez Ceseña\n\n\nGrupo : 932\n\n\nCrado con raylib en C", 200, 200, 30, WHITE);
            }
            if ((IsMouseButtonPressed(MOUSE_BUTTON_LEFT) || IsKeyPressed(KEY_E)) && current_esc == C4_e3)
            {
                exitbucle = true;
                EndDrawing();
            }
        }
        EndDrawing();
    }
    return true;
}