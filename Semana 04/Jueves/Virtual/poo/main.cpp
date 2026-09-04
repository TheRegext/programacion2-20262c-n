#include <iostream>
#include "tienda.h"
#include "tiendaRopa.h"
using namespace std;

/**
  Parte #01
  ----------
  Hacer un programa que le solicite al usuario numero de articulo entre el 1 y el 10, 
  Precio unitario y cantidad vendida de una venta.

  La cantidad de ventas son indefinidas, el programa debe finalizar cuando se 
  ingrese un numero de articulo igual a 0.

  Para cada articulo vendido mostrar la recaudaci¢n
  
  Parte #02
  -----------
  Ahora el cliente quiere que los articulos tengan un nombre y un precio fijo.
  
  Por lo tanto, ahora el programa debe:
    Cargar los Articulos (codigo de articulo, precio y nombre);
    Por cada venta solo se carga el codigo de articulo y cantidad.
    Mostrar la recaudacion me debe mostrar el nombre del articulo.
*/


int main()
{
  TiendaRopa tienda;
  
  tienda.cargarArticulos();
  
  tienda.cargarVentas();
  
  tienda.mostrarRecaudacionPorArticulo(); 
  
  tienda.actualizarPrecio();

  return 0;
}
