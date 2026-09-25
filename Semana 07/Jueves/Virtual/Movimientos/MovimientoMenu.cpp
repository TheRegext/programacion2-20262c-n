#include <iostream>
#include "MovimientoMenu.h"

using namespace std;

MovimientoMenu::MovimientoMenu()
: Menu(4)
{
    setItem(1, "Crear Movimiento");
    setItem(2, "Listar Movimientos");
    setItem(3, "Modificar Movimiento");
    setItem(4, "Eliminar Movimiento");
}


void MovimientoMenu::run(){
    int opcion;

    do {
        dibujarMenu();
        opcion = obtenerRespuesta();

        switch(opcion){
            case 1:
                 _movimientoManager.registrarMovimiento();
                break;
            case 2:
                _movimientoManager.listarMovmientos();
                break;
            case 3:
                _movimientoManager.modificarMovmientos();
                break;
            case 4:
                _movimientoManager.eliminarMovmientos();
                break;
        }
    } while(opcion != 0);
}
