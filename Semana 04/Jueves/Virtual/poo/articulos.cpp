#include "articulos.h"

Articulo::Articulo(){
  _numero = 0;
  _precio = 0;
  _nombre = "";
}

Articulo::Articulo(int numero, float precio, std::string nombre){
  setNumero(numero);
  setPrecio(precio);
  setNombre(nombre);
}

void Articulo::setNumero(int numero){
  _numero = numero;
}

int Articulo::getNumero(){
  return _numero;
}

void Articulo::setPrecio(float precio){
  _precio = precio;
}

float Articulo::getPrecio(){
  return _precio;
}

void Articulo::setNombre(std::string nombre){
  _nombre = nombre;
}

std::string Articulo::getNombre(){
  return _nombre;
}
