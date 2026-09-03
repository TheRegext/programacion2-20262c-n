#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED

#include <string>

class Fecha{
  private:
    int _dia, _mes, _anio;

  public:
    Fecha();
    Fecha(int dia, int mes, int anio);

    std::string toString(std::string separador = "/") const;

    // Setters
    void setDia(int dia);
    void setMes(int mes);
    void setAnio(int anio);

    // Getters
    int getDia() const;
    int getMes() const;
    int getAnio() const;
};

#endif // FECHA_H_INCLUDED
