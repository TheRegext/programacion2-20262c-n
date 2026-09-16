#include <iostream>
#include "prestamo.h"

using namespace std;


void Prestamo::setNumLibro(int numLibro){
    _isbn=numLibro;
}
int Prestamo::getNumLibro(){
    return _isbn;
}
void Prestamo::setIdSocio(int idSocio){
    _idSocio=idSocio;
}
int Prestamo::getIdSocio(){
    return _idSocio;
}
void Prestamo::setPrestamo(Fecha prestamo){
    _prestamo=prestamo;
}
Fecha Prestamo::getPrestamo(){
    return _prestamo;
}
void Prestamo::setDevolucion(Fecha devolucion){
    _devolucion=devolucion;
}
Fecha Prestamo::getdevolucion(){
    return _devolucion;
}
void Prestamo::cargar(){
    ///DEBEN IMPLEMENTAR ALUMNOS
}
void Prestamo::mostrar(int formato){
    ///DEBEN IMPLEMENTAR ALUMNOS
    if (formato==1){
        cout<<"ISBN "<<_isbn<<endl,
        cout<<"SOCIO "<<_idSocio<<endl;
        cout<<"FECHA PRESTAMO: ";
        _prestamo.mostrar();
        cout<<"FECHA DEVOLUCION: ";
        _devolucion.mostrar();
        cout<<"***************************"<<endl;
    }
    else{
        cout<<_isbn<<"\t"<<_idSocio<<endl;

    }
}

