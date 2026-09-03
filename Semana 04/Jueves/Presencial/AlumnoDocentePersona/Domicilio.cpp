#include "Domicilio.h"
#include <string>
using namespace std;

Domicilio::Domicilio(){
  _calle = "";
  _numero = "";
  _piso = "";
  _departamento = "";
  _localidad = "";
  _codigoPostal = "";
}

Domicilio::Domicilio(string calle,
                     string numero,
                     string piso,
                     string departamento,
                     string localidad,
                     string codigoPostal){
  _calle = calle;
  _numero = numero;
  _piso = piso;
  _departamento = departamento;
  _localidad = localidad;
  _codigoPostal = codigoPostal;
}

string Domicilio::toString() const{
  string valor = _calle + " " + _numero;

  if (!_piso.empty())
    valor += " Piso " + _piso;
  if (!_departamento.empty())
    valor += " Dpto " + _departamento;
  if (!_localidad.empty())
    valor += ", " + _localidad;
  if (!_codigoPostal.empty())
    valor += " (CP " + _codigoPostal + ")";

  return valor;
}

string Domicilio::toCSV() const{
  string valor = _calle + "," + _numero + "," + _piso + ","
               + _departamento + "," + _localidad + "," + _codigoPostal;
  return valor;
}

// Setters
void Domicilio::setCalle(string calle){
  _calle = calle;
}
void Domicilio::setNumero(string numero){
  _numero = numero;
}
void Domicilio::setPiso(string piso){
  _piso = piso;
}
void Domicilio::setDepartamento(string departamento){
  _departamento = departamento;
}
void Domicilio::setLocalidad(string localidad){
  _localidad = localidad;
}
void Domicilio::setCodigoPostal(string codigoPostal){
  _codigoPostal = codigoPostal;
}

// Getters
string Domicilio::getCalle() const{
  return _calle;
}
string Domicilio::getNumero() const{
  return _numero;
}
string Domicilio::getPiso() const{
  return _piso;
}
string Domicilio::getDepartamento() const{
  return _departamento;
}
string Domicilio::getLocalidad() const{
  return _localidad;
}
string Domicilio::getCodigoPostal() const{
  return _codigoPostal;
}
