#pragma once
#include "menu.h"

class GestorGastos{
public:
  GestorGastos();
  
  void mostrarMenu();
  
private:
  /// opciones del menu
  void establecerSaldoInicial();
  void cargarGastos();
  void mostrarBalance();

  float _saldo;
  Menu _menuGestor;
};
