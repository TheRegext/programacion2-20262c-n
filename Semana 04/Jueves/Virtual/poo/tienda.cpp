#include <iostream>
#include "tienda.h"
using namespace std;


Tienda::Tienda()
: _recaudacion{}{
}

void Tienda::cargarArticulos(){
  _articulos[0] = Articulo(1, 5000, "Coca Cola 2.25L"); /// objeto anonimo
  _articulos[1] = Articulo(2, 1200, "Agua mineral 500ml");
  _articulos[2] = Articulo(3, 2500, "Lata de atun");
  _articulos[3] = Articulo(4, 1800, "Galletitas surtidas");
  _articulos[4] = Articulo(5, 900, "Caramelo masticable");
  _articulos[5] = Articulo(6, 3200, "Harina 0000 1kg");
  _articulos[6] = Articulo(7, 1500, "Pan lactal");
  _articulos[7] = Articulo(8, 4500, "Jugo de naranja 1L");
  _articulos[8] = Articulo(9, 700, "Chocolate en barra");
  _articulos[9] = Articulo(10, 6000, "Vino Malbec 750ml");
}

void Tienda::cargarVentas()
{
  int numeroArticulo, cantidadVendida;

  cout << "Ingrese numero de articulo (1-10): ";
  cin >> numeroArticulo;

  while(numeroArticulo != 0)
  {
    cout << "Articulo: " << _articulos[numeroArticulo - 1].getNombre() << endl;
    
    cout << "Ingrese cantidad vendida: ";
    cin >> cantidadVendida;

    _recaudacion[numeroArticulo - 1] += _articulos[numeroArticulo - 1].getPrecio() * cantidadVendida;

    cout << "Ingrese numero de articulo (1-10): ";
    cin >> numeroArticulo;
  }
}

void Tienda::mostrarRecaudacionPorArticulo()
{
  cout << "Recuadacion: " << endl;
  
  for(int i=0;i<10;i++){
    cout << " -"<< _articulos[i].getNombre() << ": $" << _recaudacion[i] << endl;  
  }
}


void Tienda::actualizarPrecio(){
  int numeroArticulo;
  float precioNuevo;
  
  cout << "Ingrese numero de articulo: ";
  cin >> numeroArticulo;
  
  mostrarArticulo(numeroArticulo);
  
  cout << "Ingrese nuevo precio: ";
  cin >> precioNuevo;
  
  _articulos[numeroArticulo - 1].setPrecio(precioNuevo);
}


void Tienda::mostrarArticulo(int numero){
  cout << "----------------------" << endl;
  cout << "Numero: " << _articulos[numero - 1].getNumero() << endl;
  cout << "Nombre: " << _articulos[numero - 1].getNombre() << endl;
  cout << "Precio: $" << _articulos[numero - 1].getPrecio() << endl;
  cout << "----------------------" << endl;
}


