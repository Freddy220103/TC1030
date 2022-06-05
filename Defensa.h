//
// Creado por Alfredo Gómez Mendoza el 27/05/2022.
//
#ifndef DEFENSA_H_
#define DEFENSA_H_
#include<iostream>
#include <string>
#include <sstream>
#include "Monstruo.h"
using namespace std;

class Defensa{
protected:
    string nombre;
    int vida;
    int fuerza;
    int rango;
    string estado;
public:

    Defensa(){};
    Defensa(string nom, int vid, int fuerz, int rang, string estad)
    :nombre(nom),vida(vid),fuerza(fuerz),rango(rang){};
    virtual string get_stats();
    string disparar();
    void herirse();
    void activar_escudo();

};

string Defensa::disparar(){
    stringstream aux;
    aux<<"la defensa ha disparado"<<endl;
    return aux.str();
};
string Defensa::get_stats() {
    stringstream aux;
    aux<< "Nombre: "<<nombre<<"\nVida: "<<vida<<"\nFuerza: "<<fuerza<<"\nRango: "<<rango<<"\nEstado:"<<estado;
    return aux.str();


};

void Defensa::activar_escudo(){
    //herirse(danio);
    //danio=0;
    cout<<"La defensa ha activado su escudo"<<endl;

};
void Defensa::herirse(){
    cout<<"me dañaste, oh nooo";
    //vida-fuerza del monstruo que ataca
};

class Torreta:public Defensa{
private:
    int turnos_congelamiento;
    int ralentizar;
public:
    string get_stats();
    Torreta():Defensa("Torreta de hielo", 50, 2, 9,"vivo"){};
    Torreta(string nom, int vid, int fuerz, int rang, string estad)
    : Defensa(nom, vid, fuerz, rang,estad){
        nombre=nom;
        vida=vid;
        fuerza=fuerz;
        rango=rang;
        estado=estad;
        ralentizar=10;

    };
            //:Defensa(nombre,vida,fuerza,rango),turnos_congelamiento(turnos), retroceso(retro){};
};
    string Torreta::get_stats() {
        stringstream aux;
        aux<< "Nombre: "<<nombre<<"\nVida: "<<vida<<"\nFuerza: "<<fuerza<<"\nRango: "<<rango<<"\nRetroceso"<<ralentizar;
        return aux.str();
    }
class Transporte:public Defensa{
private:
    int cooldown;
public:
    string get_stats();
    string disparar();
    Transporte():Defensa("Transporte de misiles", 90, 12, 12,"vivo"){};
    Transporte(string nom, int vid, int fuerz, int rang,string estad)
    : Defensa(nom, vid, fuerz, rang,estad){
        nombre=nom;
        vida=vid;
        fuerza=fuerz;
        rango=rang;
        estado=estad;
        cooldown=0;

    };
};
    string Transporte::get_stats() {
        stringstream aux;
        aux<< "Nombre: "<<nombre<<"\nVida: "<<vida<<"\nFuerza: "<<fuerza<<"\nRango: "<<rango<<"Cooldown: "<<cooldown;;
        return aux.str();
    }
    string Transporte::disparar(){
    cooldown=2;
    stringstream aux;
    if (cooldown % 2==0){
        aux<<"El transporte ha disparado"<<endl;
        //monstruo->herirse();
    }
    else{
        aux<<"El transporte de misiles intentó atacar pero tiene que recargar"<<endl;
    }
    return aux.str();
};

#endif
