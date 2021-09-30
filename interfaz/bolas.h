//
// Created by deylan on 29/9/21.
//

#ifndef INTERFAZ_PROYECTO_1_DATOS_2_BOLAS_H
#define INTERFAZ_PROYECTO_1_DATOS_2_BOLAS_H


#include <SFML/Graphics/CircleShape.hpp>

class bolas {
public:
    float xball = 200;
    float yball = 300;
    float direccionx = .6f;
    //float posxBarra = 250;
    float direcciony = .6f;
    sf::CircleShape shape;

    void mover(float posxBarra);
    void mueve(float posxBarra);



};


#endif //INTERFAZ_PROYECTO_1_DATOS_2_BOLAS_H
