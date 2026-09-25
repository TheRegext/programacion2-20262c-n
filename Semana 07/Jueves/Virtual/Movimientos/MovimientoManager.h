#pragma once
#include "MovimientoArchivo.h"

class MovimientosManager
{
    public:
        MovimientosManager();

        void registrarMovimiento();
        void listarMovmientos();
        void modificarMovmientos();
        void eliminarMovmientos();

    protected:
        Movimiento crearMovimiento();
    private:
        MovimientoArchivo _movimientoArchivo;
};
