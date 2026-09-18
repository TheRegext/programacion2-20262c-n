#pragma once
#include <string>
#include "Movimiento.h"
#include "MovimientoArchivo.h"

class MovimientoManager {
public:
   void NuevoMovimiento();
   void ListarMovimientos();
   void ListarMovimientoXId();
   void ListarMovimientosXTipo();
   void MostrarResumen();

private:
   MovimientoArchivo _archivo;

   Movimiento CargarMovimiento(int idMovimiento);
   bool ExisteId(int idMovimiento);
   std::string PedirDescripcion();
   Fecha PedirFecha();
   char PedirTipo();
   float PedirImporte();
   std::string TipoToString(char tipo);
   void MostrarEncabezado();
   void MostrarMovimiento(Movimiento movimiento);
};
