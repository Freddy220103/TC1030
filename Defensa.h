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
    string estado;
public:
    int mareado;
    Defensa(){};
    Defensa(string nom, int vid, int fuerz,string estad)
            :nombre(nom),vida(vid),fuerza(fuerz){};
    virtual string get_stats();
    void disparar();
    void herirse(int fuerza);
    void activar_escudo();
    void set_fuerza(int fuerz);
    int get_fuerza();
    //Defensa& operator= (const Defensa&);
    void mareo();

};
int Defensa::get_fuerza(){
    return fuerza;
}
void Defensa::set_fuerza(int fuerz) {
    fuerza=fuerza-fuerz;
}
void Defensa::disparar(){
    cout<<" ha atacado"<<endl;
};
string Defensa::get_stats() {
    stringstream aux;
    aux<< "Nombre: "<<nombre<<"\nVida: "<<vida<<"\nFuerza: "<<fuerza<<"\nEstado:"<<estado;
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

void Defensa::mareo(){
    if (mareado%2==0){
        cout<<" fue mareada"<<endl;
        mareado+=7;
    }
    else{
        disparar();
    }
}

class Torreta:public Defensa{
private:
    int ralentizar;
public:
    string get_stats();
    Torreta():Defensa("Torreta de hielo", 50, 2,"vivo"){};
    Torreta(string nom, int vid, int fuerz, string estad)
            : Defensa(nom, vid, fuerz,estad){
        nombre=nom;
        vida=vid;
        fuerza=fuerz;
        estado=estad;
        ralentizar=10;
        mareado=3;

    };
    //:Defensa(nombre,vida,fuerza,rango),turnos_congelamiento(turnos), retroceso(retro){};
};
string Torreta::get_stats() {
    stringstream aux;
    aux<< "Nombre: "<<nombre<<"\nVida: "<<vida<<"\nFuerza: "<<fuerza<<"\nRetroceso: "<<ralentizar;
    return aux.str();
}
class Transporte:public Defensa{
private:
    int cooldown;
public:
    string get_stats();
    string disparar();
    int get_cooldown();
    Transporte():Defensa("Transporte de misiles", 90, 12,"vivo"){};
    Transporte(string nom, int vid, int fuerz,string estad)
            : Defensa(nom, vid, fuerz,estad){
        nombre=nom;
        vida=vid;
        fuerza=fuerz;
        estado=estad;
        cooldown=0;
        mareado=3;

    };
};
string Transporte::get_stats() {
    stringstream aux;
    aux<< "Nombre: "<<nombre<<"\nVida: "<<vida<<"\nFuerza: "<<fuerza<<"\nCooldown: "<<cooldown;;
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




#endif //RAMPAGE_DEFENSA_H
