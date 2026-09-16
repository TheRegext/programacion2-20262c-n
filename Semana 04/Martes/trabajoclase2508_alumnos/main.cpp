#include <iostream>
#include <cstring>

using namespace std;


#include "socio.h"
#include "libro.h"
#include "prestamo.h"
#include "funcionesGlobales.h"

///Hacer una clase Resolucion, con los métodos punto3(), punto4() y punto5() que resuelvan lo que se pide a continuación
///3. Sabiendo que los _idSocio están definidos del 100 al 109,  calcular e informar cuántos libros pidió cada socio.
///4. Sabiendo que los valores de _isbn de los libros están definidos enter el 1000 al 1009, informar los libros que no fueron prestados
///5. Hacer un listado de los préstamos que no fueron devueltos, informando el nombre del libro, el nombre del socio y la fecha del préstamo

int main(){
    Socio vSocios[10];
    Libro vLibros[10];
    Prestamo vPrestamos[10];
    int opc;
    while(true){
        system("cls");
        cout<<"1. CARGAR VECTORES"<<endl;
        cout<<"2. MOSTRAR VECTORES"<<endl;
        cout<<"3. "<<endl;
        cout<<"4. "<<endl;
        cout<<"5. "<<endl;
        cout<<"0. "<<endl;
        cout<<"********************"<<endl;
        cout<<"SELECCIONAR OPCION "<<endl;
        cin>>opc;
        system("cls");
        switch(opc){
            case 1:     cargarVectores(vLibros, vPrestamos,vSocios);
                        break;
            case 2:     mostrarVectores(vLibros, vPrestamos,vSocios);
                        break;
            case 3:
                        break;
            case 4:
                        break;
            case 5:
                        break;
            case 0:     return 0;
            default:    cout<<"INGRESO INCORRECTO "<<endl;
                        break;
        }
        system("pause");
    }

    return 0;
}
