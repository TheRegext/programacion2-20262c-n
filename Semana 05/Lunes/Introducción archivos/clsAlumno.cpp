#include <iostream>
#include <cstring>
#include "clsAlumno.h"

using namespace std;


Alumno::Alumno(int l, const char *nA, int d, int dN, int mN, int aN, const char *dom){
    legajo = l;
    strcpy(nombreApellido, nA);
    dni = d;
    diaNacimiento = dN;
    mesNacimiento = mN;
    anioNacimiento = aN;
    strcpy(domicilio, dom);
}

void Alumno::Cargar(){
    cout<<"INGRESE EL LEGAJO: ";
    cin>>legajo;
    cout<<"INGRESE EL NOMBRE Y APELLIDO: ";
    cin.ignore();
    cin.getline(nombreApellido, 50);
    cout<<"INGRESE EL DNI: ";
    cin>>dni;
    cout<<"INGRESE EL DIA DE NACIMIENTO: ";
    cin>>diaNacimiento;
    cout<<"INGRESE EL MES DE NACIMIENTO: ";
    cin>>mesNacimiento;
    cout<<"INGRESE EL AÑO DE NACIMIENTO: ";
    cin>>anioNacimiento;
    cout<<"INGRESE EL DOMICILIO: ";
    cin.ignore();
    cin.getline(domicilio, 50);
}

void Alumno::Mostrar(){
    cout<<"LEGAJO: "<<legajo<<endl;
    cout<<"NOMBRE Y APELLIDO: "<<nombreApellido<<endl;
    cout<<"DNI: "<<dni<<endl;
    cout<<"FECHA DE NACIMIENTO: "<<diaNacimiento<<"/"<<mesNacimiento<<"/"<<anioNacimiento<<endl;
    cout<<"DOMICILIO: "<<domicilio<<endl;
}

void Alumno::setLegajo(int l){
    if(l>0){
        legajo = l;
    }else{
        legajo = 0;
    }
}

void Alumno::setNombreApellido(const char *nA){
    strcpy(nombreApellido, nA);
}

int Alumno::getLegajo(){
    return legajo;
}

const char *Alumno::getNombreApellido(){
    return nombreApellido;
}

Alumno::~Alumno(){

}
