#include <iostream>
#include <iomanip>
#include "MovimientoManager.h"
#include "colors.hpp"

using namespace std;

void MovimientoManager::NuevoMovimiento(){
   int idMovimiento;

   cout << "Id del movimiento: ";
   cin >> idMovimiento;

   Movimiento movimiento = CargarMovimiento(idMovimiento);

   if(_archivo.guardar(movimiento)){
      cout << "Movimiento guardado correctamente." << endl;
   }
   else{
      cout << "No se pudo guardar el movimiento." << endl;
   }
}

Movimiento MovimientoManager::CargarMovimiento(int idMovimiento){
   string descripcion = PedirDescripcion();
   Fecha fecha = PedirFecha();
   char tipo = PedirTipo();
   int idCategoria;

   cout << "Id de categoria: ";
   cin >> idCategoria;

   float importe = PedirImporte();

   /// Todo movimiento nuevo nace activo.
   return Movimiento(idMovimiento, descripcion, fecha, tipo, idCategoria, importe, true);
}

bool MovimientoManager::ExisteId(int idMovimiento){
}

void MovimientoManager::EditarMovimiento(){
    int id;
    float importeNuevo;

    cout << "ID del registro a editar: ";
    cin >> id;

    int pos = _archivo.buscar(id);

    if (pos < 0){
        cout << "El registro no existe" << endl;
        return;
    }

    Movimiento reg = _archivo.leer(pos);
    MostrarEncabezado();
    MostrarMovimiento(reg);

    cout << endl << "Importe: $";
    cin >> importeNuevo;

    reg.setImporte(importeNuevo);

    bool ok = _archivo.guardar(reg, pos);

    if (ok){
        cout << "Registro editado correctamente" << endl;
    }
    else{
        cout << "No se pudo editar el registro" << endl;
    }

    return;
}

void MovimientoManager::EliminarMovimiento(){
    int id;
    cout << "ID del registro a editar: ";
    cin >> id;

    int pos = _archivo.buscar(id);

    if (pos < 0){
        cout << "El registro no existe" << endl;
        return;
    }

    bool ok = _archivo.eliminar(pos);

    if (ok){
        cout << "Registro eliminado correctamente" << endl;
    }
    else{
        cout << "No se pudo eliminar el registro" << endl;
    }

    return;
}

string MovimientoManager::PedirDescripcion(){
   string descripcion;

   cout << "Descripcion: ";
   cin.ignore();
   getline(cin, descripcion);

   return descripcion;
}

Fecha MovimientoManager::PedirFecha(){
   int dia, mes, anio;

   cout << "Fecha" << endl;
   cout << "  Dia: ";
   cin >> dia;
   cout << "  Mes: ";
   cin >> mes;
   cout << "  Anio: ";
   cin >> anio;

   return Fecha(dia, mes, anio);
}

char MovimientoManager::PedirTipo(){
   char tipo;

   cout << "Tipo (I = Ingreso, G = Gasto): ";
   cin >> tipo;
   tipo = toupper(tipo);

   while(tipo != 'I' && tipo != 'G'){
      cout << "Tipo invalido. Ingrese I o G: ";
      cin >> tipo;
      tipo = toupper(tipo);
   }

   return tipo;
}

float MovimientoManager::PedirImporte(){
   float importe;

   cout << "Importe: ";
   cin >> importe;

   while(importe <= 0){
      cout << "El importe debe ser mayor a cero: ";
      cin >> importe;
   }

   return importe;
}

string MovimientoManager::TipoToString(char tipo){
   if(tipo == 'I'){
      return "Ingreso";
   }

   if(tipo == 'G'){
      return "Gasto";
   }

   return "Desconocido";
}

/// --- Listados ---

void MovimientoManager::ListarMovimientos(){
   int cantidadRegistros = _archivo.contarRegistros();

   if(cantidadRegistros == 0){
      cout << "No hay movimientos cargados." << endl;
      return;
   }

   MostrarEncabezado();

   for(int i = 0; i < cantidadRegistros; i++){
      Movimiento reg = _archivo.leer(i);
      if (!reg.getActivo()){
        cout << colors::bright_red;
        MostrarMovimiento(reg);
      }
      else{
        cout << colors::bright_green;
        MostrarMovimiento(reg);
      }
   }


   cout << colors::reset << endl << "Total: " << colors::on_blue << colors::bright_white << cantidadRegistros << " movimientos." << colors::reset << endl << endl;
   cout << "Los registros eliminados se listan en " << colors::bright_red << "rojo" << colors::reset;
   cout << endl << endl;
}

void MovimientoManager::ListarMovimientoXId(){
    int idMovimiento;

    cout << "Ingresar Id Movimiento: ";
    cin >> idMovimiento;

    int pos = _archivo.buscar(idMovimiento);

    if (pos >= 0){
        MostrarEncabezado();
        MostrarMovimiento(_archivo.leer(pos));
    }
    else{
        cout << "No existe movimiento con Id " << idMovimiento << endl;
    }

}

void MovimientoManager::ListarMovimientosXTipo(){
   char tipo = PedirTipo();
   int cantidadRegistros = _archivo.contarRegistros();
   int encontrados = 0;
   float total = 0;

   for(int i = 0; i < cantidadRegistros; i++){
      Movimiento movimiento = _archivo.leer(i);

      if(movimiento.getTipo() == tipo){
         if(encontrados == 0){
            MostrarEncabezado();
         }

         MostrarMovimiento(movimiento);
         encontrados++;
         total += movimiento.getImporte();
      }
   }

   if(encontrados == 0){
      cout << "No hay movimientos de tipo " << TipoToString(tipo) << "." << endl;
      return;
   }

   cout << endl << "Movimientos encontrados: " << encontrados << endl;
   cout << "Total: $ " << fixed << setprecision(2) << total << endl;
}

void MovimientoManager::MostrarEncabezado(){
   cout << endl;
   cout << left << setw(5) << "Id" << setw(12) << "Fecha" << setw(9) << "Tipo" << setw(6) << "Cat."
        << setw(32) << "Descripcion" << right << setw(12) << "Importe" << endl;
   cout << left << setw(5) << "---" << setw(12) << "----------" << setw(9) << "-------" << setw(6) << "----"
        << setw(32) << "------------------------------" << right << setw(12) << "----------" << endl;
}

void MovimientoManager::MostrarMovimiento(Movimiento movimiento){
   cout << left << setw(5) << movimiento.getIdMovimiento()
        << setw(12) << movimiento.getFecha().toString()
        << setw(9) << TipoToString(movimiento.getTipo())
        << setw(6) << movimiento.getIdCategoria()
        << setw(32) << movimiento.getDescripcion()
        << right << setw(12) << fixed << setprecision(2) << movimiento.getImporte() << endl;
}
