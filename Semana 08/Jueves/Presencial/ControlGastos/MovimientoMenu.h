#pragma once
#include "MovimientoManager.h"
#include "ModeloExamen.h"

class MovimientoMenu {
public:
   void Mostrar();

private:
   MovimientoManager _manager;
   ModeloExamen _modeloExamen;
   void MostrarOpciones();
   void EjecutarOpcion(int opcion);
};
