#include <iostream>
#include "fecha.h"


using namespace std;

int Fecha::getDia(){
    return _dia;
}
int Fecha::getMes(){
    return _mes;
}
int Fecha::getAnio(){
    return _anio;
}
void Fecha::setDia(int dia){
    _dia=dia;
}
void Fecha::setMes(int mes){
    _mes=mes;
}
void Fecha::setAnio(int anio){
    _anio=anio;
}
void Fecha::cargar(){
    cout<<"DIA ";
    cin>>_dia;
    cout<<"MES ";
    cin>>_mes;
    cout<<"ANIO ";
    cin>>_anio;
}
void Fecha::mostrar(){
    ///DEBEN IMPLEMENTAR ALUMNOS
    cout<<_dia<<"/"<<_mes<<"/"<<_anio<<endl;
}

Fecha::Fecha(int d, int m, int a){
    _dia=d;
    _mes=m;
    _anio=a;
}

bool Fecha::operator==(const Fecha &aux){
    if(_dia!=aux._dia)return false;
    if(_mes!=aux._mes)return false;
    if(_anio!=aux._anio)return false;
    return true;
}
