//
// Created by deylan on 29/9/21.
//

#include <SFML/Graphics/RenderWindow.hpp>
#include "bolas.h"

void bolas::mover(float posxBarra) {



}

void bolas::mueve(float posxBarra) {
    sf::CircleShape shape2(7.f);
    shape2.setFillColor(sf::Color::Green);
    shape = shape2;
    yball += direcciony;
    xball += direccionx;
    if (xball > 486.f)
        direccionx = -.6f;
    if (0.f > xball)
        direccionx = .6f;
    if (yball+14 > 450 && xball > posxBarra && posxBarra+100 > xball)
        direcciony = -.6f;
    if (0 >yball )
        direcciony += .6f;

}
