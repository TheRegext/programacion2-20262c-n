#include <cstring>
#include "Movimiento.h"

Movimiento::Movimiento()
{
    _id = 0;
    _descripcion[0] = '\0';
    _fecha = FechaHora(0,0,0,0,0);
    _monto = 0;
    _tipo = TipoMovimiento::Egreso;
}

Movimiento::Movimiento(int id, std::string descripcion, FechaHora fecha, float monto, TipoMovimiento tipo)
{
    setId(id);
    setDescripcion(descripcion);
    setFecha(fecha);
    setMonto(monto);
    setTipo(tipo);
}

int Movimiento::getId()
{
    return _id;
}

void Movimiento::setId(int id)
{
    _id = id;
}

std::string Movimiento::getDescripcion()
{
    return std::string(_descripcion);
}

void Movimiento::setDescripcion(std::string descripcion)
{
    if(descripcion.size() <= 99){
        strcpy(_descripcion, descripcion.c_str());
    }
    else{
        strcpy(_descripcion, descripcion.substr(0, 99).c_str());
    }
}

FechaHora Movimiento::getFecha()
{
    return _fecha;
}

void Movimiento::setFecha(FechaHora fecha)
{
    _fecha = fecha;
}

float Movimiento::getMonto()
{
    return _monto;
}

void Movimiento::setMonto(float monto)
{
    _monto = monto;
}

TipoMovimiento Movimiento::getTipo()
{
    return _tipo;
}

void Movimiento::setTipo(TipoMovimiento tipo)
{
    _tipo = tipo;
}
