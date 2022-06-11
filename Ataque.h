//
// Creado por Alfredo Gómez Mendoza el 07/06/2022.
//

#ifndef RAMPAGE_ATAQUE_H
#define RAMPAGE_ATAQUE_H
#include <iostream>
#include "Ciudad.h"
#include "Defensa.h"
#include "Monstruo.h"
using namespace std;

class Ataque{
private:
    int i=0;
public:
    void destruir_ciudad(Ciudad *ciudad, Monstruo *monstruo);
    void ataque(Defensa *defensa, Monstruo *monstruo);
    void ataque_especial(Defensa *defensa, Monstruo *monstruo);
    void disparar(Defensa *defensa, Monstruo *monstruo);
    void transporte_disparar(Transporte *transporte, Monstruo *monstruo);
    void ordenar_ataque(Ciudad *ciudad, Monstruo &monstruo, int i2);
};
//PARTE DE MONSTRUO
void Ataque::destruir_ciudad(Ciudad *ciudad, Monstruo *monstruo){
    cout<<monstruo->get_nombre()<<" ha atacado la ciudad"<<endl;
    ciudad->set_destruccion(monstruo->get_fuerza());
    cout<<"El porcentaje de destruccion actual es de:"<<ciudad->get_porcentaje();
    cout<<"\n";
    if(ciudad->get_porcentaje()==100){
        cout<<"El monstruo ha dado el último golpe a la ciudad"<<endl;
    }
}
void Ataque::ataque(Defensa *defensa, Monstruo *monstruo){
    monstruo->ataque();
    defensa->herirse(monstruo->get_fuerza());
};

void Ataque::ataque_especial(Defensa *defensa, Monstruo *monstruo){
    monstruo->ataque_especial();
    if (i%2==0){
        monstruo->ataque();
        i=i+3;
    }
    else{
        cout<<"El ataque no pudo ser realizado porque aún no está cargado";
    }
}

void Ataque::disparar(Defensa *defensa, Monstruo *monstruo){
    defensa->disparar();
    int force;
    force= defensa->get_fuerza();
    monstruo->herirse(force);
}

/*void Ataque::transporte_disparar(Transporte *transporte, Monstruo *monstruo){
    transporte->disparar();
    int cools;
    cools=transporte->get_cooldown();
    if(cools==0){
        transporte->disparar();
    }
}
*/
void Ataque::ordenar_ataque(Ciudad*ciudad, Monstruo &monstruo, int i2) {

    if (i % 2 == 0) {
            cout<<"La defensa #"<<i2+1;
            disparar(ciudad->defe[i2], &monstruo);
            i=i+9;
        }
        else {
            cout<<"La defensa #"<<i2+1;
            ciudad->defe[i2]->activar_escudo();
            i=i+=9;

        }
}
#endif //RAMPAGE_ATAQUE_H
