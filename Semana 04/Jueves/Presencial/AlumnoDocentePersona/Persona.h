#ifndef PERSONA_H_INCLUDED
#define PERSONA_H_INCLUDED

#include "Fecha.h"
#include "Domicilio.h"
#include "Contacto.h"
#include <string>

class Persona{
  protected:
  std::string _apellido;
  std::string _nombre;
  Fecha       _fechaNacimiento;
  Domicilio   _domicilio;
  Contacto    _contacto;

  public:
  Persona();
  Persona(std::string apellido,
          std::string nombre,
          Fecha       fechaNacimiento,
          Domicilio   domicilio,
          Contacto    contacto);
  void mostrar()  const;
  std::string toCSV()  const;

  /// Setters
  void setApellido(std::string apellido);
  void setNombre(std::string nombre);

  void setFechaNacimiento(int dia, int mes, int anio);
  void setFechaNacimiento(Fecha fechaNacimiento);

  void setDomicilio(Domicilio domicilio);
  void setDomicilio(std::string calle,
                    std::string numero,
                    std::string piso,
                    std::string departamento,
                    std::string localidad,
                    std::string codigoPostal);

  void setContacto(Contacto contacto);
  void setContacto(std::string telefono, std::string email);

  /// Getters
  std::string getApellido() const;
  std::string getNombre() const;
  Fecha       getFechaNacimiento() const;
  Domicilio   getDomicilio() const;
  Contacto    getContacto() const;

};

#endif // PERSONA_H_INCLUDED
