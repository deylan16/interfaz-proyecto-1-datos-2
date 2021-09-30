//
// Created by deylan on 29/9/21.
//

#include "ventana.h"

#include "Bloqueg.h"
#include "Bloqueg.cpp"
#include "bolas.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <thread>
#include <iomanip>

bool dibujar = true;
bool dibujar2 =false;

sf::RenderWindow window(sf::VideoMode(500, 500), "SFML works!");
void ventana::juego() {
    int cronometro = 100;
    sf::Font font;
    font.loadFromFile("Minecrafter.ttf");
    sf::Text text;
    text.setFont(font);
    sf::CircleShape shape(7.f);
    shape.setFillColor(sf::Color::Green);
    sf::RectangleShape barra2(sf::Vector2f(tamanobarrax,20.f));
    barra= barra2;
    //Bolas bola1;
    //bola1.mover();
    bool perdio = false;
    while (window.isOpen())
    {
        sf::Event event{};
        int contador = 1;
        while (window.pollEvent(event))
        {

            if (event.type == sf::Event::Closed)
                window.close();
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
                posxBarra += 10.f;
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
                posxBarra -= 10.f;
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::P)){
                contador -= 1;
                if (contador == 0){
                    if (modoprofundo){
                        shape.setFillColor(sf::Color::Green);
                        modoprofundo = false;
                    }

                    else{
                        shape.setFillColor(sf::Color::Red);
                        modoprofundo = true;
                    }
                }




            }


        }

        window.clear();

        yball += direcciony;
        xball += direccionx;
        if (xball > 486.f)
            direccionx = -velocidadball;
        if (0.f > xball)
            direccionx = velocidadball;
        if (yball+14 > 450 && xball > posxBarra && posxBarra+100 > xball)
            direcciony = -velocidadball;
        if (yball + 14 > 460){
            direccionx = 0;
            direcciony = 0;
            xball = 0;
            yball = 0;
            tamanobarrax -= 10;
            barra.setSize(sf::Vector2f(tamanobarrax,20.f));
            perdio = true;
        }
        if (0 >yball )
            direcciony = velocidadball;
        if (perdio)
            text.setString("Perdiste"),text.setCharacterSize(40),text.setFillColor(sf::Color::Green),text.setPosition(0,350),window.draw(text);
        girabarra();
        //efecto de colision con bloques
        for(int i=0;i<6;i++){
            for(int j=0;j<13;j++){
                if (chocabloque(filas[i][j].getx()+38,
                                filas[i][j].getx(),
                                filas[i][j].gety(),
                                filas[i][j].gety()+20 ) &&
                    filas[i][j].getdestruido()  ){
                    filas[i][j].setcoords(-30,-30);
                    filas[i][j].setdestruido(false);

                }

            }
        }


        std::string labelpuntos ="Puntos "+ puntos;
        text.setString(labelpuntos),text.setCharacterSize(20),text.setFillColor(sf::Color::Green),text.setPosition(0,480),window.draw(text);








        if (dibujar){
            dibujabloques();

            dibujar = false;
            dibujar2 = true;
        }
        if (dibujar2){
            dibujabloques2();

        }

        shape.setPosition(xball,yball);
        barra.setPosition(posxBarra,450);
        window.draw(shape);
        window.draw(barra);

        window.display();
    }

}

void ventana::dibujabloques() {
    float x = 0;
    float y = 150;
    for(int i=0;i<6;i++){
        //Bloqueg columna[13];

        y -= 25;
        x = 0;
        for(int j=0;j<13;j++){
            sf::RectangleShape bloqueh(sf::Vector2f(38.f,20.f));
            bloqueh.setPosition(x,y);
            Bloqueg bloque;
            bloque.setBloque(bloqueh);
            bloque.setcoords(x,y);
            bloque.setcolor(2);
            if (bloque.getcolor() == 1)
                bloqueh.setFillColor(sf::Color::Blue);
            if (bloque.getcolor() == 2)
                bloqueh.setFillColor(sf::Color::Red);
            if (bloque.getcolor() == 3)
                bloqueh.setFillColor(sf::Color::Yellow);
            if (bloque.getcolor() == 4)
                bloqueh.setFillColor(sf::Color::Magenta);





            x += 39;
            window.draw(bloque.getBloque());
            window.display();
            filas[i][j]= bloque;


        }


    }

}

