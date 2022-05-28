//
// Creado por Alfredo Gómez Mendoza el 27/05/2022.
//

#ifndef RAMPAGE_ASESINO_H
#define RAMPAGE_ASESINO_H
#include "Monstruo.h"
class Asesino:public Monstruo{
private:
    int torres_destruidas;

public:
    Asesino(){};
    Asesino(string nom, int vid, int fuerz, int rang):nombre(nom),vida(vid),fuerza(fuerz),rango(rang){};

    void ataque(int *ptrvidadef);
    void mareo(Defensa *defensa);
#endif //RAMPAGE_ASESINO_H
    
    void Asesino::ataque(int *ptrvidadef){
        i=0;
        while(torres_destruidas>=i)
            *ptrvidadef-fuerza;
            i++;
    };
