#pragma once
#include <string>
#include "Fecha.h"

class Movimiento {
public:
   Movimiento();
   Movimiento(int idMovimiento, std::string descripcion, Fecha fecha, char tipo,
              int idCategoria, float importe, bool activo);

   int getIdMovimiento();
   std::string getDescripcion();
   Fecha getFecha();
   char getTipo();
   int getIdCategoria();
   float getImporte();
   bool getActivo();

   void setIdMovimiento(int idMovimiento);
   void setDescripcion(std::string descripcion);
   void setFecha(Fecha fecha);
   void setTipo(char tipo);
   void setIdCategoria(int idCategoria);
   void setImporte(float importe);
   void setActivo(bool activo);

private:
   int _idMovimiento;
   char _descripcion[50];
   Fecha _fecha;
   char _tipo;          /// 'I' = Ingreso, 'G' = Gasto
   int _idCategoria;
   float _importe;
   bool _activo;
};
