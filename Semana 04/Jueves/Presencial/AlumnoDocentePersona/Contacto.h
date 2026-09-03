#ifndef CONTACTO_H_INCLUDED
#define CONTACTO_H_INCLUDED

#include <string>

class Contacto {
private:
  std::string _telefono;
  std::string _email;

public:
  Contacto();
  Contacto(std::string telefono, std::string email);

  std::string toString() const;
  std::string toCSV() const;

  // Setters
  void setTelefono(std::string telefono);
  void setEmail(std::string email);

  // Getters
  std::string getTelefono() const;
  std::string getEmail() const;
};

#endif // CONTACTO_H_INCLUDED
