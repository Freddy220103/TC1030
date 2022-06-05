//
// Creado por Alfredo Gómez Mendoza el 27/05/2022.
//
#ifndef MONSTRUO_H_
#define MONSTRUO_H_

#include<iostream>
#include "Ciudad.h"


using namespace std;

class Monstruo{
protected:
    string nombre;
    int vida;
    int fuerza;
    int rango;

public:
    Monstruo(){};
    Monstruo(string nom, int vid, int fuerz, int rang):nombre(nom),vida(vid),fuerza(fuerz),rango(rang){};
    void ataque();
    void moverse();
    void estadisticas_monstruo();
    void herirse();
    string get_nombre();
    void destruir_ciudad(Ciudad *ciudad);
    void ataque_especial();

};
string Monstruo::get_nombre() {
    return nombre;
}
void Monstruo::ataque(){
    cout<<"tu monstruo ha atacado"<<endl;
};

void Monstruo::destruir_ciudad(Ciudad *ciudad){
    cout<<nombre<<" ha atacado la ciudad"<<endl;
    ciudad->set_destruccion(fuerza);
    cout<<"El porcentaje de destruccion actual es de:"<<ciudad->get_porcentaje();
    cout<<"\n";
    if(ciudad->get_porcentaje()==100){
        cout<<"El monstruo ha dado el último golpe a la ciudad"<<endl;
    }
}
void Monstruo::herirse(){
    cout<<"Han herido tu monstruo"<<endl;

    //vida-fuerza de la defensa
};
void Monstruo::estadisticas_monstruo(){
    cout<<"Turno de monstruo:"<<nombre<<endl;
    cout<<"     Vida: "<<vida<<endl;
    cout<<"     Fuerza: "<<fuerza<<endl;
    cout<<"     Rango: "<<rango<<endl;
}

void Monstruo::ataque_especial(){
    cout<<"El ataque especial ha iniciado"<<endl;
}
class Asesino:public Monstruo {
private:
    int torres_destruidas;
    int i;
public:
    Asesino(){};

    Asesino(string nom, int vid, int fuerz, int rang) : Monstruo(nom, vid, fuerz, rang){
        nombre=nom;
        vida=vid;
        fuerz=fuerza;
        rango=rang;
    };

    void ataque();

    void ataque_especial();
};

void Asesino::ataque(){
    i=0;
    int resultado;
    while(torres_destruidas>=i)
        resultado=fuerza+torres_destruidas;
    cout<<"el asesino ha atacado"<<endl;
    i++;
};
void Asesino::ataque_especial() {
    cout<<get_nombre()<<" ha iniciado el ataque mareo"<<endl;
}
class Tanque:public Monstruo {
private:
    int rango_escudo;
public:
    Tanque(){};

    Tanque(string nom, int vid, int fuerz, int rang) : Monstruo(nom, vid, fuerz, rang){
        nombre=nom;
        vida=vid;
        fuerz=fuerza;
        rango=rang;
    };

    void moverse();

    void proteger();

    void ataque_especial();
};

void Tanque::proteger(){
    cout<<"El monstruo se ha protegido"<<endl;
}

void Tanque::ataque_especial() {
    cout<<"El ataque destructor se ha iniciado"<<endl;
}
#endif
