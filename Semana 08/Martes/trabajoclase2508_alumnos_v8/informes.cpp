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

