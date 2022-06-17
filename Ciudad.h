/*
 *
 * Proyecto Rampage clase Ciudad
 * Alfredo Gómez Mendoza
 * A01704189
 * 16/06/2022
 * version : 4
 * La clase define objetos de tipo Ciudad que contiene la clase de Defensa por
 * la composición usada. Esta clase define objetos tipo Defensa, teniendo sus
 * funciones para obtener sus stats. Tiene el atributo numero que ayuda a
 * acceder al array que guarda las defensas creadas. Esta clase es usada en
 * en el main y es parte del proyecto nómina.
 */
//345678901234567890123456789012345678901234567890123456789012345678901234567890
#ifndef CIUDAD_H_
#define CIUDAD_H_
#include "Defensa.h"//biblioteca con mis objetos a usar
using namespace std;

const int maxdef = 8; //constante del tamaño de arreglos

class Ciudad{

    //Declaro las variables privadas de instancia
    private:
        string nombre;
        int numero;
        int porcentaje_destruccion;

        void crear_defensas();//listo

    //Declaro constructor por default y metodos públicos.
    public:
        Defensa * defe[maxdef];//se define como apuntador para usar polimorfismo
        Ciudad(string nom, int num, int destruccion){//constructor por default
        nombre=nom;
        numero=num;
        porcentaje_destruccion=destruccion;
        crear_defensas();//se llama al momento de crear un objeto ciudad
        }
        //getters y setters
        void set_destruccion(int dest);
        int get_numero();
        string get_nombre();

        int get_porcentaje();

        void get_citystats();
        void get_defensas();

};

/**
 * crea_defensas genera objetos en Defensas[]
 *
 * Genera objetos de tipo Torreta y Transporte y los
 * guarda en la variable de instancia en defe[] (arreglo de defensas)
 * para poder ser usados después. El for loop es para crear 8
 * de estas defensas solamente.
 *
 * @param
 * @return
 */

void Ciudad::crear_defensas() {
    int i;
    i=2;
    while (numero<8){
        //new crea el objeto en tiempo de ejecución para usar polimorfismo
        defe[numero] = new Torreta("Torreta de hielo", 8,
                                   2,"vivo");
        numero++;
        defe[numero] = new Transporte("Transporte misiles", 25,
                                      12,"vivo");
        numero++;
    }

};

void Ciudad::set_destruccion(int dest){
    porcentaje_destruccion=porcentaje_destruccion+dest;
}

int Ciudad::get_numero(){
    return numero;
}

string Ciudad::get_nombre(){
    return nombre;
}

int Ciudad::get_porcentaje(){
    return porcentaje_destruccion;
}

/**
 * get_defensas imprime un método de los objetos defensa
 *|
 * Utiliza el arreglo defe[] y el número de nómina, para recorre todo el
 * arreglo imprimiendo el método get_stats() de cada objeto tipo defensa.
 *
 * @param
 * @return
 */

void Ciudad::get_defensas(){
    for (int i = 0; i<numero; i++){
        cout<<"Defensa: "<<i+1<<endl;
        cout<<defe[i] -> get_stats()<<endl;
        cout<<"---------------------"<<endl;
        cout<<" \n";
    }
}
/**
 * get_citystats imprime un mensaje y el porcentaje
 *
 * Utiliza al atributo porcentaje de destruccion y
 * lo imprime junto con un mensaje.
 *
 * @param
 * @return
 */

void Ciudad::get_citystats(){
    cout<<"Porcentaje de ciudad destruido: "<<porcentaje_destruccion<<endl;
}



#endif
