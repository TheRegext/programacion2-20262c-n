#pragma once
#include <string>

/***
  Entidad de mi proyecto
*/

class Articulo{
public:
  Articulo();
  Articulo(int numero, float precio, std::string nombre);
  void setNumero(int numero);
  int getNumero();
  void setPrecio(float precio);
  float getPrecio();
  void setNombre(std::string nombre);
  std::string getNombre();
  
private:
  int _numero;
  float _precio;
  std::string _nombre;
};
