#pragma once

class Tienda{
public:
  Tienda();
  void cargarVentas();
  void mostrarRecaudacionPorArticulo();
    
private:
  float _recaudacion[10];  
};
