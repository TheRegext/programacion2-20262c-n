# include<iostream>
# include<cstring>
#include "funciones.h"

using namespace std;

///Por cada una de las 20 materias de la carrera tiene la siguiente informacion:
///NUMERO DE MATERIA (entre 1 y 20) , NOMBRE, CANTIDAD DE ALUMNOS INSCRIPTOS, CANTIDAD DE PROFESORES.

///Ademas por cada ingreso de los estudiantes al aula virtual se registra los siguiente:
///LEGAJO - FECHA DE ACCESO (DIA Y MES) - NUMERO DE LA MATERIA A LA QUE INGRESO - CANTIDAD DE HORAS (NUMERO REAL).

///El fin de los datos se indica con un numero de legajo igual a 0.


void pedirDatosMaterias(int *numeroMateria, char nombreMateria[][50], int *alumnos, int *profesores, int cantMaterias){
    int nroMat, cantAlumnos, cantProf;

    cout<<"Cargar datos de la materias: "<<endl;
    for(int i=0; i<cantMaterias; i++){
        cout<<"Ingrese nro de materia: ";
        cin>>nroMat;
        numeroMateria[nroMat-1]=nroMat;

        cout<<"Ingrese nombre: ";
        cin >> nombreMateria[nroMat - 1];

        cout<<"Ingrese cantidad de alumnos inscriptos: ";
        cin>>cantAlumnos;
        alumnos[nroMat-1]=cantAlumnos;

        cout<<"Ingrese cantidad de profesores: ";
        cin>>cantProf;
        profesores[nroMat-1]=cantProf;
    }
    cout<<endl;
}

void pedirDatosAccesos(int *numeroMateria, int *cantAccesos, float *horas, int accesosAlumnos[][31]){
    int legajo, dia, mes, nroMat;
    float cantHoras;

    cout<<"Cargar datos de los alumnos: "<<endl;
    cout << "Ingrese legajo (0 para finalizar): ";
    cin >> legajo;

    while(legajo != 0)
    {
        cout << "Ingrese dia: ";
        cin >> dia;

        cout << "Ingrese mes: ";
        cin >> mes;

        cout << "Ingrese numero de materia: ";
        cin >> nroMat;

        cout << "Ingrese cantidad de horas: ";
        cin >> cantHoras;

        cantAccesos[nroMat-1]++;

        horas[nroMat-1] += cantHoras;

        if(mes == 3)
        {
            accesosAlumnos[nroMat-1][dia - 1]++;
        }
        cout<<endl;
        cout <<"Ingrese legajo (0 para finalizar): ";
        cin >> legajo;
    }
    cout<<endl;

}

void materiasSinAccesos(int *numeroMateria, char nombreMateria[][50], int *cantidadAccesos,int cantMaterias){
    int contador=0;

    cout << "MATERIAS SIN ACCESOS"<<endl;
    for(int i = 0; i < cantMaterias; i++)
    {
        if(cantidadAccesos[i] == 0)
        {
            cout <<"Materia: "<<numeroMateria[i]<<" | "<<nombreMateria[i]<<endl;
            contador++;
        }
    }

    if(contador==0){
        cout<<"No hubo materias sin accesos"<<endl<<endl;
    }
}

void materiasMasHorasAcceso(int *numeroMateria, char nombreMateria[][50], float *horasMateria, int cantMaterias){
    int posMayor=0;

    for(int i = 1; i < cantMaterias; i++)
    {
        if(horasMateria[i] > horasMateria[posMayor])
        {
            posMayor=i;
        }
    }

    cout<<"MATERIA CON MAYOR CANTIDAD DE HORAS"<<endl;

    cout<< "Numero de materia: "<<numeroMateria[posMayor]<<endl;
    cout<< "Nombre: "<<nombreMateria[posMayor]<< endl<<endl;
}

void accesosPorDiaPorAlumno(int *numeroMateria, char nombreMateria[][50], int accesosMarzo[][31], int cantMaterias){

    cout<< "ACCESOS POR MATERIA Y DIA DE MARZO"<<endl;
    for(int i = 0; i < cantMaterias; i++)
    {
        cout <<"Nro materia: "<< numeroMateria[i]<<" | "<<"Nombre: "<<nombreMateria[i]<<endl;

        for(int j = 0; j < 31; j++)
        {
            cout<<"Dia: "<< j+1<<" " <<accesosMarzo[i][j]<<" accesos"<<endl;
        }
        cout<<endl;
    }
}
