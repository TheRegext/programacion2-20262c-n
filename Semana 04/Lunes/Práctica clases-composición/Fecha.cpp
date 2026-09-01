#include "Fecha.h"
#include <string>
using namespace std;

Fecha::Fecha(){
  _dia = 0;
  _mes = 0;
  _anio = 0;
}

Fecha::Fecha(int dia, int mes, int anio){
  _dia = dia;
  _mes = mes;
  _anio = anio;
}

string Fecha::toString(string separador){
  string diastr, messtr;
  diastr = (_dia < 10 ? "0" + to_string(_dia) : to_string(_dia));
  messtr = (_mes < 10 ? "0" + to_string(_mes) : to_string(_mes));

  string valor = diastr + separador + messtr + separador + to_string(_anio);
  return valor;
}

// Setters
void Fecha::setDia(int dia){
  _dia = dia;
}
void Fecha::setMes(int mes){
  _mes = mes;
}
void Fecha::setAnio(int anio){
  _anio = anio;
}

// Getters
int Fecha::getDia(){
  return _dia;
}
int Fecha::getMes(){
  return _mes;
}
int Fecha::getAnio(){
  return _anio;
}
