#include <iostream>
#include "Ataque.h"

using namespace std;
int main() {
    Ataque ataque;
    Ciudad city("Queretabasco", 0, 0);
    cout << "Ahora puedes ver la ciudad desde el horizonte" << endl;
    cout << "" << endl;
    cout << "Los valientes monstruos que te acompaniaran seran Godzilla y Rodan" << endl;
    Tanque godzilla("Godzilla",30,20,20);
    Asesino rodan("Rodan",10,25,25);
    int turno = 0;
    int porcentaje;
    cout<<"La ciudad ha creado sus primeras defensas"<<endl;
    cout<<"Ocho defensas se levantan desde la ciudad"<<endl;
    cout<<"----------------"<<endl;
    cout<<" \n";
    city.get_defensas();
    cout<<"\n";
    while (city.get_porcentaje() < 100) {
        cout << "\n¿Listos monstruos?\n";
        turno++;
        cout << "Turno: " << turno << "\n";
        city.get_citystats();
        cout<<"  "<<endl;
        cout<<"  "<<endl;
        godzilla.estadisticas_monstruo();
        cout<< "¿Que quieres hacer con Godzilla?\n\na - Atacar defensas\nd - Destruir ciudad\ny - Ataque destructor\np - Proteger\n"<< endl;
        char input;
        cin >> input;
        for (int i = 0; i < 1; i++) {
            if (input == 'a') {
                cout<<"A que defensa deseas atacar, escoge un numero del 1 al 8"<<endl;
                cout<<"\n";
                int elecciondefensa;
                cin>>elecciondefensa;
                Defensa defensa;
                defensa=*city.defe[elecciondefensa];
                ataque.ataque(&defensa,&godzilla);
                i++;
            }
            else if (input == 'd') {
                ataque.destruir_ciudad(&city,&godzilla);
                i++;
            }
            else if (input == 'y') {
                cout<<"A que defensa deseas atacar, escoge un numero del 1 al 8"<<endl;
                cout<<"\n";
                int elecciondefensa1;
                cin>>elecciondefensa1;
                Defensa defensa1;
                defensa1=*city.defe[elecciondefensa1];
                ataque.ataque_especial(&defensa1,&godzilla);
            }

            else if (input == 'p') {
                godzilla.proteger();
            }

            else {
                cout << "Opcion no valida" << endl;
            }


        }
        rodan.estadisticas_monstruo();
        cout<< "¿Que quieres hacer con Rodan?\n\na - Atacar defensas\nd - Destruir ciudad\ny - Habilidad Mareo"<< endl;
        char input2;
        cin >> input2;
        for (int i = 0; i < 1; i++) {
            if (input2 == 'a') {
                cout<<"A que defensa deseas atacar, escoge un numero del 1 al 8"<<endl;
                cout<<"\n";
                int elecciondefensa2;
                cin>>elecciondefensa2;
                Defensa defensa2;
                defensa2=*city.defe[elecciondefensa2];
                ataque.ataque(&defensa2,&rodan);
                i++;
            }
            else if (input2 == 'd') {
                ataque.destruir_ciudad(&city,&rodan);
                i++;
            }
            else if (input2 == 'y') {
                cout<<"A que defensa deseas atacar, escoge un numero del 1 al 8"<<endl;
                cout<<"\n";
                int elecciondefensa3;
                cin>>elecciondefensa3;
                Defensa defensa3;
                defensa3=*city.defe[elecciondefensa3];
                ataque.ataque_especial(&defensa3,&rodan);
            }

            else {
                cout << "Opcion no valida" << endl;
            }
        }
        cout<<"\n";
        cout<<"Turno de defensas"<<endl;
        int num, i2, i3;
        num=city.get_numero();
        i2=0;
        i3=0;
        for (int i = 0; i <num; i++) {

            if (i3 % 2 == 0) {
                cout<<"La defensa #"<<i2+1;
                ataque.disparar(city.defe[i2], &godzilla);
                ataque.disparar(city.defe[i2], &rodan);
                i3=i3+9;
            }
            else {
                cout<<"La defensa #"<<i2+1;
                city.defe[i2]->activar_escudo();
                i3=i3+=9;

            }

            i2++;
        }
    }
    cout<<"Destruiste la ciudad "<<city.get_nombre()<<endl;
    cout<<"GANASTE, felicidades"<<endl;
    return 0;
}


