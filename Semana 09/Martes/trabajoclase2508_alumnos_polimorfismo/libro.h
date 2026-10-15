#pragma once
#include "fecha.h"
#include <string>
#include "registro.h"
using namespace std;

class Libro:public Registro
{

    /// ISBN, el nombre del libro, el nombre del autor, la fecha de publicación, y la cantidad de ejemplares de ese libro que tiene la biblioteca
private:
    int _isbn;
    char _autor[30];
    char _nombre[40];
    Fecha _fechaPublicacion;
    int _cantEjemplares;
    bool _estado;///true registro activo; false registro borrado

public:
    void setIsbn(int isbn);
    int getID();
    void setAutor(const char *autor);
    const char * getAutor();
    void setNombre(const char * nombre);
    const char * getNombre();
    void setFechaPublicacion(Fecha fechaPublicacion);
    Fecha getFechaPublicacion();
    void setCantEjemplares(int cantEjemplares);
    int getCantEjemplares();

    void cargar(int codigo);

    void mostrar();

    void setEstado(bool estado);
    bool getEstado();

    int getTamanio();

    Libro& operator = (Registro *temp);

};
