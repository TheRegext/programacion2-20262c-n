#include <iostream>
using namespace std;

#include "MovimientoMenu.h"

void MovimientoMenu::Mostrar(){
   int opcion;

   do {
      MostrarOpciones();
      cin >> opcion;
      cout << endl;

      EjecutarOpcion(opcion);
   } while(opcion != 0);
}

void MovimientoMenu::MostrarOpciones(){
   cout << endl;
   cout << "===== CONTROL DE GASTOS E INGRESOS =====" << endl;
   cout << "1. Nuevo movimiento" << endl;
   cout << "2. Listar movimientos" << endl;
   cout << "3. Buscar movimiento por id" << endl;
   cout << "4. Listar movimientos por tipo" << endl;
   cout << "5. Resumen de ingresos y gastos" << endl;
   cout << "0. Salir" << endl;
   cout << "Opcion: ";
}

void MovimientoMenu::EjecutarOpcion(int opcion){
   switch(opcion){
      case 1:
        _manager.NuevoMovimiento();
         break;
      case 2:
         _manager.ListarMovimientos();
         break;
      case 3:
        _manager.ListarMovimientoXId();
         break;
      case 4:

         break;
      case 5:

         break;
      case 0:
         cout << "Saliendo del programa..." << endl;
         break;
      default:
         cout << "Opcion invalida." << endl;
         break;
   }
}
