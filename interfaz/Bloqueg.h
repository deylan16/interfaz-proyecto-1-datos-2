//
// Created by deylan on 29/9/21.
//

#include <SFML/Graphics/RectangleShape.hpp>

#ifndef INTERFAZ_PROYECTO_1_DATOS_2_BLOQUEG_H
#define INTERFAZ_PROYECTO_1_DATOS_2_BLOQUEG_H


class Bloqueg {
public:
    int x =0;
    int y= 0;
    bool destruido = true;
    sf::RectangleShape bloque;

    void setcoords(int x,int y);
    int getx();
    int gety();
    bool getdestruido();
    void setdestruido(bool destru);
    void setBloque(sf::RectangleShape bloque2);
    sf::RectangleShape getBloque();


};
#endif //INTERFAZ_PROYECTO_1_DATOS_2_BLOQUEG_H