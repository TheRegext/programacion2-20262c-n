#ifndef DOMICILIO_H_INCLUDED
#define DOMICILIO_H_INCLUDED

#include <string>

class Domicilio {
private:
  std::string _calle;
  std::string _numero;
  std::string _piso;
  std::string _departamento;
  std::string _localidad;
  std::string _codigoPostal;

public:
  Domicilio();
  Domicilio(std::string calle,
            std::string numero,
            std::string piso,
            std::string departamento,
            std::string localidad,
            std::string codigoPostal);

  std::string toString() const;
  std::string toCSV() const;

  // Setters
  void setCalle(std::string calle);
  void setNumero(std::string numero);
  void setPiso(std::string piso);
  void setDepartamento(std::string departamento);
  void setLocalidad(std::string localidad);
  void setCodigoPostal(std::string codigoPostal);

  // Getters
  std::string getCalle() const;
  std::string getNumero() const;
  std::string getPiso() const;
  std::string getDepartamento() const;
  std::string getLocalidad() const;
  std::string getCodigoPostal() const;
};

#endif // DOMICILIO_H_INCLUDED
