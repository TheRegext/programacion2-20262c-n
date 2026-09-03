#ifndef ALUMNO_H_INCLUDED
#define ALUMNO_H_INCLUDED

#include "Fecha.h"
#include "Domicilio.h"
#include <string>

class Alumno {
private:
  int _legajo;
  std::string  _apellido;
  std::string  _nombre;
  Fecha _nacimiento;
  Domicilio _domicilio;
  std::string  _telefono;
  std::string  _email;
  Fecha _ingreso;

public:
  Alumno();

  void mostrar();
  std::string toCSV();

  // Setters
  void setLegajo(int legajo);
  void setApellido(std::string apellido);
  void setNombre(std::string nombre);

  void setFechaNacimiento(int dia, int mes, int anio);
  void setFechaNacimiento(Fecha nacimiento);
  void setFechaIngreso(int dia, int mes, int anio);
  void setFechaIngreso(Fecha ingreso);

  void setDomicilio(Domicilio domicilio);

//  void setCalle(std::string calle);
//  void setNumero(std::string numero);
//  void setPiso(std::string piso);
//  void setDepartamento(std::string departamento);
//  void setLocalidad(std::string localidad);
//  void setCodigoPostal(std::string codigoPostal);

  void setTelefono(std::string telefono);
  void setEmail(std::string email);


  // Getters
  int getLegajo();
  std::string getApellido();
  std::string getNombre();
  Fecha getFechaNacimiento();
  Domicilio getDomicilio();
//  std::string getCalle();
//  std::string getNumero();
//  std::string getPiso();
//  std::string getDepartamento();
//  std::string getLocalidad();
//  std::string getCodigoPostal();
  std::string getTelefono();
  std::string getEmail();
  Fecha getFechaIngreso();

};

#endif // ALUMNO_H_INCLUDED
