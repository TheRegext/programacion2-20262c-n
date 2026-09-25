#include <iostream>
#include "Movimiento.h"
#include "MovimientoManager.h"
#include "utils.h"
using namespace std;



MovimientosManager::MovimientosManager()
  : _movimientoArchivo("movimientos.dat")
{

}

Movimiento MovimientosManager::crearMovimiento()
{
  int id, dia, mes, anio, hora, minutos, tipoInt;
  float monto;
  string descripcion;

  id = _movimientoArchivo.getNewID();

  cout << "--- Registrar Movimiento ---" << endl;
  cout << "ID: " << id << endl;
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
  descripcion = cargarCadena();

  return Movimiento(
           id,
           descripcion,
           FechaHora(dia, mes, anio, hora, minutos),
           monto,
           (tipoInt == 1) ? TipoMovimiento::Egreso : TipoMovimiento::Ingreso
         );
}

void MovimientosManager::registrarMovimiento()
{
  Movimiento registro = crearMovimiento();

  if(_movimientoArchivo.guardar(registro) == ArchivoError::Ok)
  {
    cout << "Movimiento registrado." << endl;
  }
  else
  {
    cout << "Ocurrio un error al guardar el Movimiento: (" << _movimientoArchivo.getLastError() << ") " << endl;
  }

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

void MovimientosManager::modificarMovmientos(){
    int index, id;
    Movimiento reg;
    string descripcion;

    cout << "Ingrese el ID del movimiento a modificar: ";
    cin >> id;

    index = _movimientoArchivo.buscarByID(id);

    if(index == -1){
        cout << "El movimiento con id " << id << " no se encuentra en el sistema." << endl;
        return;
    }

    reg = _movimientoArchivo.leer(index);

    cout << reg.getDescripcion() << endl;

    cout << "Ingrese nueva descripcion: ";
    descripcion = cargarCadena();

    reg.setDescripcion(descripcion);

    if(_movimientoArchivo.actualizar(index, reg) == ArchivoError::Ok){
        cout << "Se modfico exitosamente!" << endl;
    }
    else{
        cout << "Ocurrio un error al guardar el Movimiento: (" << _movimientoArchivo.getLastError() << ") " << endl;
    }

}

void MovimientosManager::eliminarMovmientos(){
    int index, id;
    Movimiento reg;
    string descripcion;

    cout << "Ingrese el ID del movimiento a eliminar: ";
    cin >> id;

    index = _movimientoArchivo.buscarByID(id);

    if(index == -1){
        cout << "El movimiento con id " << id << " no se encuentra en el sistema." << endl;
        return;
    }

    reg = _movimientoArchivo.leer(index);

    cout << reg.getDescripcion() << endl;

    if(_movimientoArchivo.eliminar(index) == ArchivoError::Ok){
        cout << "Se modfico exitosamente!" << endl;
    }
    else{
        cout << "Ocurrio un error al guardar el Movimiento: (" << _movimientoArchivo.getLastError() << ") " << endl;
    }
}

