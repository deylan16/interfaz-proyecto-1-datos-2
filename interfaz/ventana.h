//
// Created by deylan on 29/9/21.
//

#ifndef INTERFAZ_PROYECTO_1_DATOS_2_VENTANA_H
#define INTERFAZ_PROYECTO_1_DATOS_2_VENTANA_H


#include <string>
#include "Bloqueg.h"
#include "bolas.h"

class ventana {
public:
    float velocidadball= .6f;
    float xball = 0;
    float yball = 450;
    float direccionx = velocidadball;
    float posxBarra = 250;
    float tamanobarrax = 100.f;
    float direcciony = 0;
    bool modoprofundo = false;
    void menu();
    int vidaball = 3;
    int gradobarra = 0;
    void colisionbarra();
    bool barra90 = false;
    sf::RectangleShape barra;
    std::string puntos =  "0";
    Bloqueg filas[6][13];



    void juego();
    void girabarra();
    void girabarra2();
    void dibujabloques();
    void dibujabloques2();
    bool chocabloque(int xd, int xi, int ya, int yb );

};


#endif //INTERFAZ_PROYECTO_1_DATOS_2_VENTANA_H
