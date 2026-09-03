#ifndef DOCENTE_H_INCLUDED
#define DOCENTE_H_INCLUDED

#include "Fecha.h"
#include "Domicilio.h"
#include "Contacto.h"
#include "Persona.h"
#include <string>

class Docente:public Persona {
private:
  std::string _titulo;
  std::string _categoria;

public:
  Docente();
  Docente(std::string apellido,
          std::string nombre,
          Fecha       fechaNacimiento,
          Domicilio   domicilio,
          Contacto    contacto,
          std::string titulo,
          std::string categoria);

  void mostrar()  const;
  std::string toCSV()  const;

  // Setters
  void setTitulo(std::string titulo);
  void setCategoria(std::string categoria);

  // Getters
  std::string getTitulo() const;
  std::string getCategoria() const;
};

#endif // DOCENTE_H_INCLUDED
