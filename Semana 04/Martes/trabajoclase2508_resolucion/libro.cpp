#include <iostream>
#include "libro.h"


using namespace std;

void Libro::setIsbn(int isbn){
    _isbn=isbn;
}
int Libro::getIsbn(){
    return _isbn;
}
void Libro::setAutor(string autor){
    _autor=autor;
}
string Libro::getAutor(){
    return _autor;
}
void Libro::setNombre(string nombre){
    _nombre=nombre;
}
string Libro::getNombre(){
    return _nombre;
}
void Libro::setFechaPublicacion(Fecha fechaPublicacion){
    _fechaPublicacion=fechaPublicacion;
}
Fecha Libro::getFechaPublicacion(){
    return _fechaPublicacion;
}
void Libro::setCantEjemplares(int cantEjemplares){
    _cantEjemplares=cantEjemplares;
}
int Libro::getCantEjemplares(){
    return _cantEjemplares;
}
void Libro::cargar(){
    ///DEBEN IMPLEMENTAR ALUMNOS
}
void Libro::mostrar(){
    cout<<"ISBN "<<_isbn<<endl;
    cout<<"NOMBRE "<<_nombre<<endl;
    cout<<"*********************"<<endl;
}
