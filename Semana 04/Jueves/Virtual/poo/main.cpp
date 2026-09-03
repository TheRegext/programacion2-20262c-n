#include <iostream>
#include "tienda.h"
using namespace std;

/**
  Hacer un programa que le solicite al usuario numero de articulo entre el 1 y el 10, 
  Precio unitario y cantidad vendida de una venta.

  La cantidad de ventas son indefinidas, el programa debe finalizar cuando se 
  ingrese un numero de articulo igual a 0.

  Para cada articulo vendido mostrar la recaudaci¢n
*/


int main()
{
  Tienda tienda;
  
  tienda.cargarVentas();
  
  tienda.mostrarRecaudacionPorArticulo(); 

  return 0;
}