bool ventana::chocabloque(int xd, int xi, int ya, int yb ) {
    //xball,xball+14,yball+14,yba+14


    if (xd>xball && xball >xi && yb>yball+7 && yball+7>ya){
        direccionx = direccionx *-1.f;
        return true;

    }
    else
    if (xd>xball+7 && xball+7 >xi && yb>yball && yball>ya)
    {
        direcciony = direcciony *-1.f;
        return true;

    }
    else
    if (xd>xball+7 && xball+7 >xi && yb>yball+14 && yball+14>ya){
        direcciony = direcciony *-1.f;
        return true;


    }
    else
    if (xd>xball+14 && xball+14 >xi && yb>yball+7 && yball+7>ya){
        direccionx = direccionx *-1.f;
        return true;

    }
    else
        return false;


}

void ventana::dibujabloques2() {

    for(int i=0;i<6;i++){
        for(int j=0;j<13;j++){
            sf::RectangleShape bloqueh(sf::Vector2f(38.f,20.f));
            bloqueh.setPosition(filas[i][j].getx(),filas[i][j].gety());


            if (filas[i][j].getcolor() == 1)
                bloqueh.setFillColor(sf::Color::Blue);
            if (filas[i][j].getcolor() == 2)
                bloqueh.setFillColor(sf::Color::Red);
            if (filas[i][j].getcolor() == 3)
                bloqueh.setFillColor(sf::Color::Yellow);
            if (filas[i][j].getcolor() == 4)
                bloqueh.setFillColor(sf::Color::Magenta);
            filas[i][j].setBloque(bloqueh);
            window.draw(filas[i][j].getBloque());

        }
        //dibujar2 = false;
    }
}

