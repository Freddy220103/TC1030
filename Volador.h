//
// Creado por Alfredo Gómez Mendoza el 27/05/2022.
//

#ifndef RAMPAGE_VOLADOR_H
#define RAMPAGE_VOLADOR_H
#include "Monstruo.h"
class Volador:public Monstruo{
private:
    int rango_curacion;

public:
    Volador(){};
    Volador(string nom, int vid, int fuerz, int rang):nombre(nom),vida(vid),fuerza(fuerz),rango(rang){};

    void ataque(int *ptrvidadef);
    void moverse();
    void volar_y_huir();
    void curar(Monstruo *monstruo);
    void curarse();
#endif //RAMPAGE_VOLADOR_H
