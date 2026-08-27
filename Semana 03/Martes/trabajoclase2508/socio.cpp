#include <iostream>
#include "socio.h"

void Socio::setDni(int dni){
    _dni=dni;
}
int Socio::getDni(){
    return _dni;
}
void Socio::setApellido(string apellido){
    _apellido=apellido;
}
string Socio::getApellido(){
    return _apellido;
}
void Socio::setNumTelefono(int numTelefono){
    _numTelefono=numTelefono;
}
int Socio::getNumTelefono(){
    return _numTelefono;
}
void Socio::setNombre(string nombre){
    _nombre=nombre;
}
string Socio::getNombre(){
    return _nombre;
}
void Socio::setEmail(string email){
    _email=email;
}
string Socio::getEmail(){
    return _email;
}
void Socio::setFechaNacimiento(Fecha fechaNacimiento){
    _fechaNacimiento=fechaNacimiento;
}
Fecha Socio::getFechaNacimiento(){
    return _fechaNacimiento;
}
void Socio::setId(int id){
    _id=id;
}
int Socio::getId(){
    return _id;
}
void Socio::cargar(){
    ///DEBEN IMPLEMENTAR ALUMNOS
}
void Socio::mostrar(){
    ///DEBEN IMPLEMENTAR ALUMNOS
}

