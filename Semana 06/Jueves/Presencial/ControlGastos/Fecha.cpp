#include <string>
using namespace std;
#include "Fecha.h"

Fecha::Fecha(){
   _dia = 1;
   _mes = 1;
   _anio = 1900;
}

Fecha::Fecha(int dia, int mes, int anio){
   _dia = dia;
   _mes = mes;
   _anio = anio;
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
   _dia = dia;
}

void Fecha::setMes(int mes){
   _mes = mes;
}

void Fecha::setAnio(int anio){
   _anio = anio;
}

bool Fecha::esBisiesto(int anio){
   return (anio % 4 == 0 && anio % 100 != 0) || (anio % 400 == 0);
}

int Fecha::diasDelMes(int mes, int anio){
   if(mes == 2){
      return esBisiesto(anio) ? 29 : 28;
   }

   if(mes == 4 || mes == 6 || mes == 9 || mes == 11){
      return 30;
   }

   return 31;
}

bool Fecha::esValida(){
   if(_anio < 1900 || _anio > 2100){
      return false;
   }

   if(_mes < 1 || _mes > 12){
      return false;
   }

   return _dia >= 1 && _dia <= diasDelMes(_mes, _anio);
}

string Fecha::toString(){
    string salida;

    salida = (_dia < 10 ? "0" : "") + to_string(_dia) + "/";
    salida += (_mes < 10 ? "0" : "") + to_string(_mes) + "/";
    salida += to_string(_anio);

   return salida;
}
