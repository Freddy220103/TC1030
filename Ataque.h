/*
 *
 * Proyecto Rampage clase Ataque
 * Alfredo Gómez Mendoza
 * A01704189
 * 16/06/2022
 * version : 4
 * La clase define objetos de tipo Ataque que contiene las demás clases que son Ciudad, Defensa y Monstruo.
 * Esta clase tiene el objetivo de evitar una dependencia circular, ya que las 3 clases antes mencionadas interactuan
 * entre sí. Con lo anterior los objetos de tipo ataque pueden llamar métodos para modificar atributos de las clases
 * Ciudad, Defensa y Monstruo.
 */
#ifndef RAMPAGE_ATAQUE_H
#define RAMPAGE_ATAQUE_H
#include <iostream>
#include "Ciudad.h"
#include "Defensa.h"
#include "Monstruo.h"
using namespace std;

//Declaracion de clase ataque
class Ataque{
private:
    //Declaro variables que se usaran dentro de los métodos
    int i=0;
    //Declaro los métodos que va a tener el objeto
public:
    Ataque(){};//constructor por default
    void destruir_ciudad(Ciudad *ciudad, Monstruo *monstruo);
    void ataque(Ciudad *ciudad, Monstruo *monstruo, int i);
    void ataque_especial(Ciudad *ciudad, Monstruo *monstruo,int i2);
    void disparar(Ciudad *ciudad, Monstruo *monstruo, int i3);
    void transporte_disparar(Transporte *transporte, Monstruo *monstruo);
};

/**
 * destruir_ciudad llama un método de ciudad
 *|
 * El método llama el método destruir_ciudad() de un objeto monstruo tipo apuntador, también llama el método
 * set_destruccion de un objeto ciudad. Al llamarlo pone como parámetro el método de monstruo llamado get_fuerza().
 * También saca a la consola un mensaje junto con lo que regresa el método get_porcentaje() de un objeto ciudad.
 * Al final mediante un if statement checa si lo que regresa el método get_porcentaje de un objeto ciudad es igual a 100.
 * Si esto se cumple, regresa otro mensaje.
 *
 * @param Ciudad  del objeto apuntador ciudad, Monstruo del objeto apuntador monstruo
 * @return
 */

void Ataque::destruir_ciudad(Ciudad *ciudad, Monstruo *monstruo){
    monstruo->destruir_ciudad();
    ciudad->set_destruccion(monstruo->get_fuerza());
    cout<<"El porcentaje de destruccion actual es de:"<<ciudad->get_porcentaje();
    cout<<"\n";
    if(ciudad->get_porcentaje()==100){
        cout<<"El monstruo ha dado el último golpe a la ciudad"<<endl;
    }
}

/**
 * ataque llama un método de monstruo y defensa
 *
 * Llama el método del objeto monstruo apuntador de los parámetros. También llama un método de un objeto tipo defensa
 * y mete como parámetro el método del objeto monstruo apuntador. El objeto defensa lo saca de un array que esta en
 * el objeto apuntador tipo ciudad.
 *
 * @param Ciudad del objeto apuntador ciudad, Monstruo del objeto apuntador monstruo, entero i2
 * @return
 */
void Ataque::ataque(Ciudad *ciudad, Monstruo *monstruo, int i){
    monstruo->ataque();
    ciudad->defe[i]->herirse(monstruo->get_fuerza());
};

/**
 * ataque_especial llama un método de monstruo y defensa
 *
 * Llama el método del objeto monstruo apuntador de los parámetros. También llama un método de un objeto tipo defensa
 * y mete como parámetro el método del objeto monstruo apuntador. El objeto defensa lo saca de un array que esta en
 * el objeto apuntador tipo ciudad. También tiene un if statement en el caso que el monstruo tenga el atributo asesino
 * como 1. En este caso en vez de llamar el método herirse de un objeto defensa, llama el método mareado.
 *
 * @param Ciudad del objeto apuntador ciudad, Monstruo del objeto apuntador monstruo, entero i2
 * @return
 */

void Ataque::ataque_especial(Ciudad *ciudad, Monstruo *monstruo, int i2){
    monstruo->ataque_especial();
    monstruo->ataque();
    ciudad->defe[i2]->herirse(monstruo->get_fuerza());
    if (monstruo->es_asesino==1){
        ciudad->defe[i2]->mareado+=7;
    }
}

/**
 * disparar llama un método de monstruo y defensa
 *
 * Llama el método mareo() del objeto defensa apuntador que viene desde el objeto apuntador ciudad de los parámetros.
 * También tiene un if statement en el cúal si se cumple la condición llama un método de un objeto tipo monstruo
 * y mete como parámetro a la variable force.
 *
 * @param Ciudad del objeto apuntador ciudad, Monstruo del objeto apuntador monstruo, entero i3
 * @return
 */

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

#endif //RAMPAGE_ATAQUE_H

