//
// Creado por Alfredo Gómez Mendoza el 27/05/2022.
//

#ifndef CIUDAD_H_
#define CIUDAD_H_
#include "Torreta.h"
#include<iostream>
using namespace std;

class Ciudad{
private:
    int porcentaje_destruccion;
    int porcentaje_generación_defensas;
    int tamanio[3];
    Defensa defensas[8];
    i=1;
    void crear_defensas();
public:
    Ciudad(){};
    void get_citystats();

    Defensa get_defensas();
};

void Ciudad::crear_defensas() {
    if (i<9){
        if(i%2!=0){
            defensas[i]=Torreta();
        }
        else{
            defensas[i]=Transporte();
        }
        i++;
    }
    else{
        cout<<"La ciudad intentó crear otra defensa, pero ya no tiene recursos"<<endl;
    }

}
void Defensa::get_citystats(){
    cout<<"Porcentaje de ciudad destruído: "<<porcentaje_destruccion<<endl;
    cout<<"Porcentaje de generación: "<<porcentaje_generacion<<endl;
}
#endif
