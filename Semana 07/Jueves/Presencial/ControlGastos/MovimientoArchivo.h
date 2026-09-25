#ifndef MOVIMIENTOARCHIVO_H_INCLUDED
#define MOVIMIENTOARCHIVO_H_INCLUDED

#include "Movimiento.h"
#include <string>

class MovimientoArchivo{
    public:

    MovimientoArchivo(std::string nombre = "movimientos.dat");
    bool eliminar(int pos);
    bool guardar(Movimiento reg); // Añade al final
    bool guardar(Movimiento reg, int pos); // Sobreescribe uno existente
    Movimiento leer(int pos);
    int buscar(int idMovimiento);
    int contarRegistros();

    private:
    std::string _nombre;

};

#endif // MOVIMIENTOARCHIVO_H_INCLUDED
