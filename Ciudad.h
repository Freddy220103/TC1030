//
// Creado por Alfredo Gómez Mendoza el 27/05/2022.
//
#ifndef CIUDAD_H_
#define CIUDAD_H_
#include "Defensa.h"
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
    crear_defensas();
    }
    int get_numero();
    void set_destruccion(int dest);
    void get_citystats();//listo
    void get_defensas();//listo
    int get_porcentaje();
    string get_nombre();
};
void Ciudad::set_destruccion(int dest){
    porcentaje_destruccion=porcentaje_destruccion+dest;
}
void Ciudad::crear_defensas() {
    int i;
    i=2;
    while (numero<8){
        defe[numero] = new Torreta("Torreta de hielo", 50, 2, 9,"vivo");
        numero++;
        defe[numero] = new Transporte("Transporte misiles", 90, 12, 12,"vivo");
        numero++;
    }
    cout<<"La ciudad intentó crear otra defensa, pero ya no tiene recursos"<<endl;

};
int Ciudad::get_numero(){
    return numero;
}
string Ciudad::get_nombre(){
    return nombre;
}
void Ciudad::get_defensas(){
    for (int i = 0; i<numero; i++){
        cout<<"Defensa: "<<i+1<<endl;
        cout<<defe[i] -> get_stats()<<endl;
        cout<<"---------------------"<<endl;
        cout<<" \n";
    }
}

void Ciudad::get_citystats(){
    cout<<"Porcentaje de ciudad destruido: "<<porcentaje_destruccion<<endl;
}
int Ciudad::get_porcentaje(){
    return porcentaje_destruccion;
}


#endif
