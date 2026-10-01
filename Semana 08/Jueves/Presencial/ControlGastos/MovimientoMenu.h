#pragma once
#include "MovimientoManager.h"

class MovimientoMenu {
public:
   void Mostrar();

private:
   MovimientoManager _manager;
   void MostrarOpciones();
   void EjecutarOpcion(int opcion);
};
