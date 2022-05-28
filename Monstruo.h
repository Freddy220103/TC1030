//
// Creado por Alfredo Gómez Mendoza el 27/05/2022.
//

#ifndef MONSTRUO_H
#define MONSTRUO_H
#include<iostream>
#include "Ciudad.h"
#include "Defensa.h";
using namespace std;

class Monstruo{
protected:
    string nombre;
    int vida;
    int fuerza;
    int posicion[3];
    int rango;

public:
    Monstruo(){};
    Monstruo(string nom, int vid, int fuerz, int rang):nombre(nom),vida(vid),fuerza(fuerz),rango(rang){};

    void ataque(int *ptrvidadef);
    void moverse();
    //void destruir(Ciudad *ciudad);
    void estadísticas_personaje();

};

void Monstruo::ataque(int *ptrvidadef){
    *ptrvidadef-fuerza;
};
#endif
