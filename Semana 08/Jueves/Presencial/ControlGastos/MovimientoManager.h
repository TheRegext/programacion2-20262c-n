#pragma once
#include <string>
#include "Movimiento.h"
#include "MovimientoArchivo.h"

class MovimientoManager {
public:
   void NuevoMovimiento();
   void EditarMovimiento();
   void EliminarMovimiento();
   void ListarMovimientos();
   void ListarMovimientoXId();
   void ListarMovimientosXTipo();
   void MostrarResumen();
   void PuntoA();
   void PuntoB();
   void PuntoC();

private:
   MovimientoArchivo _archivo;

   void OrdenarDatos(float *vectorGastos, std::string *nombres);
   void MostrarGastosPorMes(float *vectorGastos, std::string *nombres);
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