void ventana::menu() {
    bool escribiendo = false;
    bool esnombre= false;
    bool esip= false;
    bool espuerto= false;
    std::string entrada ="";
    std::string nombre = "";
    std::string ip = "";
    std::string puerto = "";

    while (window.isOpen())
    {
        int contadorborrar = 1;
        int contadorborrar2 = 1;
        sf::Event event{};

        int mousex =sf::Mouse::getPosition(window).x;
        int mousey = sf::Mouse::getPosition(window).y;
        while (window.pollEvent(event))
        {

            if (event.type == sf::Event::Closed)
                window.close();
            if (50<mousex && mousex<50+25 && mousey<120+20 && mousey>120)
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                    escribiendo = true;
                    esip = true;
                    esnombre = false;
                    espuerto = false;
                }
            if (250<mousex && mousex<250+100 && mousey<250+20 && mousey>250)
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                    juego();

                }
            if (50<mousex && mousex<50+100 && mousey<50+20 && mousey>50)
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                    escribiendo = true;
                    esip = false;
                    esnombre = true;
                    espuerto = false;
                }
            if (50<mousex && mousex<50+90 && mousey<180+20 && mousey>180)
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                    escribiendo = true;
                    esip = false;
                    esnombre = false;
                    espuerto = true;
                }

            if (escribiendo){
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) ){
                    entrada.append("a");
                    contadorborrar = contadorborrar -1;
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::B) ){
                    entrada.append("b");
                    contadorborrar = contadorborrar -1;
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::C) ){
                    entrada.append("c");
                    contadorborrar = contadorborrar -1;
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) ){
                    entrada.append("d");
                    contadorborrar = contadorborrar -1;
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::E) ){
                    entrada.append("e");
                    contadorborrar = contadorborrar -1;
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::F) ){
                    entrada.append("f");
                    contadorborrar = contadorborrar -1;
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::G) ){
                    entrada.append("g");
                    contadorborrar = contadorborrar -1;
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::H) ){
                    entrada.append("h");
                    contadorborrar = contadorborrar -1;
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::I) ){
                    entrada.append("i");
                    contadorborrar = contadorborrar -1;
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::J) ){
                    entrada.append("j");
                    contadorborrar = contadorborrar -1;
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::K) ){
                    entrada.append("k");
                    contadorborrar = contadorborrar -1;
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::L) ){
                    entrada.append("l");
                    contadorborrar = contadorborrar -1;
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::M) ){
                    entrada.append("m");
                    contadorborrar = contadorborrar -1;
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::N) ){
                    entrada.append("n");
                    contadorborrar = contadorborrar -1;
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::O) ){
                    entrada.append("o");
                    contadorborrar = contadorborrar -1;
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::P) ){
                    entrada.append("p");
                    contadorborrar = contadorborrar -1;
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q) ){
                    entrada.append("q");
                    contadorborrar = contadorborrar -1;
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::R) ){
                    entrada.append("r");
                    contadorborrar = contadorborrar -1;
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) ){
                    entrada.append("s");
                    contadorborrar = contadorborrar -1;
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::T) ){
                    entrada.append("t");
                    contadorborrar = contadorborrar -1;
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::U) ){
                    entrada.append("u");
                    contadorborrar = contadorborrar -1;
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::V) ){
                    entrada.append("v");
                    contadorborrar = contadorborrar -1;
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) ){
                    entrada.append("w");
                    contadorborrar = contadorborrar -1;
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::X) ){
                    entrada.append("x");
                    contadorborrar = contadorborrar -1;
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Y) ){
                    entrada.append("y");
                    contadorborrar = contadorborrar -1;
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z) ){
                    entrada.append("z");
                    contadorborrar = contadorborrar -1;
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace) ){
                    if (contadorborrar2 == 0){
                        if (esip){
                            if (ip != "")
                                ip.pop_back();
                        }
                        if (esnombre){
                            if (nombre != "")
                                nombre.pop_back();
                        }
                        if (espuerto){
                            if (puerto != "")
                                puerto.pop_back();
                        }
                    }
                    else
                        contadorborrar2 = contadorborrar2-1;

                }
                if (contadorborrar == 0){
                    entrada.pop_back();

                }
                if (esip){
                    ip = ip+entrada;
                    entrada = "";
                }
                if (esnombre){
                    nombre = nombre+entrada;
                    entrada = "";
                }
                if (espuerto){
                    puerto = puerto+entrada;
                    entrada = "";
                }





            }


        }
        window.clear();


        //boton para nombre
        sf::RectangleShape bloqueh(sf::Vector2f(100.f,20.f));
        bloqueh.setPosition(50,50);
        if (50<mousex && mousex<50+100 && mousey<50+20 && mousey>50)
            bloqueh.setFillColor(sf::Color::Red);
        else
            bloqueh.setFillColor(sf::Color::Blue);
        //boton para ip
        sf::RectangleShape botonip(sf::Vector2f(25.f,20.f));
        botonip.setPosition(50,120);
        if (50<mousex && mousex<50+25 && mousey<120+20 && mousey>120)
            botonip.setFillColor(sf::Color::Red);
        else
            botonip.setFillColor(sf::Color::Blue);
        //boton para puerto
        sf::RectangleShape botonpuerto(sf::Vector2f(90.f,20.f));
        botonpuerto.setPosition(50,180);
        if (50<mousex && mousex<50+90 && mousey<180+20 && mousey>180)
            botonpuerto.setFillColor(sf::Color::Red);
        else
            botonpuerto.setFillColor(sf::Color::Blue);

        window.draw(bloqueh);
        window.draw(botonip);

        window.draw(botonpuerto);
        sf::Font font;
        font.loadFromFile("Minecrafter.ttf");
        sf::Text text;
        text.setFont(font);

        //para introducir nombre
        text.setString("Nombre"),text.setCharacterSize(20),text.setFillColor(sf::Color::Green),text.setPosition(50,50-2),window.draw(text);
        text.setString(nombre),text.setCharacterSize(20),text.setFillColor(sf::Color::Green),text.setPosition(50,80),window.draw(text);

        //para introducir ip
        text.setString("Ip"),text.setCharacterSize(20),text.setFillColor(sf::Color::Green),text.setPosition(50,120-2),window.draw(text);
        text.setString(ip),text.setCharacterSize(20),text.setFillColor(sf::Color::Green),text.setPosition(50,150),window.draw(text);

        //para introducir puerto
        text.setString("Puerto"),text.setCharacterSize(20),text.setFillColor(sf::Color::Green),text.setPosition(50,180-2),window.draw(text);
        text.setString(puerto),text.setCharacterSize(20),text.setFillColor(sf::Color::Green),text.setPosition(50,210),window.draw(text);

        //boton para nombre
        sf::RectangleShape botonaceptar(sf::Vector2f(100.f,20.f));
        botonaceptar.setPosition(250,250);
        if (250<mousex && mousex<250+100 && mousey<250+20 && mousey>250)
            botonaceptar.setFillColor(sf::Color::Red);
        else
            botonaceptar.setFillColor(sf::Color::Blue);
        window.draw(botonaceptar);




        window.display();
    }
}

void ventana::girabarra() {
    std::thread girabarra2();

}

void ventana::girabarra2() {
    barra.setRotation(90);
    barra.setPosition(posxBarra+50,450);

}

int main()
{   /*auto start = std::chrono::system_clock::now();
    // Some computation here
    auto end = std::chrono::system_clock::now();
    bool hi = true;
    int hola = 0;
    while(hi){
        std::chrono::duration<double> elapsed_seconds = end-start;
        hola = elapsed_seconds.count();
        if (hola == 1)
            hi = false;
    }

    std::time_t end_time = std::chrono::system_clock::to_time_t(end);

    std::cout << "finished computation at " << std::ctime(&end_time)
              << "elapsed time: " << hola<< "s\n";*/
    ventana juego;
    juego.menu();
}