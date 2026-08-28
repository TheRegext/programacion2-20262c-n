#include <iostream>
using namespace std;
#include <string>

#include "Alumno.h"


Alumno::Alumno(){
    _legajo = 0;
}

std::string Alumno::toCSV(){
  std::string valor;
  valor = to_string(_legajo) + "," + _apellido + "," + _nombre;
  return valor;
}

// Getters
int Alumno::getLegajo(){
  return _legajo;
}
std::string Alumno::getApellido(){
  return _apellido;
}
std::string Alumno::getNombre(){
  return _nombre;
}
//int Alumno::getDiaNacimiento(){
//  return _diaNacimiento;
//}
//int Alumno::getMesNacimiento(){
//  return _mesNacimiento;
//}
//int Alumno::getAnioNacimiento(){
//  return _anioNacimiento;
//}
std::string Alumno::getCalle(){
  return _calle;
}
std::string Alumno::getNumero(){
  return _numero;
}
std::string Alumno::getPiso(){
  return _piso;
}
std::string Alumno::getDepartamento(){
  return _departamento;
}
std::string Alumno::getLocalidad(){
  return _localidad;
}
std::string Alumno::getCodigoPostal(){
  return _codigoPostal;
}
std::string Alumno::getTelefono(){
  return _telefono;
}
std::string Alumno::getEmail(){
  return _email;
}

Fecha Alumno::getFechaNacimiento(){
  return _nacimiento;
}

Fecha Alumno::getFechaIngreso(){
  return _ingreso;
}

//int Alumno::getDiaIngreso(){
//  return _diaIngreso;
//}
//int Alumno::getMesIngreso(){
//  return _mesIngreso;
//}
//int Alumno::getAnioIngreso(){
//  return _anioIngreso;
//}

// Setters
void Alumno::setLegajo(int legajo){
  _legajo = legajo;
}
void Alumno::setApellido(std::string apellido){
  _apellido = apellido;
}
void Alumno::setNombre(std::string nombre){
  _nombre = nombre;
}

void Alumno::setCalle(std::string calle){
  _calle = calle;
}
void Alumno::setNumero(std::string numero){
  _numero = numero;
}
void Alumno::setPiso(std::string piso){
  _piso = piso;
}
void Alumno::setDepartamento(std::string departamento){
  _departamento = departamento;
}
void Alumno::setLocalidad(std::string localidad){
  _localidad = localidad;
}
void Alumno::setCodigoPostal(std::string codigoPostal){
  _codigoPostal = codigoPostal;
}
void Alumno::setTelefono(std::string telefono){
  _telefono = telefono;
}
void Alumno::setEmail(std::string email){
  _email = email;
}

void Alumno::setFechaNacimiento(int dia, int mes, int anio){
  _nacimiento.setDia(dia);
  _nacimiento.setMes(mes);
  _nacimiento.setAnio(anio);
}
void Alumno::setFechaNacimiento(Fecha nacimiento){
  _nacimiento = nacimiento;
}
void Alumno::setFechaIngreso(int dia, int mes, int anio){
  _ingreso.setDia(dia);
  _ingreso.setMes(mes);
  _ingreso.setAnio(anio);
}
void Alumno::setFechaIngreso(Fecha ingreso){
  _ingreso = ingreso;
}


void Alumno::mostrar(){
    cout << "Legajo: " << _legajo << endl;
    cout << "Apellido y nombre: " << _apellido << " " << _nombre << endl;
    cout << "Fecha de nacimiento: " << _nacimiento.toString("-") << endl;
    cout << "Domicilio: " << _calle << " " << _numero;
    if (!_piso.empty())
        cout << " Piso " << _piso;
    if (!_departamento.empty())
        cout << " Dpto " << _departamento;
    cout << endl;
    cout << "Localidad: " << _localidad << " (CP " << _codigoPostal << ")" << endl;
    cout << "Telefono: " << _telefono << endl;
    cout << "Email: " << _email << endl;
    cout << "Fecha de ingreso: " << _ingreso.toString() << endl;
}
