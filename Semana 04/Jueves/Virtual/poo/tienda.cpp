#include <iostream>
#include "tienda.h"
using namespace std;


Tienda::Tienda()
: _recaudacion{}{
  
}

void Tienda::cargarVentas()
{
  int numeroArticulo, cantidadVendida;
  float precioUnitario;

  cout << "Ingrese numero de articulo (1-10): ";
  cin >> numeroArticulo;

  while(numeroArticulo != 0)
  {
    cout << "Ingrese precio unitario: ";
    cin >> precioUnitario;
    cout << "Ingrese cantidad vendida: ";
    cin >> cantidadVendida;

    _recaudacion[numeroArticulo - 1] += precioUnitario * cantidadVendida;

    cout << "Ingrese numero de articulo (1-10): ";
    cin >> numeroArticulo;
  }
}

void Tienda::mostrarRecaudacionPorArticulo()
{
  cout << "Recuadacion: " << endl;
  
  for(int i=0;i<10;i++){
    cout << "#"<< i+1 << ": $" << _recaudacion[i] << endl;  
  }
  
}
