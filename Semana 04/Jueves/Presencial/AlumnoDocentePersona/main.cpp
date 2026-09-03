#include <iostream>
using namespace std;

#include "Fecha.h"
#include "Domicilio.h"
#include "Contacto.h"
#include "Persona.h"
#include "Alumno.h"
#include "Docente.h"

int main(){
    Alumno alumno(
        "Simon",
        "Angel",
        Fecha(2, 10, 1986),
        Domicilio(
            "Mitre",
            "1234",
            "",
            "",
            "Tigre",
            "1617"),
        Contacto("12345678", "asimon@docentes.frgp.utn.edu.ar"),
        89389,
        Fecha(1, 3, 2007)
    );

    alumno.mostrar();

    Docente docente(
        "Varela",
        "Mariano",
        Fecha (15, 5, 1990),
        Domicilio(
            "Mitre",
            "1234",
            "",
            "",
            "Tigre",
            "1617"),
        Contacto("12342344", "mvarela@docentes.frgp.utn.edu.ar"),
        "Lic. en Tecnologia Educativa",
        "Jefe de trabajos practicos"
    );

    cout << endl << "--------------------" << endl;

    docente.mostrar();


    return 0;
}
