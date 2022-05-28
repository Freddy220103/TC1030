//
// Creado por Alfredo Gómez Mendoza el 27/05/2022.
//
#ifndef RAMPAGE_TORRETA_H
#define RAMPAGE_TORRETA_H
#include "Defensa.h"

class Torreta:public Defensa{
private:
    int turnos_congelamiento;
    int retroceso;
    void activar_escudo();
public:
    Torreta():Defensa("Torreta de hielo", 50, 2, 9){};
    Torreta(string nombre, int vida, int fuerza, int rango, int turnos, int retro)
    :Defensa(nombre,vida,fuerza,rango),turnos_congelamiento(turnos), retroceso(retro){};
};
#endif
