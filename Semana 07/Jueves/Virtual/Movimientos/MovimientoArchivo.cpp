#include <iostream>
#include "MovimientoArchivo.h"

using namespace std;

MovimientoArchivo::MovimientoArchivo(std::string filename)
{
    _fileName = filename;
}

/// Excepciones

ArchivoError MovimientoArchivo::guardar(Movimiento reg){
    FILE *pFile;
    size_t escritura;
    const int CANTIDAD_REGISTROS = 1;

    pFile=fopen(_fileName.c_str(), "ab");

    if(pFile==nullptr){
        _errorMessage = "No se pudo abrir el archivo " + _fileName;
        return ArchivoError::Abrir;
    }

    escritura = fwrite(&reg,sizeof (Movimiento), CANTIDAD_REGISTROS, pFile);

    fclose(pFile);

    if(escritura != CANTIDAD_REGISTROS){
        _errorMessage = "No se pudo escribir el registro";
        return ArchivoError::Escribir;
    }

    _errorMessage = "";
    return ArchivoError::Ok;
}

ArchivoError MovimientoArchivo::leerTodos(Movimiento reg[], int cant){
    FILE *pFile;
    size_t lecturas;

    pFile=fopen(_fileName.c_str(), "rb");

    if(pFile==nullptr){
       _errorMessage = "No se pudo abrir el archivo " + _fileName;
        return ArchivoError::Abrir;
    }

    lecturas = fread(reg, sizeof (Movimiento), cant, pFile);
    fclose(pFile);

    if(lecturas != cant){
        _errorMessage = "No se pudo leer los registros";
        return ArchivoError::Leer;
    }

    _errorMessage = "";
    return ArchivoError::Ok;
}


Movimiento MovimientoArchivo::leer(int indice){
    FILE *pFile;
    Movimiento reg;
    reg.setId(-1);

    pFile=fopen(_fileName.c_str(), "rb");

    if(pFile==nullptr){
        _errorMessage = "No se pudo abrir el archivo " + _fileName;
        return reg;
    }

    fseek(pFile, indice * sizeof (Movimiento), SEEK_SET);

    int lectura = fread(&reg,sizeof (Movimiento), 1, pFile);

    fclose(pFile);

    if(lectura != 1){
        _errorMessage = "No se pudo leer el registro";
        return reg;
    }

    _errorMessage = "";
    return reg;
}


ArchivoError MovimientoArchivo::actualizar(int indice, Movimiento reg){
    FILE *pFile;
    size_t escritura;
    const int CANTIDAD_REGISTROS = 1;

    pFile=fopen(_fileName.c_str(), "rb+");

    if(pFile==nullptr){
        _errorMessage = "No se pudo abrir el archivo " + _fileName;
        return ArchivoError::Abrir;
    }

    fseek(pFile, indice * sizeof (Movimiento), SEEK_SET);

    escritura = fwrite(&reg,sizeof (Movimiento), CANTIDAD_REGISTROS, pFile);

    fclose(pFile);

    if(escritura != CANTIDAD_REGISTROS){
        _errorMessage = "No se pudo actualizar el registro";
        return ArchivoError::Escribir;
    }

    _errorMessage = "";
    return ArchivoError::Ok;
}

int MovimientoArchivo::getCantidadRegistros(){
    FILE *pFile;


    pFile=fopen(_fileName.c_str(), "rb");

    if(pFile==nullptr){
        return 0;
    }

    fseek(pFile, 0, SEEK_END);
    int cantidad = ftell(pFile) / sizeof (Movimiento);

    fclose(pFile);

    return cantidad;
}

int MovimientoArchivo::getNewID(){
    return getCantidadRegistros() + 1;
}

std::string MovimientoArchivo::getLastError(){
    return _errorMessage;
}

void MovimientoArchivo::setFileName(std::string filename){
    _fileName = filename;
}


int MovimientoArchivo::buscarByID(int id){
    FILE *pFile;
    Movimiento reg;
    int posicion;

    pFile=fopen(_fileName.c_str(), "rb");

    if(pFile==nullptr){
        return -1;
    }

    posicion = 0;
    while(fread(&reg, sizeof (Movimiento), 1, pFile)){
        if(reg.getId() == id){
            fclose(pFile);
            return posicion;
        }
        posicion++;
    }

    fclose(pFile);
    return -1;
}

