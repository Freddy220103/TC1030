/*
 *
 * Proyecto Rampage clase Defensa
 * Alfredo Gómez Mendoza
 * A01704189
 * 16/06/2022
 * version : 4
 * Esta clase defina objeto de tipo Defensa que contiene las clases heredadas
 * Torreta y Transporte.
 */
//FALTA DEFINIR LOS ESCUDOS Y EL ATAQUE DE TRANSPORTE
#ifndef DEFENSA_H_
#define DEFENSA_H_
#include <string>
#include <sstream>
using namespace std;

class Defensa{

    //Declaro variables de instancia
    protected:
        string nombre;
        int vida;
        int fuerza;
        string estado;

    //Declaro los métodos y atributos públicos que va a tener el objeto
    public:
        int mareado;
        Defensa(){}; //constructor por default
        Defensa(string nom, int vid, int fuerz,string estad)
                :nombre(nom),vida(vid),fuerza(fuerz){};

        //getters y setters
        int get_fuerza();
        int get_vida();
        void set_fuerza(int fuerz);

        virtual string get_stats(); //método virtual
        void disparar();
        void herirse(int fuerza);
        void activar_escudo();
        void mareo();


};

int Defensa::get_vida(){
    return vida;
}

int Defensa::get_fuerza(){
    return fuerza;
}

void Defensa::set_fuerza(int fuerz) {
    fuerza=fuerza-fuerz;
}

/**
 * disparar imprime un mensaje
 *
 * Imprime un mensaje que será usado después.
 *
 * @param
 * @return
 */

void Defensa::disparar(){
    cout<<" ha atacado"<<endl;
}

/**
 * get_stats convierte atributos a string.
 *
 * Concatena todos los valores de los atributos en un string para ser impreso
 *
 * @param
 * @return string con valores y texto concatenados
 */

string Defensa::get_stats() {
    stringstream aux;
    aux<< "Nombre: "<<nombre<<"\nVida: "<<vida<<"\nFuerza: "<<fuerza<<"\nEstado:"<<estado;
    return aux.str();


}
//CHECAR
/**
 * activar_escudo imprime un mensaje
 *
 * Imprime un mensaje que será usado después.
 *
 * @param
 * @return
 */

void Defensa::activar_escudo(){
    //herirse(danio);
    //danio=0;
    cout<<" ha activado su escudo"<<endl;

}

/**
 * herirse saca a la consola un mensaje y cambia la vida de la defensa
 *
 * Saca un mensaje a la consola para después modificar la vida. Resta vida menos
 * fuerz. Usa un if statement, siendo si la vida es menor a 0, la redefinirá
 * como 0.
 *
 * @param fuerz del tipo int
 * @return
 */

void Defensa::herirse(int fuerz){
    cout<<"Has daniado a la defensa"<<endl;
    vida=vida-fuerz;
    if (vida<0){
        vida=0;
    }
}

/**
 * mareo es la que administra el método disparar de las defensas
 *
 * Usa un if statement, siendo que si el residuo de mareado entre 2 es 0, saca
 * un mensaje a la consola. Después suma 7 a mareado. En el caso que el residuo
 * no sea 0, procede a usar el método disparar.
 *
 * @param
 * @return
 */

void Defensa::mareo(){
    if (mareado%2==0){
        cout<<" fue mareada"<<endl;
        mareado+=7;
    }
    else{
        disparar();
    }
}

//Declaro objeto Torreta que hereda de Defensa
class Torreta:public Defensa{

    //Declaro las variables de instancia privadas
private:
    int ralentizar;

    //Declaro metodos públicos y constructores
public:

    Torreta():Defensa("Torreta de hielo", 50,
                      2,"vivo"){};//constructor por default
    Torreta(string nom, int vid, int fuerz, string estad)
            : Defensa(nom, vid, fuerz,estad){
        nombre=nom;
        vida=vid;
        fuerza=fuerz;
        estado=estad;
        ralentizar=10;
        mareado=3;
    };

    string get_stats();
};

/**
 * get_stats convierte atributos a string.
 *
 * Concatena todos los valores de los atributos en un string para ser impreso
 *
 * @param
 * @return string con valores y texto concatenados
 */

string Torreta::get_stats() {
    stringstream aux;
    aux<< "Nombre: "<<nombre<<"\nVida: "<<vida<<"\nFuerza: "
    <<fuerza<<"\nRetroceso: "<<ralentizar;

    return aux.str();
}

//Declaro objeto Transporte que hereda de Defensa
class Transporte:public Defensa{

    //Variables privadas del objeto
private:

    int cooldown;

    //Metodos públicos del objeto
public:

    Transporte():Defensa("Transporte de misiles",
                         90, 12,"vivo"){}; //constructor por default
    Transporte(string nom, int vid, int fuerz,string estad)
            : Defensa(nom, vid, fuerz,estad){
        nombre=nom;
        vida=vid;
        fuerza=fuerz;
        estado=estad;
        cooldown=0;
        mareado=3;
    };

    int get_cooldown();
    string get_stats();
    void disparar();
};

int Transporte::get_cooldown() {
    return cooldown;
}

/**
 * get_stats convierte atributos a string.
 *
 * Concatena todos los valores de los atributos en un string para ser impreso
 *
 * @param
 * @return string con valores y texto concatenados
 */

string Transporte::get_stats() {
    stringstream aux;
    aux<< "Nombre: "<<nombre<<"\nVida: "<<vida<<"\nFuerza: "
    <<fuerza<<"\nCooldown: "<<cooldown;

    return aux.str();
}

/**
 * disparar imprime un mensaje y modifica el atributo cooldown
 *
 * Imprime un mensaje que será usado después en base al atributo
 * cooldown. Si es igual a 0 imprime un mensaje y hace que
 * este mismo atributo sea igual a 1. En el caso contrario
 * imprime otro mensaje y pone a cooldown como 0.
 *
 * @param
 * @return
 */

void Transporte::disparar(){
    stringstream aux;
    if (cooldown==0){
        cout<<" de tipo transporte ha disparado"<<endl;
        cooldown=1;
    }
    else{
        cout<<" intentó atacar pero tiene que recargar"<<endl;
        cooldown=0;
    }

}




#endif //RAMPAGE_DEFENSA_H
