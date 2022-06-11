//
// Creado por Alfredo Gómez Mendoza el 27/05/2022.
//
#ifndef MONSTRUO_H_
#define MONSTRUO_H_
#include<iostream>
using namespace std;
class Monstruo{
protected:
    string nombre;
    int vida;
    int fuerza;
    int energia;

public:
    int es_asesino;
    Monstruo(){};
    Monstruo(string nom, int vid, int fuerz):nombre(nom),vida(vid),fuerza(fuerz){
        energia=100;
    };
    virtual void ataque()=0;
    virtual void ataque_especial()=0;
    void estadisticas_monstruo();
    void herirse(int fuerz);
    string get_nombre();
    void destruir_ciudad();
    int get_fuerza();
    int get_vida();

};
int Monstruo::get_vida(){
    return vida;
}
string Monstruo::get_nombre() {
    return nombre;
}

int Monstruo::get_fuerza(){
    return fuerza;
}
void Monstruo::ataque(){
    cout<<"Tu monstruo ha atacado"<<endl;
};

void Monstruo::destruir_ciudad(){
    cout<<nombre<<" ha atacado la ciudad"<<endl;

}
void Monstruo::herirse(int fuerz){
    cout<<"Han herido tu monstruo"<<endl;
    if(vida>=0) {
        vida = vida - fuerz;
    }
    else{
        cout<<"\n";
        cout<<"Los latidos de tu monstruo se comienzan a detener\n";
    }
    //vida-fuerza de la defensa
};
void Monstruo::estadisticas_monstruo(){
    cout<<"Turno de monstruo:"<<nombre<<endl;
    cout<<"     Vida: "<<vida<<endl;
    cout<<"     Fuerza: "<<fuerza<<endl;
    cout<<"     Energia: "<<energia<<endl;
}

void Monstruo::ataque_especial(){
    if(energia=100){
        cout<<"El ataque especial ha iniciado"<<endl;
        energia=0;
    }
    else{
        cout<<"La energía no es suficiente"<<endl;
        energia+=25;
    }
}


class Asesino:public Monstruo {
private:
    int torres_destruidas;
    int i;
    int resultado;
public:


    Asesino(){};

    Asesino(string nom, int vid, int fuerz) : Monstruo(nom, vid, fuerz){
        nombre=nom;
        vida=vid;
        fuerz=fuerza;
        resultado=0;
        energia=100;
        es_asesino=1;
    };

    void ataque();

    void ataque_especial();
};

void Asesino::ataque(){
    i=0;

    while(torres_destruidas>=i) {
        resultado = fuerza + torres_destruidas;
    }
    cout<<"El asesino ha atacado"<<endl;
    i++;
};
void Asesino::ataque_especial() {
    if(energia=100){
        cout<<get_nombre()<<" ha iniciado el ataque mareo"<<endl;
        energia=0;
    }
    else{
        cout<<"La energía no es suficiente"<<endl;
        energia+=25;
    }
}


class Tanque:public Monstruo {
public:


    Tanque(){};

    Tanque(string nom, int vid, int fuerz) : Monstruo(nom, vid, fuerz){
        nombre=nom;
        vida=vid;
        fuerz=fuerza;
        energia=100;
        es_asesino=0;
    };

    void proteger();
    void ataque();
    void ataque_especial();
};

void Tanque::ataque(){
    fuerza=20;
    cout<<get_nombre()<<" ha atacado"<<endl;
}
void Tanque::proteger(){
    cout<<"El monstruo se ha protegido"<<endl;
}

void Tanque::ataque_especial() {

    if(energia=100){
        cout<<"El monstruo "<<get_nombre()<<" ha iniciado el ataque especial"<<endl;
        fuerza=100;
        energia=10;
    }
    else{
        cout<<"La energía no es suficiente"<<endl;
        energia+=55;
    }
}
#endif
