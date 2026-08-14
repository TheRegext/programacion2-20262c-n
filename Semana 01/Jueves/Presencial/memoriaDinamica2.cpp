#include <iostream>
using namespace std;

int main(){
    int *vectorEdades = nullptr;
    int cantAlumnos;

    cout << "Cantidad Alumnos: ";
    cin >> cantAlumnos;

    if (cantAlumnos <= 0){
        cout << "No sé como haces para tener alumnos negativos" << endl;
        return 1;
    }

    vectorEdades = new int[cantAlumnos];

    if (vectorEdades == nullptr){
        cout << "No hay memoria disponible" << endl;
        return 1;
    }

    for (int i=0; i<cantAlumnos; i++){
        cout << "Ingresar edad del alumno " << i+1 << ": ";
        cin >> vectorEdades[i];
    }

    cout << endl;

    for (int i=0; i<cantAlumnos; i++){
        cout << "Edad del alumno " << i+1 << ": ";
        cout << vectorEdades[i] << endl;
    }

    delete []vectorEdades;

    return 0;
}
