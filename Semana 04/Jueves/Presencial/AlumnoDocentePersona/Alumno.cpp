#include <iostream>
#include <string>
using namespace std;

#include "Alumno.h"

Alumno::Alumno(){
    setApellido("");
    setNombre("");
    setFechaIngreso(Fecha(0, 0, 0));
    setDomicilio(Domicilio("", "", "", "", "", ""));
    setContacto(Contacto("", ""));
    setLegajo(0);
    setFechaIngreso(Fecha(0, 0, 0));
}

Alumno::Alumno(std::string apellido,
               std::string nombre,
               Fecha       fechaNacimiento,
               Domicilio   domicilio,
               Contacto    contacto,
               int         legajo,
               Fecha       fechaIngreso)
{
  _apellido = apellido;
  _nombre = nombre;
  _fechaNacimiento = fechaNacimiento;
  _domicilio = domicilio;
  _contacto = contacto;

  _legajo = legajo;
  _fechaIngreso = fechaIngreso;
}

std::string Alumno::toCSV()  const{
  std::string valor;
  valor = to_string(_legajo) + "," + _apellido + "," + _nombre + ","
        + _fechaNacimiento.toString() + ","
        + _domicilio.toCSV() + ","
        + _contacto.toCSV() + ","
        + _fechaIngreso.toString();
  return valor;
}

// Setters
void Alumno::setLegajo(int legajo){
  _legajo = legajo;
}

void Alumno::setFechaIngreso(int dia, int mes, int anio){
  _fechaIngreso.setDia(dia);
  _fechaIngreso.setMes(mes);
  _fechaIngreso.setAnio(anio);
}
void Alumno::setFechaIngreso(Fecha fechaIngreso){
  _fechaIngreso = fechaIngreso;
}

// Getters
int Alumno::getLegajo() const{
  return _legajo;
}
Fecha Alumno::getFechaIngreso() const{
  return _fechaIngreso;
}

void Alumno::mostrar() const{
  Persona::mostrar();
  cout << "Legajo: " << _legajo << endl;
  cout << "Fecha de ingreso: " << _fechaIngreso.toString() << endl;
}
