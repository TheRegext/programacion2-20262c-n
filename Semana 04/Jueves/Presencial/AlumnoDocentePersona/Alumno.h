#ifndef ALUMNO_H_INCLUDED
#define ALUMNO_H_INCLUDED

#include "Fecha.h"
#include "Domicilio.h"
#include "Contacto.h"
#include "Persona.h"
#include <string>

class Alumno{
private:
  Persona _personaAlumno;
  int         _legajo;
  Fecha       _fechaIngreso;

public:
  Alumno();
  Alumno(std::string apellido,
         std::string nombre,
         Fecha       fechaNacimiento,
         Domicilio   domicilio,
         Contacto    contacto,
         int         legajo,
         Fecha       fechaIngreso);

  void mostrar()  const;
  std::string toCSV()  const;

  // Setters
  void setLegajo(int legajo);

  void setFechaIngreso(int dia, int mes, int anio);
  void setFechaIngreso(Fecha fechaIngreso);

  // Getters
  int         getLegajo() const;
  Fecha       getFechaIngreso() const;
};

#endif // ALUMNO_H_INCLUDED
