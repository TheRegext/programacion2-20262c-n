# include<iostream>


using namespace std;
# include "libro.h"
# include "archivoLibros.h"


bool agregarRegistroLibro(){
    ///declaración de variables
    FILE *pLibro;
    Libro reg;
    ///apertura del archivo
    pLibro=fopen("libros.dat", "ab");
    ///chequear si se pudo abrir
    if(pLibro==nullptr){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return false;
    }
    ///Cargar en memoria el registro de libro
    reg.cargar();
    ///Escribir en el disco el registro
    int escribio=fwrite(&reg,sizeof reg, 1, pLibro);///Si pudo escribir devuelve la cantidad de registros
    ///Cerrrar el archivo                           ///Si no pudo escribir devuelve 0
    fclose(pLibro);
    return escribio;
}

bool mostrarRegistroLibro(){
    ///declaración de variables
    FILE *pLibro;
    Libro reg;
    ///apertura del archivo
    pLibro=fopen("libros.dat", "rb");
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
