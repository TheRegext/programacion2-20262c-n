#pragma once
#include <string>
#include "FechaHora.h"

enum class TipoMovimiento
{
  Ingreso,
  Egreso
};

class Movimiento
{
public:
  Movimiento();
  Movimiento(int id, std::string descripcion, FechaHora fecha, float monto, TipoMovimiento tipo);

  int getId();
  void setId(int id);

  std::string getDescripcion();
  void setDescripcion(std::string descripcion);

  FechaHora getFecha();
  void setFecha(FechaHora fecha);

  float getMonto();
  void setMonto(float monto);

  TipoMovimiento getTipo();
  void setTipo(TipoMovimiento tipo);

protected:

private:
  int _id;
  char _descripcion[100];
  FechaHora _fecha;
  float _monto;
  TipoMovimiento _tipo;
};
