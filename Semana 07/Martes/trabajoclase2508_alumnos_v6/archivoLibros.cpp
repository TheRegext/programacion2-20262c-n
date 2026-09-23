# include<iostream>
# include<cstring>

using namespace std;
# include "libro.h"
# include "archivoLibros.h"



ArchivoLibro::ArchivoLibro(const char *nombreArchivo){
    strcpy(_nombreArchivo,nombreArchivo);
}
bool ArchivoLibro::agregarRegistroLibro(){
    ///declaración de variables
    FILE *pLibro;
    Libro reg;
    ///apertura del archivo
    pLibro=fopen(_nombreArchivo, "ab");
    ///chequear si se pudo abrir
    if(pLibro==nullptr){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return false;
    }
    ///Cargar en memoria el registro de libro
    cout<<"INGRESAR EL ISBN ";
    int isbn;
    cin>>isbn;
    int pos=buscarRegistroLibro(isbn);
    if(pos>=0) return false;
    reg.cargar(isbn);
    ///Escribir en el disco el registro
    int escribio=fwrite(&reg,sizeof reg, 1, pLibro);///Si pudo escribir devuelve la cantidad de registros
    ///Cerrrar el archivo                           ///Si no pudo escribir devuelve 0
    fclose(pLibro);
    return escribio;
}

bool ArchivoLibro::mostrarRegistroLibro(){
    ///declaración de variables
    FILE *pLibro;
    Libro reg;
    ///apertura del archivo
    pLibro=fopen(_nombreArchivo, "rb");
    ///chequear si se pudo abrir
    if(pLibro==nullptr){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return false;
    }
    ///Leer del disco el/los registro/s mientras haya registros en el archivo
    while(fread(&reg,sizeof reg, 1, pLibro)==1){;///Si pudo leer devuelve la cantidad de registros
    ///mostrar el registro
        reg.mostrar();
    }

    fclose(pLibro);
    return true;

}

int ArchivoLibro::buscarRegistroLibro(int isbn){
    FILE *pLibro;
    Libro reg;
    int pos=0;
    pLibro=fopen(_nombreArchivo, "rb");
    if(pLibro==nullptr){
            return -2;
    }
    while(fread(&reg, sizeof reg, 1, pLibro)==1){
        if(reg.getIsbn()==isbn && reg.getEstado()){
            fclose(pLibro);
            return pos;
        }
        pos++;
    }
    fclose(pLibro);
    return -1;
}

bool ArchivoLibro::borradoLogicoRegistro(){
    Libro reg;
    int isbn;
///Ingresar el valor a buscar del registro
    cout<<"INGRESAR EL ISBN DEL LIBRO A BORRAR ";
    cin>>isbn;
///    Buscar el registro que se quiere eliminar.
    int pos=buscarRegistroLibro(isbn);
    if(pos==-2){
        cout<<"ERROR EN LA APERTURA DEL ARCHIVO "<<endl;
        return false;
    }
    if(pos==-1){
        cout<<"NO EXISTE UN REGISTRO CON ESE ISBN"<<endl;
        return false;
    }
///Leer el registro (escribirlo en una variable de memoria)
    reg=leerRegistro(pos);///hacerla!!!
///Cambiar el estado del campo que se utiliza como bandera de /la variable
    reg.setEstado(false);
///Sobrescribir el registro en la misma posición del archivo en que se encontraba.
    bool escribio=sobreEscribirRegistro(reg,pos);///hacer!!!
    return escribio;
}

Libro ArchivoLibro::leerRegistro(int pos){
    FILE *pLibro;
    Libro reg;
    reg.setIsbn(-12);
    pLibro=fopen(_nombreArchivo, "rb");
    if(pLibro==nullptr){
            return reg;
    }
    fseek(pLibro,pos*sizeof(Libro),0);
    ///SEEK_SET->0 desde el principio
    ///SEEK_CUR->1 desde donde está
    ///SEEK_END->2 desde el final
    fread(&reg, sizeof reg, 1, pLibro);
    fclose(pLibro);
    return reg;
}


bool ArchivoLibro::sobreEscribirRegistro(Libro reg, int pos){
    FILE *pLibro;
    pLibro=fopen(_nombreArchivo, "rb+");///+ le agrega al modo lo que no tiene
    if(pLibro==nullptr){
            return false;
    }
    fseek(pLibro,pos*sizeof(Libro),0);
    ///SEEK_SET->0 desde el principio
    ///SEEK_CUR->1 desde donde está
    ///SEEK_END->2 desde el final
    bool escribio=fwrite(&reg, sizeof reg, 1, pLibro);
    fclose(pLibro);
    return escribio;
}

bool ArchivoLibro::modificarCantidad(){
    Libro reg;
    int isbn;
///Ingresar el valor a buscar del registro
    cout<<"INGRESAR EL ISBN DEL LIBRO A MODIFICAR ";
    cin>>isbn;
///    Buscar el registro que se quiere modificar.
    int pos=buscarRegistroLibro(isbn);
    if(pos==-2){
        cout<<"ERROR EN LA APERTURA DEL ARCHIVO "<<endl;
        return false;
    }
    if(pos==-1){
        cout<<"NO EXISTE UN REGISTRO CON ESE ISBN"<<endl;
        return false;
    }
///Leer el registro (escribirlo en una variable de memoria)
    reg=leerRegistro(pos);
///Pedir el ingreso y cambiar el valor del campo a modificar
    cout<<"INGRESAR EL NUEVO VALOR DE CANTIDAD DE EJEMPLARES ";
    int cantidadEjemplares;
    cin>>cantidadEjemplares;
    reg.setCantEjemplares(cantidadEjemplares);
///Sobrescribir el registro en la misma posición del archivo en que se encontraba.
    bool escribio=sobreEscribirRegistro(reg,pos);
    return escribio;

}
