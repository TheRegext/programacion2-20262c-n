#pragma once
#include "fecha.h"
#include <string>

using namespace std;

class Libro
{

    /// ISBN, el nombre del libro, el nombre del autor, la fecha de publicación, y la cantidad de ejemplares de ese libro que tiene la biblioteca
private:
    int _isbn;
    string _autor;
    string _nombre;
    Fecha _fechaPublicacion;
    int _cantEjemplares;

public:
    void setIsbn(int isbn);
    int getIsbn();
    void setAutor(string autor);
    string getAutor();
    void setNombre(string nombre);
    string getNombre();
    void setFechaPublicacion(Fecha fechaPublicacion);
    Fecha getFechaPublicacion();
    void setCantEjemplares(int cantEjemplares);
    int getCantEjemplares();

    void cargar();
    void mostrar();

};
