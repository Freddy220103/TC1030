//
// Created by Usuario on 07/06/2022.
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
    void ataque(Ciudad *ciudad, Monstruo *monstruo, int i);
    void ataque_especial(Ciudad *ciudad, Monstruo *monstruo,int i2);
    void disparar(Ciudad *ciudad, Monstruo *monstruo, int i3);
    void transporte_disparar(Transporte *transporte, Monstruo *monstruo);
    void ordenar_ataque(Ciudad *ciudad, Monstruo &monstruo, int i2);
};
//PARTE DE MONSTRUO
void Ataque::destruir_ciudad(Ciudad *ciudad, Monstruo *monstruo){
    monstruo->destruir_ciudad();
    ciudad->set_destruccion(monstruo->get_fuerza());
    cout<<"El porcentaje de destruccion actual es de:"<<ciudad->get_porcentaje();
    cout<<"\n";
    if(ciudad->get_porcentaje()==100){
        cout<<"El monstruo ha dado el último golpe a la ciudad"<<endl;
    }
}
void Ataque::ataque(Ciudad *ciudad, Monstruo *monstruo, int i){
    monstruo->ataque();
    ciudad->defe[i]->herirse(monstruo->get_fuerza());
};

void Ataque::ataque_especial(Ciudad *ciudad, Monstruo *monstruo, int i2){
    monstruo->ataque_especial();
    monstruo->ataque();
    ciudad->defe[i2]->herirse(monstruo->get_fuerza());
    if (monstruo->es_asesino==1){
        ciudad->defe[i2]->mareado+=7;
    }
}

void Ataque::disparar(Ciudad *ciudad, Monstruo *monstruo,int i3){
    ciudad->defe[i3]->mareo();
    int force;
    if (ciudad->defe[i3]->mareado%2!=0){
        force= ciudad->defe[i3]->get_fuerza();
        monstruo->herirse(force);
    }

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
/*void Ataque::ordenar_ataque(Ciudad*ciudad, Monstruo &monstruo, int i2) {

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
}*/
#endif //RAMPAGE_ATAQUE_H

