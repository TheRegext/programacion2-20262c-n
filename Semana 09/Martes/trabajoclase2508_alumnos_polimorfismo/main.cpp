#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctime>

using namespace std;


#include "registro.h"
#include "socio.h"
#include "libro.h"
#include "prestamo.h"
#include "funcionesGlobales.h"
#include "archivoLibros.h"
#include "archivo.h"




int main(){
    //generarArchivos();
    Archivo ar("libros.dat",sizeof(Libro));
    Libro reg;
    //ar.listarArchivo(reg);
    //system("pause");
    //reg.cargar();
    //ar.grabarRegistro(reg, -1);
    //ar.listarArchivo(reg);
    cout<<"REGISTROS "<<ar.cantidadRegistros()<<endl;
    int pos=ar.buscarRegistro(reg, 1000);
    cout<<"EL REGISTRO ESTA EN LA POSICION "<<pos<<endl;
    reg.mostrar();
    //system("pause");
    //return 0;
    int opc;
    ArchivoLibro archiLibro;
    while(true){
        system("cls");
        cout<<"1. AGREGAR REGISTRO DE LIBRO"<<endl;
        cout<<"2. MOSTRAR REGISTROS DE LIBROS"<<endl;
        cout<<"3. ELIMINAR REGISTRO DE LIBRO"<<endl;
        cout<<"4. MODIFICAR CANTIDAD DE EJEMPLARES"<<endl;
        cout<<"5. MENU INFORMES"<<endl;
        cout<<"0. FIN DEL PROGRAMA"<<endl;
        cout<<"********************"<<endl;
        cout<<"SELECCIONAR OPCION "<<endl;
        cin>>opc;
        system("cls");
        switch(opc){
            case 1:     if(archiLibro.agregarRegistroLibro()) cout<<"REGISTRO AGREGADO";
                        else cout<<"NO SE PUDO AGREGAR EL REGISTRO";
                        cout<<endl;
                        break;
            case 2:     if(!archiLibro.mostrarRegistroLibro())cout<<"NO SE PUDO LEER EL ARCHIVO"<<endl;
                        break;
            case 3:     if(!archiLibro.borradoLogicoRegistro())cout<<"NO SE PUDO BORRAR EL REGISTRO"<<endl;
                        else cout<<"REGISTRO ELIMINADO"<<endl;
                        break;
            case 4:     if(!archiLibro.modificarCantidad())cout<<"NO SE PUDO MODIFICAR EL REGISTRO"<<endl;
                        else cout<<"REGISTRO MODIFICADO"<<endl;
                        break;
            case 5:     menuInformes();
                        break;
            case 0:     return 0;
            default:    cout<<"INGRESO INCORRECTO "<<endl;
                        break;
        }
        system("pause");
    }

    return 0;
}
