# include<iostream>
# include<cstring>

using namespace std;

# include "informes.h"
# include "libro.h"
# include "archivoLibros.h"


void Informes::punto1(){
    int cantEjemplares;
    cout<<"INGRESAR LA CANTIDAD DE EJEMPLARES DE LIBROS ";
    cin>>cantEjemplares;
    ArchivoLibro archiLibro;
    Libro reg;
    int cantReg=archiLibro.cantidadRegistros();
    if(cantReg<1){
        cout<<"NO EXISTE EL ARCHIVO "<<endl;
        return;
    }
    for(int i=0;i<cantReg;i++){
        reg=archiLibro.leerRegistro(i);
        if(reg.getCantEjemplares()==cantEjemplares){
            reg.mostrar();
            cout<<endl;
        }
    }

}


void Informes::punto5(){
    ///no tiene en cuenta si los registros están borrados
    /*ArchivoLibro archiLibro;
    Libro reg;
    int cantReg=archiLibro.cantidadRegistros();
    if(cantReg<1){
        cout<<"NO EXISTE EL ARCHIVO "<<endl;
        return;
    }
    Libro *pLibro;
    pLibro=new Libro[cantReg];
    if(pLibro==nullptr){
        cout<<"ERROR DE MEMORIA "<<endl;
        return;
    }
    for(int i=0;i<cantReg;i++){
        pLibro[i]=archiLibro.leerRegistro(i);
    }
    ///ordenar por cantidad de ejemplares
    Libro aux;
    int posMin;
    for(int i=0;i<cantReg-1;i++){
        posMin=i;
        for(int j=i+1;j<cantReg;j++){
            if(strcmp(pLibro[j].getNombre(), pLibro[posMin].getNombre())<0){
                posMin=j;
            }
        }
        aux=pLibro[i];
        pLibro[i]=pLibro[posMin];
        pLibro[posMin]=aux;
    }
    ///ordenado por cantida de ejemplares
    for(int i=0;i<cantReg-1;i++){
        posMin=i;
        for(int j=i+1;j<cantReg;j++){
            if(pLibro[j].getCantEjemplares()<pLibro[posMin].getCantEjemplares()){
                posMin=j;
            }
        }
        aux=pLibro[i];
        pLibro[i]=pLibro[posMin];
        pLibro[posMin]=aux;
    }
    */
    ///teniendo en cuenta los registros borrados
    ArchivoLibro archiLibro;
    Libro reg;
    int cantReg=archiLibro.cantidadRegistros(1);///me cuenta sólo los activos
    if(cantReg<1){
        cout<<"NO EXISTE EL ARCHIVO "<<endl;
        return;
    }
    Libro *pLibro;
    pLibro=new Libro[cantReg];
    if(pLibro==nullptr){
        cout<<"ERROR DE MEMORIA "<<endl;
        return;
    }
    int pos=0;
    int cantidadTotal=archiLibro.cantidadRegistros();
    for(int i=0;i<cantidadTotal;i++){
        reg=archiLibro.leerRegistro(i);
        if(reg.getEstado()){
            pLibro[pos]=reg;
            pos++;
        }
    }

    Libro aux;
    int posMin;
    for(int i=0;i<cantReg-1;i++){
        posMin=i;
        for(int j=i+1;j<cantReg;j++){
            if(strcmp(pLibro[j].getNombre(), pLibro[posMin].getNombre())<0){
                posMin=j;
            }
        }
        aux=pLibro[i];
        pLibro[i]=pLibro[posMin];
        pLibro[posMin]=aux;
    }


    ///mostrar el vector ordenado
    for(int i=0;i<cantReg;i++){
        pLibro[i].mostrar();
        cout<<endl;
    }
    ///devolver la memoria solicitada
    delete []pLibro;
}
