#include "Contacto.h"
#include <string>
using namespace std;

Contacto::Contacto(){
  _telefono = "";
  _email = "";
}

Contacto::Contacto(string telefono, string email){
  _telefono = telefono;
  _email = email;
}

string Contacto::toString() const{
  string valor = _telefono;

  if (!_telefono.empty() && !_email.empty())
    valor += " / ";
  valor += _email;

  return valor;
}

string Contacto::toCSV() const{
  string valor = _telefono + "," + _email;
  return valor;
}

// Setters
void Contacto::setTelefono(string telefono){
  _telefono = telefono;
}
void Contacto::setEmail(string email){
  _email = email;
}

// Getters
string Contacto::getTelefono() const{
  return _telefono;
}
string Contacto::getEmail() const{
  return _email;
}
