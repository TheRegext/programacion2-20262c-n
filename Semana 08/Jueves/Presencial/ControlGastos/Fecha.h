#pragma once
#include <string>

/// Clase Fecha utilizada en clases anteriores.
/// Guarda dia, mes y anio, valida la fecha y la muestra como DD/MM/AAAA.
class Fecha {
public:
   Fecha();
   Fecha(int dia, int mes, int anio);

   int getDia();
   int getMes();
   int getAnio();

   void setDia(int dia);
   void setMes(int mes);
   void setAnio(int anio);

   bool esValida();
   std::string toString();

private:
   int _dia;
   int _mes;
   int _anio;

   bool esBisiesto(int anio);
   int diasDelMes(int mes, int anio);
};
