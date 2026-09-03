#include <iostream>
using namespace std;
#include "Alumno.h"
#include "Fecha.h"

/**
Utilizando el mecanismo de la composición, agregar una clase Domicilio para utilizar como propiedad de la clase Alumno.

Crear una clase Docente con los siguientes datos:
-Legajo docente. (int)
-Nombre y apellido.
-CUIL. (string o vector char)
-Fecha de nacimiento.
-Fecha de contratación.
-Domicilio.
-Telefono.
-Email.

Hacer un programa que le solicite al usuario una cantidad de alumnos a ingresar. El programa debe tener un menu con las siguientes opciones:
1-Cargar alumnos.
2-Mostrar alumnos.
3-Buscar alumno por legajo.
4-Listar alumnos por apellido.
5-Listar alumnos que se inscribieron antes de una fecha que se ingresa por teclado.
*/

int main()
{
  Alumno alu;

  alu.setLegajo(34437);
  alu.setApellido("Chiotta");
  alu.setNombre("Brian");
  Fecha fechaAux;
  fechaAux.setDia(14);
  fechaAux.setMes(3);
  fechaAux.setAnio(2002);
  alu.setFechaNacimiento(fechaAux);
  Domicilio aux("Calle falsa", "123", "3", "", "Springfield", "1234B");
  alu.setDomicilio(aux);
//  alu.setCalle("Av. Rivadavia");
//  alu.setNumero("4520");
//  alu.setPiso("3");
//  alu.setDepartamento("B");
//  alu.setLocalidad("Caballito, CABA");
//  alu.setCodigoPostal("C1424");
  alu.setTelefono("011-4555-1234");
  alu.setEmail("brian.chiotta@gmail.com");
  Fecha f(1, 3, 2026);
  alu.setFechaIngreso(f);

  alu.mostrar();


    return 0;
}
