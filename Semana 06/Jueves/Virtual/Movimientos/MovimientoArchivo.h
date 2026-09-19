#pragma once
#include <string>
#include "Movimiento.h"

class MovimientoArchivo
{
    public:
        MovimientoArchivo(std::string filename = "movimientos.dat");
        void guardar(Movimiento reg);
        void leerTodos(Movimiento reg[], int cant);
        int getCantidadRegistros();

    protected:

    private:
        std::string _fileName;
};
