#include <cstring>
#include "Movimiento.h"

using namespace std;

Movimiento::Movimiento(){
   _idMovimiento = 0;
   strcpy(_descripcion, "");
   _fecha = Fecha();
   _tipo = ' ';
   _idCategoria = 0;
   _importe = 0;
   _activo = false;
}

Movimiento::Movimiento(int idMovimiento, string descripcion, Fecha fecha, char tipo,
                       int idCategoria, float importe, bool activo){
   _idMovimiento = idMovimiento;
   setDescripcion(descripcion);
   _fecha = fecha;
   _tipo = tipo;
   _idCategoria = idCategoria;
   _importe = importe;
   _activo = activo;
}

int Movimiento::getIdMovimiento(){
   return _idMovimiento;
}

string Movimiento::getDescripcion(){
   string descripcion = _descripcion;
   return descripcion;
}

Fecha Movimiento::getFecha(){
   return _fecha;
}

char Movimiento::getTipo(){
   return _tipo;
}

int Movimiento::getIdCategoria(){
   return _idCategoria;
}

float Movimiento::getImporte(){
   return _importe;
}

bool Movimiento::getActivo(){
   return _activo;
}

void Movimiento::setIdMovimiento(int idMovimiento){
   _idMovimiento = idMovimiento;
}

void Movimiento::setDescripcion(string descripcion){
   strcpy(_descripcion, descripcion.c_str());
}

void Movimiento::setFecha(Fecha fecha){
   _fecha = fecha;
}

void Movimiento::setTipo(char tipo){
   _tipo = tipo;
}

void Movimiento::setIdCategoria(int idCategoria){
   _idCategoria = idCategoria;
}

void Movimiento::setImporte(float importe){
   _importe = importe;
}

void Movimiento::setActivo(bool activo){
   _activo = activo;
}
