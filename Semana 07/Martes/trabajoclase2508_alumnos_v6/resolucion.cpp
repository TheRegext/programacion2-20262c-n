///Ejercicio:
///Autor:DEK
///Fecha:
///Comentario:

# include<iostream>
#include <cstring>

using namespace std;


#include "socio.h"
#include "libro.h"
#include "prestamo.h"
#include "funcionesGlobales.h"
#include "resolucion.h"

///Sabiendo que los _idSocio están definidos del 100 al 109,  calcular e informar cuántos libros pidió cada socio.
void Resolucion::punto3(Prestamo *vP){
    int vPedidos[10]={0}, pos, i;
    for(i=0;i<10;i++){
        pos=vP[i].getIdSocio()-100;
        vPedidos[pos]++;
    }
    for(i=0;i<10;i++){
        cout<<"SOCIO "<<i+100<<"\t";
        cout<<"CANTIDAD DE LIBROS PEDIDOS "<<vPedidos[pos]<<endl;
    }
}

///4. Sabiendo que los valores de _isbn de los libros están definidos enter el 1000 al 1009,
///informar los libros que no fueron prestados

void Resolucion::punto4(Prestamo *vP){
    int vPrestados[10]={0}, pos, i;
    for(i=0;i<10;i++){
        pos=vP[i].getNumLibro()-1000;
        vPrestados[pos]++;
    }
    for(i=0;i<10;i++){
            if(vPrestados[i]==0){
                cout<<"EL LIBRO "<<i+1000<<" NO FUE PRESTADO "<<endl;
            }
    }
}

///5. Hacer un listado de los préstamos que no fueron devueltos,
///informando el nombre del libro, el nombre del socio y la fecha del préstamo
///NOTA: si el libro no fue devuelto la fecha de devolución es 0/0/0

void Resolucion::punto5(Libro *vL, Socio *vS, Prestamo *vP){
    ///NO SE SABE QUE POSICION OCUPAN LOS idSocio en el vector, pero como están definidos entre
    ///100 y 109 puedo copiarlos de manera ordenada en un vector auxliliar
    Socio vAuxSocio[10];
    int i, pos;
    for(i=0;i<10;i++){
        pos=vS[i].getId()-100;
        vAuxSocio[pos]=vS[pos];
    }
    ///NO SE SABE QUE POSICION OCUPAN LOS _isbn de cada libro en el vector, pero como están definidos entre
    ///1000 y 1009 puedo copiarlos de manera ordenada en un vector auxiliar
    Libro vAuxLibro[10];
    for(i=0;i<10;i++){
        pos=vL[i].getIsbn()-1000;
        vAuxLibro[pos]=vL[pos];
    }

    for(i=0;i<10;i++){
        if(vP[i].getdevolucion().getDia()==0){
            pos=vP[i].getNumLibro()-1000;
            cout<<"NOMBRE DEL LIBRO "<<vAuxLibro[pos].getNombre()<<endl;
            pos=vP[i].getIdSocio()-100;
            cout<<"NOMBRE DEL SOCIO "<<vAuxSocio[pos].getNombre()<<" "<<vAuxSocio[pos].getApellido()<<endl;
        }
    }
}
