#include <iostream>
#include "prestamo.h"

void Prestamo::setNumLibro(int numLibro){
    _numLibro=numLibro;
}
int Prestamo::getNumLibro(){
    return _numLibro;
}
void Prestamo::setIdSocio(int idSocio){
    _idSocio=idSocio;
}
int Prestamo::getIdSocio(){
    return _idSocio;
}
Fecha Prestamo::setPrestamo(Fecha prestamo){
    _prestamo=prestamo;
}
Fecha Prestamo::getPrestamo(){
    return _prestamo;
}
Fecha Prestamo::setDevolucion(Fecha devolucion){
    _devolucion=devolucion;
}
Fecha Prestamo::getdevolucion(){
    return _devolucion;
}
void Prestamo::cargar(){
    ///DEBEN IMPLEMENTAR ALUMNOS
}
void Prestamo::mostrar(){
    ///DEBEN IMPLEMENTAR ALUMNOS
}

