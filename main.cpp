#include <iostream>
#include "Monstruo.h"

using namespace std;
int main() {

    Ciudad city("Queretabasco", 0, 0);
    cout << "Ahora puedes ver la ciudad desde el horizonte" << endl;
    cout << "" << endl;
    cout << "Los valientes monstruos que te acompaniaran seran Godzilla y Rodan" << endl;
    Tanque godzilla("Godzilla",30,20,20);
    Asesino rodan("Rodan",10,25,25);
    int turno = 0;
    int porcentaje;
    porcentaje = city.get_porcentaje();
    while (porcentaje < 100) {
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
                godzilla.ataque();
                i++;
            }
            else if (input == 'd') {
                godzilla.destruir_ciudad();
                city.set_destruccion(10);
                i++;
            }
            else if (input == 'y') {
                godzilla.ataque_especial();
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
                rodan.ataque();
                i++;
            }
            else if (input2 == 'd') {
                rodan.destruir_ciudad();
                city.set_destruccion(10);
                i++;
            }
            else if (input2 == 'y') {
                rodan.ataque_especial();
            }

            else {
                cout << "Opcion no valida" << endl;
            }
        }

        cout<<"Turno de defensas"<<endl;
        city.get_defensas();
        city.ordenar_ataque();
    }
    return 0;
}
