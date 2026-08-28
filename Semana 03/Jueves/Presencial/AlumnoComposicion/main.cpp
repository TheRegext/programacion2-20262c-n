#include <iostream>
using namespace std;
#include "Alumno.h"
#include "Fecha.h"

int main()
{
  Alumno alu;

  alu.setLegajo(34437);
  alu.setApellido("Chiotta");
  alu.setNombre("Brian");
  alu.setFechaNacimiento(14, 3, 2002);
  alu.setCalle("Av. Rivadavia");
  alu.setNumero("4520");
  alu.setPiso("3");
  alu.setDepartamento("B");
  alu.setLocalidad("Caballito, CABA");
  alu.setCodigoPostal("C1424");
  alu.setTelefono("011-4555-1234");
  alu.setEmail("brian.chiotta@gmail.com");
  Fecha f(1, 3, 2026);
  alu.setFechaIngreso(f);

  alu.mostrar();


    return 0;
}
