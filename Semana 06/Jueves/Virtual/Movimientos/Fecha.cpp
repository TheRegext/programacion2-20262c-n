#include "Fecha.h"

Fecha::Fecha(){
    _dia = _mes = _anio = 0;
}

Fecha::Fecha(int d, int m, int a){
    setDia(d);
    setMes(m);
    setAnio(a);
}

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


