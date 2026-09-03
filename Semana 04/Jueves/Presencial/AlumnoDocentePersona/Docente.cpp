#include <iostream>
#include <string>
using namespace std;

#include "Docente.h"

Docente::Docente(){
 setApellido("");
 setNombre("");
 setDomicilio(Domicilio("", "", "", "", "", ""));
 setContacto(Contacto("", ""));
 setTitulo("");
 setCategoria("");
}

Docente::Docente(std::string apellido,
                 std::string nombre,
                 Fecha       fechaNacimiento,
                 Domicilio   domicilio,
                 Contacto    contacto,
                 std::string titulo,
                 std::string categoria)
{
  _apellido = apellido;
  _nombre = nombre;
  _domicilio = domicilio;
  _contacto = contacto;
  _fechaNacimiento = fechaNacimiento;

  _titulo = titulo;
  _categoria = categoria;
}

std::string Docente::toCSV()  const{
  std::string valor;
  valor = _apellido + "," + _nombre + ","
        + _fechaNacimiento.toString() + ","
        + _domicilio.toCSV() + ","
        + _contacto.toCSV() + ","
        + _titulo + "," + _categoria;
  return valor;
}

// Setters
void Docente::setTitulo(std::string titulo){
  _titulo = titulo;
}
void Docente::setCategoria(std::string categoria){
  _categoria = categoria;
}

// Getters

std::string Docente::getTitulo() const{
  return _titulo;
}
std::string Docente::getCategoria() const{
  return _categoria;
}

void Docente::mostrar() const{
  Persona::mostrar();
  cout << "Titulo: " << _titulo << endl;
  cout << "Categoria: " << _categoria << endl;
}
