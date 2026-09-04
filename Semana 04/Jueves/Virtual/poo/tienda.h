#pragma once
#include "articulos.h"

class Tienda{
public:
  Tienda();
  void cargarArticulos();
  void cargarVentas();
  void mostrarRecaudacionPorArticulo();
  void actualizarPrecio();
    
private:
  void mostrarArticulo(int numero);
  float _recaudacion[10];  
  
protected:
  Articulo _articulos[10];
};
