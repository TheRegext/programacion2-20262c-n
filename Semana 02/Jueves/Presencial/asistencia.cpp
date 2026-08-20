/**
    crearAsistentes tiene un bug que no libera la memoria ante ingresos
    múltiples.

    Pensar una manera apropiada de solucionar ese problema.
*/


#include <iostream>
using namespace std;

void crearAsistentes(bool *& asistentes, int &cantidad) {

    cout << "Ingresar la cantidad de asistentes: ";
    cin >> cantidad;

    if (cantidad <= 0){
        cout << "Cantidad de asistentes incorrecta\n";
        return;
    }

    asistentes = new bool [cantidad];

    if (asistentes == nullptr){
        cout << "No se puede continuar. No hay memoria.\n";
        return;
    }

    for (int i = 0; i < cantidad; i++){
        asistentes[i] = false;
    }

}

void marcarAsistencia(bool *asistentes, int cantidad) {
    int nroAsistente;
    bool asistio;

    cout << endl << endl;

    cout << "Ingresar el número de asistente (1 a " << cantidad << "): ";
    cin >> nroAsistente;

    if (nroAsistente <= 0 || nroAsistente > cantidad){
        cout << "Número de asistente incorrecto.\n";
        return;
    }

    cout << "Asistió (1 - Sí | 0 - No): ";
    cin >> asistio;

    asistentes[nroAsistente - 1] = asistio;

}

void mostrarAsistentes(bool *asistentes, int cantidad){
    int i;
    cout << endl << endl;
    for (i = 0; i < cantidad; i++){
        cout << "Asistente " << (i+1) << ": ";
        cout << (asistentes[i] == 1 ? "Asistió" : "No asistió") << endl;
    }
}

int main() {
    int opcion;
    int cantidad;
    bool *asistentes = nullptr;

    do {
        cout << "\n===== MENU =====\n";
        cout << "1. Crear asistentes\n";
        if (asistentes != nullptr){
            cout << "2. Marcar asistencia\n";
            cout << "3. Mostrar asistentes\n";
        }
        cout << "0. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                crearAsistentes(asistentes, cantidad);
                break;
            case 2:
                if (asistentes != nullptr){
                    marcarAsistencia(asistentes, cantidad);
                }
                break;
            case 3:
                if (asistentes != nullptr){
                    mostrarAsistentes(asistentes, cantidad);
                }
                break;
            case 0:
                cout << "Saliendo del programa...\n";
                break;
            default:
                cout << "Opcion invalida.\n";
        }

    } while (opcion != 0);

    if (asistentes != nullptr){
        delete [] asistentes;
    }

    return 0;
}
