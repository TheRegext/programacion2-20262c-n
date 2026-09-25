#include "FechaHora.h"

FechaHora::FechaHora()
{
    _hora =  _minutos = 0;
}

FechaHora::FechaHora(int dia, int mes, int anio, int hora, int minuto)
: Fecha(dia, mes, anio){
    setHora(hora);
    setMinutos(minuto);
}

int FechaHora::getHora()
{
    return _hora;
}

int FechaHora::getMinutos()
{
    return _minutos;
}

void FechaHora::setHora(int hora)
{
    _hora = hora;
}

void FechaHora::setMinutos(int minutos)
{
    _minutos = minutos;
}
