//
// Creado por Alfredo Gómez Mendoza el 27/05/2022.
//
#ifndef RAMPAGE_TANQUE_H
#define RAMPAGE_TANQUE_H
#include "Monstruo.h"
class Tanque:public Monstruo{
private:
    int rango_escudo;
public:
    Tanque(){};
    Tanque(string nom, int vid, int fuerz, int rang):nombre(nom),vida(vid),fuerza(fuerz),rango(rang){};

    void ataque(int *ptrvidadef);
    void moverse();
    void proteger();
    void ataque_destructor();
#endif //RAMPAGE_TANQUE_H
