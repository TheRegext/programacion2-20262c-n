#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctime>

using namespace std;


#include "socio.h"
#include "libro.h"
#include "prestamo.h"
#include "funcionesGlobales.h"
#include "archivoLibros.h"

///Agregar al programa las siguientes opciones del menú:
    ///cout<<"3. AGREGAR REGISTRO DE SOCIO"<<endl;
    /// cout<<"4. MOSTRAR REGISTROS DE SOCIOS"<<endl;
    ///cout<<"5. AGREGAR REGISTRO DE PRESTAMO"<<endl;
    /// cout<<"6. MOSTRAR REGISTROS DE PRESTAMOS"<<endl;
///Agregar todas las funciones y archivos que sean necesarios.
///Modificar, si es necesario, el tipo de dato de las propiedades definidas en las clases

///Para la opción de agregar registros de libros, validar que no se repita el ISBN
int main(){
    int opc;
    /*Libro obj;
    cout<<sizeof obj<<endl; sizeof-> operador que devuelve el tamaño en bytes de una variable o tipo
    cout<<sizeof(Libro)<<endl;
    system("pause");
    return 0;*/

    while(true){
        system("cls");
        cout<<"1. AGREGAR REGISTRO DE LIBRO"<<endl;
        cout<<"2. MOSTRAR REGISTROS DE LIBROS"<<endl;
        /*cout<<"3. "<<endl;
        cout<<"4. "<<endl;
        cout<<"5. "<<endl;*/
        cout<<"0. FIN DEL PROGRAMA"<<endl;
        cout<<"********************"<<endl;
        cout<<"SELECCIONAR OPCION "<<endl;
        cin>>opc;
        system("cls");
        switch(opc){
            case 1:     if(agregarRegistroLibro()) cout<<"REGISTRO AGREGADO";
                        else cout<<"NO SE PUDO AGREGAR EL REGISTRO";
                        cout<<endl;
                        break;
            case 2:     if(!mostrarRegistroLibro())cout<<"NO SE PUDO LEER EL ARCHIVO"<<endl;
                        break;
            case 3:
                        break;
            case 4:
                        break;
            case 5:
                        break;
            case 0:     return 0;
            default:    cout<<"INGRESO INCORRECTO "<<endl;
                        break;
        }
        system("pause");
    }

    return 0;
}
