//
// Creado por Alfredo Gómez Mendoza el 27/05/2022.
//

#ifndef CIUDAD_H_
#define CIUDAD_H_
#include "Defensa.h"
#include<iostream>
#include <string>
#include <sstream>
using namespace std;
const int maxdef = 8; //constante del tamaño de arreglos

class Ciudad{
private:
    string nombre;
    int numero;
    int porcentaje_destruccion;

    void crear_defensas();//listo
public:
    Defensa * defe[maxdef];
    Ciudad(string nom, int num, int destruccion){
    nombre=nom;
    numero=num;
    porcentaje_destruccion=destruccion;
    }
    void set_destruccion(int dest);
    void get_citystats();//listo
    void get_defensas();//listo
    int get_porcentaje();
    void ordenar_ataque();
};
void Ciudad::set_destruccion(int dest){
    porcentaje_destruccion+=dest;
}
void Ciudad::crear_defensas() {
    int i;
    i=2;
    if (numero<8){
        defe[numero] = new Torreta("Torreta de hielo", 50, 2, 9,"vivo");
        numero++;
        defe[numero] = new Transporte("Transporte misiles", 90, 12, 12,"vivo");
        numero++;
    }
    else{
        cout<<"La ciudad intentó crear otra defensa, pero ya no tiene recursos"<<endl;
    }

};

void Ciudad::get_defensas(){
    for (int i = 0; i<numero; i++)
        cout<<defe[i] -> get_stats();
}

void Ciudad::ordenar_ataque() {
    stringstream aux;
    for (int i = 0; i <numero; i++)
        aux<<defe[i] -> disparar();
}
void Ciudad::get_citystats(){
    cout<<"Porcentaje de ciudad destruido: "<<porcentaje_destruccion<<endl;
    //cout<<"Porcentaje de generación: "<<porcentaje_generacion<<endl;
}
int Ciudad::get_porcentaje(){
    return porcentaje_destruccion;
}
#endif
