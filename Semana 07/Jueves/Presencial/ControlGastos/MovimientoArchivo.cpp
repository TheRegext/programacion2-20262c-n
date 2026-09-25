#include "MovimientoArchivo.h"
#include <string>
#include <cstdio>
using namespace std;

MovimientoArchivo::MovimientoArchivo(string nombreArchivo){
    _nombre = nombreArchivo;
}

bool MovimientoArchivo::guardar(Movimiento reg){
    FILE *p;

    p = fopen(_nombre.c_str(), "ab");
    if (p == NULL){
        return false;
    }
    bool ok = fwrite(&reg, sizeof(Movimiento), 1, p);
    fclose(p);
    return ok;
}

bool MovimientoArchivo::guardar(Movimiento reg, int pos){
    FILE *p;

    p = fopen(_nombre.c_str(), "rb+");
    if (p == NULL){
        return false;
    }
    fseek(p, sizeof(Movimiento) * pos, SEEK_SET);
    bool ok = fwrite(&reg, sizeof(Movimiento), 1, p);
    fclose(p);
    return ok;
}

bool MovimientoArchivo::eliminar(int pos){
    Movimiento aux = leer(pos);
    aux.setActivo(false);
    bool ok = guardar(aux, pos);
    return ok;
}

Movimiento MovimientoArchivo::leer(int pos){
    FILE *p;
    Movimiento reg;

    p = fopen(_nombre.c_str(), "rb");
    if (p == NULL){
        reg.setIdMovimiento(-1);
        return reg;
    }
    fseek(p, sizeof(Movimiento) * pos, SEEK_SET);
    fread(&reg, sizeof(Movimiento), 1, p);
    fclose(p);
    return reg;
}

int MovimientoArchivo::buscar(int idMovimiento){
    int cant = contarRegistros();
    Movimiento aux;

    for(int i=0; i<cant; i++){
        aux = leer(i);
        if (aux.getIdMovimiento() == idMovimiento){
            return i;
        }
    }
    return -1;
}


int MovimientoArchivo::contarRegistros(){
    FILE *p;
    Movimiento reg;

    p = fopen(_nombre.c_str(), "rb");

    if (p == NULL){
        return 0;
    }

    int cantidad;
    fseek(p, 0, SEEK_END); // Se desplaza 0 bytes desde el final
    int bytes = ftell(p); // Devuelve la cantidad de bytes desplazados
    fclose(p);
    cantidad = bytes / sizeof(Movimiento);
    return cantidad;
}
