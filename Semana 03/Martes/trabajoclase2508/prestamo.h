#pragma once
#include "fecha.h"

using namespace std;

class Prestamo
{

/// el libro que se prestó, a qué socio se lo prestó, cuál fue el día del préstamo y cuál fue la fecha de devolución.

private:
    int _numLibro;
    int _idSocio;
    Fecha _prestamo;
    Fecha _devolucion;

public:
    void setNumLibro(int numLibro);
    int getNumLibro();
    void setIdSocio(int idSocio);
    int getIdSocio();
    Fecha setPrestamo(Fecha prestamo);
    Fecha getPrestamo();
    Fecha setDevolucion(Fecha devolucion);
    Fecha getdevolucion();

    void cargar();
    void mostrar();

};
