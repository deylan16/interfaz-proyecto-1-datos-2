//
// Created by deylan on 29/9/21.
//

#ifndef INTERFAZ_PROYECTO_1_DATOS_2_VENTANA_H
#define INTERFAZ_PROYECTO_1_DATOS_2_VENTANA_H


#include "Bloqueg.h"
#include "bolas.h"

class ventana {
public:
    float xball = 200;
    float yball = 300;
    float direccionx = .6f;
    float posxBarra = 250;
    float direcciony = .6f;
    Bloqueg filas[6][13];
    bolas grupopelotas[6];



    void juego();
    void menu();
    void dibujabloques();
    void dibujabloques2();
    //bool chocabloque(int xd, int xi, int ya, int yb );

};


#endif //INTERFAZ_PROYECTO_1_DATOS_2_VENTANA_H
