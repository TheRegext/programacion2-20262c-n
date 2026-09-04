#include "TiendaRopa.h"


TiendaRopa::TiendaRopa()
: Tienda(){

}

void TiendaRopa::cargarArticulos(){
  _articulos[0] = Articulo(1, 8500, "Remera manga corta");
  _articulos[1] = Articulo(2, 12500, "Jean clasico");
  _articulos[2] = Articulo(3, 9800, "Buzo canguro");
  _articulos[3] = Articulo(4, 11500, "Camisa formal");
  _articulos[4] = Articulo(5, 6400, "Pantalon de algodon");
  _articulos[5] = Articulo(6, 7800, "Pollera plisada");
  _articulos[6] = Articulo(7, 15000, "Campera de jean");
  _articulos[7] = Articulo(8, 5200, "Short deportivo");
  _articulos[8] = Articulo(9, 4300, "Medias tobilleras x3");
  _articulos[9] = Articulo(10, 6900, "Bufanda tejida");
}
