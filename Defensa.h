//
// Created by Usuario on 05/06/2022.
//

#ifndef DEFENSA_H_
#define DEFENSA_H_
#include <string>
#include <sstream>
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
    void disparar();
    void herirse(int fuerza);
    void activar_escudo();
    void set_fuerza(int fuerz);
    int get_fuerza();
    Defensa& operator= (const Defensa&);

};
int Defensa::get_fuerza(){
    return fuerza;
}
void Defensa::set_fuerza(int fuerz) {
    fuerza=fuerza-fuerz;
}
void Defensa::disparar(){
    cout<<" Ha disparado"<<endl;
};
string Defensa::get_stats() {
    stringstream aux;
    aux<< "Nombre: "<<nombre<<"\nVida: "<<vida<<"\nFuerza: "<<fuerza<<"\nRango: "<<rango<<"\nEstado:"<<estado;
    return aux.str();


};

void Defensa::activar_escudo(){
    //herirse(danio);
    //danio=0;
    cout<<" ha activado su escudo"<<endl;

};
void Defensa::herirse(int fuerz){
    cout<<"Has daniado a la defensa"<<endl;
    vida=vida-fuerz;
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
    aux<< "Nombre: "<<nombre<<"\nVida: "<<vida<<"\nFuerza: "<<fuerza<<"\nRango: "<<rango<<"\nRetroceso: "<<ralentizar;
    return aux.str();
}
class Transporte:public Defensa{
private:
    int cooldown;
public:
    string get_stats();
    string disparar();
    int get_cooldown();
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
    aux<< "Nombre: "<<nombre<<"\nVida: "<<vida<<"\nFuerza: "<<fuerza<<"\nRango: "<<rango<<"\nCooldown: "<<cooldown;;
    return aux.str();
}
string Transporte::disparar(){
    stringstream aux;
    if (cooldown==0){
        aux<<"El transporte ha disparado"<<endl;
        //monstruo->herirse();
        cooldown=1;
    }
    else{
        aux<<"El transporte de misiles intentó atacar pero tiene que recargar"<<endl;
        cooldown=0;
    }
    return aux.str();
};
int Transporte::get_cooldown() {
    return cooldown;
}

Defensa& Defensa::operator = (const Defensa& param)
{
    return *this;
}

#endif //RAMPAGE_DEFENSA_H

