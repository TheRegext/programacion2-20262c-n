#pragma once
#include "fecha.h"

using namespace std;

class Socio
{

///  DNI, el nombre, el apellido, un número de teléfono, un email y la fecha de nacimiento
private:
    int _dni;
    string _apellido;
    int _numTelefono;
    string _nombre;
    string _email;
    Fecha _fechaNacimiento;
    int _id;

public:
    void setDni(int dni);
    int getDni();
    void setApellido(string apellido);
    string getApellido();
    void setNumTelefono(int numTelefono);
    int getNumTelefono();
    void setNombre(string nombre);
    string getNombre();
    void setEmail(string email);
    string getEmail();
    void setFechaNacimiento(Fecha fechaNacimiento);
    Fecha getFechaNacimiento();
    void setId(int id);
    int getId();

    void cargar();
    void mostrar();
};
