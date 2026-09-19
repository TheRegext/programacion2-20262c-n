#include <iostream>
#include "MovimientoMenu.h"

using namespace std;

MovimientoMenu::MovimientoMenu()
: Menu(2)
{
    setItem(1, "Crear Movimiento");
    setItem(2, "Listar Movimientos");
}


void MovimientoMenu::run(){
    int opcion;

    do {
        dibujarMenu();
        opcion = obtenerRespuesta();

        switch(opcion){
            case 1: {
                 _movimientoManager.registrarMovimiento();
                break;
            }
            case 2: {
                _movimientoManager.listarMovmientos();
                break;
            }
        }
    } while(opcion != 0);
}
