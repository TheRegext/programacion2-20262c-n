#include <iostream>
#include "MovimientoArchivo.h"

using namespace std;

MovimientoArchivo::MovimientoArchivo()
{
    //ctor
}


void MovimientoArchivo::guardar(Movimiento reg){
    FILE *pFile;

    pFile=fopen("movimientos.dat", "ab");

    if(pFile==nullptr){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return;
    }

    fwrite(&reg,sizeof (Movimiento), 1, pFile);

    fclose(pFile);
}

void MovimientoArchivo::leerTodos(Movimiento reg[], int cant){
    FILE *pFile;

    pFile=fopen("movimientos.dat", "rb");

    if(pFile==nullptr){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return;
    }

    fread(reg, sizeof (Movimiento), cant, pFile);

    fclose(pFile);
}



int MovimientoArchivo::getCantidadRegistros(){
    FILE *pFile;

    pFile=fopen("movimientos.dat", "rb");

    if(pFile==nullptr){
        return 0;
    }

    fseek(pFile, 0, SEEK_END);
    int cantidad = ftell(pFile) / sizeof (Movimiento);

    fclose(pFile);

    return cantidad;
}
