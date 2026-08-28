#include <iostream>
#include <cstring>
#include "clsAlumno.h"

using namespace std;

/**
Crear una clase Alumno que almacene los siguientes datos:
-Legajo (int).
-Nombre y apellido (string o vector char).
-DNI.
-Dia, mes y año de nacimiento (3 int).
-Domicilio (string o vector char).

El programa deberá solicitar la cantidad de alumnos que se van a cargar al momento de iniciarse la carga.

Extra: Crear además una clase Inscripcion que permita cargar las inscripciones del alumno a una materia que se identifica con un número de materia del 1 al 20.
PIENSENLO COMO UN TOTAL DE INSCRIPCIONES, NO POR MATERIA.

-ID de inscripcion.
-Numero de materia.
-Legajo del alumno.
*/

void menuPrincipal();
void cargarAlumnos(Alumno *, int);
void mostrarAlumnos(Alumno *, int);
void listarPorPosicion(Alumno *, int);

int main()
{
    menuPrincipal();
    return 0;
}

void menuPrincipal(){
    int opc;
    Alumno *vecAlumnos=nullptr;
    int cant;
    cout<<"INGRESE LA CANTIDAD DE ALUMNOS A CARGAR: ";
    cin>>cant;
    ///VALIDO LA CANTIDAD INGRESADA
    if(cant<=0){
        cout<<"LA CANTIDAD INGRESADA NO ES VALIDA."<<endl;
        system("pause");
        return;
    }
    ///SOLICITO MEMORIA PARA MI PUNTERO
    vecAlumnos = new Alumno[cant];
    ///COMPRUEBO QUE SE HAYA PODIDO RESERVAR LA MEMORIA PARA EL PUNTERO
    if(vecAlumnos == nullptr){
        cout<<"ERROR DE ASIGNACION DE MEMORIA."<<endl;
        return;
    }
    while(true){
        system("cls");
        cout<<"MENU PRINCIPAL"<<endl;
        cout<<"================="<<endl;
        cout<<"1 - CARGAR ALUMNOS"<<endl;
        cout<<"2 - MOSTRAR ALUMNOS"<<endl;
        cout<<"3 - LISTAR ALUMNO POR POSICION"<<endl;
        cout<<"0 - SALIR"<<endl;
        cout<<"================="<<endl;
        cout<<"INGRESE UNA OPCION: ";
        cin>>opc;
        system("cls");
        switch(opc){
            case 1:
                cargarAlumnos(vecAlumnos, cant);
                break;
            case 2:
                mostrarAlumnos(vecAlumnos, cant);
                break;
            case 3:
                listarPorPosicion(vecAlumnos, cant);
                break;
            case 0:
                delete[] vecAlumnos;
                return;
        }
        system("pause");
    }
}

void cargarAlumnos(Alumno vec[], int cant){
    for(int i=0; i<cant; i++){
        vec[i].Cargar();
    }
}

void mostrarAlumnos(Alumno vec[], int cant){
    for(int i=0; i<cant; i++){
        vec[i].Mostrar();
        cout<<endl;
    }
}

void listarPorPosicion(Alumno *vec, int cant){
    int pos;
    cout<<"INGRESE LA POSICION: ";
    cin>>pos;
    if(!(pos < cant and pos >= 0)){
        cout<<"LA POSICION INGRESADA ESTA FUERA DEL VECTOR"<<endl;
        return;
    }
    vec[pos].Mostrar();
}
