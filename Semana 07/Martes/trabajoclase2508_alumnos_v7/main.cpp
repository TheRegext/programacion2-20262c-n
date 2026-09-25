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




int main(){
    int opc;
    ArchivoLibro archiLibro;
    while(true){
        system("cls");
        cout<<"1. AGREGAR REGISTRO DE LIBRO"<<endl;
        cout<<"2. MOSTRAR REGISTROS DE LIBROS"<<endl;
        cout<<"3. ELIMINAR REGISTRO DE LIBRO"<<endl;
        cout<<"4. MODIFICAR CANTIDAD DE EJEMPLARES"<<endl;
        cout<<"5. MOSTRAR CANTIDAD DE LIBROS REGISTRADOS"<<endl;
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
            case 2:     if(!archiLibro.mostrarRegistroLibro(2))cout<<"NO SE PUDO LEER EL ARCHIVO"<<endl;
                        break;
            case 3:     if(!archiLibro.borradoLogicoRegistro())cout<<"NO SE PUDO BORRAR EL REGISTRO"<<endl;
                        else cout<<"REGISTRO ELIMINADO"<<endl;
                        break;
            case 4:     if(!archiLibro.modificarCantidad())cout<<"NO SE PUDO MODIFICAR EL REGISTRO"<<endl;
                        else cout<<"REGISTRO MODIFICADO"<<endl;
                        break;
            case 5:     if(archiLibro.contarRegistros()==0)cout << "NO HAY REGISTROS CARGADOS";
                        else cout << "CANTIDAD DE LIBROS REGISTRADOS: " << archiLibro.contarRegistros() << endl;
                        break;
            case 0:     return 0;
            default:    cout<<"INGRESO INCORRECTO "<<endl;
                        break;
        }
        system("pause");
    }

    return 0;
}
