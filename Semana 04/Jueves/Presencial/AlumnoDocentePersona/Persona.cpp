#include <iostream>
#include <string>
using namespace std;

#include "Persona.h"

/// CSV: Comma separated values
Persona::Persona(){
 setApellido("");
 setNombre("");
 setDomicilio(Domicilio("", "", "", "", "", ""));
 setContacto(Contacto("", ""));
 setFechaNacimiento(Fecha(0, 0, 0));
}

Persona::Persona(std::string apellido,
                 std::string nombre,
                 Fecha       fechaNacimiento,
                 Domicilio   domicilio,
                 Contacto    contacto)
{
  _apellido = apellido;
  _nombre = nombre;
  _domicilio = domicilio;
  _contacto = contacto;
  _fechaNacimiento = fechaNacimiento;
}

std::string Persona::toCSV()  const{
  std::string valor;
  valor = _apellido + "," + _nombre + ","
        + _fechaNacimiento.toString() + ","
        + _domicilio.toCSV() + ","
        + _contacto.toCSV();
  return valor;
}

void Persona::mostrar() const{
  cout << "Apellido y nombre: " << _apellido << " " << _nombre << endl;
  cout << "Fecha de nacimiento: " << _fechaNacimiento.toString("/") << endl;
  cout << "Domicilio: " << _domicilio.toString() << endl;
  //cout << "Contacto: " << _contacto.toString() << endl;
  cout << "Contacto: TEL " << _contacto.getTelefono() <<  " o MAIL " << _contacto.getEmail() << endl;
}

void Persona::setApellido(std::string apellido){
  _apellido = apellido;
}
void Persona::setNombre(std::string nombre){
  _nombre = nombre;
}

void Persona::setFechaNacimiento(int dia, int mes, int anio){
  _fechaNacimiento.setDia(dia);
  _fechaNacimiento.setMes(mes);
  _fechaNacimiento.setAnio(anio);
}
void Persona::setFechaNacimiento(Fecha fechaNacimiento){
  _fechaNacimiento = fechaNacimiento;
}

void Persona::setDomicilio(Domicilio domicilio){
  _domicilio = domicilio;
}
void Persona::setDomicilio(std::string calle,
                           std::string numero,
                           std::string piso,
                           std::string departamento,
                           std::string localidad,
                           std::string codigoPostal){
  _domicilio.setCalle(calle);
  _domicilio.setNumero(numero);
  _domicilio.setPiso(piso);
  _domicilio.setDepartamento(departamento);
  _domicilio.setLocalidad(localidad);
  _domicilio.setCodigoPostal(codigoPostal);
}

void Persona::setContacto(Contacto contacto){
  _contacto = contacto;
}
void Persona::setContacto(std::string telefono, std::string email){
  _contacto.setTelefono(telefono);
  _contacto.setEmail(email);
}

std::string Persona::getApellido() const{
  return _apellido;
}
std::string Persona::getNombre() const{
  return _nombre;
}
Fecha Persona::getFechaNacimiento() const{
  return _fechaNacimiento;
}
Domicilio Persona::getDomicilio() const{
  return _domicilio;
}
Contacto Persona::getContacto() const{
  return _contacto;
}
