#pragma once
#include <string>
#include "Movimiento.h"

enum class ArchivoError{
    Ok = 0,

    Leer,
    Abrir,
    Escribir,
};



class MovimientoArchivo
{
    public:
        MovimientoArchivo(std::string filename = "movimientos.dat");
        ArchivoError guardar(Movimiento reg);
        Movimiento leer(int index);
        ArchivoError leerTodos(Movimiento reg[], int cant);
        ArchivoError actualizar(int indice, Movimiento reg);
        int buscarByID(int id);

        int getCantidadRegistros();

        int getNewID();

        std::string getLastError();

        void setFileName(std::string filename);

    protected:

    private:
        std::string _fileName;
        std::string _errorMessage;
};
