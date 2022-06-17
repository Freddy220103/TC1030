/*
 * Proyecto Rampage main
 * Alfredo Gómez Mendoza
 * A01704696
 * 16/06/2022
 *
 * El programa es un videojuego de turnos tipo Pokemón.
 * El juego tiene una idea simple, hay una ciudad con un porcentaje de
 * destrucción, siendo que este porcentaje de destrucción irá aumentando cada
 * vez que un monstruo lo ataque. El jugador (ósease el que use el código)
 * tendrá que llegar al porcentaje de destrucción de la ciudad al 100%. Cuando
 * se llegue a este porcentaje, el juego termina. Sin embargo, no será tan
 * sencillo, ya que la ciudad puede generar defensas de dos diferentes tipos
 * que atacan a los monstruos para evitar la destrucción total del lugar.
 * Los monstruos deben destruir las defensas para no morir con un ataque simple
 * y un ataque especial. Las defensas también pueden hacer uso de un disparo
 * base y una habilidad especial.
 */

#include <iostream> //para imprimir
#include "Ataque.h" //biblioteca que incluye las demás librerías del juego.

using namespace std;
int main() {
    Ataque ataque;
    Ciudad city("Queretabasco", 0, 0);
    cout << "Ahora puedes ver la ciudad desde el horizonte" << endl;
    cout << "" << endl;
    cout << "Los valientes monstruos que te acompaniaran seran Godzilla y Rodan" << endl;
    Tanque godzilla("Godzilla",100,20);
    Asesino rodan("Rodan",50,25);
    int turno = 0;
    int porcentaje;
    cout<<"La ciudad ha creado sus primeras defensas"<<endl;
    cout<<"Ocho defensas se levantan desde la ciudad"<<endl;
    cout<<"----------------"<<endl;
    cout<<" \n";
    city.get_defensas();
    cout<<"\n";
    int muertegodzilla, muerterodan;
    muertegodzilla = 0;
    muerterodan=0;
    while (city.get_porcentaje() < 100) {
        int suma;
        suma=0;
        for(int i=0; i<8; i++){
            int vidadefensa;
            vidadefensa=city.defe[i]->get_vida();
            suma+=vidadefensa;

        }
        cout << "\n¿Listos monstruos?\n";
        turno++;
        cout << "Turno: " << turno << "\n";
        city.get_citystats();
        cout << "  " << endl;
        cout << "  " << endl;
        if (godzilla.get_vida() >0) {
            godzilla.estadisticas_monstruo();
            cout
                    << "¿Que quieres hacer con Godzilla?\n\na - Atacar defensas\nd - Destruir ciudad\ny - Ataque destructor\np - Proteger\n"
                    << endl;
            char input;
            cin >> input;
            for (int i = 0; i < 1; i++) {
                if (input == 'a') {
                    if (suma > 0) {
                        cout << "A que defensa deseas atacar, escoge un numero del 1 al 8" << endl;
                        cout << "\n";
                        int elecciondefensa;
                        cin >> elecciondefensa;
                        elecciondefensa = elecciondefensa - 1;
                        ataque.ataque(&city, &godzilla, elecciondefensa);
                        i++;
                    }
                    else{
                        cout<<"Todas las defensas fueron destruidas, no puedes atacarlas mas"<<endl;
                        cout<<"\n";
                    }
                } else if (input == 'd') {
                    ataque.destruir_ciudad(&city, &godzilla);
                    i++;
                } else if (input == 'y') {
                    if(suma>0) {
                        if(godzilla.get_energia()>=100) {
                            cout << "A que defensa deseas atacar, escoge un numero del 1 al 8" << endl;
                            cout << "\n";
                            int elecciondefensa1;
                            cin >> elecciondefensa1;
                            elecciondefensa1 = elecciondefensa1 - 1;
                            ataque.ataque_especial(&city, &godzilla, elecciondefensa1);
                        }
                        else{
                            cout<<"La energia no es la suficiente"<<endl;
                            cout<<"\n";
                        }
                    }
                    else{
                        cout<<"Todas las defensas fueron destruidas, no puedes atacarlas mas"<<endl;
                        cout<<"\n";
                    }
                } else if (input == 'p') {
                    godzilla.proteger();
                } else {
                    cout << "Opcion no valida" << endl;
                }


            }
        }
        cout << "\n";
        if (godzilla.get_vida() <= 0) {
            cout << "R I P" << endl;
            cout << godzilla.get_nombre() << " ha muerto, ya no esta disponible para pelear\n";

        }


        if (rodan.get_vida() > 0) {
            rodan.estadisticas_monstruo();
            cout << "¿Que quieres hacer con Rodan?\n\na - Atacar defensas\nd - Destruir ciudad\ny - Habilidad Mareo"
                 << endl;
            char input2;
            cin >> input2;
            for (int i = 0; i < 1; i++) {
                if (input2 == 'a') {
                    cout << "A que defensa deseas atacar, escoge un numero del 1 al 8" << endl;
                    cout << "\n";
                    if(suma>0) {
                        int elecciondefensa2;
                        cin >> elecciondefensa2;
                        elecciondefensa2 = elecciondefensa2 - 1;
                        ataque.ataque(&city, &rodan, elecciondefensa2);
                        i++;
                    }
                    else{
                        cout<<"Todas las defensas fueron destruidas, no puedes atacarlas mas"<<endl;
                        cout<<"\n";
                    }
                } else if (input2 == 'd') {
                    ataque.destruir_ciudad(&city, &rodan);
                    i++;
                } else if (input2 == 'y') {
                    if(suma) {
                        if(rodan.get_energia()>=100) {
                            cout << "A que defensa deseas atacar, escoge un numero del 1 al 8" << endl;
                            cout << "\n";
                            int elecciondefensa3;
                            cin >> elecciondefensa3;
                            elecciondefensa3 = elecciondefensa3 - 1;
                            Defensa defensa3;
                            defensa3 = *city.defe[elecciondefensa3];
                            ataque.ataque_especial(&city, &rodan, elecciondefensa3);
                        }
                        else{
                            cout<<"La energia no es la suficiente"<<endl;
                            cout<<"\n";
                        }
                    }
                    else{
                        cout<<"Todas las defensas fueron destruidas, no puedes atacarlas mas"<<endl;
                        cout<<"\n";
                    }
                } else {
                    cout << "Opcion no valida" << endl;
                }
            }
        }
        cout << "\n";
        if (rodan.get_vida() <= 0) {
            cout << "R I P" << endl;
            cout << rodan.get_nombre() << " ha muerto, ya no esta disponible para pelear\n";

        }
        cout << "\n";
        if (godzilla.get_vida() <= 0 && rodan.get_vida() <= 0) {
            cout<<"Ambos monstruos han muerto"<<endl;
            break;
        }
        if(city.get_porcentaje()<100) {
            if (suma > 0) {

                cout << "Turno de defensas" << endl;
                int num, i2, i3;
                num = city.get_numero();
                i2 = 0;
                i3 = 0;
                for (int i = 0; i < num; i++) {

                    if (i3 % 2 == 0) {
                        if (city.defe[i2]->get_vida() > 0) {
                            cout << "\n";
                            cout << "Ataque dirigido hacia " << godzilla.get_nombre() << "\n";
                            cout << "La defensa #" << i2 + 1;
                            ataque.disparar(&city, &godzilla, i2);

                            cout << "\n";
                            cout << "Ataque dirigido hacia " << rodan.get_nombre() << "\n";
                            cout << "La defensa #" << i2 + 1;
                            ataque.disparar(&city, &rodan, i2);
                            i3 = i3 + 9;
                        } else {
                            cout << "La defensa # " << i2 + 1 << " fue destruida" << endl;
                            godzilla.aniadir_energia(20);
                            rodan.aniadir_energia(30);
                        }
                    } else {
                        if (city.defe[i2]->get_vida() > 0) {
                            cout << "La defensa #" << i2 + 1;
                            city.defe[i2]->activar_escudo();
                            i3 = i3 += 9;
                        } else {
                            cout << "La defensa # " << i2 + 1 << " fue destruida" << endl;
                            godzilla.aniadir_energia(20);
                            rodan.aniadir_energia(30);
                        }

                    }

                    i2++;
                }
            } else {
                cout << "Todas las defensas fueron destruidas" << endl;
                cout << "Es tu momento de atacar la ciudad" << endl;
                cout<<"\n";
            }
        }

        if (muertegodzilla == 0) {
            if (godzilla.get_vida() <= 0) {
                cout << "Oh no " << godzilla.get_nombre() << " ha tenido una muerte trágica y dolorosa\n";
            }
            muertegodzilla += 1;
        }
        if (muerterodan == 0) {
            if (rodan.get_vida() <= 0) {
                cout << "Oh no le han dado a " << rodan.get_nombre() << " mientras volaba, el demonio de fuego ha caido"
                     << endl;
            }
            muerterodan += 1;
        }

    }
    cout<<"\n"<<endl;
    if(city.get_porcentaje()>=100){
        cout<<"Destruiste la ciudad "<<city.get_nombre()<<endl;
        cout<<"GANASTE, felicidades"<<endl;
    }
    else{
        cout<<"H A B E I S  P E R D I D O"<<endl;
        cout<<"GAME OVER"<<endl;
    }

    return 0;
}
