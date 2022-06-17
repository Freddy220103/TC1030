/*
 *
 * Proyecto Rampage clase Monstruo
 * Alfredo Gómez Mendoza
 * A01704189
 * 16/06/2022
 * version : 4
 * Esta clase defina objeto de tipo Monstruo que contiene las clases heredadas
 * Tanque y Asesino
 */
#ifndef MONSTRUO_H_
#define MONSTRUO_H_
#include<iostream>
using namespace std;

//Declaracion de clase Monstruo que es abstracta
class Monstruo{
    //Declaro variables de instancia
protected:
    string nombre;
    int vida;
    int fuerza;
    int energia;

    //Declaro los métodos y atributos públicos que va a tener el objeto
public:
    int es_asesino;
    Monstruo(){};//constructor por default
    Monstruo(string nom, int vid, int fuerz):nombre(nom),vida(vid),fuerza(fuerz){
        energia=100;
    };


    virtual void ataque()=0;//método abstracto será sobreescrito
    virtual void ataque_especial()=0;//método abstracto será sobreescrito

    void estadisticas_monstruo();
    void herirse(int fuerz);
    void destruir_ciudad();

    //getters y setters
    int get_fuerza();
    int get_vida();
    int get_energia();
    string get_nombre();
    void aniadir_energia(int ener);

};
void Monstruo::aniadir_energia(int ener){
    energia+=ener;
}
int Monstruo::get_energia() {
    return energia;
}
int Monstruo::get_vida(){
    return vida;
}
string Monstruo::get_nombre() {
    return nombre;
}

int Monstruo::get_fuerza(){
    return fuerza;
}

/**
 * ataque imprime un mensaje
 *
 * Imprime un mensaje que será usado después.
 *
 * @param
 * @return
 */

void Monstruo::ataque(){
    cout<<"Tu monstruo ha atacado"<<endl;
};

/**
 * destruir_ciudad imprime un mensaje
 *
 * Imprime un mensaje que será usado después.
 *
 * @param
 * @return
 */

void Monstruo::destruir_ciudad(){
    cout<<nombre<<" ha atacado la ciudad"<<endl;

}

/**
 * herirse saca a la consola un mensaje y cambia la vida del monstruo
 *
 * Saca un mensaje a la consola para después modificar la vida. Resta vida menos
 * fuerz. Usa un if statement, siendo si la vida es mayor o igual a 0, hará la resta.
 * En el caso contrario sacará un mensaje a la consola.
 *
 * @param fuerz del tipo int
 * @return
 */

void Monstruo::herirse(int fuerz){
    cout<<"Han herido tu monstruo"<<endl;
    if(vida>=0) {
        vida = vida - fuerz;
    }
    else{
        cout<<"\n";
        cout<<"Los latidos de tu monstruo se comienzan a detener\n";
    }
};

/**
 * estadisticas_monstruo imprime varios mensaje
 *
 * Imprime mediante couts los atributos del objeto junto
 * con texto.
 *
 * @param
 * @return
 */

void Monstruo::estadisticas_monstruo(){
    cout<<"Turno de monstruo:"<<nombre<<endl;
    cout<<"     Vida: "<<vida<<endl;
    cout<<"     Fuerza: "<<fuerza<<endl;
    cout<<"     Energia: "<<energia<<endl;
}

/**
 * ataque_especial imprime un mensaje y modifica la energia
 *
 * Imprime un mensaje que será usado después en base a  un if statements que
 * checa el atributo energia. Si es igual a 100 imprime un mensaje y hace
 * que este mismo atributo sea igual a 0. Por el otro lado es esto es
 * falso imprime otro mensaje y aumenta el valor del atributo energia.
 *
 * @param
 * @return
 */

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

//Declaro objeto Asesino que hereda de Monstruo
class Asesino:public Monstruo {

    //Variables de instancia del objeto
private:
    int torres_destruidas;
    int i;
    int resultado;

    //Metodospublicos del objeto
public:


    Asesino(){};//constructor por default

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

/**
 * ataque imprime un mensaje y redifine la fuerza
 *
 * Imprime un mensaje que será usado después. Sin embargo este
 * también usa un while statements para aumentar la fuerza del
 * monstruo con las torretas destruidas.
 *
 * @param
 * @return
 */
void Asesino::ataque(){
    i=0;

    while(torres_destruidas>=i) {
        resultado = fuerza + torres_destruidas;
    }
    cout<<"El asesino ha atacado"<<endl;
    i++;
};

/**
 * ataque_especial imprime un mensaje y modifica la energia
 *
 * Imprime un mensaje que será usado después en base a  un if statements que
 * checa el atributo energia. Si es igual a 100 imprime un mensaje y hace
 * que este mismo atributo sea igual a 0. Por el otro lado es esto es
 * falso imprime otro mensaje y aumenta el valor del atributo energia.
 *
 * @param
 * @return
 */
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

//Declaro objeto Tanque que hereda de Monstruo
class Tanque:public Monstruo {

    //Declaro metodos públicos
public:


    Tanque(){};//constructor por default

    Tanque(string nom, int vid, int fuerz) : Monstruo(nom, vid, fuerz){
        nombre=nom;
        vida=vid;
        fuerza=fuerz;
        energia=100;
        es_asesino=0;
    };

    void proteger();
    void ataque();
    void ataque_especial();
};

/**
 * ataque imprime un mensaje y redifine la fuerza
 *
 * Imprime un mensaje que será usado después. También redifine la fuerza.
 *
 * @param
 * @return
 */

void Tanque::ataque(){
    fuerza=20;
    cout<<get_nombre()<<" ha atacado"<<endl;
}

/**
 * proteger imprime un mensaje
 *
 * Imprime un mensaje que será usado después.
 *
 * @param
 * @return
 */

void Tanque::proteger(){
    cout<<"El monstruo se ha protegido"<<endl;
}

/**
 * ataque_especial imprime un mensaje y modifica la energia
 *
 * Imprime un mensaje que será usado después en base a  un if statements que
 * checa el atributo energia. Si es igual a 100 imprime un mensaje y hace
 * que este mismo atributo sea igual a 0. Por el otro lado es esto es
 * falso imprime otro mensaje y aumenta el valor del atributo energia.
 *
 * @param
 * @return
 */

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
