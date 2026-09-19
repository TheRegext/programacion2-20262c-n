#pragma once
#include "MovimientoArchivo.h"

class MovimientosManager
{
    public:
        MovimientosManager();

        void registrarMovimiento();
        void listarMovmientos();

    protected:

    private:
        MovimientoArchivo _movimientoArchivo;
};
