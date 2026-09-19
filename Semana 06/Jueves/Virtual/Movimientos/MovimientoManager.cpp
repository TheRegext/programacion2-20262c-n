#include <iostream>
#include "Movimiento.h"
#include "MovimientoManager.h"

using namespace std;

MovimientosManager::MovimientosManager()
{

}

void MovimientosManager::registrarMovimiento()
{
  int id, dia, mes, anio, hora, minutos, tipoInt;
  float monto;
  string descripcion;

  cout << "--- Registrar Movimiento ---" << endl;
  cout << "ID: ";
  cin >> id;
  cout << "Monto: ";
  cin >> monto;
  cout << "Dia: ";
  cin >> dia;
  cout << "Mes: ";
  cin >> mes;
  cout << "Anio: ";
  cin >> anio;
  cout << "Hora: ";
  cin >> hora;
  cout << "Minutos: ";
  cin >> minutos;
  cout << "Tipo (0-Ingreso, 1-Egreso): ";
  cin >> tipoInt;
  cout << "Descripcion: ";
  cin.ignore();
  getline(cin, descripcion);

  ///expresion condicional =>  condicion ? verdadero : falso


  FechaHora fecha(dia, mes, anio, hora, minutos);
  TipoMovimiento tipo = (tipoInt == 1) ? TipoMovimiento::Egreso : TipoMovimiento::Ingreso;

  Movimiento m(id, descripcion, fecha, monto, tipo);

  _movimientoArchivo.guardar(m);

  cout << "Movimiento registrado." << endl;
  system("pause");
}

void MovimientosManager::listarMovmientos()
{
  int cantidad = _movimientoArchivo.getCantidadRegistros();
  cout << "--- Listado de Movimientos ---" << endl;

  if(cantidad == 0)
  {
    cout << "No hay movimientos registrados." << endl;
  }
  else
  {
    Movimiento *vecMov = new Movimiento[cantidad];
    _movimientoArchivo.leerTodos(vecMov, cantidad);
    for(int i = 0; i < cantidad; i++)
    {
      cout << "ID: " << vecMov[i].getId() << endl;
      cout << "Monto: " << vecMov[i].getMonto() << endl;

      if(vecMov[i].getTipo() == TipoMovimiento::Ingreso)
      {
        cout << "Tipo: " <<  "Ingreso" << endl;
      }
      else
      {
        cout << "Tipo: " << "Egreso" << endl;
      }

      cout << "Descripcion: " << vecMov[i].getDescripcion() << endl;
      cout << "-----------------------------" << endl;
    }

    delete [] vecMov;
  }
  system("pause");
}

