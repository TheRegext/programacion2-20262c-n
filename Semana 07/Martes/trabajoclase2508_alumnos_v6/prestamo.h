#pragma once
#include "fecha.h"

using namespace std;

class Prestamo
{

/// el libro que se prestó, a qué socio se lo prestó, cuál fue el día del préstamo y cuál fue la fecha de devolución.

private:
    int _isbn;
    int _idSocio;
    Fecha _prestamo;
    Fecha _devolucion;

public:
    void setNumLibro(int numLibro);
    int getNumLibro();
    void setIdSocio(int idSocio);
    int getIdSocio();
    void setPrestamo(Fecha prestamo);
    Fecha getPrestamo();
    void setDevolucion(Fecha devolucion);
    Fecha getdevolucion();

    void cargar();
    void mostrar(int formato=0);

};
