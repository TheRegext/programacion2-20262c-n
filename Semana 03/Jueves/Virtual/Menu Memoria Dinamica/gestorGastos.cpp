#include <iostream>
#include "gestorGastos.h"
using namespace std;

GestorGastos::GestorGastos()
  : _menuGestor(3), _saldo(0)
{
  _menuGestor.setItem(1, "Establecer monto inicial");
  _menuGestor.setItem(2, "Registrar gasto");
  _menuGestor.setItem(3, "Ver balance");
}

void GestorGastos::mostrarMenu()
{
  bool salir = false;
  do
  {
    _menuGestor.dibujarMenu();

    switch(_menuGestor.obtenerRespuesta())
    {
    case 1:
      establecerSaldoInicial();
      break;
    case 2:
      cargarGastos();
      break;
    case 3:
      mostrarBalance();
      break;
    case 0:
      salir = true;
      break;
    }
  }
  while(!salir);
}

/// opciones del menu
void GestorGastos::establecerSaldoInicial()
{
  cout << "Ingrese saldo inicial: ";
  cin >> _saldo;
}

void GestorGastos::cargarGastos()
{
  float gasto;
  
  cout << "Ingrese gasto: ";
  cin >> gasto;

  while(gasto != 0)
  {
    _saldo -= gasto;

    cout << "Ingrese gasto: ";
    cin >> gasto;
  }
}

void GestorGastos::mostrarBalance()
{
  cout << "Balance: " << _saldo << endl;
}
